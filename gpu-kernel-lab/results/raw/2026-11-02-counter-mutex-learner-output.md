# mutex 计数器：首次本人运行与理解

日期：2026-11-02（Asia/Shanghai）。运行证据来自本人在对话中的终端截图，原图保留在对话中。助手只读核对源码，未改动或代跑。

## 输入、预期与实际

- 初始值 0，2 个工作线程，每线程累加 100000 次。
- 导师按规格独立计算的正确计数：0 + 2 × 100000 = 200000。
- 工作目录：项目根目录。

本人编译与运行：

```bash
g++ -std=c++17 -Wall -Wextra -O0 -pthread gpu-kernel-lab/cpp-basics/counter.cpp -o /tmp/llm-counter-mutex
/tmp/llm-counter-mutex
```

截图实际输出：

```text
actual=200000
```

随后返回提示符；未单独显示退出状态，不补造 exit=0。与此前无锁版本同样的线程数和次数相比，本次输出与正确计数一致；尚不代表已通过 20 次验证，无性能测量。

## 助手读取的源码快照

```cpp
#include <iostream>
#include <thread>
#include <mutex>
long long counter = 0;
const int increments = 100000;
std::mutex counter_mutex;
void worker() {
    for (int i = 0; i < increments; ++i) {
    std::lock_guard<std::mutex> guard(counter_mutex);
    ++counter;
}
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "actual=" << counter << '\n';
}
```

锁对象定义在函数外，两线程使用同一把锁；每轮在递增前获取锁，作用域结束自动释放；主线程在两次 join 完成后读取结果。缩进未齐，不影响当前括号作用域与语义，导师未修改。

## 理解检查

问题：「如果把 ++counter 放在 lock_guard 声明之前，这把锁还能保护这次累加吗？为什么？」

本人原答：「不能，因为此时不能保证t1t2互斥访问counter」。

判断：通过。导师补充时间顺序：累加先发生时，锁还没有获取，之后加锁不能保护已经发生的访问。

帮助范围：沿用导师局部示例，由本人修改、编译和运行，不计无提示独立实现。
