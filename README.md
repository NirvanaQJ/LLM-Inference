# LLM Inference / GPU Systems 学习与实验项目

这是我从 2026 年 10 月开始，面向 **LLM Inference Systems / GPU Systems** 岗位的学习、实验与求职工作区。学习主线为 Python / C++ / Linux → CUDA / Triton → 大模型推理 → vLLM / SGLang → GPU 性能分析；NCCL 与集群通信是与推理性能相连接的扩展方向。

> **截至 2026-10-10：**10 月 5—8 日和 10 日的 P0、P1 与固定练习均有验收证据；9 日的 P0 已通过，P1 与岗位核查固定项仍待验证。当前可复现成果主要是基础编程、日志统计和**模拟**延迟分析，尚无 CUDA、Triton、模型推理或通信性能实测。练习时长依据本人报告，未单独计时。

## 从哪里开始

| 想找什么 | 入口 |
| --- | --- |
| 每天的任务、阶段目标和验收标准 | [交互式学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) |
| 实际完成情况、未通过项和完整证据链 | [日记索引](日记/README.md)；最近记录：[10 月 9 日](日记/2026-10-09.md)、[10 月 10 日](日记/2026-10-10.md) |
| 两个实验项目的目标、目录及现状 | [LLM 推理实验](llm-inference-lab/README.md) · [GPU 算子实验](gpu-kernel-lab/README.md) |
| 起点与路线图审核 | [基线技能记录](baseline-skills.md) · [路线图审核记录](Red-Team-Audit-2026-10-03.md) |

**阅读方式：**路线图写计划；日记按日期记录实际操作和验收；下面的主题索引只选关键文件。需要复现时，从对应日记进入测试记录和原始数据。路线图网页中的勾选状态保存在浏览器本地，不会因提交日记而自动同步。

## 成果索引（按主题）

| 主题 | 实现与数据 | 验收和日期 |
| --- | --- | --- |
| Python 累加与输入边界 | [累加器](gpu-kernel-lab/python-basics/basics.py) | [6 组输入对照](gpu-kernel-lab/tests/2026-10-05-basics-cases.md) · [10 月 5 日日记](日记/2026-10-05.md) |
| 请求去重与均值 | [请求处理脚本](gpu-kernel-lab/python-basics/requests.py) | [输入对照](gpu-kernel-lab/tests/2026-10-06-requests-cases.md) · [自测问答](gpu-kernel-lab/tests/2026-10-06-requests-selfcheck.md) · [10 月 6 日日记](日记/2026-10-06.md) |
| 文件解析与去重复做 | [原始 JSONL](gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl) · [解析脚本](gpu-kernel-lab/python-basics/parse_logs.py) · [复做脚本](gpu-kernel-lab/python-basics/requests_redo.py) | [解析验收](gpu-kernel-lab/tests/2026-10-07-parse-logs-cases.md) · [10 月 7 日日记](日记/2026-10-07.md) |
| 日志统计与保留末次请求变式 | [运行说明](gpu-kernel-lab/python-basics/README.md) · [统计脚本](gpu-kernel-lab/python-basics/stats.py) · [变式脚本](gpu-kernel-lab/python-basics/requests_last.py) | [统计验收](gpu-kernel-lab/tests/2026-10-08-stats-cases.md) · [10 月 8 日日记](日记/2026-10-08.md) |
| Git 与越界调试 | [推理项目说明](llm-inference-lab/README.md) · [算子项目说明](gpu-kernel-lab/README.md) · [调试脚本](gpu-kernel-lab/python-basics/index_debug.py) | [失败、断点与修复记录](gpu-kernel-lab/python-basics/debug.md) · [10 月 9 日日记](日记/2026-10-09.md) |
| 固定种子的模拟延迟分析 | [分析脚本](gpu-kernel-lab/python-basics/analyze.py) · [100 条 CSV](gpu-kernel-lab/results/raw/latency.csv) / [分布图](gpu-kernel-lab/results/figures/latency.svg) · [120 条 CSV](gpu-kernel-lab/results/raw/latency-count-120.csv) / [分布图](gpu-kernel-lab/results/figures/latency-count-120.svg) | [统计与排序核对](gpu-kernel-lab/tests/2026-10-10-latency-cases.md) · [10 月 10 日日记](日记/2026-10-10.md) |

10 月 3—4 日的路线图、审核、环境及最小 C++ 结果，见[日记索引](日记/README.md)和上方基线入口。表中 10 月 10 日的延迟由固定种子的随机数生成，**不是 GPU 测量结果**；两组数据的差异不代表性能变化。

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
