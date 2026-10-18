# Python 日志统计

在**项目根目录**运行以下命令。项目根目录是包含 `gpu-kernel-lab/` 的目录；`run.sh` 中的路径以这里为起点。需要 Python 3.14 及其 `venv` 组件。

首次使用或重新克隆项目后，创建独立环境并读取依赖清单：

```bash
python3 -m venv .venv
./.venv/bin/python -m pip install -r gpu-kernel-lab/python-basics/requirements.txt
```

以后每次打开新终端，进入项目根目录后运行：

```bash
bash gpu-kernel-lab/python-basics/run.sh --input gpu-kernel-lab/results/raw/2026-10-07-logs.jsonl
```

这份样例数据的预期输出为 `count=10, total_ms=125, avg_ms=12.5`。`--input` 后可换成其他相对于项目根目录的 JSONL 文件路径，无需修改脚本；每行应是含数值 `latency_ms` 的 JSON 对象。空文件输出 `count=0, total_ms=0, avg_ms=N/A`，平均耗时只适用于非空输入。当前脚本不为坏 JSON 或缺失字段提供定制错误提示。

`run.sh` 使用 `.venv` 中的 Python，因此新终端不需要先激活环境。如果 Ubuntu 提示缺少 `ensurepip`，先安装与 `python3` 版本对应的 `python3.x-venv` 包，再创建环境。

## Python/C++ CSV 统计对照

17 日任务于 2026-10-18 补学完成。独立的 [C++ 统计器](../cpp-basics/stats_cli.cpp)读取 CSV；[compare.py](compare.py)计算 Python 参考结果、调用 C++ 并自动比较。在项目根目录先编译，再运行：

```bash
g++ -std=c++17 -Wall -Wextra gpu-kernel-lab/cpp-basics/stats_cli.cpp -o gpu-kernel-lab/cpp-basics/stats_cli
python3 gpu-kernel-lab/python-basics/compare.py gpu-kernel-lab/results/raw/latency.csv
python3 gpu-kernel-lab/python-basics/compare.py gpu-kernel-lab/results/raw/latency-count-120.csv
```

本次核对环境为 Python 3.14.4、g++ 15.2.0，仅使用标准库。上述是已验证版本的复现命令，收尾整理时未重新执行。

| 模拟输入 | count | total_ms | avg_ms | 自动对照 |
| --- | --- | --- | --- | --- |
| latency.csv | 100 | 2744.892 | 27.44892 | PASS |
| latency-count-120.csv | 120 | 3392.04 | 28.267 | PASS |

输入限定为单列、未加引号、LF 换行的简化 CSV：首行必须为 `latency_ms`，每条数据是有限非负数，允许数值周围普通空白。只有表头时输出 `count=0`、`total_ms=0`、`avg_ms=N/A`；坏表头或坏数据返回 1，错误写入 stderr，不输出部分统计。这里没有实现通用多列或带引号 CSV。

跨进程捕获的输出字段最初都是 `str`，字段完整性检查后才将条数转换为 `int`、总和与非空均值转换为 `float`。条数精确比较，浮点数使用 `math.isclose(rel_tol=1e-12, abs_tol=1e-9)`，空均值单独比较 `N/A`；全部匹配才输出 `compare=PASS`。

本人实跑、原始错误与纠正、助手边界复核和 P1 预期/实际/局限见[完整验收记录](../tests/2026-10-17-python-cpp-cases.md)。这些数据仅用于统计一致性练习；未测程序耗时，不能据此推断语言速度或真实 GPU 延迟。
