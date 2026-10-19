// Include the learner's current implementation without invoking its demo main.
#define main file_guard_demo_main
#include "../cpp-basics/file_guard.cpp"
#undef main

void attempt_copy_construction(const FileGuard& source) {
    FileGuard copied(source); // Expected: use of deleted copy constructor.
}
