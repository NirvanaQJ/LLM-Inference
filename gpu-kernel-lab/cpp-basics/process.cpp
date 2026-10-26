#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cerrno>
int main() {
    pid_t child = fork();

    if (child == -1) {
        std::perror("fork");
        return 1;
    }

   if (child == 0) {
    std::cout << "child PID:" << getpid()
              << " PPID:" << getppid() << std::endl;
execl("/bin/echo", "echo", "hello from exec",
          static_cast<char*>(nullptr));

    std::perror("execl");
    _exit(127);
}

   int status = 0;
pid_t reaped;

do {
    reaped = waitpid(child, &status, 0);
} while (reaped == -1 && errno == EINTR);

if (reaped == -1) {
    std::perror("waitpid");
    return 1;
}

std::cout << "parent PID:" << getpid()
          << " child:" << child << '\n';
std::cout << "reaped:" << reaped << '\n';

if (WIFEXITED(status)) {
    int exit_code = WEXITSTATUS(status);
    std::cout << "child exit:" << exit_code << '\n';

return exit_code;
}

std::cerr << "child did not exit normally\n";
return 1;
}
