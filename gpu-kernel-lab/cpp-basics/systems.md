# 2026-10-31 本机 TCP echo 实验记录

任务来源：[路线图当日任务](../../LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-31)。[逐项验收与课堂原答](../tests/2026-10-31-socket-cases.md)。

最终状态：2026-10-31 的 P0、P1、必要理解与固定结果/下一步记录全部通过，保留指导、助手实现/修复和纠错范围。本人确认实际用时 P0 90 分钟、P1 20 分钟，合计 110 分钟；没有性能测量结论。

## 最终结果与复现入口

| 接收数组容量 | 输入 | 实际接收 n | 累计 / 回显字节数 | 客户端比较 |
| --- | --- | --- | --- | --- |
| 4 | hi | 2 | 2 / 2 | True |
| 4 | hello socket! | 4/4/4/1 | 13 / 13 | True |
| 3 | hi | 2 | 2 / 2 | True |
| 3 | hello socket! | 3/3/3/3/1 | 13 / 13 | True |

每个 n 是一次实际读取量；具体分段不保证重现。所有目标均为 127.0.0.1:39031。容量 3/4 是单次 recv 的上限，不是固定消息划分规则；两种容量均能完整回显两个输入。源码只改数组容量，[P1 预期、源码差异、原始结果和局限](../tests/2026-10-31-socket-buffer-variant.md)与[逐项验收](../tests/2026-10-31-socket-cases.md)可继续追溯。

当前 echo.cpp 是最终 buf3 版本。以下命令可从项目根目录分别编译 buf4 基线和最终 buf3；后文课堂步骤中的命令对应当时的源码阶段，不应直接当作旧版本重现。

```bash
cd "/home/bestqjj/桌面/LLM Inference"
g++ -std=c++17 -Wall -Wextra -g gpu-kernel-lab/tests/2026-10-31-echo-buf4.cpp -o /tmp/llm-echo-buf4
g++ -std=c++17 -Wall -Wextra -g gpu-kernel-lab/cpp-basics/echo.cpp -o /tmp/llm-echo-buf3
```

终端 A 启动其中一个版本（例如 `/tmp/llm-echo-buf3`）；终端 B 在项目根目录运行下列客户端之一。每个服务端实例只处理一个连接，下一输入或另一容量前需重新启动对应服务端。

```bash
python3 gpu-kernel-lab/tests/socket_echo.py 'hi'
python3 gpu-kernel-lab/tests/socket_echo.py 'hello socket!'
```

验证环境：Linux，g++ 15.2.0，Python 3.14.4 为助手检查到的版本；本人使用 .venv 下的 python3，未另报告虚拟环境 Python 精确版本。此实验不涉及 GPU、远程网络或计时比较。实际短写没有单独记录；send 进度题是纸面假设。epoll 只完成用途理解，未实现多连接事件循环。

## 字节流与临时缓冲区

- 纸面题：两次发送 `ABC` 与 `DEFG`，第一次读取 `ABCD` 可以跨越发送分界；剩余字节为 `EFG`。
- `buf[4]` 是复用的临时数组，已读有效字节另存到累计字符串。下一次仍从数组起始位置写入，容量上限不因过去读过的数据而自动减小。
- 本人在提示与两轮纠错后，正确回答第三次最多可接收 4 字节、`DEFG` 可以一次读完。导师补充：可以不代表保证，具体返回量可能更小；完整的无消息边界解释及运行后复核仍待本人完成。

## 第 2 步：创建和关闭 socket

源文件：[echo.cpp](echo.cpp)。助手提供最小骨架；本人已贴出运行输出，未另贴编译命令或退出码。

工作目录：`/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics`。

本人操作命令：

```bash
cd "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics"
g++ -std=c++17 -Wall -Wextra -g echo.cpp -o /tmp/llm-echo-step1 && /tmp/llm-echo-step1
```

关键参数：`-std=c++17` 选择 C++17，`-Wall -Wextra` 开启常用警告，`-g` 保留调试信息，`-o` 指定生成程序路径；`&&` 表示编译成功才运行。

