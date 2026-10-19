#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdexcept>
#include <cerrno>
#include <string>

class FileGuard {
private:
    int fd_ = -1;

public:
int get() const {
    return fd_;
}
FileGuard(const FileGuard&) = delete;
FileGuard& operator=(const FileGuard&) = delete;
   FileGuard(const char* path) {
    fd_ = open(path, O_RDONLY);

    if (fd_ == -1) {
        throw std::runtime_error("打开文件失败");
    }

    std::cout << "构造 fd=" << fd_ << "\n";
}

    ~FileGuard() {
        if (fd_ != -1) {
            // TODO 2：关闭 fd_ 对应的句柄
            close(fd_);

            std::cout << "析构 fd=" << fd_ << "\n";
        }
    }
};
int main(int argc, char* argv[]) {
    bool simulate_error =
        argc > 1 && std::string(argv[1]) == "throw";

    int saved_fd = -1;
    bool ready_for_throw = false;

    try {
        FileGuard guard("lifetime_demo.cpp");
        saved_fd = guard.get();

        int inside_result = fcntl(saved_fd, F_GETFD);
        std::cout << "作用域内查询=" << inside_result << "\n";

        if (inside_result == -1) {
            throw std::runtime_error("作用域内句柄无效");
        }

        ready_for_throw = true;

        if (simulate_error) {
            throw std::runtime_error("模拟使用文件失败");
        }
    } catch (const std::exception& e) {
        std::cout << "捕获异常：" << e.what() << "\n";

        if (!simulate_error || !ready_for_throw) {
            return 1;
        }
    }

    errno = 0;
    int outside_result = fcntl(saved_fd, F_GETFD);
    int error = errno;

    std::cout << "作用域外查询=" << outside_result
              << ", EBADF=" << (error == EBADF) << "\n";

    if (outside_result == -1 && error == EBADF) {
        std::cout << "关闭检查 PASS\n";
        return 0;
    }

    std::cerr << "关闭检查 FAIL\n";
    return 2;
}