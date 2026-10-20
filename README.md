# LLM Inference / GPU Systems 学习与实验项目

这是我从 2026 年 10 月开始，面向 **LLM Inference Systems / GPU Systems** 岗位的学习、实验与求职工作区。学习主线为 Python / C++ / Linux → CUDA / Triton → 大模型推理 → vLLM / SGLang → GPU 性能分析；NCCL 与集群通信是与推理性能相连接的扩展方向。

> **截至 2026-10-20：**20 日「智能指针」的 P0（含固定哈希新题）与 P1 今日三道问答通过，见[当日日记](日记/2026-10-20.md)；2026-10-21 不看笔记复答及遗漏记录仍待验证。按指导完成 unique_ptr 转移、shared_ptr/weak_ptr 观察与循环引用修复，固定新题「有效的字母异位词」八组边界及复杂度解释通过。完整示例、骨架填空、提示纠错与助手检查分别记录，不扩大为全程独立掌握。本人报告总学习 120 分钟，其中算法练习 30 分钟，包含在总时长内。19 日对象生命周期、17 日补学及 18 日 W02 周验收的既有证据保留于对应日记及[周验收](week-02-review.md)。

此前 10 月 5—8 日和 10—16 日均有 P0、P1 与固定项通过证据，13 日次日复答已于 14 日完成。9 日 P0 已通过，P1 与岗位核查固定项仍待验证，今日成果不自动补算旧欠账。当前成果主要是基础编程、日志统计和**模拟**延迟分析，尚无 CUDA、Triton、模型推理或通信性能实测。

## 从哪里开始

| 想找什么 | 入口 |
| --- | --- |
| 每天的任务、阶段目标和验收标准 | [交互式学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) |
| 实际完成情况、未通过项和完整证据链 | [日记索引](日记/README.md)；最近记录：[10 月 19 日](日记/2026-10-19.md)、[10 月 20 日](日记/2026-10-20.md) |
| 两个实验项目的目标、目录及现状 | [LLM 推理实验](llm-inference-lab/README.md) · [GPU 算子实验](gpu-kernel-lab/README.md) |
| 起点与路线图审核 | [基线技能记录](baseline-skills.md) · [路线图审核记录](Red-Team-Audit-2026-10-03.md) |

**阅读方式：**路线图写计划；日记记录实际操作和验收，补学明确区分任务日期与实际学习日期；下面的主题索引只选关键文件。需要复现时，从对应日记进入测试记录和原始数据。路线图网页中的勾选状态保存在浏览器本地，不会因提交日记而自动同步。

## 成果索引（按主题）

| 主题 | 实现与数据 | 验收和日期 |
| --- | --- | --- |
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
| 智能指针与循环引用修复 | [独占转移、弱观察、循环演示与修复](gpu-kernel-lab/cpp-basics/ownership.cpp) | [本人运行、关系图与理解验收](gpu-kernel-lab/tests/2026-10-20-ownership-cases.md) · [三题问答（今日通过，次日复答待验证）](gpu-kernel-lab/tests/2026-10-20-ownership-selfcheck.md) · [10 月 20 日日记](日记/2026-10-20.md) |
| 哈希新题：有效的字母异位词 | [计数字典函数与八组调用](gpu-kernel-lab/python-basics/is_anagram.py) | [边界与复杂度验收](gpu-kernel-lab/tests/2026-10-20-anagram-cases.md) · [10 月 20 日日记](日记/2026-10-20.md) |

10 月 3—4 日的路线图、审核、环境及最小 C++ 结果，见[日记索引](日记/README.md)和上方基线入口。表中 10 月 10 日生成、18 日沿用的延迟来自固定种子的随机数，**不是 GPU 测量结果**；两组数据的差异不代表性能变化，跨语言统计 PASS 也不能说明程序谁更快。

## 项目结构与记录规则

| 目录 | 用途与详细说明 |
| --- | --- |
| [`llm-inference-lab/`](llm-inference-lab/) | 模型推理实验；配置、负载、脚本、原始结果、图表、性能分析、源码阅读和通信分析的放置规则见[项目 README](llm-inference-lab/README.md)。目前尚无可复现的推理性能结果。 |
| [`gpu-kernel-lab/`](gpu-kernel-lab/) | Python / C++ 基础练习及后续 CUDA / Triton 算子实验；代码、测试、基准、原始结果和图表的放置规则见[项目 README](gpu-kernel-lab/README.md)。目前尚无已验证的 GPU 算子性能结果。 |
| [`日记/`](日记/) | 按 Asia/Shanghai 日期保存真实成果、验收状态、复现信息和待办；完整日期列表见[日记索引](日记/README.md)。 |

现有基础练习已放在对应项目目录；其余子目录供后续任务使用，空目录通过 `.gitkeep` 保留。新增成果先保存代码、输入、原始结果和分析，再从当日日记链接过去。性能结论需要硬件与软件版本、测试参数、计时方法及原始数据；失败或没有收益的结果也如实记录。

## 阶段目标

1. **2026 年 10—12 月：**补 Python、C++、Linux 和 GPU 基础，开始 CUDA Kernel 实验。
2. **2026 年 12 月—2027 年 2 月：**完成 Triton、推理机制、vLLM 源码阅读和单卡推理性能项目的第一版；同步准备简历。
3. **2027 年 2—6 月：**迭代两个核心项目，同时投递暑期实习、练习算法和模拟面试。
4. **2027 年夏—2028 年毕业：**围绕实习转正、提前批与秋招推进，维护可复现项目和毕业要求。

逐日任务、优先级与延期后的调整方式以[交互式学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html)为准；未来招聘日期需以企业官方公告核对。

## 本地私有资料与网页进度

- `career-private/` 保存简历、投递、面试、规划与备份；10 月 9 日的岗位筛选报告也在这里。报告已有岗位要求对照和下一步，个人资格与可出勤时间仍待核查。这些资料不提交公开仓库。
- `llm-inference-lab/configs/hardware.json` 是本机硬件与软件环境快照，只在本地保存；公开性能报告可另写经过筛选的硬件摘要。
- `work/` 用于页面构建、截图和临时验证，不作为项目成果提交。
- 路线图中的勾选、周记录和岗位信息保存在**当前浏览器的本地存储**中。每周从页面导出 JSON 备份并放在本地私有目录；更换浏览器、设备或文件路径后，使用页面的导入功能恢复。

上述私有路径已写入 [`.gitignore`](.gitignore)。公开提交前仍要检查待提交文件，确认没有个人资料、凭据或不准备公开的数据。
