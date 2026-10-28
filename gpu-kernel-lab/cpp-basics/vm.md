# 虚拟内存与文件映射实验

任务及实际学习日期：2026-10-28（Asia/Shanghai）。来源：[路线图](../../LLM-Inference-GPU-Systems-Roadmap-2026-2028.html) `d-2026-10-28`。本记录由导师根据本人真实回答、报告输出及只读核对整理；源码在分步示例指导下由本人保存运行，不记为全程独立设计。

## 目标与当前结论

- 比较普通 read 与只读 mmap 校验同一固定、不在运行期间修改的普通文件。
- 六字节文本、空文件、单字节与五字节二进制四组中，两种方式的字节数及字节和均符合独立预期，match=yes、exit=0。
- 缺失参数、缺失源文件及目录输入均报告错误并返回 1。
- 本次只验证上述输入的正确性；程序未计时，没有性能测量或 mmap/read 快慢结论。课堂假设的 10/15 微秒不是实测数据。

## 虚拟地址、物理内存与分页

程序使用虚拟地址。每个进程有自己的地址空间；相同的虚拟地址数值不保证对应相同物理内存。

分页把虚拟地址空间分成固定大小的页，物理内存分成同样大小的页框。将虚拟地址拆为虚拟页号和页内偏移，依据进程页表确定物理页框，再计算物理地址：

```text
虚拟页号 = 虚拟地址 / 页大小的整数商
页内偏移 = 虚拟地址除以页大小的余数
物理地址 = 物理页框号 × 页大小 + 页内偏移
```

教学假设每页 16 字节、虚拟页 2 映射到物理页框 7，则虚拟地址 38 对应页号 2、偏移 6、物理地址 118。本人的手算回答三项正确。16 字节是教学假设，不是本机页大小测量。

本人完整解释的核心关系正确；“先确定虚拟页表”的措辞由导师精确补充为先拆出虚拟页号及偏移，再查进程页表。[本人原答及核对](../results/raw/2026-10-28-vm-understanding-learner-observation.json)

## 两种读取方式

- read：程序准备缓冲区，通过 read 读入数据，仅处理每次实际返回的有效字节；循环处理 EINTR、其他错误及 EOF。
- mmap：把文件区域映射到进程虚拟地址空间，成功后通过指针按字节访问；使用 PROT_READ、MAP_PRIVATE、文件偏移 0，失败判断 MAP_FAILED，结束后 munmap。
- 先 mmap 遍历并解除映射，再通过同一 fd 执行 read；mmap 访问不推进 fd 的读取位置，首次 read 从文件开头开始。
- 空文件不调用长度为 0 的 mmap，映射字节数与字节和为 0；read 首次返回 0。
- 当前只接受普通文件，输入在整个实验期间保持不变。

校验规则：每个字节作为 unsigned char（0～255）累加到 std::uint64_t，按无符号 64 位加法计算。mmap_bytes 是映射遍历范围 length，read_bytes 是每次 read 正返回值的累计；两条路径同时比较长度和字节和。

简单字节和可能碰撞，不足以证明任意两个文件完全相同。本实验使用同一固定输入，并与独立预存的字节数、字节和核对。

## 环境与复现

工作目录：项目根目录。助手只读确认环境为 Linux 7.0.0-38-generic、g++ 15.2.0、全局 Python 3.14.4；C++ 使用 C++17。本人未单独报告编译器版本，以助手检查为环境记录。没有 GPU 性能实验。

源码：[mmap.cpp](mmap.cpp)。编译及运行命令如下，结果保存在下节链接的本人报告，导师没有代跑：

```bash
g++ -std=c++17 -Wall -Wextra gpu-kernel-lab/cpp-basics/mmap.cpp -o /tmp/llm-vm-2026-10-28
/tmp/llm-vm-2026-10-28 gpu-kernel-lab/results/raw/2026-10-28-vm-input.txt
echo "exit=$?"

for vm_case in empty one binary; do
    echo "$vm_case"
    /tmp/llm-vm-2026-10-28 "gpu-kernel-lab/results/raw/2026-10-28-vm-${vm_case}.bin"
    echo "exit=$?"
done
```

已有原始输入位于 results/raw。下列命令用于在新的临时目录重建相同字节，不覆盖已有课堂输入；这是复现说明，不是新增实测：

