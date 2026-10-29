# 2026-10-29 P1：SA_RESTART 与退出标志的适用范围（通过）

原文要求：为当天结果加 1 个反例或限制条件，并说明适用范围；不扩新主题。预算 30 分钟，P1 实际分项用时未报告；本人报告全日实际 120 分钟，见[原话](../results/raw/2026-10-29-study-time-learner-observation.json)。

最终状态：对照运行与本人适用范围解释全部通过，包含导师准备源码、命令指导与信号时机纠错，不记为无提示独立完成。以下保留检查过程，当时的待验证状态以本页最终验收为准。

## 对照准备与补充验收

基线 [signal.cpp](../cpp-basics/signal.cpp) 的 sa_flags=0，本人已在终端 read 阻塞时按 Ctrl+C，观察到 EINTR、close 成功、退出状态 0。证据见[基线验收](2026-10-29-signal-cases.md)。

导师准备 [signal_restart.cpp](../cpp-basics/signal_restart.cpp)，唯一行为修改为 sa_flags=SA_RESTART，并更新相应注释；不是本人独立实现。本人已编译并在 strace 下运行。主程序仍只在信号处理函数内设置标志，普通代码需等 read 返回才能重新检查循环条件。

依据 [Linux signal(7) 的系统调用中断说明](https://man7.org/linux/man-pages/man7/signal.7.html)，终端上尚未读取数据的阻塞 read 在启用 SA_RESTART 时，会在信号处理函数返回后自动重启。运行前预期：在此状态按 Ctrl+C 后仍等输入，暂不出现 read interrupted 或 cleanup；再输入一行后 read 返回，随后在循环条件处退出并清理。

以下为按原文要求制定的补充检查，不是路线图新增原文：

| 检查 | 状态 | 所需证据 |
| --- | --- | --- |
| 只修改信号重启配置的对照 | 通过（导师准备源码，本人编译运行） | 截图显示命令；源码差异仅配置/相应注释，实际 rt_sigaction 标志含 SA_RESTART |
| Ctrl+C 后终端 read 仍在等待 | 通过（本次两次信号） | 本人截图显示 ^C^C 后无清理和新提示符；strace 两次 SIGINT 后均再次 read，末尾仍等待 |
| 输入一行后正常清理 | 通过 | 本人截图 read_bytes=4、cleanup；strace 确认 abc 加换行读到 4、close 返回 0、exited with 0 |
| 本人解释反例及适用范围 | 通过（信号时机经纠正复答） | 正确解释重启和原配置为 0；初次误答 B，讲解后复答“等待输入，没有返回”，确认 SIGINT 到达时 read 尚未返回 |

不得把设置标志等同于正在阻塞的主流程已检查到标志；也不能由此推导所有系统调用都能由 SA_RESTART 重启。当前预期不作为实际结果。

## 已观察的等待反例

本人截图显示 ready、waiting for input 后按了两次 Ctrl+C（^C^C），没有 read interrupted、cleanup 或新的终端提示符。助手只读确认 [restart-trace.txt](../profiles/2026-10-29/restart-trace.txt)实际注册标志含 SA_RESTART，两次 SIGINT 后均从处理返回并再次 read，最后标准输入 read 尚无返回值。[截图描述及当时跟踪/源码快照](../results/raw/2026-10-29-signal-restart-learner-observation.json)已保存，未代跑。

处理函数将退出标志设为 1 的解释来自源码及信号处理返回路径，本次未用 gdb 直接读出该标志。下一步输入 abc 加 Enter，预期 read_bytes=4、cleanup: fd closed、exit=0，尚未发生，不提前记为通过。适用范围仍待本人解释。

## 输入后清理与退出已验证

本人新截图显示两次 Ctrl+C 后输入 abc，随后 read_bytes=4、cleanup: fd closed，回到终端提示符；助手只读检查最终跟踪：

```text
read(0</dev/pts/0<char 136:0>>, "abc\n", 64) = 4
close(3</dev/null<char 1:3>>)           = 0
+++ exited with 0 +++
```

符合运行前给出的预期，输入返回后可继续执行普通代码并退出。[最终截图转录与跟踪快照](../results/raw/2026-10-29-signal-restart-learner-observation.json)保存在 completion_checkpoint。

截图先执行 echo $/，再执行 echo $? 得到 0，后者对应前一条 echo 命令，不能作为本程序退出状态证据；本程序 exit=0 由 strace 最后一行独立确认，无需重跑。本人关于反例原因和适用范围的解释仍待验收，P1 尚未整体完成。

## 最终理解与适用范围

本人先回答“因为会在处理函数返回时自动重启，主流程需要在read返回后才能检查他”“0 不重新启动read”，原因与配置正确。对信号时机补查初答 B（read 已返回）错误；导师依据 waiting for input -> SIGINT -> read interrupted 的真实顺序纠正后，本人复答“等待输入，没有返回”，正确。原答、错答、纠正与最终复答均保存在[完整原始记录](../results/raw/2026-10-29-signal-restart-learner-observation.json)，不覆盖错误。

适用范围：本日 Linux 终端实验中，read 已阻塞、尚未读到数据时收到 SIGINT；配置 sa_flags=0，read 在处理返回后以 -1/EINTR 返回，主流程才能重新检查退出标志并清理。启用 SA_RESTART 的对照中，同一类终端读取自动重启，标志已设置也要等 read 返回后才能在循环条件中检查。本次输入 abc 加换行使其返回 4，随后 close 成功、exit=0。

这为“只设置退出标志即可保证立即退出”的泛化提供了实际反例。结论不推广为所有系统调用、任意配置或所有信号到达时机；检查标志与进入 read 之间的其他时机未做实验，也未宣称该程序是通用无竞争退出方案。P1 原文反例/限制与适用范围要求通过。

## 复现入口

在项目根目录，编译对照程序，再执行跟踪；ready、waiting 后按 Ctrl+C 观察仍等待，再输入 abc 加 Enter。下列命令用于后续复现，本次验收依据上述本人记录，不是新增助手运行：

```bash
g++ -std=c++17 -Wall -Wextra -g -O0 gpu-kernel-lab/cpp-basics/signal_restart.cpp -o /tmp/llm-signal-restart-demo
strace -I 3 -yy -e trace=rt_sigaction,read,close,rt_sigreturn -o gpu-kernel-lab/profiles/2026-10-29/restart-trace.txt /tmp/llm-signal-restart-demo
```

若用 echo $? 检查状态，应在程序返回后立刻执行，中间不插入其他命令。重跑会覆盖上述 strace 输出文件，需保留原始记录时另选日志名；课堂快照已独立保存在 JSON 中。
