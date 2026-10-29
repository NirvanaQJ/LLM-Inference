#include <signal.h>   // 信号相关：SIGINT、sigaction、sig_atomic_t
#include <unistd.h>   // sleep（等待）、close（关闭文件）
#include <fcntl.h>    // open（打开文件）、O_WRONLY（只写）
#include <cstdio>     // perror（输出错误原因）
#include <iostream>   // cout（输出文字）
#include <cerrno>  // errno 保存错误原因；EINTR 表示被信号打断

// 退出标志，放在函数外，让 main 和信号处理函数都能访问。
// 0：继续运行；1：请求退出。
//
// sig_atomic_t：适合在信号处理函数与普通代码之间
//              进行简单读写的整数类型。
// volatile：要求编译器保留对这个变量的实际读取，
//           因为它可能被信号处理函数修改。
volatile sig_atomic_t stop_requested = 0;


// 信号处理函数：收到 SIGINT 时，系统会调用它。
//
// int 参数用于接收信号编号。
// 这里不使用这个编号，因此没有给参数起名字。
void handle_sigint(int) {
    // 这里只发出退出请求，不打印、不关闭文件。
    stop_requested = 1;
}


int main() {
    // 创建一份“收到信号后怎么办”的配置。
    // {} 表示先把各成员初始化为零值。
    struct sigaction action{};

    // 指定处理函数。
    // 这里没有括号：是在登记函数，而不是立刻调用函数。
    action.sa_handler = handle_sigint;

    // 清空“处理期间要额外屏蔽哪些信号”的集合。
    // 今天先照着用，不需要深入信号屏蔽机制。
    sigemptyset(&action.sa_mask);

    // P1 对照：启用可重启调用选项。
    // 本例终端 read 被 SIGINT 打断后会在处理函数返回时自动重启。
    // 即使退出标志已为 1，主流程仍需等 read 返回后才能检查它。
    action.sa_flags = SA_RESTART;

    // 正式注册：
    // SIGINT：要处理的信号，通常由 Ctrl+C 触发。
    // &action：把上面的配置交给系统。
    // nullptr：不需要保存此前的处理配置。
    //
    // 注册失败时返回 -1。
    if (sigaction(SIGINT, &action, nullptr) == -1) {
        std::perror("sigaction");  // 输出错误原因
        return 1;                 // 用非零状态表示失败
    }

    // 打开 /dev/null，只写模式。
    // /dev/null 是 Linux 的特殊文件，写进去的数据会被丢弃。
    // 这里用它来练习“打开资源 → 使用 → 关闭”。
    //
    // 成功：返回一个非负整数，也就是文件描述符。
    // 失败：返回 -1。
    int fd = open("/dev/null", O_WRONLY);

    if (fd == -1) {
        std::perror("open");
        return 1;
    }

    // 提示程序已经准备好。
    // endl 输出换行，并让这条提示立即显示出来。
    std::cout << "ready: press Ctrl+C" << std::endl;

    // ! 表示逻辑取反：
    // stop_requested 为 0 → !0 为 true  → 继续循环。
    // stop_requested 为 1 → !1 为 false → 结束循环。
    char buffer[64];  // 准备一块最多容纳 64 字节的存储空间

while (!stop_requested) {
    std::cout << "waiting for input..." << std::endl;

    // 从标准输入读取数据，放进 buffer，最多读取 64 字节。
    // STDIN_FILENO 的值是 0，在当前终端中对应键盘输入。
    // ssize_t 是带符号的整数类型，可以保存字节数，也能保存 -1。
    ssize_t count = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (count > 0) {
        // 成功读到了数据，count 是本次实际读取的字节数。
        std::cout << "read_bytes=" << count << std::endl;
    } else if (count == 0) {
        // 输入结束，跳出循环，继续执行后面的清理代码。
        std::cout << "input ended" << std::endl;
        break;
    } else if (errno == EINTR) {
        // read 返回 -1，并且原因是“被信号打断”。
        // 这里仍然在 main 中，可以正常输出。
        std::cout << "read interrupted" << std::endl;

        // 回到循环条件，重新检查退出标志。
        // 如果 SIGINT 处理函数已把标志设成 1，就结束循环。
        continue;
    } else {
        // 其他读取错误：输出原因，尝试关闭资源，以失败状态退出。
        std::perror("read");
        close(fd);
        return 1;
    }
}

    // 能走到这里，说明循环已经结束。
    // 清理工作放在 main 的普通执行流程中。
    if (close(fd) == -1) {
        std::perror("close");
        return 1;
    }

    // close 已经成功，输出清理完成的信息。
    std::cout << "cleanup: fd closed\n";

    return 0;  // 正常结束
}