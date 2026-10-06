# 2026-10-06 请求去重输入对照

- 受测文件：[requests.py](../python-basics/requests.py)
- 环境：Python 3.14.4；项目根目录执行。2026-10-06 归档时再次复核，三类结果一致。
- 复核方式：助手在项目根目录运行 `python3 gpu-kernel-lab/python-basics/requests.py`，实际输出去重列表与 `15.0`；再在内存中加载当前脚本，分别调用 `deduplicate_requests` 和 `mean_latency` 核对三类输入。加载时的样例打印已从测试输出中隔离；未修改磁盘脚本。
- 以下 expected 根据“重复 ID 保留首次出现的整条请求”及“保留请求的 `latency_ms` 算术平均值”两项已确认约定独立列出；空列表均值返回 `None`。actual 来自本次运行。

| 输入类别 | 输入 | expected 去重 | actual 去重 | expected 均值 | actual 均值 | 结果 |
| --- | --- | --- | --- | --- | --- | --- |
| 空列表 | `[]` | `[]` | `[]` | `None` | `None` | 通过 |
| 重复 ID | `A:10, B:20, A:99` | `A:10, B:20` | `A:10, B:20` | `15.0` | `15.0` | 通过 |
| 单元素 | `C:7` | `C:7` | `C:7` | `7.0` | `7.0` | 通过 |

注：本表中的 `A:10` 表示 `{"request_id": "A", "latency_ms": 10}`；其余记录同理。

从项目根目录复现三类函数检查：

```bash
python3 - <<'PY'
import contextlib
import io
import runpy

with contextlib.redirect_stdout(io.StringIO()):
    ns = runpy.run_path('gpu-kernel-lab/python-basics/requests.py')

cases = [
    [],
    [{'request_id': 'A', 'latency_ms': 10}, {'request_id': 'B', 'latency_ms': 20}, {'request_id': 'A', 'latency_ms': 99}],
    [{'request_id': 'C', 'latency_ms': 7}],
]
for requests in cases:
    print(ns['deduplicate_requests'](requests), ns['mean_latency'](requests))
PY
```

## 复杂度复核

- 用户判断整体时间复杂度为 O(n)、额外空间复杂度为 O(n)，并在提示后确认三条输入先经历 3 次去重循环、再经历 2 次求和循环。
- 设输入长度为 n、去重后长度为 u（u ≤ n）：`mean_latency` 调用去重函数遍历 n 条，再求和遍历 u 条，总计 O(n + u) = O(n)。集合和去重结果列表最多各保存 u 项，额外空间 O(u)，最坏为 O(n)。
- 当前脚本还在主程序中额外打印一次去重结果，因此直接运行样例会多调用一次去重函数；总体渐近复杂度仍为 O(n)。
