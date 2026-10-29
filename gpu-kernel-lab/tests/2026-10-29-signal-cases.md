# 2026-10-29 signal 分步验收

任务来源：路线图 `d-2026-10-29` / `x-2026-10-29`。工作目录为项目根目录，C++17；导师提供示例、注释与命令，本人保存并运行，不记为无提示独立完成。

## 首次 Ctrl+C 实跑

输入/动作：执行 `/tmp/llm-signal-demo`，在 `ready: press Ctrl+C` 出现后按一次 Ctrl+C，回到终端后立即执行 `echo $?`。

- 独立预期（运行前已给出）：输出 `cleanup: fd closed`，程序退出状态为 0。
- 实际证据：本人终端截图显示 `ready: press Ctrl+C`、`^Ccleanup: fd closed`，随后 `echo $?` 输出 `0`。截图未显示编译诊断。
- [原始转录、命令与当时源码快照](../results/raw/2026-10-29-signal-first-learner-observation.json)。截图保留在聊天中，本地记录是人工转录。
- 助手只读核对源码，未代编译、代跑。终端 `^C` 与程序输出相邻不影响验收。

| 任务/原文要求 | 状态 | 真实证据/结果 | 需补做 |
| --- | --- | --- | --- |
| Ctrl+C 后正常清理 | 通过（sleep 与本次阻塞 read 场景，指导下） | 本人两次截图均显示清理完成及 exit=0；阻塞 read 的跟踪确认 EINTR、close 返回 0、exited with 0 | 理解和适用范围单独检查，不扩展为任意信号时机保证 |
| 处理器内不做复杂 I/O | 通过（当前源码静态核对） | handle_sigint 仅执行 stop_requested=1，无输出调用 | 后续修改程序时重新核对 |
| 调试阻塞读取 | 通过（所列场景，指导下） | 等待、4 字节输入、Ctrl+C/EINTR、EOF 均符合预期；本人正确区分等待与返回 0、解释退出标志，措辞由导师精确补充 | 无；不扩展为其他未测错误分支 |
| strace/gdb 分工、debug-map.md | 通过（指导和纠错下） | gdb 断点、next、count=4、main:85、exited normally；本人正确选择 strace 看 close 调用结果、gdb 看标志值；文档已形成 | 无；P1 限制条件单列 |
| 固定项：链表与栈周四变式 | 通过（规格/分支提示、导师提供测试） | 本人八组结果和 bool 断言通过、exit=0；解释最坏 O(n)/O(n) 及理由；见 parentheses-variant-cases.md | 无 |
| P1：一个反例或限制条件与适用范围 | 通过（导师准备对照源码，信号时机经纠正复答） | SA_RESTART 下 Ctrl+C 后仍等待，输入后读到 4、close 成功、exit=0；本人解释重启及原配置为 0，纠正后确认 read 当时等待且未返回 | 无；详见 signal-restart-limits.md |

当前最终状态：今日 P0、P1、固定练习及必要理解全部通过，包含指导和纠错，不记为全程无提示独立完成。本人报告全日实际 120 分钟，分项未报告；[原话](../results/raw/2026-10-29-study-time-learner-observation.json)。

必要理解证据：[三题原答及核对](../results/raw/2026-10-29-signal-understanding-learner-observation.json)。固定项详见 [固定练习验收](2026-10-29-parentheses-variant-cases.md)，P1 详见 [对照及纠错复答验收](2026-10-29-signal-restart-limits.md)，三项现均通过。

## strace 补充证据

本人执行指导命令后回复“已运行”；助手只读检查 [signal-trace.txt](../profiles/2026-10-29/signal-trace.txt)，实际注册 SIGINT 成功、打开 /dev/null 得到 fd=3，SIGINT 到达后 close 返回 0，最终 exited with 0，符合运行前已列出的预期。助手未代跑。原始记录及当时源码快照见 [strace 观察](../results/raw/2026-10-29-signal-strace-learner-observation.json)，解读见 [debug-map.md](../cpp-basics/debug-map.md)。本人读懂记录的能力单独待验证，不能凭文件存在判定已掌握。
