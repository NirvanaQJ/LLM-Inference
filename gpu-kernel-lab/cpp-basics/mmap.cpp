#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstddef>
#include <sys/mman.h>
#include <cstdint>
#include <cerrno>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: " << argv[0] << " <file>\n";
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        std::perror("open");
        return 1;
    }

    struct stat info{};
    if (fstat(fd, &info) == -1) {
        std::perror("fstat");
        close(fd);
        return 1;
    }

    std::cout << "size=" << info.st_size << '\n';
  if (!S_ISREG(info.st_mode) || info.st_size < 0) {
    std::cerr << "expected a regular file with nonnegative size\n";
    close(fd);
    return 1;
}

std::size_t length = static_cast<std::size_t>(info.st_size);
std::uint64_t mmap_sum = 0;

if (length > 0) {
    void* mapping = mmap(nullptr, length, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapping == MAP_FAILED) {
        std::perror("mmap");
        close(fd);
        return 1;
    }

    const unsigned char* bytes =
        static_cast<const unsigned char*>(mapping);

    for (std::size_t index = 0; index < length; ++index) {
        mmap_sum += bytes[index];
    }

    if (munmap(mapping, length) == -1) {
        std::perror("munmap");
        close(fd);
        return 1;
    }
}

std::cout << "mmap_bytes=" << length << '\n';
std::cout << "mmap_sum=" << mmap_sum << '\n';
unsigned char buffer[4];
std::size_t read_bytes = 0;
std::uint64_t read_sum = 0;

while (true) {
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read < 0) {
        if (errno == EINTR) {
            continue;
        }
        std::perror("read");
        close(fd);
        return 1;
    }

    if (bytes_read == 0) {
        break;
    }

    std::size_t count = static_cast<std::size_t>(bytes_read);
    read_bytes += count;
    for (std::size_t index = 0; index < count; ++index) {
        read_sum += buffer[index];
    }
}

std::cout << "read_bytes=" << read_bytes << '\n';
std::cout << "read_sum=" << read_sum << '\n';

bool matched = (read_bytes == length && read_sum == mmap_sum);
std::cout << "match=" << (matched ? "yes" : "no") << '\n';

if (!matched) {
    close(fd);
    return 1;
}

    if (close(fd) == -1) {
        std::perror("close");
        return 1;
    }
    return 0;
}