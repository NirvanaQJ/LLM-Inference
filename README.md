# LLM Inference / GPU Systems 学习与实验项目

这是我从 2026 年 10 月开始，面向 **LLM Inference Systems / GPU Systems** 岗位的学习、实验与求职工作区。主线是 C++ / Linux → CUDA / Triton → 大模型推理 → vLLM / SGLang → GPU 性能分析；NCCL 与集群通信作为与推理性能相连接的扩展方向。

> 当前状态：学习路线和项目目录已建立。2026-10-05 至 10-08、10-10 的每日 P0、P1 与固定练习均有验收证据，详见对应日记；10-09 的 P0 已通过，P1 与固定项仍待验证。10-10 完成固定种子的模拟延迟统计、排序交叉核对、标注“模拟”的分布图，以及 `--count` 单项扩展。练习时长依据本人报告，未单独计时。CUDA Kernel、推理性能及通信实验尚未在本仓库形成可复现结果。以下目录约定不代表相应实验已经完成。

## 从这里开始

| 文件 | 用途 |
| --- | --- |
| [交互式学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) | 2026—2028 时间线、逐日任务、阶段验收、项目与求职里程碑；下载后可直接用浏览器打开。 |
| [路线图审核记录](Red-Team-Audit-2026-10-03.md) | 2026-10-03 的计划审核与网页功能验证记录；其中硬件信息相关限制是当日快照。 |
| [基线技能记录](baseline-skills.md) | 2026-10-04 已核验的工具版本、终端及最小 C++ 程序结果。 |
| [日记说明与索引](日记/README.md) | 按日期记录实际完成的成果，并链接到相应文件。 |
| [2026-10-03 日记](日记/2026-10-03.md) · [2026-10-04 日记](日记/2026-10-04.md) · [2026-10-05 日记](日记/2026-10-05.md) · [2026-10-06 日记](日记/2026-10-06.md) · [2026-10-07：文件解析与数组哈希复做](日记/2026-10-07.md) · [2026-10-08：命令行与环境](日记/2026-10-08.md) · [2026-10-09：Git 与调试](日记/2026-10-09.md) · [2026-10-10：模拟延迟分析](日记/2026-10-10.md) | 已有的每日成果与待验证事项记录。 |
| [Python 累加器](gpu-kernel-lab/python-basics/basics.py) · [6 组输入对照](gpu-kernel-lab/tests/2026-10-05-basics-cases.md) | 已保存的代码与 expected/actual；当前脚本默认输入为 `[1.5]`。 |
| [请求去重与均值](gpu-kernel-lab/python-basics/requests.py) · [三类输入对照](gpu-kernel-lab/tests/2026-10-06-requests-cases.md) · [自测问答](gpu-kernel-lab/tests/2026-10-06-requests-selfcheck.md) | 2026-10-06 的代码、验收、次日复答与遗漏修正。 |
| [10 行原始记录](gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl) · [文件解析脚本](gpu-kernel-lab/python-basics/parse_logs.py) · [CSV 输出](gpu-kernel-lab/results/raw/sample.csv) · [解析验收](gpu-kernel-lab/tests/2026-10-07-parse-logs-cases.md) · [去重复做](gpu-kernel-lab/python-basics/requests_redo.py) · [边界测试](gpu-kernel-lab/tests/2026-10-07-dedup-cases.md) | 2026-10-07 的 P0、P1 和固定练习成果。 |
| [Python 统计运行说明](gpu-kernel-lab/python-basics/README.md) · [统计脚本](gpu-kernel-lab/python-basics/stats.py) · [依赖清单](gpu-kernel-lab/python-basics/requirements.txt) · [运行脚本](gpu-kernel-lab/python-basics/run.sh) · [空日志与统计验收](gpu-kernel-lab/tests/2026-10-08-stats-cases.md) · [保留末次请求变式](gpu-kernel-lab/python-basics/requests_last.py) · [变式验收](gpu-kernel-lab/tests/2026-10-08-last-dedup-cases.md) | 2026-10-08 的 P0、P1 和固定练习成果。 |
| [推理实验说明](llm-inference-lab/README.md) · [GPU 算子实验说明](gpu-kernel-lab/README.md) · [越界调试脚本](gpu-kernel-lab/python-basics/index_debug.py) · [调试记录](gpu-kernel-lab/python-basics/debug.md) | 2026-10-09 的 P0 成果；P1 和固定练习状态见[当日日记](日记/2026-10-09.md)。 |
| [模拟延迟分析脚本](gpu-kernel-lab/python-basics/analyze.py) · [100 条原始 CSV](gpu-kernel-lab/results/raw/latency.csv) · [100 条分布图](gpu-kernel-lab/results/figures/latency.svg) · [120 条原始 CSV](gpu-kernel-lab/results/raw/latency-count-120.csv) · [120 条分布图](gpu-kernel-lab/results/figures/latency-count-120.svg) · [分析检查记录](gpu-kernel-lab/tests/2026-10-10-latency-cases.md) | 2026-10-10 的模拟数据统计、图表与 `--count` 扩展；不代表 GPU 性能实测。 |

