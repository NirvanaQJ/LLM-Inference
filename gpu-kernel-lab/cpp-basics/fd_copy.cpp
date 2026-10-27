#include <fcntl.h>   // open、O_RDONLY
#include <unistd.h>  // close
#include <cstdio>    // printf、perror
#include <cerrno>

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
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::fprintf(stderr, "usage: %s SOURCE DEST\n", argv[0]);
        return 2;
    }

    int in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        std::perror("open source");
        return 1;
    }

    int out_fd = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0600);
    if (out_fd < 0) {
        std::perror("open destination");
        close(in_fd);
        return 1;
    }

    char buf[4];
    int result = 0;

    while (true) {
        ssize_t n = read(in_fd, buf, sizeof(buf));

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

        if (!write_all(out_fd, buf, static_cast<size_t>(n))) {
            result = 1;
            break;
        }
    }

    if (close(in_fd) < 0) {
        std::perror("close source");
        result = 1;
    }

    if (close(out_fd) < 0) {
        std::perror("close destination");
        result = 1;
    }

    return result;
}