```bash
vm_replay_dir=$(mktemp -d /tmp/llm-vm-replay.XXXXXX)
printf 'ABCDEF' > "$vm_replay_dir/text.bin"
printf '%s' '' > "$vm_replay_dir/empty.bin"
printf 'A' > "$vm_replay_dir/one.bin"
printf '\000\177\200\377A' > "$vm_replay_dir/binary.bin"
```

## 正确性与边界结果

下表预期由输入规格独立计算，实际来自本人运行报告；助手只读核对了输入长度、准确字节及 SHA-256。

| 输入（results/raw/ 下） | 独立预期：字节数/字节和 | 本人报告：mmap | 本人报告：read | 比较/退出 |
| --- | --- | --- | --- | --- |
| 2026-10-28-vm-input.txt：ABCDEF | 6/405（65+66+67+68+69+70） | 6/405 | 6/405 | yes/0 |
| 2026-10-28-vm-empty.bin：空 | 0/0 | 0/0 | 0/0 | yes/0 |
| 2026-10-28-vm-one.bin：A | 1/65 | 1/65 | 1/65 | yes/0 |
| 2026-10-28-vm-binary.bin：00 7f 80 ff 41（十六进制） | 5/575（0+127+128+255+65） | 5/575 | 5/575 | yes/0 |

证据：[六字节普通读取对照及当时源码快照](../results/raw/2026-10-28-read-compare-learner-observation.json) · [空/单字节/二进制及当前源码快照](../results/raw/2026-10-28-vm-boundaries-learner-observation.json)。六字节文本在加入空文件处理前实跑；加入后本人实跑了后三组，未补记文本的再次运行。

归档复核：助手于 2026-10-28 编译最终源码并重新核对全部四种输入及三条错误路径，全部符合独立预期，无编译警告。[归档审计](../results/raw/2026-10-28-archive-audit.json)单独保存预期、实际和源码/输入哈希，包含最终源码对六字节文本的复测；这不是本人新增实跑，没有性能计时。

| 错误输入 | 独立预期 | 本人实际报告 |
| --- | --- | --- |
| 缺失文件参数 | usage，exit=1 | 符合 |
| 不存在的 2026-10-28-vm-missing.bin | open 报文件不存在，exit=1 | 符合 |
| cpp-basics 目录 | 拒绝非普通文件，exit=1；目录 size 不固定 | size=4096，expected a regular file with nonnegative size，exit=1 |

[三条错误路径的完整报告](../results/raw/2026-10-28-vm-errors-learner-observation.json)。没有实跑 fstat/mmap/read/munmap/close 的任意失败或 EINTR 分支，不把源码包含错误处理等同于全部故障已验证。

## 性能结论与理解边界

本人正确判断不能根据一次小文件耗时宣称 mmap 普遍更快，并说明“六字节的快慢不能代表其他大文件”，还提出需要考虑缓存及系统状态。[本人原答、复答与导师补充](../results/raw/2026-10-28-vm-understanding-learner-observation.json)

导师纠正并补充：缺页处理或页表相关操作存在成本，不能仅凭成本存在就判定 mmap 更慢；需要明确输入规模、访问方式和计时范围，控制/记录缓存与系统状态，对每种方式重复测量并保存原始结果，以观察波动。本人没有独立答出重复测量动作，不记为已独立设计性能测试。

## 参考与验收入口

- [OSTEP Address Spaces](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-intro.pdf)
- [OSTEP Paging](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-paging.pdf)
- [Linux mmap/munmap](https://man7.org/linux/man-pages/man2/mmap.2.html)
- [Linux read](https://man7.org/linux/man-pages/man2/read.2.html)
- [Linux fstat](https://man7.org/linux/man-pages/man2/stat.2.html)
- [Google Benchmark 测量说明](https://google.github.io/benchmark/user_guide.html#runtime-and-reporting-considerations)
- [逐项验收](../tests/2026-10-28-vm-cases.md) · [今日日记](../../日记/2026-10-28.md)

主实验及原文两项理解验收通过（含示例、局部纠错与导师补充）；当天[固定练习](../tests/2026-10-28-linked-list-redo-cases.md)和 [P1](../tests/2026-10-28-parentheses-redo-cases.md)也已分别验收通过，帮助范围与真实结果各自保留。
