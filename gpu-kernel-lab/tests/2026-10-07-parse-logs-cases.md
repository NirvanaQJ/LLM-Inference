# 2026-10-07 文件解析与 CSV 验收

- 工作目录：项目根目录。
- 环境：Python 3.14.4；使用 Python 标准库 `pathlib`、`json`、`csv`、`sys`。
- 代码：[parse_logs.py](../python-basics/parse_logs.py)。
- 正常输入：[10 行 JSONL](../results/raw/2026-10-07-logs.jsonl)；输出：[sample.csv](../results/raw/sample.csv)。
- 实施约定：每行是 JSON 对象，`request_id` 为非空字符串，`latency_ms` 为非负整数；重复 ID 保留，按输入顺序输出。这些细节是本次练习约定，路线图未指定。

| 用例与运行命令 | 独立预期 | 实际结果 |
| --- | --- | --- |
| `python3 gpu-kernel-lab/python-basics/parse_logs.py` | 表头 `request_id,latency_ms`；10 条数据按输入顺序写出，首条 `A,10`，末条 `A,11` | 本人终端截图显示写入 10 条；助手用 `csv.DictReader` 逐条对照输入，表头、数量、内容和顺序均一致。 |
| `python3 gpu-kernel-lab/python-basics/parse_logs.py gpu-kernel-lab/results/raw/missing.jsonl` | 报文件不存在及路径，不进入 CSV 写入 | 本人终端截图显示“文件不存在”及路径，无堆栈。 |
| `python3 gpu-kernel-lab/python-basics/parse_logs.py gpu-kernel-lab/tests/2026-10-07-bad-json.jsonl` | [坏 JSON](2026-10-07-bad-json.jsonl) 第 2 行缺少数值，消息包含真实行号 2 | 本人终端截图显示“第 2 行：JSON 格式错误：Expecting value”，无堆栈。 |
| `python3 gpu-kernel-lab/python-basics/parse_logs.py gpu-kernel-lab/tests/2026-10-07-bad-fields.jsonl` | [坏字段](2026-10-07-bad-fields.jsonl) 第 2 行的延迟为字符串，消息包含行号 2 | 本人终端截图显示“第 2 行：字段不合法”，无堆栈。 |
| 默认命令运行两次，每次随后执行 `sha256sum gpu-kernel-lab/results/raw/sample.csv` | 两次 CSV 字节内容一致，哈希相同 | 本人终端截图显示两次均写入 10 条；两次 SHA-256 均为 `171b55ea8942a2170be55370b8337b1bca71d9f63b5a50f78a93b6a9bb729ada`。助手另行读取当前文件复核同一哈希。 |

理解检查：本人解释 `line` 是字符串、`json.loads(line)` 得到的 `record` 是字典；本人正确指出 `-2` 会在非负判断中被拒绝。对 `"slow"`，助手纠正了“会先转成整数”的误解：当前代码直接检查原值类型。不存在的文件没有可报告的输入行号，错误消息报告文件路径；坏数据消息报告输入文件行号。