路线图中的勾选、周记录和岗位信息保存在**当前浏览器的本地存储**中；仓库不会自动同步这些数据。每周从页面导出一次 JSON 备份，并放在本地私有目录。更换浏览器、设备或文件路径后，使用页面的导入功能恢复。

## 项目目录与每日产出

两个实验区分别是 [`llm-inference-lab/`](llm-inference-lab/) 和 [`gpu-kernel-lab/`](gpu-kernel-lab/)。部分目录已放入基础练习，其余子目录用于整理后续任务产出；空目录通过 `.gitkeep` 保留在 Git 中。

| 目录 | 放什么 |
| --- | --- |
| `llm-inference-lab/configs/` | 模型、引擎、硬件与运行参数；本机的 `hardware.json` 只在本地保存。 |
| `llm-inference-lab/workloads/` | 固定输入/输出长度、并发和请求分布的测试负载。 |
| `llm-inference-lab/src/` | 推理服务调用、实验控制及必要的实现修改。 |
| `llm-inference-lab/bench/` | benchmark 脚本和运行说明。 |
| `llm-inference-lab/results/raw/` | 原始结果，例如带日期、模型和版本信息的 CSV/JSON。 |
| `llm-inference-lab/results/figures/` | 由原始结果生成的图表。 |
| `llm-inference-lab/profiles/` | Nsight / PyTorch Profiler 的分析记录与摘要。 |
| `llm-inference-lab/source-maps/` | vLLM / SGLang 的源码阅读笔记、调用图及固定的版本信息。 |
| `llm-inference-lab/communication/` | NCCL、Tensor Parallel 通信与推理性能的关联分析；无多卡硬件时明确标记未实测。 |
| `gpu-kernel-lab/cuda/` · `gpu-kernel-lab/triton/` | CUDA 与 Triton 的 Kernel 实现及优化版本。 |
| `gpu-kernel-lab/cpp-basics/` | C++ 入门程序和基础练习。 |
| `gpu-kernel-lab/python-basics/` | Python 入门程序，目前包含 token 数量累加、请求去重与均值、文件解析、日志统计、模拟延迟分析及数组哈希变式练习。 |
| `gpu-kernel-lab/tests/` | 正确性、边界形状和数值误差验证；目前保存累加器、请求去重、文件解析、日志统计、模拟延迟分析与变式练习的输入对照及自测问答。 |
| `gpu-kernel-lab/bench/` | PyTorch / CUDA / Triton 基准测试脚本。 |
| `gpu-kernel-lab/results/raw/` · `gpu-kernel-lab/results/figures/` | 原始计时数据与图表。 |
| `gpu-kernel-lab/profiles/` | Nsight Systems / Nsight Compute 的分析记录与结论。 |

**每天怎么放文件：**先在对应项目目录保存代码、原始数据和分析，再在当天的 `日记/YYYY-MM-DD.md` 中用相对路径链接到这些文件。日记只写实际完成和验证过的内容。性能结论需附硬件、软件版本、测试参数、计时方法及原始结果；没有收益的优化也记录原因，不编造提升。

## 阶段目标

1. **2026 年 10—12 月：**补 Python、C++、Linux 和 GPU 基础，开始 CUDA Kernel 实验。
2. **2026 年 12 月—2027 年 2 月：**完成 Triton、推理机制、vLLM 源码阅读和单卡推理性能项目的第一版；同步准备简历。
3. **2027 年 2—6 月：**迭代两个核心项目，同时投递暑期实习、练习算法和模拟面试。
4. **2027 年夏—2028 年毕业：**围绕实习转正、提前批与秋招推进，维护可复现项目和毕业要求。

逐日任务、优先级与延期后的调整方式以[交互式学习路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html)为准；未来招聘日期需以企业官方公告核对。

## 本地私有与临时文件

- `career-private/`：简历、投递、面试、规划与备份，保留在本机，不提交到公开仓库。
- `llm-inference-lab/configs/hardware.json`：本机硬件与软件环境快照，供实验复现时核对；公开结果可另写经过筛选的硬件摘要。
- `work/`：页面构建和验证时产生的脚本、截图及临时结果，不作为项目成果提交。

这些路径已写入 [`.gitignore`](.gitignore)。公开提交前仍应检查 `git status`，确认没有个人资料、凭据或不准备公开的实验数据。
