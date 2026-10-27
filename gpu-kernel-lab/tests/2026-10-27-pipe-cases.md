# 2026-10-27 管道消息：逐步验收

来源：[路线图](../../LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) `d-2026-10-27`，原文学习内容包含 pipe，动手要求“通过 pipe 传递短消息”。本文件的具体步骤和测试均为教学补充。

## 验收范围（正常实跑及 EOF 理解通过，异常路径未实跑）

- 创建管道，使用 fork 连接父子进程，在子进程发送确定字节的短消息、父进程读取并核对内容。
- 按实际字节数处理读写；关闭各进程不用的端，发送完成关闭写端，父进程读完全部缓冲数据后收到 EOF。
- 父进程 waitpid 回收子进程并检查状态，错误路径合理收尾。具体消息、字节数与 expected 在实操前固定。
- 保留源码 `cpp-basics/pipe_message.cpp`、本人运行输出及必要解释；未将创建管道等同于消息传递完成。

## 检查点 1：只创建、查看和关闭两个端（通过）

- 工作目录项目根目录，源码 `gpu-kernel-lab/cpp-basics/pipe_message.cpp`，已由本人按最小示例保存。
- pipe(p) 成功返回 0，同时将读端 fd 写到 p[0]、写端 fd 写到 p[1]；失败返回 -1。数组下标与数组里存储的 fd 编号分别判断。
- 程序打印 `read_fd=… write_fd=…`，检查两个 close 并返回正常/错误状态。
- expected：读端与写端是不同的非负编号，具体编号动态分配；正常关闭后退出状态 0。此时没有 fork、发送或读取消息。
- 编译：`g++ -std=c++17 -Wall -Wextra gpu-kernel-lab/cpp-basics/pipe_message.cpp -o /tmp/pipe_message_20261027`；成功后运行并立即打印退出状态。
- actual：本人报告 `read_fd=3 write_fd=4`、`exit=0`，符合预存 expected，创建/查看/关闭两端检查点通过；助手只读核对源码，未代写或代跑。[本人输出与源码快照](../results/raw/2026-10-27-pipe-create-learner-observation.json)已保存。

## 检查点 2：fork 后的端点分工（通过）

- 先 pipe 后 fork，父子分别持有两端的描述符，仍指向同一条内核管道；关闭当前进程的某一端不等于把另一进程的同编号端也关闭。
- 本次分工：子发送、父接收。分别关闭各自不用的端；子发送完成后还需关闭写端，父读尽缓冲内容且所有写端已关闭后才能读到 EOF。
- 检查：子进程 write 使用哪个数组元素、先关闭哪个不用的端？父进程 read 使用哪个、先关闭哪个不用的端？
- expected：子 write(p[1])、close(p[0])；父 read(p[0])、close(p[1])。本人实际回答依次为“1”“0”“0”“1”，四项正确，分工阅读检查通过；尚未加入 fork 或实际收发。

## 检查点 3：父子传递 hello pipe（正常实跑、EOF 理解经纠正后通过）

- 本人将 fd_copy.cpp 中已完成的 write_all 函数复制到 pipe_message.cpp 的 main 前复用；加入 <cerrno>、<string>、<sys/wait.h>。主程序由导师给出拼接示例，不计为本人独立设计。
- 固定消息为 ASCII `hello pipe`，精确 10 字节；字符数组 sizeof 包含末尾的零值终止字节，发送 sizeof(message)-1，终止字节不作为消息发送。
- 先 pipe 再 fork；子关闭读端，通过 write_all 发送并关闭写端，用 _exit 返回状态；父关闭写端、用四字节缓冲区循环读取、按实际 n 追加到 std::string；read==0 后关闭读端，用 waitpid 回收并检查子状态。
- 预存 expected：received=hello pipe、bytes=10、child_exit=0、shell exit=0，内容/长度严格一致，正常返回证明父读到 EOF 而不是读取错误路径；动态 PID 不作固定预期。
- 本轮每个正常 close 均检查，fork 失败时尽力关闭两端；read/write/waitpid 按 EINTR 重试。异常退出子状态也报错。
- actual：本人报告 `received=hello pipe`、`bytes=10`、`child_exit=0`、`exit=0`，与预存 expected 全部一致；助手只读核对完整源码，正常消息传递、读取到 EOF 与 waitpid 回收检查点通过（按示例拼接），未代跑，异常路径未触发。
- EOF 变式初答：“会返回0,因为此时读段没有关闭，父进程会以为子进程没有关闭写端”，未通过。父仍持有自己的写端，默认阻塞管道读空后会等待；内核依据所有写端关闭及缓冲数据读尽判定 EOF，不由父进程猜测子状态。
- 纠错后变式：父已关闭自己的 p[1]、子仍保留 p[1]、管道暂空，read 返回 0 还是等待？谁仍持有写端？expected 为等待、子进程；本人复答“继续等待，子进程还持有写端”，正确，EOF 理解经纠正后通过。
- [本人输出、初答与源码快照](../results/raw/2026-10-27-pipe-message-learner-observation.json)已保存，未因正常实跑成功将错误理解判为通过。

参考：[pipe(2)](https://man7.org/linux/man-pages/man2/pipe.2.html)、[pipe(7)](https://man7.org/linux/man-pages/man7/pipe.7.html)；本轮已读取 pipe(7) 核对单向通道与 EOF 条件。
