# LLM Inference / GPU Systems

面向 **LLM Inference Systems / GPU Systems** 岗位的个人学习与实验仓库，始于 2026 年 10 月。

学习主线：**Python / C++ / Linux → CUDA / Triton → 大模型推理 → vLLM / SGLang → GPU 性能分析**。NCCL 与集群通信作为连接推理性能的扩展方向。

[学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) · [学习日记](日记/README.md) · [核心项目](#两个核心项目) · [代表成果](#代表性成果) · [完整索引](#完整成果索引)

## 当前进度

> **最近学习：2026-10-31「最小 socket 实验」**。仅本机 TCP echo 的 2 字节、13 字节收发正确，完成接收容量 4→3 的 P1 变式；P0/P1/固定项及必要理解全部通过，包含助手示例、修复和纠错。实际 110 分钟（P0 90、P1 20）；没有性能测量结论。[查看当日成果与状态](日记/2026-10-31.md)

| 项目 | 当前状态 |
| --- | --- |
| 所处阶段 | A 阶段 · W04：Linux、进程与第一版简历 |
| 已有成果 | Python 数据处理与算法、C++ 内存与工具链、Linux 进程、文件/管道/映射、信号调试与本机 TCP echo；首版求职简历已生成（本地私有） |
| 最近周验收 | [W03：请求容器与哈希复做](week-03-review.md)通过；[W01](week-01-review.md)、[W02](week-02-review.md)记录保留 |
| 当前学习 | [2026-10-31「最小 socket 实验」](日记/2026-10-31.md)全部验收通过；下次按 11 月 1 日路线图开展 W04 周验收，先复习今日易错点 |
| 待验证范围 | CUDA / Triton 算子性能、模型推理服务性能及多卡通信性能尚无实测成果 |

通过记录包含骨架、示例指导与纠错，具体帮助程度见各次验收。10 月 9 日的 P1 与岗位核查固定项仍待验证；10 月 30 日岗位清单与资格核查按本人要求跳过、未完成，后续完成记录不补算历史欠账。

## 两个核心项目

| 项目 | 目标 | 目前进展 |
| --- | --- | --- |
| [GPU 算子实验](gpu-kernel-lab/README.md) | 从正确性与边界测试出发，用 CUDA / Triton 实现并测量算子 | 已有 Python、C++、Linux 基础代码和测试；后续开展 GPU 实验 |
| [LLM 推理性能实验](llm-inference-lab/README.md) | 建立可复现的单卡服务基线，结合负载、源码和性能分析验证改进假设 | 已建立目录与实验约定；模型服务基线和优化实验尚未形成 |

两个项目共享“**实现 → 测试 → 原始结果 → 分析**”的记录方式；各子项目 README 说明文件放置与实验要求。

## 代表性成果

先从下面几项了解当前工作。详细输入、运行输出、边界条件与理解检查均可从验收记录继续追溯。

| 方向 | 实现 / 数据 | 验证内容 |
| --- | --- | --- |
| 本机 TCP echo 与接收容量变式 | [echo.cpp](gpu-kernel-lab/cpp-basics/echo.cpp) · [系统记录与复现入口](gpu-kernel-lab/cpp-basics/systems.md) | [2/13 字节、部分读取与理解检查](gpu-kernel-lab/tests/2026-10-31-socket-cases.md) · [只改接收容量 4→3 的 P1](gpu-kernel-lab/tests/2026-10-31-socket-buffer-variant.md)；无性能结论 |
| 信号退出与阻塞读取调试 | [signal.cpp](gpu-kernel-lab/cpp-basics/signal.cpp) · [strace/gdb 记录](gpu-kernel-lab/cpp-basics/debug-map.md) | [Ctrl+C 清理、数据/EOF、工具分工](gpu-kernel-lab/tests/2026-10-29-signal-cases.md) · [SA_RESTART 反例与适用范围](gpu-kernel-lab/tests/2026-10-29-signal-restart-limits.md) |
| 虚拟内存与文件映射 | [mmap/read 校验器](gpu-kernel-lab/cpp-basics/mmap.cpp) · [实验记录](gpu-kernel-lab/cpp-basics/vm.md) | [四种固定输入、三条错误路径及理解](gpu-kernel-lab/tests/2026-10-28-vm-cases.md)，仅正确性，无性能测量 |
| Linux 文件描述符与管道 | [字节复制器](gpu-kernel-lab/cpp-basics/fd_copy.cpp) · [父子消息](gpu-kernel-lab/cpp-basics/pipe_message.cpp) | [空文件/二进制、错误路径及受控短读写](gpu-kernel-lab/tests/2026-10-27-fd-cases.md) · [管道 EOF](gpu-kernel-lab/tests/2026-10-27-pipe-cases.md) |
| Linux 进程与系统调用 | [进程程序](gpu-kernel-lab/cpp-basics/process.cpp) · [真实 strace](gpu-kernel-lab/profiles/2026-10-26/trace.txt) | [父子 PID、执行替换、回收与失败路径](gpu-kernel-lab/tests/2026-10-26-process-cases.md) |
| C++ 内存安全与构建 | [CMake](gpu-kernel-lab/cpp-basics/CMakeLists.txt) · [Buffer](gpu-kernel-lab/cpp-basics/buffer.cpp) | [sanitizer 定位、复制/移动与十组测试](gpu-kernel-lab/tests/2026-10-24-sanitizer-cases.md) |
| 资源与所有权 | [文件句柄 RAII](gpu-kernel-lab/cpp-basics/file_guard.cpp) · [智能指针](gpu-kernel-lab/cpp-basics/ownership.cpp) | [正常/异常关闭与拷贝保护](gpu-kernel-lab/tests/2026-10-19-file-guard-cases.md) · [循环引用与弱观察](gpu-kernel-lab/tests/2026-10-20-ownership-cases.md) |
| Python / C++ 数据对照 | [C++ CSV 统计](gpu-kernel-lab/cpp-basics/stats_cli.cpp) · [Python 自动对照](gpu-kernel-lab/python-basics/compare.py) | [同输入统计、边界与类型转换](gpu-kernel-lab/tests/2026-10-17-python-cpp-cases.md) |
| 基础数据结构 | [安全出栈](gpu-kernel-lab/python-basics/stack_basics.py) · [原地链表反转](gpu-kernel-lab/python-basics/linked_list_basics.py) | [空栈与零值](gpu-kernel-lab/tests/2026-10-26-stack-cases.md) · [链表边界、节点身份与复杂度](gpu-kernel-lab/tests/2026-10-26-linked-list-cases.md) |
| 栈新题：有效括号 | [三种括号配对与嵌套](gpu-kernel-lab/python-basics/valid_parentheses.py) | [12 组本人实跑与 O(n)/O(n) 复杂度](gpu-kernel-lab/tests/2026-10-27-parentheses-cases.md) |
| 模拟延迟分析 | [分析脚本](gpu-kernel-lab/python-basics/analyze.py) · [分布图](gpu-kernel-lab/results/figures/latency.svg) | [固定种子数据的统计与排序核对](gpu-kernel-lab/tests/2026-10-10-latency-cases.md) |

延迟分析使用固定种子的随机数，属于**模拟数据**。100 条与 120 条两组结果的差异不代表性能变化，跨语言统计一致也不能说明程序谁更快。

## 学习与复现

| 目的 | 从这里进入 |
| --- | --- |
| 查看每天的任务、预算和验收标准 | [交互式学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html)，下载后用浏览器打开 |
| 接着上次进度学习 | [日记索引](日记/README.md) → [10 月 31 日检查点](日记/2026-10-31.md#备注)；当天全部验收通过，下次先复习易错点再开展 W04 周验收 |
| 重跑已有练习 | 对应日记中的复现命令 → 源码与测试 → 原始 expected/actual；[最近实验复现入口](gpu-kernel-lab/cpp-basics/systems.md#最终结果与复现入口) |
| 查看周总结与能力边界 | [W01](week-01-review.md) · [W02](week-02-review.md) · [W03](week-03-review.md) |
| 了解起点与路线审核 | [基线技能](baseline-skills.md) · [路线图审核](Red-Team-Audit-2026-10-03.md) |

路线图记录计划，日记记录实际完成情况；运行命令、依赖和输入以对应实验记录为准。补学会分别注明任务日期与实际学习日期。

## 阶段路线

| 时间 | 重点 | 计划产出 |
| --- | --- | --- |
| 2026 年 10—12 月 | Python、C++、Linux 与 GPU 基础 | 基础练习与首批 CUDA Kernel 实验 |
| 2026 年 12 月—2027 年 2 月 | Triton、推理机制、vLLM 源码与单卡服务 | 两个核心项目第一版、简历迭代 |
| 2027 年 2—6 月 | 性能实验迭代、算法、模拟面试与实习投递 | 可复现项目与面试准备记录 |
| 2027 年夏—2028 年毕业 | 实习转正、提前批、秋招与毕业要求 | 持续维护的项目和求职材料 |

具体日任务、优先级与延期调整以[路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html)为准；未来招聘时间需核对企业官方公告。

## 完整成果索引

<details>
<summary>展开全部主题、实现文件与验收证据</summary>

| 主题 | 实现与数据 | 验收和日期 |
| --- | --- | --- |
| 本机 TCP echo、部分读取与单配置变式 | [服务端](gpu-kernel-lab/cpp-basics/echo.cpp) · [系统记录与复现命令](gpu-kernel-lab/cpp-basics/systems.md) | [逐项验收](gpu-kernel-lab/tests/2026-10-31-socket-cases.md) · [P1 预测、实测与局限](gpu-kernel-lab/tests/2026-10-31-socket-buffer-variant.md) · [10 月 31 日日记](日记/2026-10-31.md)；指导及纠错后通过，无性能结论 |
| 求职简历 v1 与项目证据核对 | 简历 PDF、文字稿及事实说明本地私有；公开仓库仅保留进度说明 | [10 月 30 日成果与逐项状态](日记/2026-10-30.md)；一页 PDF 已检查，[P1 复测通过](gpu-kernel-lab/tests/2026-10-30-earliest-failure-recheck.md)，岗位清单/固定核查已跳过、未完成 |
| signal、阻塞读取与调试 | [signal.cpp](gpu-kernel-lab/cpp-basics/signal.cpp) · [debug-map.md](gpu-kernel-lab/cpp-basics/debug-map.md) · [SA_RESTART 对照](gpu-kernel-lab/cpp-basics/signal_restart.cpp) | [主实验](gpu-kernel-lab/tests/2026-10-29-signal-cases.md) · [P1 反例与纠正复答](gpu-kernel-lab/tests/2026-10-29-signal-restart-limits.md) · [10 月 29 日日记](日记/2026-10-29.md) |
| 有效括号周四变式 | [忽略普通字符](gpu-kernel-lab/python-basics/valid_parentheses_ignore_text.py) | [八组边界、bool 类型及最坏 O(n)/O(n)](gpu-kernel-lab/tests/2026-10-29-parentheses-variant-cases.md)；同题族变式不增加独立新题数 |
| 虚拟内存、分页与文件映射 | [mmap/read 校验器](gpu-kernel-lab/cpp-basics/mmap.cpp) · [实验说明](gpu-kernel-lab/cpp-basics/vm.md) | [四种固定输入、三条错误路径及原文理解](gpu-kernel-lab/tests/2026-10-28-vm-cases.md) · [10 月 28 日日记](日记/2026-10-28.md)；没有性能计时 |
| 链表与栈周三复做 | [链表反转](gpu-kernel-lab/python-basics/linked_list_redo.py) · [P1 有效括号](gpu-kernel-lab/python-basics/valid_parentheses_redo.py) | [四组链表边界与身份检查、O(n)/O(1)](gpu-kernel-lab/tests/2026-10-28-linked-list-redo-cases.md) · [五组括号测试、O(n)/O(n)](gpu-kernel-lab/tests/2026-10-28-parentheses-redo-cases.md)；复做不重复计作新题 |
| Python 累加与输入边界 | [累加器](gpu-kernel-lab/python-basics/basics.py) | [6 组输入对照](gpu-kernel-lab/tests/2026-10-05-basics-cases.md) · [10 月 5 日日记](日记/2026-10-05.md) |
| 请求去重与均值 | [请求处理脚本](gpu-kernel-lab/python-basics/requests.py) | [输入对照](gpu-kernel-lab/tests/2026-10-06-requests-cases.md) · [自测问答](gpu-kernel-lab/tests/2026-10-06-requests-selfcheck.md) · [10 月 6 日日记](日记/2026-10-06.md) |
| 文件解析与去重复做 | [原始 JSONL](gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl) · [解析脚本](gpu-kernel-lab/python-basics/parse_logs.py) · [复做脚本](gpu-kernel-lab/python-basics/requests_redo.py) | [解析验收](gpu-kernel-lab/tests/2026-10-07-parse-logs-cases.md) · [10 月 7 日日记](日记/2026-10-07.md) |
| 日志统计与保留末次请求变式 | [运行说明](gpu-kernel-lab/python-basics/README.md) · [统计脚本](gpu-kernel-lab/python-basics/stats.py) · [变式脚本](gpu-kernel-lab/python-basics/requests_last.py) | [统计验收](gpu-kernel-lab/tests/2026-10-08-stats-cases.md) · [10 月 8 日日记](日记/2026-10-08.md) |
| Git 与越界调试 | [推理项目说明](llm-inference-lab/README.md) · [算子项目说明](gpu-kernel-lab/README.md) · [调试脚本](gpu-kernel-lab/python-basics/index_debug.py) | [失败、断点与修复记录](gpu-kernel-lab/python-basics/debug.md) · [10 月 9 日日记](日记/2026-10-09.md) |
| 固定种子的模拟延迟分析 | [分析脚本](gpu-kernel-lab/python-basics/analyze.py) · [100 条 CSV](gpu-kernel-lab/results/raw/latency.csv) / [分布图](gpu-kernel-lab/results/figures/latency.svg) · [120 条 CSV](gpu-kernel-lab/results/raw/latency-count-120.csv) / [分布图](gpu-kernel-lab/results/figures/latency-count-120.svg) | [统计与排序核对](gpu-kernel-lab/tests/2026-10-10-latency-cases.md) · [10 月 10 日日记](日记/2026-10-10.md) |
| W01 周验收与旧题复做 | [保留首次请求](gpu-kernel-lab/python-basics/requests_week01.py) · [空日志统计保护](gpu-kernel-lab/python-basics/stats_week01.py) | [周验收](week-01-review.md) · [错题记录](gpu-kernel-lab/tests/algorithm-errors.md) · [10 月 11 日日记](日记/2026-10-11.md) |
| C++ 类型、编译与链接 | [命令行求和器](gpu-kernel-lab/cpp-basics/sum.cpp) · [构建记录](gpu-kernel-lab/cpp-basics/build.txt) | [五组 P0 与 P1 边界验收](gpu-kernel-lab/tests/2026-10-12-sum-cases.md) · [10 月 12 日日记](日记/2026-10-12.md) |
| 数组与双指针模板 | [有序两数求和](gpu-kernel-lab/python-basics/two_sum_sorted.py) | [六组边界、复杂度与纠错记录](gpu-kernel-lab/tests/2026-10-12-two-pointers-cases.md) · [10 月 12 日日记](日记/2026-10-12.md) |
| C++ 指针、引用与 const | [三种交换实现](gpu-kernel-lab/cpp-basics/pointers.cpp) · [构建记录](gpu-kernel-lab/cpp-basics/build.txt) | [地址、内存图与边界验收](gpu-kernel-lab/tests/2026-10-13-pointers-cases.md) · [三题自测（次日复答于 14 日通过）](gpu-kernel-lab/tests/2026-10-13-pointers-selfcheck.md) · [10 月 13 日日记](日记/2026-10-13.md) |
| 同向双指针移动零 | [移动零函数与边界调用](gpu-kernel-lab/python-basics/move_zeros.py) | [七组输入、复杂度与顺序解释](gpu-kernel-lab/tests/2026-10-13-move-zeros-cases.md) · [原列表、长度及返回值复核](gpu-kernel-lab/results/raw/2026-10-13-move-zeros-check.json) · [10 月 13 日日记](日记/2026-10-13.md) |
| C++ vector、string 与严格整数去重 | [读取一行并保留首次整数](gpu-kernel-lab/cpp-basics/dedup.cpp) · [构建记录](gpu-kernel-lab/cpp-basics/build.txt) | [本人运行、理解纠错与边界验收](gpu-kernel-lab/tests/2026-10-14-dedup-cases.md) · [66 组助手独立复核](gpu-kernel-lab/results/raw/2026-10-14-dedup-check.json) · [10 月 14 日日记](日记/2026-10-14.md) |
| 有序两数求和复做 | [新文件复做函数](gpu-kernel-lab/python-basics/two_sum_sorted_redo.py) | [六组边界、类型纠错与复杂度](gpu-kernel-lab/tests/2026-10-14-two-pointers-redo-cases.md) · [输入不变复核](gpu-kernel-lab/results/raw/2026-10-14-two-pointers-redo-check.json) · [10 月 14 日日记](日记/2026-10-14.md) |
| 移动零从空文件复做 | [P1 新文件实现](gpu-kernel-lab/python-basics/move_zeros_redo.py) | [两组本人边界、复杂度与计数纠错](gpu-kernel-lab/tests/2026-10-14-move-zeros-redo-cases.md) · [七组原列表/长度/返回值复核](gpu-kernel-lab/results/raw/2026-10-14-move-zeros-redo-check.json) · [10 月 14 日日记](日记/2026-10-14.md) |
| C++ 函数、结构体与双源文件解析/统计 | [共享头文件](gpu-kernel-lab/cpp-basics/request.hpp) · [解析函数](gpu-kernel-lab/cpp-basics/request.cpp) · [统计入口](gpu-kernel-lab/cpp-basics/stats.cpp) | [编译链接、本人运行与理解验收](gpu-kernel-lab/tests/2026-10-15-request-stats-cases.md) · [23 组边界复核](gpu-kernel-lab/results/raw/2026-10-15-request-stats-check.json) · [10 月 15 日日记](日记/2026-10-15.md) |
| 移动零的指定值变式 | [原地移动指定值](gpu-kernel-lab/python-basics/move_value_to_end.py) | [本人三组运行、复杂度与顺序解释](gpu-kernel-lab/tests/2026-10-15-move-value-cases.md) · [八组原列表/长度/返回复核](gpu-kernel-lab/results/raw/2026-10-15-move-value-check.json) · [10 月 15 日日记](日记/2026-10-15.md) |
| 重复编号与统计适用范围 | [三行输入](gpu-kernel-lab/tests/2026-10-15-duplicate-requests.txt) · [限制条件分析](gpu-kernel-lab/tests/2026-10-15-request-stats-limits.md) | [两种规则手算、本人运行及适用范围](gpu-kernel-lab/tests/2026-10-15-request-stats-limits.md) · [10 月 15 日日记](日记/2026-10-15.md) |
| gdb 越界定位与修复 | [修复后源码](gpu-kernel-lab/cpp-basics/gdb_demo.cpp) · [修复前源码](gpu-kernel-lab/cpp-basics/gdb_demo_before.cpp) · [调试日志](gpu-kernel-lab/cpp-basics/gdb-session.txt) | [断点、单步、变量、堆栈与修复验收](gpu-kernel-lab/tests/2026-10-16-gdb-cases.md) · [三组函数复核](gpu-kernel-lab/results/raw/2026-10-16-gdb-fixed-check.json) · [10 月 16 日日记](日记/2026-10-16.md) |
| C++ 链接缺库错误复测 | [复用求和器](gpu-kernel-lab/cpp-basics/sum.cpp) · [失败日志](gpu-kernel-lab/results/raw/2026-10-16-p1-link-failure.txt) · [成功输出](gpu-kernel-lab/results/raw/2026-10-16-p1-link-success.txt) | [旧错答、当前复答、同一目标文件链接失败与修正](gpu-kernel-lab/tests/2026-10-16-linking-recheck.md) · [10 月 16 日日记](日记/2026-10-16.md) |
| Python/C++ 同输入统计与类型转换 | [C++ CSV 统计](gpu-kernel-lab/cpp-basics/stats_cli.cpp) · [Python 自动对照](gpu-kernel-lab/python-basics/compare.py) · [运行说明](gpu-kernel-lab/python-basics/README.md#pythonc-csv-统计对照) | [完整验收与纠错](gpu-kernel-lab/tests/2026-10-17-python-cpp-cases.md) · [120 条原始输出](gpu-kernel-lab/results/raw/2026-10-18-csv-120-output.txt) · [10 月 17 日日记（18 日补学）](日记/2026-10-17.md) |
| W02 周验收与旧题复做 | [两数求和本次实现](gpu-kernel-lab/python-basics/two_sum_sorted_week02.py) · [移动零本次实现](gpu-kernel-lab/python-basics/move_zeros_week02.py) | [周验收与下一步](week-02-review.md) · [两数求和验收](gpu-kernel-lab/tests/2026-10-18-week02-two-sum-cases.md) · [移动零验收](gpu-kernel-lab/tests/2026-10-18-week02-move-zeros-cases.md) · [错题记录](gpu-kernel-lab/tests/algorithm-errors.md) · [10 月 18 日日记](日记/2026-10-18.md) |
| C++ 对象生命周期与文件句柄 RAII | [局部对象示例](gpu-kernel-lab/cpp-basics/lifetime_demo.cpp) · [禁止拷贝的文件管理类](gpu-kernel-lab/cpp-basics/file_guard.cpp) | [正常/异常关闭、拷贝拒绝、缺失文件与理解验收](gpu-kernel-lab/tests/2026-10-19-file-guard-cases.md) · [10 月 19 日日记](日记/2026-10-19.md) |
| 两数求和的无序输入/哈希模板 | [本人函数与七组调用](gpu-kernel-lab/python-basics/two_sum_hash.py) | [边界、先查再存与复杂度](gpu-kernel-lab/tests/2026-10-19-two-sum-hash-cases.md) · [10 月 19 日日记](日记/2026-10-19.md)；同题族变式不重复增加独立新题数 |
| 智能指针与循环引用修复 | [独占转移、弱观察、循环演示与修复](gpu-kernel-lab/cpp-basics/ownership.cpp) | [本人运行、关系图与理解验收](gpu-kernel-lab/tests/2026-10-20-ownership-cases.md) · [三题问答（次日不看笔记复答于 21 日通过）](gpu-kernel-lab/tests/2026-10-20-ownership-selfcheck.md) · [10 月 20 日日记](日记/2026-10-20.md) |
| 哈希新题：有效的字母异位词 | [计数字典函数与八组调用](gpu-kernel-lab/python-basics/is_anagram.py) | [边界与复杂度验收](gpu-kernel-lab/tests/2026-10-20-anagram-cases.md) · [10 月 20 日日记](日记/2026-10-20.md) |
| C++ 移动语义与 vector 扩容 | [缓冲区及两个演示](gpu-kernel-lab/cpp-basics/buffer.cpp) | [逐项验收与本人两次扩容](gpu-kernel-lab/tests/2026-10-21-buffer-cases.md) · [10 月 21 日日记](日记/2026-10-21.md) |
| 两道哈希旧题复做 | [异位词复做](gpu-kernel-lab/python-basics/is_anagram_redo.py) · [两数求和复做](gpu-kernel-lab/python-basics/two_sum_hash_redo.py) | [八组异位词及复杂度](gpu-kernel-lab/tests/2026-10-21-anagram-redo-cases.md) · [P1 两边界、返回约定及复杂度](gpu-kernel-lab/tests/2026-10-21-two-sum-hash-redo-cases.md) |
| STL 请求排序、分组与顺序限制 | [C++ 实现及测试调用](gpu-kernel-lab/cpp-basics/stl_stats.cpp) | [排序分组及迭代器验收](gpu-kernel-lab/tests/2026-10-22-stl-stats-cases.md) · [分组限制反例](gpu-kernel-lab/tests/2026-10-22-stl-stats-limits.md) · [10 月 22 日日记](日记/2026-10-22.md) |
| 函数模板、可调用对象过滤器与实例化错误 | [min/max、过滤器与本人测试调用](gpu-kernel-lab/cpp-basics/templates.cpp) · [编译失败诊断](gpu-kernel-lab/results/raw/2026-10-23-template-error.txt) | [逐项验收与类型纠错](gpu-kernel-lab/tests/2026-10-23-templates-cases.md) · [析构旧错复验](gpu-kernel-lab/tests/2026-10-23-earliest-failure-recheck.md) · [10 月 23 日日记](日记/2026-10-23.md) |
| CMake sanitizer、释放后访问与复制/移动测试 | [构建说明](gpu-kernel-lab/cpp-basics/CMakeLists.txt) · [操作与结果](gpu-kernel-lab/cpp-basics/sanitizer.txt) · [Buffer 测试](gpu-kernel-lab/cpp-basics/buffer.cpp) | [逐项验收及纠错](gpu-kernel-lab/tests/2026-10-24-sanitizer-cases.md) · [十组结果](gpu-kernel-lab/results/raw/2026-10-24-ten-cases.txt) · [空输入结果](gpu-kernel-lab/results/raw/2026-10-24-empty-buffer.txt) · [10 月 24 日日记](日记/2026-10-24.md) |
| W03 请求容器与两道哈希复做 | [请求容器](gpu-kernel-lab/cpp-basics/request_container_week03.cpp) · [两数求和](gpu-kernel-lab/python-basics/two_sum_hash_week03.py) · [异位词](gpu-kernel-lab/python-basics/is_anagram_week03.py) | [周验收与周证据](week-03-review.md) · [两数求和验收](gpu-kernel-lab/tests/2026-10-25-week03-two-sum-cases.md) · [异位词验收](gpu-kernel-lab/tests/2026-10-25-week03-anagram-cases.md) · [10 月 25 日日记](日记/2026-10-25.md) |
| Linux 进程、执行替换与回收 | [进程程序](gpu-kernel-lab/cpp-basics/process.cpp) · [真实 strace](gpu-kernel-lab/profiles/2026-10-26/trace.txt) | [进程与 P1 逐项验收](gpu-kernel-lab/tests/2026-10-26-process-cases.md) · [10 月 26 日日记](日记/2026-10-26.md) |
| Linux 文件复制、管道与重定向 | [复制器](gpu-kernel-lab/cpp-basics/fd_copy.cpp) · [父子消息](gpu-kernel-lab/cpp-basics/pipe_message.cpp) · [受控测试工具](gpu-kernel-lab/tests/run_fd_faults.py) | [逐项验收](gpu-kernel-lab/tests/2026-10-27-fd-cases.md) · [重定向](gpu-kernel-lab/tests/2026-10-27-redirection-cases.md) · [三题问答（次日复答于 28 日通过）](gpu-kernel-lab/tests/2026-10-27-fd-selfcheck.md) · [10 月 27 日日记](日记/2026-10-27.md) |
| 栈新题：有效括号 | [Python 函数与 12 组测试](gpu-kernel-lab/python-basics/valid_parentheses.py) | [空串、错配、嵌套、剩余括号及复杂度](gpu-kernel-lab/tests/2026-10-27-parentheses-cases.md)，骨架与纠错指导下通过 |
| 栈与单链表反转模板 | [安全出栈](gpu-kernel-lab/python-basics/stack_basics.py) · [原地链表反转](gpu-kernel-lab/python-basics/linked_list_basics.py) | [栈边界与复杂度](gpu-kernel-lab/tests/2026-10-26-stack-cases.md) · [链表边界、节点身份与复杂度](gpu-kernel-lab/tests/2026-10-26-linked-list-cases.md) |
| 大小写不敏感异位词变式 | [lower 后排序比较](gpu-kernel-lab/python-basics/is_anagram_ignore_case.py) | [六组边界、复杂度及纠错](gpu-kernel-lab/tests/2026-10-22-anagram-ignore-case-cases.md)；采用排序方案，不记作哈希实现证据 |

</details>

早期路线、环境与最小 C++ 结果见[日记索引](日记/README.md)。复做与同题族变式保留各自证据，不重复计作多道独立新题。

## 目录与记录约定

```text
.
├── README.md                                      # 项目总览与成果入口
├── LLM-Inference-GPU-Systems-Roadmap-2026-2028.html  # 交互式学习计划
├── gpu-kernel-lab/                                 # 基础练习与后续 GPU 算子实验
├── llm-inference-lab/                              # 推理服务、源码与性能实验
├── 日记/                                          # 按实际学习日期记录成果与待办
└── week-*-review.md                                # 每周验收与复盘
```

**文件归属：**源码放在相应项目的代码目录，测试放 `tests/`，原始结果放 `results/raw/`，图表放 `results/figures/`，跟踪记录放 `profiles/`；其余目录约定见各子项目说明。预留空目录由 `.gitkeep` 保留。

**实验记录：**保存工作目录、命令、版本、输入、预期与实际结果，再从日记链接过去。性能结论还需硬件、负载、计时方法与原始数据；失败、零收益和负收益同样记录。

<details>
<summary>本地资料与路线图进度备份</summary>

- `career-private/` 保存简历、投递、面试与备份；`llm-inference-lab/configs/hardware.json` 是本机环境快照，均只在本地保存。
- `work/` 用于页面构建、截图与临时验证。上述内容通过 [`.gitignore`](.gitignore) 排除，公开提交前仍需核对文件内容。
- 路线图的勾选、周记录和岗位信息保存在当前浏览器的本地存储中；日记归档不会自动同步网页状态。
- 每周从路线图导出 JSON 到本地私有目录；更换浏览器、设备或文件路径后，通过页面导入功能恢复进度。

</details>
