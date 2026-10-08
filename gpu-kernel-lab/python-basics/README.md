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