本步骤当时版本的预期：正常情况下打印 `socket_fd=<某个非负整数>` 及 `socket closed`，进程返回 0。fd 的具体数字不固定，也不是网络端口号。当时版本没有绑定地址、监听、连接或收发。

| 检查 | 实际结果 | 帮助范围 |
| --- | --- | --- |
| 助手编译检查 | g++ 15.2.0，编译退出码 0，无诊断输出；未运行 | 助手提供完整的创建/关闭骨架，不计本人编程或运行通过 |
| 本人运行反馈 | `socket_fd=3`、`socket closed`，符合预期；未另报告编译诊断或退出码 | 运行助手提供的骨架，不计独立编写或完整 echo 验收通过 |

本人原始反馈见 [socket-create-learner-output.txt](../results/raw/2026-10-31-socket-create-learner-output.txt)。按当前源码，`socket closed` 仅在 `close` 成功后打印；这支持正常创建和关闭路径，未验证失败路径。

助手编译的工作目录为项目根目录，命令为 `g++ -std=c++17 -Wall -Wextra -g gpu-kernel-lab/cpp-basics/echo.cpp -o /tmp/llm-echo-step1-assistant`。临时可执行文件不作为长期成果。

接口资料：[socket(2)](https://man7.org/linux/man-pages/man2/socket.2.html)、[accept(2)](https://man7.org/linux/man-pages/man2/accept.2.html)。服务器的监听 fd 用于接受连接，`accept` 返回另一个已连接 fd 用于收发；创建 socket 本身不代表已建立连接。

## 第 3 步：本机绑定与监听

助手提供局部插入片段，本人已在 `echo.cpp` 中补充 `<netinet/in.h>`，并在打印 `socket_fd` 之后、关闭 socket 之前加入 IPv4 地址配置、`bind`、`listen`。助手已读取保存后的真实源文件，核对为回环绑定及正常关闭路径。

本步实施约定：IP 为 `127.0.0.1`，端口 `39031`；地址结构清零后指定 `AF_INET`，端口使用 `htons`，回环地址使用 `htonl(INADDR_LOOPBACK)`；`bind` 与 `listen` 都检查失败并关闭 socket。`listen(sock_fd, 1)` 中的 1 是待接受连接队列长度参数，不是读取字节数。`listen` 不等待客户端到来；本步暂时保留末尾关闭，因此打印监听状态后立即关闭。

运行入口（先完成代码插入）：

```bash
cd "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics"
g++ -std=c++17 -Wall -Wextra -g echo.cpp -o /tmp/llm-echo-step2 && /tmp/llm-echo-step2
```

预期（不是实测）：打印非负 `socket_fd`、`listening on 127.0.0.1:39031` 和 `socket closed` 后退出。如果端口正在使用，可能报 `bind: Address already in use`；保留真实报错，不盲目更换地址或杀进程。

本人实际反馈：[socket-listen-learner-output.txt](../results/raw/2026-10-31-socket-listen-learner-output.txt)，打印 `socket_fd=3`、`listening on 127.0.0.1:39031`、`socket closed`。当前源码仅在 bind/listen 均成功后打印监听提示，在 close 成功后打印关闭提示；正常路径符合预期。本人未另贴编译命令或退出码；本步未验证端口占用等失败路径。

本人理解原答：「fd给服务端程序自己使用，端口号给客户端使用，用于链接这个服务端」。本例中 fd 与端口的主要用途区分正确；导师补充客户端也有自己的 fd，端口是网络端点地址的一部分，服务端也需要配置本地端口。

参考：[bind(2)](https://man7.org/linux/man-pages/man2/bind.2.html)、[listen(2)](https://man7.org/linux/man-pages/man2/listen.2.html)、[ip(7)](https://man7.org/linux/man-pages/man7/ip.7.html)。

## 第 4 步：accept 等待连接

本人已在打印监听地址之后、关闭监听 socket 之前，按导师片段加入等待提示、`fflush(stdout)`、`accept(sock_fd, nullptr, nullptr)`、返回值检查和连接 fd 的打印及关闭，助手已只读核对源文件。两个 nullptr 表示本步不取客户端地址；成功时返回独立的已连接 fd，原监听 fd 仍保留。`fflush` 让等待提示立即显示，避免尚未显示提示就进入等待。

运行入口：

```bash
cd "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics"
g++ -std=c++17 -Wall -Wextra -g echo.cpp -o /tmp/llm-echo-step3 && /tmp/llm-echo-step3
```

本轮先不启动客户端。预期（不是实测）：显示 socket fd、监听地址和 `waiting for client...`，随后尚不返回命令提示符；程序阻塞在 accept。本人需保留服务器运行，反馈当前输出，并判断等待发生在 listen 还是 accept。连接成功返回、收发与失败路径均未验证。

本人实际反馈：[socket-accept-wait-learner-output.txt](../results/raw/2026-10-31-socket-accept-wait-learner-output.txt)，显示 `socket_fd=3`、监听地址和 `waiting for client...`，未贴出 accepted 或关闭提示。本人判断原答：「停在listen」，此项理解未通过。

导师纠错依据：本次核对时源文件第 31 行调用 listen，第 38 行打印等待提示，第 41 行调用 accept。已经打印第 38 行说明前面的 listen 已返回；无客户端时，当前的阻塞式 accept 等待连接。这里根据源码顺序与本人反馈核对，没有使用调试器或系统调用跟踪重新定位进程。

纠正复答原文：「listen负责打开接待窗口」「accept会等待并接待一个具体的客户端」。两者职责的区分在提示后复答通过，保留原错答与纠错范围；尚未观察 accept 成功返回。

## 第 5 步：从另一个终端建立本机连接

终端 A：保留正在运行、显示 `waiting for client...` 的服务器。终端 B：新开一个终端，在任意目录执行助手提供的辅助客户端：

```bash
python3 "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/tests/socket_connect.py"
```

源文件：[socket_connect.py](../tests/socket_connect.py)。只连接 `127.0.0.1:39031`，连接超时参数为 3 秒，打印客户端自身 fd，并在退出 with 时关闭连接；本步不发送应用数据。接口来自 [Python 官方 socket 文档](https://docs.python.org/3.14/library/socket.html#socket.create_connection)。

预期（不是实测）：终端 B 显示连接目标、`client_fd=<非负整数>`、`client closed`；终端 A 新增 `accepted: listen_fd=<原监听 fd>, conn_fd=<新的连接 fd>` 和 `socket closed` 后退出。不同进程的 fd 编号可以相同，服务器内部这两个同时打开的 fd 应不同。不固定客户端 fd 为 3 或服务端连接 fd 为 4。

本人实际反馈：终端 A 显示 `accepted: listen_fd=3, conn_fd=4` 并关闭，见[服务端完整反馈](../results/raw/2026-10-31-socket-connect-server-learner-output.txt)；终端 B 反馈 `client_fd=3`、`client closed`，见[客户端原始反馈](../results/raw/2026-10-31-socket-connect-client-learner-output.txt)。客户端反馈没有脚本中的目标地址提示，不补写为实测；服务端 accept 成功与双方已贴内容支持建立连接的正常路径，未验证错误路径。

本人回答后续 recv 使用「conn_fd」，正确。服务端监听 fd 和连接 fd 的职责区分在指导下通过；未收发应用数据，不计 echo 验收通过。

## 第 6 步：循环接收 13 字节

本人需在 `echo.cpp` 顶部增加 `<string>`、`<cerrno>`，并在 accepted 打印之后、close(conn_fd) 之前，按导师片段插入接收循环：每次 `recv(conn_fd, buf, sizeof(buf), 0)`，buf 容量为 4；错误 EINTR 重试，其余错误关闭两个 fd 并退出；n=0 打印发送结束并退出循环；n>0 时按实际 n 追加到独立字符串，记录单次 n 和累计长度。接收结束后打印完整字符串和总长度。本轮尚不回显。

结束协议：每个连接只传一个固定输入；辅助客户端发送完毕后调用 `shutdown(SHUT_WR)` 关闭发送方向。服务端读尽之前数据后，正长度 recv 返回 0 表示对端发送结束。临时没有数据时，当前阻塞式 recv 会等待，不等同于返回 0；n 小于缓冲区容量也不能作为流结束条件。此结束规则由实验定义，不代表 TCP 自动保留消息边界。

客户端：[socket_send.py](../tests/socket_send.py)，由助手提供；使用 sendall 处理全部待发送字节，再关闭发送方向，最后退出 with 关闭 socket。当前不接收回复，后续加入 echo 前需要扩展客户端的接收部分。

先在终端 A 编译运行：

```bash
cd "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics"
g++ -std=c++17 -Wall -Wextra -g echo.cpp -o /tmp/llm-echo-step4 && /tmp/llm-echo-step4
```

看到等待提示后，在终端 B 运行：

```bash
python3 "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/tests/socket_send.py" 'hello socket!'
```

运行前的独立预期：固定 ASCII 输入 `hello socket!` 为 13 字节，完整接收内容一致；每次正数返回 n 不超过 4，累计最终为 13，最后读到 0。具体分段和调用次数不预设；例如 4+4+4+1 只是可能序列。本轮本人输出、源文件新增循环以及对 n=0 和 n<4 的区分均待核对。

### 首次失败、定位与修复

- 本人提供客户端错误截图：sendall 后打印 sent_bytes=13，随后 `client.shutdown(socket.SHUT_WR)` 报 `OSError: [Errno 107] Transport endpoint is not connected`。[截图中关键输出的人工转录摘录](../results/raw/2026-10-31-socket-shutdown-failure-learner-excerpt.txt)只保存可见关键行，未补造完整日志；未收到本次服务端输出。
- 助手读取真实源码，发现接收循环位于 `if (conn_fd < 0)` 内，在 accept 失败时才进入；正常连接成功会跳过接收并直接 close。此控制流错误与服务端过早关闭的现象相符，但没有抓包证明具体 TCP 报文时序；sendall 成功也不能单独证明对方应用已接收。
- [错误版本快照](../tests/2026-10-31-socket-recv-before-fix.cpp)已保留。助手将循环移到 accept 成功打印之后、关闭连接之前，整理缩进，未吞掉或绕过客户端 shutdown 异常；[修复后的接收阶段快照](../tests/2026-10-31-socket-recv-fixed.cpp)已保存。
- 助手试图读取监听状态时，ss 的 netlink 调用被受限环境禁止，故未据此断言真实端口状态，也没有操作其他进程。

### 助手独立复核（不计本人复测通过）

- 编译工作目录为项目根目录；命令 `g++ -std=c++17 -Wall -Wextra -g gpu-kernel-lab/cpp-basics/echo.cpp -o /tmp/llm-echo-step4-assistant`，退出码 0，无诊断。
- 在获执行权限的环境中，仅启动上述测试程序，先确认该子进程成功输出 waiting 提示，再运行现有 socket_send.py 发送同一 13 字节输入；没有对其他监听进程发送数据。
- 独立 expected：原样接收 hello socket!、总长度 13、每次 1..4 字节、累计一致、最后 EOF、双方正常退出。实测读取序列为 4/4/4/1，累计 4/8/12/13；内容和长度一致，双方退出码 0、无 stderr，客户端 shutdown 正常。[完整独立复核记录](../results/raw/2026-10-31-socket-recv-assistant-recheck.json)。这个分段序列是本次实测，后续不要求相同。
- 修复来自助手，须保留帮助范围；本人的失败证据不被助手结果替代。当前等待本人按上方命令重新编译服务器、发送相同输入并反馈双方输出，随后核对 n=1 是否足以判断输入结束。

若重启时出现 bind 地址占用，保留报错并检查对应端口状态，不擅自关闭其他进程；尚未发生或验收此错误路径。

### 本人修复后复测通过

- 本人贴出[服务端完整输出](../results/raw/2026-10-31-socket-recv-fixed-server-learner-output.txt)：读取 4/4/4/1，累计 4/8/12/13，随后 EOF，完整内容 hello socket!、总长度 13，并关闭。与独立预期一致。
- [客户端完整输出](../results/raw/2026-10-31-socket-recv-fixed-client-learner-output.txt)含 expected_bytes=13、sent_bytes=13、send direction closed、client closed，本次无报错；本人未另贴退出码。
- 本人理解原答：「某次recv返回1字节，有可能本次只接收了1字节，不能判断是否输入已经结束」。结束条件区分正确；准确说返回 1 确实表示本次收到 1 字节，是否结束仍需后续读取判断。本步骤在指导及助手修复后，通过本人复测，不记独立排错或已完成回显。

## 第 7 步：完整 echo 两种长度

助手将发送循环加入完整接收之后、关闭连接之前。sent 从 0 开始，调用 send 时从 received.data()+sent 开始，长度为 received.size()-sent；每次只按实际返回 n 推进 sent，EINTR 重试，其他错误或无进展时关闭并失败退出。MSG_NOSIGNAL 让断开连接的发送错误保留在返回值路径，不因 SIGPIPE 直接终止。循环结束打印 echoed_bytes，再关闭连接。

发送循环由助手实现；编译命令为项目根目录下 `g++ -std=c++17 -Wall -Wextra -g gpu-kernel-lab/cpp-basics/echo.cpp -o /tmp/llm-echo-step5-assistant`，退出码 0，无诊断。当前新发送分支尚未运行，不声称已观察到实际短写或失败路径。

新增助手验收客户端 [socket_echo.py](../tests/socket_echo.py)：将原命令行 ASCII 输入作为 expected，sendall 后仅关闭发送方向，继续循环接收直至服务端关闭；逐字节比较完整实际回显与原输入，并打印 expected/actual 内容、长度和 echo_match。匹配时退出 0，不匹配退出 1；助手只做语法检查，尚未代替本人运行。

结束顺序：客户端发完并 shutdown(SHUT_WR) → 服务端读尽后得到 EOF → 服务端原样回显并关闭 → 客户端收到全部回显后读到 EOF。此规则每个连接只传一个输入，不提供多个应用消息的分帧功能。

独立预期：

| 输入 | expected 内容 | expected 字节数 | 比较方法 |
| --- | --- | --- | --- |
| hi | b'hi' | 2 | 实际完整回显与原输入逐字节相同 |
| hello socket! | b'hello socket!' | 13 | 同上；服务端每次接收 n<=4，累计最终 13，不固定分段 |

终端 A 编译并启动第一组：

```bash
cd "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/cpp-basics"
g++ -std=c++17 -Wall -Wextra -g echo.cpp -o /tmp/llm-echo && /tmp/llm-echo
```

终端 B：

```bash
python3 "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/tests/socket_echo.py" 'hi'
```

本服务端每次运行处理一个连接后退出。第二组先在终端 A 重新运行 `/tmp/llm-echo`，看到等待提示，再在终端 B 执行：

```bash
python3 "/home/bestqjj/桌面/LLM Inference/gpu-kernel-lab/tests/socket_echo.py" 'hello socket!'
```

本人需反馈两组服务端和客户端完整输出，并回答纸面推进题：总长 13，第一次 send 返回 5 时，下一次起点偏移与剩余长度分别是多少？本步实际回显和发送循环理解仍待验证。

### 本人两组完整回显实测通过

| 输入 | 服务端实际读取 / 总长 / 回显长 | 客户端实际结果 | 原始输出 |
| --- | --- | --- | --- |
| hi | n=2，总长 2，回显 2 | actual=b'hi'，长度 2，echo_match=True | [服务端](../results/raw/2026-10-31-echo-buf4-hi-server-learner-output.txt) / [客户端](../results/raw/2026-10-31-echo-buf4-hi-client-learner-output.txt) |
| hello socket! | n=4/4/4/1，累计 13，回显 13 | actual=b'hello socket!'，长度 13，echo_match=True | [服务端](../results/raw/2026-10-31-echo-buf4-long-server-learner-output.txt) / [客户端](../results/raw/2026-10-31-echo-buf4-long-client-learner-output.txt) |

本人贴出第一组编译启动命令和第二组重启命令，与课堂步骤一致；两组服务端均有 EOF 与关闭提示。未另贴退出码或计时，不做性能结论。助手只读核对服务端回环地址及客户端的回环目标和逐字节比较逻辑，保存[buf4 基线源码](../tests/2026-10-31-echo-buf4.cpp)，供 P1 单配置变式比较。实现包含助手提供的骨架、发送循环和错误分支修复，不记独立实现。

### 发送推进题：需纠正复答

总长 13、首次 send 返回 5 的题目下，本人先后两次回复「1 3」；按紧邻题目作答核对为未通过，保留原文，不把它当作运行数据。

导师解释：send 的正返回值是本次交给发送调用的字节数。sent 初始为 0，第一次后为 0+5=5，所以下次起点偏移为 5（第 6 个字节），剩余长度为 13-5=8。不能用发送次数代替字节进度。

当前待答变式（纸面假设，非实际短写）：总长仍为 13，前两次 send 依次返回 5 和 3；此时累计已发送多少字节、还剩多少字节？本人尚未回答，不判理解通过。

### 接收数组与发送来源：补充讲解检查点

本人追问原文：「缓冲区不是4个字节么？」。此疑问需回答，不记作新的运行失败；发送推进理解仍未通过，不假定已理解 send 可以处理的范围。

导师对照当前代码说明：recv 的目标是固定容量 buf[4]，每次最多接收 4 字节；有效数据追加到另一个可增长字符串 received。已实测 4/4/4/1 的四次接收后，received 保存完整 13 字节。send 的来源为 received.data()+sent，长度为 received.size()-sent，并不使用 buf 作为发送来源；sent=0 时请求发送完整 13 字节。接收数组容量不限制这一发送调用的请求长度。

先前 send 返回 5 是纸面假设；实际只打印最终 echoed_bytes，没有逐次记录 send 返回值，不能声称本次实测发生 5 字节短写。

当前待本人回答：发送时读取的是 buf 还是 received？发送循环刚开始时，一共待发送多少字节？核对这一点后再恢复两次返回 5、3 的累计进度变式；两组完整回显实测通过状态不变。

本人复答原文：「recived，13字节」。含义正确，发送来源和初始待发长度在提示后通过；导师将变量拼写明确为 received，不把拼写笔误算作概念失败。

当前恢复累计进度题：总长 13，两次 send 先后返回 5 和 3，sent 初始为 0；根据 `sent += n`，计算 `sent = 0 + 5 + 3`，剩余长度为 `13 - sent`。本人需分别给出累计已发与剩余字节数；此题尚未收到回答，不判定通过。

本人累计进度复答：「8 5」。累计已发 8、剩余 5 均正确，此小题在分步提示后通过；保留先前错误与帮助范围，不记实际短写已发生。

## 第 8 步：P1 单配置变式

独立记录：[P1 缓冲区变式](../tests/2026-10-31-socket-buffer-variant.md)。本人已在修改前预测 n=3/3/3/3/1，累计 13，作为可能分段正确；导师补充至少 5 次的下界解释与回显内容不变的规格。当前源码仍为 buf[4]，下一步由本人只改为 buf[3]，编译运行两种长度并说明结果能否证明更快；命令及全部预期见 P1 记录。实际结果尚未验证，不把预测写作实测。

最新结果：本人 buf3 两组回显正确，hi 的 n=2，13 字节的 n=3/3/3/3/1；实际与先前可能分段预测一致，但不锁定后续分段。助手核对源码仅容量 4→3，保存快照、差异与全部本人输出，见 P1 独立记录。本人指出不能由此比较快慢且缺少计时，导师补充往返耗时、重复比较与创建/关闭开销的范围区别；P1 通过。

## 第 9 步：epoll 用途与 TCP 无消息边界（待本人回答）

TCP 提供按序的字节流，不保存应用的发送分界。今天同一完整输入按 4/4/4/1 或 3/3/3/3/1 取出，说明不能用一次 recv 的边界代替应用数据结束规则；本实验约定每连接一个输入，以客户端结束发送方向及服务端读到 EOF 判定输入完毕。

epoll 用于关注多个 fd 的 I/O 事件。直观例子：连接 A 没发数据、B 已有数据，若单条执行路径先阻塞读取 A，就不能及时处理 B；epoll 可以报告就绪事件，程序据此处理相应 fd。它不代替 recv 取数据，也不保证可读事件意味着一条完整业务消息收齐。实际多连接事件循环通常还需要非阻塞 I/O（暂时没有数据时立即返回，避免一次调用阻塞整个流程），本日原文只要求理解 epoll 用途，未实现该事件循环。

参考：[epoll(7)](https://man7.org/linux/man-pages/man7/epoll.7.html)、[tcp(7)](https://man7.org/linux/man-pages/man7/tcp.7.html)。

当前待答：

1. A 没发数据、B 已有数据时，epoll 能帮程序做什么？它会替程序读取 B 的字节吗？
2. 结合今天 13 字节被多次 recv 取出的结果，用自己的话解释 TCP 无消息边界；epoll 报告可读是否意味着完整业务消息已收齐？

尚未收到本人回答，不判此项通过；固定结果与下一步记录也待本人补充。

### 第 9 步初答与纠错

本人原答：

> 能帮a切换到接受模式，不能替程序读取
> 不

- 「不能替程序读取」正确，epoll 自身不执行应用的 recv。
- 「帮 A 切换到接受模式」不正确：A/B 是同一服务器程序持有的两条已连接 socket。epoll 报告哪些 fd 有就绪事件，程序根据通知选择对应 fd 再读；它不替程序切换连接模式，也不会自动中断已经阻塞的 recv(A)。实际事件循环需要程序主动先等就绪通知，再处理就绪 fd。
- 「不」正确判断可读不等于完整消息；尚无 TCP 无消息边界的完整本人解释，因此原文解释项仍待验证，不因一句判断通过。

当前分步复答：假设 A 保持连接但尚无数据，B 已有数据；epoll 应报告哪条连接可读？之后由谁调用 recv 读取数据？先核对这一点，再补 TCP 解释，不新增代码或多连接实验要求。

### epoll 第一次纠正复答

本人原答：「报告B可读，由A调用recv」。报告 B 可读正确；读取执行者仍不正确，A 是服务器持有的一条连接，不是运行 C++ 代码的服务器程序。

导师进一步区分：服务器程序执行 `recv(fd_B, buf, sizeof(buf), 0)`，其中 fd_B 指向连接 B；这是纸面多连接示意，不是当前单连接源码中的新增实测。程序是执行者，B 是读取对象，A 此刻仍无数据，不参与此次读取。

当前待本人复述：用「服务器程序」和「连接 B」两个名称，说清楚谁调用 recv、读取谁的数据。尚未收到正确完整复述，epoll 理解保持待纠正。

### epoll 第二次纠正复答通过

本人原答：「服务器调用recv，链接B，读取客户端的数据」。读取执行者为服务器、对象为连接 B 对应客户端的数据，含义正确；导师将表述明确为「服务器程序对已经建立的连接 B 调用 recv」，此处 recv 不重新建立连接。结合前面正确判断 B 可读、不代读，epoll 用途理解在多次提示与纠错后通过；不记无提示独立掌握或已实现多连接事件循环。

### 当前待答：TCP 无消息边界与结束规则

对照本人实测：同一 13 字节输入 hello socket!，buf4 接收为 4/4/4/1，buf3 为 3/3/3/3/1；完整内容与总长一致。请本人用自己的话解释「TCP 无消息边界」，说明发送次数与接收次数是什么关系；并指出本实验服务端根据什么判断输入已结束。

当前尚未收到这个完整解释，不因 epoll 一项通过而自动通过 TCP 原文解释验收；固定结果/下一步记录也仍待补充。

### TCP 原文解释与结束规则：本人复答通过

本人原答：

> 指没有消息结束标志，不一定对应，接收区不同的划分规则会导致不固定的接收次数
> 读到recv=0判断输入已经结束

原文要求的核心解释通过：本人说明消息结束边界不由 TCP 提供，发送次数和读取次数不必对应，并联系接收分段；本实验以 recv 返回 0 判定输入结束。导师进一步精确为「不保留应用消息分界」，不是没有字节流结束信号；分段还受当时可读数据量与到达时机影响，容量只是每次读取的上限。当前正长度阻塞式 recv 的 0，对应对端结束发送且先前数据已读尽；本例客户端用 shutdown(SHUT_WR) 标记发送方向结束。

## 固定记录：已完成

原始输入、输出、源码与错误记录已由助手保存。按原预算的固定 10 分钟记录项，请本人用自己的话补充：

1. 今日实测结论（一句话，来自 buf4/buf3 两种输入实际输出，不写未经测量的性能变化）。
2. 下一步准备复习或改进什么。
3. 今日实际总学习用时；可估计，未计时则明确标注未计时，不据原预算推算实际用时。

待本人反馈后合并为当天结果/下一步检查点。10 分钟是原定记录预算，尚无实际分项计时证据；不得补造已花 10 分钟。

### 本人收尾反馈与最终记录

本人原答：

> buf4 buf3表示接收端不同的划分规则，表示一次可以接收几个字节
> 随你安排
> 90分钟，20分钟

导师精确补充：buf4、buf3 分别是单次接收最多 4、3 字节，并非固定切分规则；结合已经保存的实测，两种容量均正确回显 2 字节和 13 字节输入，长输入分段由 4/4/4/1 变为本次的 3/3/3/3/1。只验证正确性与分段现象，没有速度结论。

本人授权导师安排下一步，已只读核对 [2026-11-01 路线图](../../LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01)，安排如下（今天未提前开始下一日课程）：

- 开始时用约 5 分钟不看笔记复述「接收数组与累计字符串」「epoll 通知、程序读取」，并确认接收循环位于 accept 成功路径；这是针对今日错误的复习建议，计入次日 P0 预算。
- 按次日 P0「周验收、错题与恢复」复跑一个最小 Linux 实例，优先选择今日 echo；复做本周一题，核对本周简历与实验的真实证据；更新岗位/科研日历并选择下周最早未过 P0。产出按原文为 week-04-review.md、algorithm-errors.md。
- 次日原预算 P0 1.5 小时、全日 3.5 小时，固定 40 分钟错题/周复盘已计预算；P1 2 小时复做两道旧错题后休息，遇学业/面试冲突按原文可不做。具体题目在下次开课时依最新错题记录选定，不把今日计划当已完成。
- 10 月 30 日已明确跳过的岗位清单/资格核查保留原状态，不自动补算完成或恢复为今日欠账。

本人随后确认时间含义：「P0 90分钟，P1 20分钟」。实际合计 110 分钟（1 小时 50 分钟）。固定记录未单独报告实际耗时，不将原预算 10 分钟再次加到总时长。

原始结果由助手整理，本人结论经导师精确补充，下一步依本人授权安排；固定结果/下一步记录通过。今日全部要求与必要理解通过，具体帮助程度以上述记录为准。

## 当前继续位置

- 2026-10-31 课程已完成，无当日必做剩余项。下一次按 2026-11-01 的 W04 周验收开始，先做上面的针对性复习。
- 未读取或修改浏览器 localStorage，未修改路线图原文；基于真实验收，可勾选 d-2026-10-31 与 x-2026-10-31，网页勾选尚未同步。
