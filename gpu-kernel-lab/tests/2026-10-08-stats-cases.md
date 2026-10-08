# 2026-10-08 统计脚本验收记录

工作目录：项目根目录；Python：项目 `.venv` 中的 3.14.4。

## `--input` 参数检查

- 命令：`./.venv/bin/python gpu-kernel-lab/python-basics/stats.py --input gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl`
- 运行前预期：打印所传入的相对路径 `gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl`。
- 实际：学习者终端截图显示该路径；助手复核结果一致。
- 学习者说明了脚本路径与数据路径的区别。此阶段只验证了参数接收；文件读取与统计的后续结果见下文。

## 10 行日志：条数与总耗时

- 输入：[10 行原始记录](../results/raw/2026-10-07-logs.jsonl)。
- 运行前学习者手算预期：`count=10`，`total_ms=125`。
- 命令：`./.venv/bin/python gpu-kernel-lab/python-basics/stats.py --input gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl`。
- 实际：学习者终端输出 `count=10, total_ms=125`；助手复核同一命令结果一致。
- 学习者曾遇到 `ModuleNotFoundError: No module named 'Path'`；保存的代码已改为 `from pathlib import Path`，后续运行成功。
- 这一阶段的条数与总耗时检查通过；其余验收见下文。

## 10 行日志：平均耗时

- 运行前独立预期：手算总耗时 `125` 毫秒，除以 `10` 条，平均耗时 `12.5` 毫秒。
- 命令同上。
- 实际：学习者终端输出 `count=10, total_ms=125, avg_ms=12.5`；助手复核结果一致。
- 正常输入统计检查点通过；空输入结果见下文。缺失或坏数据的定制错误提示不在本次 P1 验收范围内。

## P1 反例：空日志（修正前）

- 输入：[空日志](2026-10-08-empty.jsonl)，助手核对为 0 行、0 字节。
- 运行前学习者预期：条数和总耗时均为 0，平均值处发生除零错误。
- 命令：`./.venv/bin/python gpu-kernel-lab/python-basics/stats.py --input gpu-kernel-lab/tests/2026-10-08-empty.jsonl`。
- 实际：学习者终端及助手复核均显示 `ZeroDivisionError: division by zero`，位置是 `avg_ms = total_ms / count`；因 `print` 在计算之后，终端没有先输出条数和总耗时。
- 修正前状态：反例已复现；空输入的处理与适用范围说明见下文。

## P1 反例：空日志（修正后）

- 实施约定：空日志时 `count=0`、`total_ms=0`、`avg_ms=N/A`；路线图原文未规定这个显示值。
- 学习者在计算平均值前增加 `count == 0` 分支；运行前预期为空日志显示 `N/A`，原 10 行日志仍显示 `12.5`。
- 实际：学习者终端分别输出 `count=0, total_ms=0, avg_ms=N/A` 和 `count=10, total_ms=125, avg_ms=12.5`；助手复核均一致。
- 学习者说明平均耗时适用于非空输入。此处数据格式沿用昨日 JSONL 约定，每行有可累加的 `latency_ms`；坏数据的错误提示没有纳入本次 P1 验收。
- P1 反例与适用范围检查通过。

## `run.sh` 参数转发

- 学习者创建 `gpu-kernel-lab/python-basics/run.sh`，从项目根目录以 `"$@"` 转发 `--input` 及相对数据路径，说明无需在脚本中写死数据文件路径。
- 命令：`bash gpu-kernel-lab/python-basics/run.sh --input gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl`。
- 运行前预期：`count=10, total_ms=125, avg_ms=12.5`。
- 实际：学习者终端和助手复核均得到预期输出。
- `run.sh` 当前要求在项目根目录运行；使用方法已写入 [README](../python-basics/README.md)。

## 新终端按 README 复现

- 学习者按新开终端的检查指令，在项目根目录运行 README 所列 `bash gpu-kernel-lab/python-basics/run.sh --input gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl`，终端截图显示 `count=10, total_ms=125, avg_ms=12.5`；无需激活环境，数据路径为相对路径。
- README 同时列出首次创建 `.venv` 和读取 `requirements.txt` 的命令；这两条命令已在此前检查点由学习者执行并验证。
- 路线图 P0 原文“新终端按 README 可运行，不依赖绝对数据路径”据上述证据通过。新终端这一点依据学习者对该检查指令的响应；截图本身不提供终端进程身份。
