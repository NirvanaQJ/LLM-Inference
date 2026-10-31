// 2026-10-31 课堂第 7 步：本机 TCP 循环接收，读到 EOF 后原样回显。
// 接口来源：Linux man-pages 的 socket/bind/listen/accept/recv/send 手册。
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
        close(sock_fd);
        return 1;
    }

    std::printf("accepted: listen_fd=%d, conn_fd=%d\n",
                sock_fd, conn_fd);

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

    // sent 表示已经交给 send 的字节数；每次从未发送的位置继续。
    size_t sent = 0;
    while (sent < received.size()) {
        ssize_t n = send(conn_fd,
                         received.data() + sent,
                         received.size() - sent,
                         MSG_NOSIGNAL);
        if (n < 0) {
            if (errno == EINTR) {
                continue;
            }
            std::perror("send");
            close(conn_fd);
            close(sock_fd);
            return 1;
        }
        if (n == 0) {
            std::fprintf(stderr, "send: no progress\n");
            close(conn_fd);
            close(sock_fd);
            return 1;
        }
        sent += static_cast<size_t>(n);
    }
    std::printf("echoed_bytes=%zu\n", sent);

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
