# 2026-10-27 重定向：补充验收

来源：[路线图](../../LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) `d-2026-10-27`，学习内容包含“重定向”；本文件将其转为可检查的实操，属于教学补充。

## 约定与预期（实跑与理解经纠正后通过）

- 环境只读确认：Bash 5.3.9(1)-release，wc 来自 uutils coreutils 0.10.0，`wc -c` 统计字节；工作目录项目根目录。
- 解释标准输入 fd 0、标准输出 fd 1、标准错误 fd 2；shell 的 `<`、`>`、`2>` 分别连接它们，程序通过原有描述符读写。
- 将 pipe_message 的标准输出重定向到 `results/raw/2026-10-27-pipe-stdout.txt`；预期程序状态 0，文件为固定三行 received/bytes/child_exit，共 42 字节（含标签和换行）。用 cat 显示、`wc -c < 文件` 验证输入重定向。
- 用空文件作为源、已有二进制副本为目标触发拒绝覆盖；分别用 `>` 保存标准输出到 `2026-10-27-copy-stdout.txt`、`2>` 保存标准错误到 `2026-10-27-copy-stderr.txt`。预期状态 1、标准输出 0 字节、标准错误为 `open destination: File exists`，已有目标不变。
- [独立预存 expected](../results/raw/2026-10-27-redirection-expected.json)保存确切内容、字节数和消息输出 SHA-256。准备时三个新日志路径均不存在；本轮不修改 C++ 程序。
- 理解检查：如果只写 `>out.txt`，perror 的错误是否也会进入该文件？为什么？
- actual：本人完整输出与预存 expected 一致，pipe 状态 0、三行文件 42 字节，copy 状态 1、标准输出 0 字节、错误为 File exists。助手只读复核三个日志、pipe 输出哈希及原目标未变，重定向实跑通过，未代跑。
- 理解初答：“不会，因为这是标准输出，不是输入”，结论正确，理由未通过：应区分 stdout(fd1) 与 stderr(fd2)，而非 stdin(fd0)。导师已解释 > 只连接 fd1、perror 写 fd2。
- 复答：默认 stdout/stderr 都接终端，执行 `program >out.txt` 后 printf 与 perror 分别去哪里？expected 为 out.txt、终端；本人回答“out.txt”“终端”，两项正确，重定向理解经纠正后通过。原始回答、复答与文件复核均已追加到上述预期/实际 JSON。

参考：[Bash 重定向手册](https://www.gnu.org/s/bash/manual/html_node/Redirections.html)、[uutils wc 文档](https://uutils.org/coreutils/docs/utils/wc.html)。首次 GNU /software/ 地址抓取超时，后通过官方 /s/ 索引与本机 --help 核对。
