# 2026-10-31 P1：只改变接收缓冲区容量

原文任务：[路线图当日 P1](../../LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-31)，只扩展一个输入/shape/配置，写预期、实际与局限。本文的具体方法为补充验收，不替代原文要求。

## 实验约定

- 唯一改变：服务端 `char buf[4]` 改为 `char buf[3]`。
- 固定输入仍为 ASCII `hi`（2 字节）、`hello socket!`（13 字节），不添加换行。
- 固定回环地址 `127.0.0.1:39031`、单连接处理、结束发送方向后等待回显的协议、发送循环与客户端不变。
- 客户端仍使用 [socket_echo.py](socket_echo.py)，其中接收请求容量 4096 不改；P1 只改变服务端 recv 使用的临时数组。
- [buf4 基线源码](2026-10-31-echo-buf4.cpp)已保存。开始 P1 时助手只读比较当前源码与基线一致，仍为 buf[4]；尚未修改为 3。
- 基线本人实测：hi 的接收 n=2；13 字节的 n=4/4/4/1；两组均完整回显且 echo_match=True。原始证据见 [主验收记录](2026-10-31-socket-cases.md)。

## 运行前预期：已记录

先针对同一个 13 字节输入回答：

1. 缓冲区改为 3 后，完整回显内容与总字节数应怎样？
2. 至少需要几次 n>0 的 recv 才能收齐 13 字节？给出一种可能的正数返回序列。

本人在修改与运行之前给出的预测原文：

```text
recv_bytes=3, total=3
recv_bytes=3, total=6
recv_bytes=3, total=9
recv_bytes=3, total=12
recv_bytes=1, total=13
```

这是一种正确的可能分段，共 5 次正数读取，累计 13。导师补充解释最少次数：4 次每次最多 3 字节，只能取得 12 字节，故至少 5 次。每次读取量是上限约束，实际不要求与预测分段完全相同。

独立正确性预期按原样回显规格补全：hi 的完整回显仍为 b'hi'、2 字节；hello socket! 的完整回显仍为 b'hello socket!'、13 字节，两组 echo_match=True。具体内容规则由导师明确，不记作本人本轮已主动解释所有部分。

预测提交后助手只读核对源码仍为 buf[4]，尚未进行 P1 修改或运行。

## 本人操作入口

只把 echo.cpp 中的 `char buf[4]` 改为 `char buf[3]`，其余代码与客户端保持固定。

终端 A 编译并启动第一组：

```bash
cd "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics"
g++ -std=c++17 -Wall -Wextra -g echo.cpp -o /tmp/llm-echo-buf3 && /tmp/llm-echo-buf3
```

终端 B 第一组：

```bash
python3 "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/tests/socket_echo.py" 'hi'
```

第一组结束后，终端 A 再运行 `/tmp/llm-echo-buf3`，看到等待提示，再在终端 B 运行第二组：

```bash
python3 "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/tests/socket_echo.py" 'hello socket!'
```

待本人反馈两组双方输出，并回答：仅凭这次结果，是否足以证明 3 字节缓冲区比 4 字节更快？还需要什么证据？此题用于局限检查，尚未收到回答。

## 实际结果与局限

助手只读比较当前源码与 buf4 基线，确实只有 `char buf[4]` → `char buf[3]` 一处容量差异。[buf3 源码快照](2026-10-31-echo-buf3.cpp)与[实际源码差异](../results/raw/2026-10-31-echo-buf3-source.diff)已保存，未改客户端、输入、协议、地址或发送循环。

| 输入 | buf4 基线 n | buf3 实际 n | 实际回显 |
| --- | --- | --- | --- |
| hi | 2 | 2 | b'hi'，2 字节，echo_match=True |
| hello socket! | 4/4/4/1 | 3/3/3/3/1 | b'hello socket!'，13 字节，echo_match=True |

本人原始输出：[hi 服务端](../results/raw/2026-10-31-echo-buf3-hi-server-learner-output.txt) / [客户端](../results/raw/2026-10-31-echo-buf3-hi-client-learner-output.txt)、[13 字节服务端](../results/raw/2026-10-31-echo-buf3-long-server-learner-output.txt) / [客户端](../results/raw/2026-10-31-echo-buf3-long-client-learner-output.txt)。第一组本人粘贴内容从监听提示开始，未补造最前面的 socket_fd 行；accepted 提示仍含两个 fd。两组完整内容、累计长度、回显长度、EOF 与关闭符合预期；本人未另贴计时或退出码。

本人局限原答：「不能，还确发送时间、接收时间的测量，或者测量sock_fd启动和关闭的时间」。不能据此判断更快、当前缺少计时的判断正确。导师进一步区分测量范围：若比较收发效果，可固定输入与连接条件，测客户端开始发送到完整接收回显的往返耗时，重复多次比较；单独的 send 返回耗时不等于对方应用收齐耗时，创建/关闭开销需作为另一测量范围说明，不能直接代替收发耗时。

本次仅验证本机两个小输入的正确性与部分读取，不证明性能提升或真实网络负载下表现；具体分段序列不保证每次相同。没有新增性能测试要求，也没有补造计时。本次局限记录含导师补充，不记作本人独立设计完整性能实验。

| 项目 | 状态 | 需补做 |
| --- | --- | --- |
| 运行前预期 | 通过（指导下记录） | 本人给出可能分段与累计 13，导师说明次数下界并补全原样回显规格；实际分段不锁定 |
| 只改一个配置 | 通过 | 已保存基线、buf3 快照及单行容量差异 |
| 两种长度实际结果 | 通过 | 本人运行两组，内容/长度正确，n<=3；原始输出已保存 |
| 局限解释 | 通过（导师补充测量范围） | 本人正确指出不能比较速度、缺少计时；计时范围与覆盖边界由导师进一步说明 |

P1 的预期、实际、单配置约束与局限均已完成；当天剩余概念与固定项见主验收记录，不据此宣布全日完成。
