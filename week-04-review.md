# W04 周验收：Linux、进程与第一版简历

任务日期与实际学习日期：2026-11-01（Asia/Shanghai）。本日 P0、P1、固定练习及必要理解全部通过；本人报告实际总学习约 60 分钟，其中错题复做/周复盘约 20 分钟，已包含在总时长内。周验收包含导师测试、证据整理及解释细化，不扩大为全程无提示独立完成。10 月 30 日跳过的岗位任务仍未完成。

## 任务来源与原文要求

来源：[最新路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01)，A 阶段 W04，主题「周验收、错题与恢复」。

- 周目标：一页简历 v1 和可复现 Linux 小实验；算法主题为链表与栈。
- 学习内容：Linux、进程与第一版简历 的证据核对；算法主题：链表与栈。
- 动手任务：对照本周目标「一页简历 v1 和可复现 Linux 小实验」复跑一个最小实例；复做本周一题；更新岗位/科研日历并选择下周最早未过 P0。
- 产出：week-04-review.md、algorithm-errors.md。
- 客观验收：逐项写通过/未通过/待硬件；引用实际文件路径；记录用时和一个下一步；未完成项保持不勾，不把写总结当实验通过。
- 原预算：P0 1.5h / 全日 3.5h。
- 固定项原文：预算内固定项：40 分钟错题复做/周复盘；本周去重题数 2–3 道，复做另记，不靠刷数量。
- P1 原文：P1 · 2h 复做两道旧错题，完成后休息；若学业/面试冲突，本项直接不做。

## 课程实施安排（教学补充）

1. 按昨日已约定的续学点，用约 5 分钟复习接收数组与累计字符串、epoll 通知与服务器读取、接收循环所处的 accept 成功路径。先从数组与字符串一项开始，收到本人回答后逐项推进；这不是增加路线图验收门槛。
2. Linux 最小复跑优先沿用 [echo.cpp](gpu-kernel-lab/cpp-basics/echo.cpp) 与已有客户端。当前源码单次接收容量为 3；保留 2 字节和 13 字节输入、完整回显、双方退出状态等真实结果，不以昨天记录代替今天复跑，也不预设分段次数或性能结论。
3. 复做题选链表反转与有效括号，依据 [链表历史纠错](gpu-kernel-lab/tests/2026-10-26-linked-list-cases.md) 和 [括号历史纠错](gpu-kernel-lab/tests/2026-10-27-parentheses-cases.md)。同一次链表复做对应 P0 本周一题及 P1 第一题，成果和用时只记一次；两题复做不增加去重新题数。
4. 复做的具体输入规格、独立 expected、边界及复杂度检查在相应实操开始前明确；它们为教学补充，不冒称路线图逐字要求。源码放既有 python-basics 目录，验收放 tests，原始结果放 results/raw；[错题记录](gpu-kernel-lab/tests/algorithm-errors.md)在有真实反馈后追加。
5. 核对本周简历与 Linux 证据、更新岗位/科研日历，个人材料继续本地私有。10 月 30 日按本人要求跳过的岗位清单和资格核查保持原状态，不转为今日补做要求，也不补算通过。
6. 收尾记录本人实际用时、一个下一步及剩余项。固定 40 分钟已计入预算，不再额外相加；P1 的冲突规则按原文执行。

## 初始证据与环境（助手只读核对）

