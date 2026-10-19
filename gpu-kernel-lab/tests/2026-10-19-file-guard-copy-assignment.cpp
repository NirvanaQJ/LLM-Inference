// Include the learner's current implementation without invoking its demo main.
#define main file_guard_demo_main
#include "../cpp-basics/file_guard.cpp"
#undef main

void attempt_copy_assignment(FileGuard& target, const FileGuard& source) {
    target = source; // Expected: use of deleted copy assignment.
}
