#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <cerrno>
#include <string>

bool write_all(int out_fd, const char* data, size_t total) {
    size_t done = 0;

    while (done < total) {
        ssize_t written = write(out_fd, data + done, total - done);

        if (written < 0) {
            if (errno == EINTR) {
                continue;
            }
            std::perror("write");
            return false;
        }

        if (written == 0) {
            std::fprintf(stderr, "write: no progress\n");
            return false;
        }

        done += written;
    }

    return true;
}

int main() {
    int p[2];
    if (pipe(p) < 0) {
        std::perror("pipe");
        return 1;
    }

    pid_t child = fork();
    if (child < 0) {
        std::perror("fork");
        close(p[0]);
        close(p[1]);
        return 1;
    }

    if (child == 0) {
        int result = 0;

        if (close(p[0]) < 0) {
            std::perror("child close read end");
            result = 1;
        }

        const char message[] = "hello pipe";
        if (!write_all(p[1], message, sizeof(message) - 1)) {
            result = 1;
        }

        if (close(p[1]) < 0) {
            std::perror("child close write end");
            result = 1;
        }

        _exit(result);
    }

    int result = 0;
    if (close(p[1]) < 0) {
        std::perror("parent close write end");
        result = 1;
    }

    std::string received;
    char buf[4];

    while (true) {
        ssize_t n = read(p[0], buf, sizeof(buf));
        if (n < 0) {
            if (errno == EINTR) {
                continue;
            }
            std::perror("read");
            result = 1;
            break;
        }
        if (n == 0) {
            break;
        }
        received.append(buf, static_cast<size_t>(n));
    }

    if (close(p[0]) < 0) {
        std::perror("parent close read end");
        result = 1;
    }

    int status = 0;
    pid_t reaped;
    do {
        reaped = waitpid(child, &status, 0);
    } while (reaped < 0 && errno == EINTR);

    if (reaped < 0) {
        std::perror("waitpid");
        return 1;
    }
    if (!WIFEXITED(status)) {
        std::fprintf(stderr, "child terminated abnormally\n");
        return 1;
    }

    int child_exit = WEXITSTATUS(status);
    std::printf("received=%s\n", received.c_str());
    std::printf("bytes=%zu\n", received.size());
    std::printf("child_exit=%d\n", child_exit);

    if (child_exit != 0 || received != "hello pipe") {
        result = 1;
    }
    return result;
}