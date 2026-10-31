// 2026-10-31 课堂第 2 步：创建并关闭 IPv4 TCP socket。
// 后续在此逐步加入本机绑定、监听、接受连接和原样回显。
// 接口来源：https://man7.org/linux/man-pages/man2/socket.2.html
#include <sys/socket.h>
#include <unistd.h>
#include <cstdio>
#include <netinet/in.h>
#include <string>
#include <cerrno>

int main() {
    // AF_INET 选择 IPv4；SOCK_STREAM 选择字节流；0 选择默认协议 TCP。
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        std::perror("socket");
        return 1;
    }

    std::printf("socket_fd=%d\n", sock_fd);
    sockaddr_in addr{};  // IPv4 地址结构，先清零
addr.sin_family = AF_INET;
addr.sin_port = htons(39031);
addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

if (bind(sock_fd,
         reinterpret_cast<const sockaddr*>(&addr),
         sizeof(addr)) < 0) {
    std::perror("bind");
    close(sock_fd);
    return 1;
}

if (listen(sock_fd, 1) < 0) {
    std::perror("listen");
    close(sock_fd);
    return 1;
}

std::puts("listening on 127.0.0.1:39031");
std::puts("waiting for client...");
std::fflush(stdout);  // 让等待提示立即显示

int conn_fd = accept(sock_fd, nullptr, nullptr);
if (conn_fd < 0) {
    std::perror("accept");
    std::string received;  // 累计保存完整数据
char buf[4];           // 每次接收时复用的小缓冲区

while (true) {
    ssize_t n = recv(conn_fd, buf, sizeof(buf), 0);

    if (n < 0) {
        if (errno == EINTR) {
            continue;
        }
        std::perror("recv");
        close(conn_fd);
        close(sock_fd);
        return 1;
    }

    if (n == 0) {
        std::puts("peer send EOF");
        break;
    }

    received.append(buf, static_cast<size_t>(n));
    std::printf("recv_bytes=%zd, total=%zu\n",
                n, received.size());
}

std::printf("received=%s\n", received.c_str());
std::printf("total_bytes=%zu\n", received.size());
    close(sock_fd);
    return 1;
}

std::printf("accepted: listen_fd=%d, conn_fd=%d\n",
            sock_fd, conn_fd);

if (close(conn_fd) < 0) {
    std::perror("close connection");
    close(sock_fd);
    return 1;
}

    if (close(sock_fd) < 0) {
        std::perror("close");
        return 1;
    }
    std::puts("socket closed");
    return 0;
}
