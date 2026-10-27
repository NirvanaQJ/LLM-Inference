// Test-only syscall wrappers. Compile together with the learner's current source.
#include <algorithm>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

#define main fd_copy_program_main
#include "../cpp-basics/fd_copy.cpp"
#undef main

struct Event {
    const char* operation;
    long long requested;
    long long returned;
    int error;
    bool controlled;
    bool real_closed;
};

static std::string scenario;
static bool active = false;
static int read_calls = 0, write_calls = 0, close_calls = 0;
static std::vector<Event> events;

extern "C" ssize_t __real_read(int, void*, size_t);
extern "C" ssize_t __real_write(int, const void*, size_t);
extern "C" int __real_close(int);

static void record(const char* op, long long count, long long result,
                   int error, bool controlled, bool real_closed = false) {
    events.push_back({op, count, result, result < 0 ? error : 0,
                      controlled, real_closed});
    errno = error;
}

extern "C" ssize_t __wrap_read(int fd, void* data, size_t count) {
    if (!active) return __real_read(fd, data, count);
    ++read_calls;
    if ((scenario == "eintr" || scenario == "read_error") && read_calls == 1) {
        const int error = scenario == "eintr" ? EINTR : EIO;
        record("read", count, -1, error, true);
        return -1;
    }
    const size_t limited = scenario == "short_read" ? std::min(count, size_t{2}) : count;
    const ssize_t result = __real_read(fd, data, limited);
    const int error = errno;
    record("read", count, result, error, limited != count);
    return result;
}

extern "C" ssize_t __wrap_write(int fd, const void* data, size_t count) {
    if (!active) return __real_write(fd, data, count);
    ++write_calls;
    if ((scenario == "eintr" || scenario == "write_error") && write_calls == 1) {
        const int error = scenario == "eintr" ? EINTR : ENOSPC;
        record("write", count, -1, error, true);
        return -1;
    }
    if (scenario == "write_zero" && write_calls == 1) {
        record("write", count, 0, 0, true);
        return 0;
    }
    const size_t limited = scenario == "short_write" ? std::min(count, size_t{1}) : count;
    const ssize_t result = __real_write(fd, data, limited);
    const int error = errno;
    record("write", count, result, error, limited != count);
    return result;
}

extern "C" int __wrap_close(int fd) {
    if (!active) return __real_close(fd);
    ++close_calls;
    const int real_result = __real_close(fd);
    const bool inject = real_result == 0 &&
        ((scenario == "close_source_error" && close_calls == 1) ||
         (scenario == "close_destination_error" && close_calls == 2));
    const int error = inject ? EIO : errno;
    const int result = inject ? -1 : real_result;
    record("close", 0, result, error, inject, real_result == 0);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) return 2;
    scenario = argv[1];
    char name[] = "fd_copy_under_test";
    char* arguments[] = {name, argv[2], argv[3], nullptr};
    active = true;
    const int result = fd_copy_program_main(scenario == "usage" ? 1 : 3, arguments);
    active = false;

    std::printf("{\"program_exit\":%d,\"read_calls\":%d,\"write_calls\":%d,\"close_calls\":%d,\"events\":[",
                result, read_calls, write_calls, close_calls);
    for (size_t i = 0; i < events.size(); ++i) {
        const Event& e = events[i];
        std::printf("%s{\"operation\":\"%s\",\"requested\":%lld,\"returned\":%lld,\"errno\":%d,\"controlled\":%s,\"real_closed\":%s}",
                    i ? "," : "", e.operation, e.requested, e.returned, e.error,
                    e.controlled ? "true" : "false", e.real_closed ? "true" : "false");
    }
    std::printf("]}\n");
    return 0;
}