- [10 月 31 日日记](日记/2026-10-31.md)确认昨日 P0/P1/固定项及必要理解全部通过，包含示例、修复和纠错；实际 P0 90 分钟、P1 20 分钟。这不是今天的复跑或无提示掌握证据。
- [系统记录的当前继续位置](gpu-kernel-lab/cpp-basics/systems.md#当前继续位置)安排先复习昨日易错点，再开展今日周验收。
- [10 月 30 日日记](日记/2026-10-30.md)记录一页简历 PDF 已检查，文件本地私有；岗位清单/固定核查跳过、未完成。
- 今日工具只读实测：Linux；Python 3.14.4；g++ 15.2.0（Ubuntu 15.2.0-16ubuntu1）。今日不需要 GPU，尚未执行网络复跑。
- 接收语义核对：[Linux recv 手册](https://man7.org/linux/man-pages/man2/recv.2.html)；通知语义核对：[Linux epoll 手册](https://man7.org/linux/man-pages/man7/epoll.7.html)。
- 下周候选起点已从最新路线图提取为 [11 月 2 日 thread 与 mutex](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-02)；最终选择和日历更新待对应步骤核对，不提前记通过。

## 本日验收追踪

下表为本日最终验收；后文保留课堂各检查点与原答。已通过本日周验收不等同本周每一天全部通过，历史未完成项保持原状态。

| 任务/要求 | 当前状态 | 证据位置/结果 | 待做步骤 |
| --- | --- | --- | --- |
| 对照一页简历 v1 和可复现 Linux 小实验核对证据 | 通过（助手核对材料与历史证据） | 简历仍为已验证的一页文件、字节未变，详情本地私有；本日 echo 2/13 字节复跑真实通过，下方周证据表保留帮助范围 | 无本周目标材料待补；不等同每项均独立掌握或每天全部通过 |
| 本日最小 Linux 实例复跑 | 通过 | 本日 2/13 字节两组完整回显、双方状态 0，见检查点 4、5 及截图转录 | 无此复跑项待补；不扩大为独立实现或性能结论 |
| P0 本周一题复做 | 通过 | 链表函数、四组 passed/exit=0、O(n)/O(1) 及保留后继理解均通过，见本次验收 | 无此题待补 |
| P1 两道旧错题 | 通过 | 链表反转与有效括号函数、运行、复杂度及必要理解均通过，帮助范围见各自验收 | 无复做待补，收尾后休息 |
| 固定错题/周复盘及去重记录 | 通过 | 两道复做及去重 2 题族已记录；本人报告复做/周复盘约 20 分钟，已含在全日 60 分钟内 | 无；原 40 分钟为预算，不新增补时门槛 |
| 更新岗位/科研日历及选择下周起点 | 通过（个人安排仅本地保留） | 已据本人真实反馈更新已知约束、未知事项、W05 七天计划/预算及下一核查节点；选择 11 月 2 日 thread 与 mutex | 具体未知时段随通知补充，不虚构；不影响本次如实更新验收 |
| 状态、实际路径、实际用时与一个下一步 | 通过 | [公开收尾记录](gpu-kernel-lab/results/raw/2026-11-01-final-learning-record.json)：60/20 分钟；个人安排省略，下一步已核对，历史未完成不补算通过 | 无本日课程待补；网页勾选未同步 |

## 检查点 1：接收数组与累计字符串（通过，措辞经导师细化）

第一步仅做纸面推演，不运行代码。假设累计字符串初始为空，复用 `char buf[3]`，两次成功 recv 分别读到 ASCII 文本 `ABC`（n=3）和 `DE`（n=2），每次均执行 `received.append(buf, n)`。

本人原答：

> ABCDE 5个字节
> 不能，因为可能buf里面只有1个字节

内容与长度均正确，且正确判断不能从容量推断实际读取量。导师细化第二句：可能是本次实际只读取了 1 个字节，数组容量仍为 3；应以返回值 n 确定本次有效数据范围，不能把剩余位置的旧数据当作本次接收。此小项理解通过，不计作本日代码运行、echo 复跑或整日验收通过。

## 检查点 2：epoll 通知与服务器读取（通过）

本轮仅做概念复习：服务器同时管理连接 A、B，以 fd_A、fd_B 表示各自连接的文件描述符，假设只有 B 有新数据。导师讲解 epoll 负责通知、服务器程序调用 recv 后，请本人补全「epoll 通知 ___ 可读；___ 调用 recv，读取 ___」。

本人原答：`B 服务器 B`。三个空均正确，能区分通知对象、执行读取的程序与读取目标，此小项通过。为讲解后的填空复习，不扩大为独立编写 epoll 程序、多连接实测或本日 echo 复跑。

## 检查点 3：accept 成功路径（通过）

阅读简化控制流：`int conn_fd = accept(...); if (conn_fd < 0) { perror("accept"); /* A */ return 1; } /* B */`。A 为失败判断的代码块内部、return 前；B 为该代码块之后。

本人原答为 `B`、`不会`，两项正确：循环在失败判断块之后，连接成功时不会进入 `conn_fd < 0` 分支。本小项通过，完成开课的三项复习；为简化控制流判断，不扩大为独立修复或本日实跑证据。助手另只读确认当前实际源码循环位置正确。

## 检查点 4：本日 echo 普通输入复跑（通过）

复用当前 [echo.cpp](gpu-kernel-lab/cpp-basics/echo.cpp)（buf 容量 3）与 [socket_echo.py](gpu-kernel-lab/tests/socket_echo.py)，本轮不修改源码。工作目录为克隆后的项目根目录，编译和运行操作由本人执行。

终端 A：

```bash
g++ -std=c++17 -Wall -Wextra -g gpu-kernel-lab/cpp-basics/echo.cpp -o /tmp/llm-echo-week04 && /tmp/llm-echo-week04
echo "server_exit=$?"
```

终端 B（A 出现 waiting for client 后）：

```bash
python3 gpu-kernel-lab/tests/socket_echo.py 'hi'
echo "client_exit=$?"
```

本轮输入独立确定为 ASCII `hi`、2 字节。运行前预期：客户端 expected/actual 均为 `b'hi'`、2 字节，echo_match=True、client_exit=0；服务端 received=hi、total_bytes=2、echoed_bytes=2、socket closed、server_exit=0。recv 每次分段不作固定要求。

本人提供了双方终端截图，全部关键结果与运行前预期一致，普通输入复跑通过。服务端本次读取为 2 字节；客户端在 .venv 中执行，虚拟环境 Python 精确版本未另测。证据为[服务端截图文字转录](gpu-kernel-lab/results/raw/2026-11-01-week04-echo-hi-server-learner-output.txt)与[客户端截图文字转录](gpu-kernel-lab/results/raw/2026-11-01-week04-echo-hi-client-learner-output.txt)，原图留在对话、未另存本地；助手只读核对和转录，未代跑。此项为现有源码复跑，不计无提示独立编写或性能实测。

## 检查点 5：13 字节长输入复跑（通过）

当前服务端每次只处理一个连接，hi 实验后已退出，下一组必须重新启动；源码未改，沿用刚编译的 `/tmp/llm-echo-week04` 即可，无需重复编译。

终端 A：

```bash
/tmp/llm-echo-week04
echo "server_exit=$?"
```

终端 B（A 再次显示 waiting for client 后，在项目根目录）：

```bash
python3 gpu-kernel-lab/tests/socket_echo.py 'hello socket!'
echo "client_exit=$?"
```

独立预期：ASCII `hello socket!` 共 13 字节；客户端 actual_payload=b'hello socket!'、actual_bytes=13、echo_match=True、client_exit=0；服务端 received=hello socket!、total_bytes=13、echoed_bytes=13、socket closed、server_exit=0。接收数组容量为 3，单次正返回量不超过 3，但不要求分段固定为 3/3/3/3/1。

本人双方截图与独立预期一致，本次正长度读取为 3/3/3/3/1、累计 13，完整回显且双方退出状态 0，长输入通过。本日最小 Linux 实例复跑完成。证据：[服务端截图转录](gpu-kernel-lab/results/raw/2026-11-01-week04-echo-long-server-learner-output.txt)、[客户端截图转录](gpu-kernel-lab/results/raw/2026-11-01-week04-echo-long-client-learner-output.txt)。助手仅核对和转录，未代跑；不据本次分段推断每次固定读取量，不记录未经测量的性能结论。

## 检查点 6：链表反转函数复做（源码检查通过，整题待验证）

已建立[本次规格与独立预期](gpu-kernel-lab/tests/2026-11-01-week04-linked-list-cases.md)，初始[新文件](gpu-kernel-lab/python-basics/linked_list_week04.py)仅含导师提供 Node 类和函数占位。本人报告「已保存」，助手读取后确认函数为正确的原地迭代反转：prev/current/next_code 引用更新顺序正确，保留原节点，空输入返回 None。本人函数快照及帮助范围另存[源码检查记录](gpu-kernel-lab/results/raw/2026-11-01-week04-linked-list-source-review.json)。未代写或修正本人函数，未执行实现，不把源码正确当本次实跑或理解通过。

## 检查点 7：链表四组边界实跑（通过）

导师已按预存 expected 在原文件末尾追加空链、单节点、普通链与重复值四组 assert 身份测试，未改本人函数体。本人在项目根目录运行 `python3 gpu-kernel-lab/python-basics/linked_list_week04.py`，紧接 `echo "exit=$?"`，截图实际为 empty/single/normal/duplicates 四行 passed、exit=0，匹配预期。四组边界、原节点身份与尾链接检查通过，[截图转录](gpu-kernel-lab/results/raw/2026-11-01-week04-linked-list-learner-output.txt)已保存；助手只读核对当前源码，未代跑。

## 检查点 8：链表复杂度与关键步骤理解（通过）

本人答时间 O(n)、逐个处理整条链表；额外空间 O(1)、仅固定数量引用变量；先保存后继为了防止找不到下一个节点。三项核心正确，导师细化每节点固定次数操作及改写 next 后须靠预存引用访问原后继。[原答与细化范围](gpu-kernel-lab/results/raw/2026-11-01-week04-linked-list-understanding.md)已保存。结合本人函数与四组运行，链表反转完整通过，满足 P0 本周一题及 P1 第一题，成果/用时只记一次。

## 检查点 9：有效括号函数复做（源码检查通过）

初始[新文件](gpu-kernel-lab/python-basics/valid_parentheses_week04.py)仅含函数签名与占位，[本次规格与八组独立 expected](gpu-kernel-lab/tests/2026-11-01-week04-parentheses-cases.md)已在实现前保存。首次反馈后目标文件仍为占位，未判算法失败；再次反馈后读到本人正确函数。append/pop、判空、按当前右括号查字典及最终 not stack 均正确，源码检查通过。[本人函数快照](gpu-kernel-lab/results/raw/2026-11-01-week04-parentheses-source-review.json)已保存，未修改函数、未代跑；是否参考旧实现未独立核验。

## 检查点 10：有效括号八组实跑（通过）

导师按预存 expected 在文件末尾追加八组打印和 bool 类型/返回值断言，本人在项目根目录运行 `python3 gpu-kernel-lab/python-basics/valid_parentheses_week04.py`，紧接 `echo "exit=$?"`。本人截图八组值均与预期一致，8 cases passed、exit=0，类型/返回值检查通过；[截图转录](gpu-kernel-lab/results/raw/2026-11-01-week04-parentheses-learner-output.txt)已保存。助手只读核对源码测试，未代跑。

## 检查点 11：有效括号最坏复杂度（通过）

本人答最坏时间 O(n)、全为左括号要扫描 n 个；最坏额外空间 O(n)，全为左括号使栈最长为 n 个元素。核心理解正确，导师补充每字符处理一轮、字典与列表末尾操作按给定成本模型分析的完整时间上界理由。[原答与帮助范围](gpu-kernel-lab/results/raw/2026-11-01-week04-parentheses-understanding.md)已保存。结合正确函数和八组本人运行，第二题完整通过，P1 两道旧题复做完成。

## 本周证据核对（助手只读，不新增历史实测）

| 日期/主题 | 核对结论 | 实际证据路径与能力边界 |
| --- | --- | --- |
| 10 月 26 日：进程与 syscall | 既有验收通过 | [process.cpp](gpu-kernel-lab/cpp-basics/process.cpp)、[trace.txt](gpu-kernel-lab/profiles/2026-10-26/trace.txt)、[当日日记](日记/2026-10-26.md)；fork/exec/wait、正常与失败路径，包含骨架与纠错 |
| 10 月 27 日：文件描述符、管道与重定向 | 既有验收通过，P1 次日复答完成 | [fd_copy.cpp](gpu-kernel-lab/cpp-basics/fd_copy.cpp)、[pipe_message.cpp](gpu-kernel-lab/cpp-basics/pipe_message.cpp)、[当日日记](日记/2026-10-27.md)；受控短读写验证由助手执行，不能写成本人独立测试 |
| 10 月 28 日：虚拟内存 | 既有验收通过 | [mmap.cpp](gpu-kernel-lab/cpp-basics/mmap.cpp)、[vm.md](gpu-kernel-lab/cpp-basics/vm.md)、[当日日记](日记/2026-10-28.md)；四种文件正确性与错误路径，无性能结论 |
| 10 月 29 日：信号与调试 | 既有验收通过 | [signal.cpp](gpu-kernel-lab/cpp-basics/signal.cpp)、[debug-map.md](gpu-kernel-lab/cpp-basics/debug-map.md)、[当日日记](日记/2026-10-29.md)；SA_RESTART 反例限所列场景，含指导及纠错 |
| 10 月 30 日：简历 v1 | 简历/P1 通过；当天部分完成 | [当日日记](日记/2026-10-30.md)、[最早失败复测](gpu-kernel-lab/tests/2026-10-30-earliest-failure-recheck.md)；简历文件与实际私有路径本地保存，今日核对页数 1、哈希与此前渲染检查文件一致。岗位清单/资格核查仍按本人要求跳过、未完成 |
| 10 月 31 日：最小 socket | 既有验收通过，本日另完成复跑 | [echo.cpp](gpu-kernel-lab/cpp-basics/echo.cpp)、[systems.md](gpu-kernel-lab/cpp-basics/systems.md)、[当日日记](日记/2026-10-31.md)及本日检查点 4、5；无多连接或性能实测 |

本周目标「一页简历 v1 和可复现 Linux 小实验」证据成立，但不补算 10 月 30 日未完成项，也不据周总结新增 GPU/模型服务能力。本周算法去重为链表反转、有效括号 2 题族，复做与变式另记；[完整去重表](gpu-kernel-lab/tests/algorithm-errors.md#w04-算法去重口径)已保存。

## 检查点 12：日历与实际用时（通过）

下周 11 月 2—8 日最新任务已提取，P0 15.5h、P1 6.5h、全周原预算 22h，固定项已含预算；草稿保存到既有私有日历，保留旧版本。没有下周已通过日记，选择下周最早未过 P0 为 11 月 2 日 thread 与 mutex：比较无锁/互斥计数器，正确版 20 次一致并解释错误版非必然每次出错；固定算法转为二分查找。只选择起点，未提前开课。

本人已反馈下周一项已知约束，其余安排未知；原答及具体安排仅保存在本地私有收尾记录和日历。已据此更新 W05 日历、未知事项与开始学习前的核查节点，不虚构个人时段或无冲突结论。

本人用时原答：`1个小时，20分钟`，对应总学习约 60 分钟，其中两道错题复做/周复盘约 20 分钟，已含在 60 分钟内；为本人估计、未独立计时，未拆造 P0/P1 分项。与原全日预算 210 分钟相比少约 150 分钟，固定项比原预算 40 分钟少约 20 分钟；预算不是最低学习时长，不追加凑时任务。[公开收尾记录](gpu-kernel-lab/results/raw/2026-11-01-final-learning-record.json)已保存。

## 当前继续位置

- 2026-11-01 的 P0、P1、固定练习及必要理解全部通过，收尾后休息，不追加新题。
- 下次从 2026-11-02 thread 与 mutex 开始，先解释线程共享、竞争条件与互斥，再按原文写并行计数器；固定练习为二分查找，未提前开课。
- 10 月 30 日岗位清单/资格核查及更早历史未完成项保留原状态，不因本日验收通过补算。
- 未读取或修改浏览器 localStorage，未修改路线图任务。基于真实验收可勾选 d-2026-11-01 和 x-2026-11-01，网页进度尚未同步。
