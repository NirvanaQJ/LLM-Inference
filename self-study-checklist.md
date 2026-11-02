# 项目之外的完整自学清单

编制日期：2026-11-02（Asia/Shanghai）。本文件是学习任务与自检标准，**不是新增学习成果、已通过证明或新的每日排课表**。

依据：[当前项目学习计划](project-learning-plan.md)、[完整路线图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html)、[根 README](README.md)、[GPU 项目说明](gpu-kernel-lab/README.md)、[推理项目说明](llm-inference-lab/README.md)、[能力基线](baseline-skills.md)、[日记索引](日记/README.md)、W01–W04 周验收与已有相关记录。当前计划和本人最新分工优先于旧日历。

## 使用方式与边界

- 助手按检查点连续指导当前选定项目；两个项目目标保留，当前为 LLM 项目 L0 待开始，仅本人明确要求才切换。本清单涵盖其余自主学习、通用前置、算法及非技术事项，不等待清单全部完成才开始项目，也不按日期轮换主线。
- 72 项按知识依赖分组，组内依赖见各项。近期可先查 S01–S04、S28–S29、S33–S34、S37；已会部分不必重读整套教材，遇到具体缺口再补。P1 保留原计划深化程度，P2 为条件化选修，不自动升级为必修。
- **“学习进度/已有证据”“本项产出达标”“本项独立考核通过”分别记录。** 所有新考核都尚未执行，勾选初始为空；已有课程通过仍保留在状态与链接里，不能直接替代新考核。未来只改变有本人反馈支持的状态。
- 各项“当前状态”采用：已完成（仅限所述范围）、部分完成、未开始、待确认。未来主题没有仓库记录时标待确认，不推断本人从未课下学过；本文件所列新考核为未开始。
- **统一独立考核边界：**可查官方文档、API签名、编译错误及工具帮助；不可照抄旧实现、完整题解或请助手生成待考核的实现/推导。自行设计、编写、运行并解释。若借助提示/示例，记为指导下练习，随后换输入或从空白再考。理论题自行画图/推导/讲解；不必强行写程序。
- 考核中的小数组、公式结果是验收基准，不是解题步骤或完整代码。除单项另有要求，至少保留一组正常、两组边界和一组错误/限制条件；纯理论事项用反例代替错误输入。先写预期再运行，记录真实输出和必要环境。CPU模拟、合成数据、真实硬件结果显式区分。
- 各项“产出”是未来应交内容，最低包含可读文件/图示、复现入口或推导条件、结论与限制。“已有材料链接”只指向真实文件，不为待办创建空文件。自学新材料可先放个人自学目录，后续按既有目录约定归档；本次只生成本清单。
- 私人日历、简历、申请、offer与学校资料保留私有位置；公开日记只写必要状态，不粘贴个人原文或私有链接。未来核查招聘/软件时再查实际官方信息；本次未重新联网核验旧路线图的外部资料或岗位状态。
- 日常自然语言汇报即可：实际日期、学了什么、做到哪、产出/测试、疑问、本人用时（可省略）。归档合并自学汇报与项目证据，同日去重；不以本清单尚未考完阻断项目，不自动创建后台归档或提醒。

## 建议推进顺序

| 分组 | 条目 | 如何穿插 |
| --- | --- | --- |
| 工具/Python/统计 | S01–S06 | 优先运行与阅读所需部分 |
| C++/工具链 | S07–S12 | 在系统/GPU源码前逐步补齐 |
| Linux/网络/并发/方法 | S13–S22 | 复习已有成果，补队列等未核验项 |
| GPU/张量/数学 | S23–S30 | GPU原理与CPU练习，不重复核心算子 |
| 推理原理 | S31–S44 | 先L0所需术语/预算，随后机制与选修 |
| 通信/网络选修 | S45–S52 | CPU语义→条件化真实硬件，网络限量 |
| 算法 | S53–S62 | 数组/哈希→链表/栈→树/图/DP，复做分账 |
| 求职/实习/毕业 | S63–S72 | 按真实机会与学业窗口持续维护 |

本清单的模块拆分、独立小练习、验收输入和预期值是本次为自学补充的设计；原路线图提供范围、项目协议、优先级和长期目标。它们不是旧日历逐字原题，也不是额外叠加的每日课时。


## 第一组：终端、Python 与数据处理

L0 近期优先 S01–S03；S04/S06 按客户端与分析需求补。


<a id="s01"></a>

### S01 终端、路径、环境与依赖版本

- **计划出处：**[启动日](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#daily)；[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5)；[W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23)；其余重复出处见逐日覆盖表；[2026-10-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-03)；[2026-10-04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-04)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**工作目录、相对路径、引号、标准输入输出/退出码；venv、pip、依赖锁定、OS/驱动/runtime 区别，能从错误定位到实际解释器和文件。
- **前置与顺序：**无；L0 近期优先，缺项可随项目补。
- **学后产出：**环境清单、可复制命令说明、依赖记录；每项注明实际值或未知，不提交私人硬件原文。
- **独立考核：**在名称含空格的临时目录中创建独立环境；从两个不同工作目录调用同一统计入口并传入相对数据路径；验证缺参、路径不存在两条错误路径。
- **通过标准：**两次正常输出一致；解释器路径可核对；错误为非零退出且信息明确；不靠修改全局环境或写死本机路径。
- **当前状态：**部分完成：已有独立环境与路径练习；[10-08](日记/2026-10-08.md)、[W02 路径纠错](week-02-review.md)。新考核未执行。
- [ ] S01 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S01 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s02"></a>

### S02 Python 语法、函数与容器

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[2026-10-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-05)；[2026-10-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-06)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**数值/字符串、布尔值、if/for、函数参数与返回值、list/dict/set、可变对象与别名；能逐步追踪类型、累计值与空输入。
- **前置与顺序：**S01；L0 近期优先。
- **学后产出：**自行实现的小模块、输入契约、至少五组手算对照及一页类型/循环跟踪。
- **独立考核：**实现记录按 ID 保留首次并统计数值的函数：[(A,4),(B,8),(A,100)] 应保留 A/B，均值 6；补空、单条、全部重复及非法数值，事先确定错误策略。
- **通过标准：**输出类型和顺序符合契约；不改输入；空输入不除零；说明别名与复制、两段循环和集合空间成本。
- **当前状态：**部分完成：累加、去重、均值及复做通过，含提示；[W01](week-01-review.md)。不代表所有语法已独立掌握。
- [ ] S02 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S02 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s03"></a>

### S03 Python 文件、异常与命令行工具

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[2026-10-07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-07)；[2026-10-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-08)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**pathlib、with、UTF-8、JSON/JSONL/CSV、字段校验、异常分类、argparse；能区分路径字符串、文本和解析对象。
- **前置与顺序：**S01–S02；L0 近期优先。
- **学后产出：**JSONL→CSV 小工具、README 与正常/坏数据/缺失文件记录；错误应定位行号。
- **独立考核：**自建十行含 ID 与数值的 JSONL，转换为带固定表头的 CSV；分别加入坏 JSON、缺字段和非数值，并测试空文件、缺失文件。
- **通过标准：**有效记录逐行一致、重复运行一致；错误类型和行号正确；不输出伪装成功的半份结果；用 with 管理文件。
- **当前状态：**部分完成：[10-07](日记/2026-10-07.md)、[10-08](日记/2026-10-08.md)有指导下实现及错误路径证据。
- [ ] S03 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S03 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s04"></a>

### S04 Python 模块、类、NumPy 与测试

- **计划出处：**[W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5)；[2026-11-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-06)；[2026-11-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-08)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**导入/模块边界、类与实例、NumPy shape/轴/广播、pytest 断言与异常测试；掌握可复用接口，不要求先学完整框架。
- **前置与顺序：**S02–S03、S06 基础；L0 客户端需要时补。
- **学后产出：**可导入的统计模块、一个配置类、NumPy 形状笔记、覆盖正常和错误输入的测试文件。
- **独立考核：**从新目录导入模块，计算二维数据每列统计；对 [[1,10],[3,30]] 给出均值 [2,20]；测试空数据、单行、列数不一致与非法值。
- **通过标准：**导入不意外执行命令；轴选择正确；测试含至少一个异常断言；解释实例属性与类、数组与列表的差别。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S04 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S04 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s05"></a>

### S05 Git、最小排错与备份恢复

- **计划出处：**[启动日](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#daily)；[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-27)；[W30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-30)；[W34](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-34)；[2026-10-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-03)；[2026-10-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-09)；[备份/使用约定](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#audit)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**status/diff/暂存/commit、分支、局部回退、traceback；排除临时/私有文件；网页 JSON 与代码备份分开验证。
- **前置与顺序：**S01；贯穿学习。
- **学后产出：**临时仓库三次有意义提交、一次故障与修复记录、干净目录恢复说明；若使用网页，另存一次备份恢复记录。
- **独立考核：**在临时仓库创建小脚本，分三次提交功能/错误/修复；只回退指定改动并从副本恢复。网页备份在隔离副本或测试浏览器中导入，避免覆盖唯一进度。
- **通过标准：**提交内容可解释；无密钥/构建产物；traceback 指到真实错误；恢复后文件内容匹配；仅“导出成功”不算恢复成功。
- **当前状态：**部分完成：[10-09](日记/2026-10-09.md)有提交与调试记录；备份完整恢复能力待确认。
- [ ] S05 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S05 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s06"></a>

### S06 统计、数据清洗与可解释图表

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-27)；其余重复出处见逐日覆盖表；[2026-10-10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-10)；[2026-10-17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-17)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**均值/中位数/最近秩分位数、样本数、失败样本、轮间波动；了解 bootstrap 区间假设与样本不足；图的单位、条件、数据来源。
- **前置与顺序：**S02–S03；性能项目分析前按需学。
- **学后产出：**标注“合成数据”的 CSV、分析脚本和分布图；附统计口径、三轮摘要与局限。
- **独立考核：**对 [1,2,3,4,100] 计算均值/中位数/最近秩 p95，并对 3 轮合成记录汇总成功数与失败数；加入空集合和离群值，对排序结果交叉核对。
- **通过标准：**上述三个统计量应为 22、3、100；空集合不伪造分位数；失败不静默删除；不把合成或轮间差异写成 GPU 优化；区间须注明算法与重采样单位。
- **当前状态：**部分完成：[10-10](日记/2026-10-10.md)完成模拟数据和分位数核对；置信区间/多轮解释待确认。
- [ ] S06 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S06 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第二组：C++ 与工具链

为系统与GPU源码阅读逐步准备，不作为L0开课的整段前置。


<a id="s07"></a>

### S07 C++ 类型、编译、函数与分离链接

- **计划出处：**[启动日](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#daily)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[2026-10-04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-04)；[2026-10-12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-12)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**main、基本类型、整除/转换/溢出边界、函数、struct、声明/定义、头文件与多源文件编译链接；开启警告。
- **前置与顺序：**S01；CUDA 源码阅读前按需学。
- **学后产出：**两个源文件和头文件组成的小统计工具、构建命令、至少五组测试与类型比较说明。
- **独立考核：**独立实现读入整数序列并输出数量、和、均值；输入 2、-3、7 时为 3、6、2；覆盖空输入、小数拒绝、超范围文本及一次故意缺失定义的链接错误。
- **通过标准：**正常构建无 -Wall/-Wextra 警告；异常输入非零退出；能区别编译/链接/运行错误；解释 5/2 与浮点除法。
- **当前状态：**部分完成：[10-12](日记/2026-10-12.md)、[10-15](日记/2026-10-15.md)、[W02](week-02-review.md)有指导与自行组织构建证据。
- [ ] S07 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S07 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s08"></a>

### S08 C++ 指针、引用、const 与容器边界

- **计划出处：**[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[2026-10-13](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-13)；[2026-10-14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-14)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**值/地址/解引用、引用与指针、const 指向/对象、vector/string、struct 与生命周期；区分空指针、悬空指针与合法对象。
- **前置与顺序：**S07。
- **学后产出：**交换与安全访问小程序、内存关系图、坏输入与空容器测试。
- **独立考核：**分别写值传递、引用和指针版本交换 3 与 9；为容器首元素提供安全接口，测试空/单元素/重复值；画调用前后对象关系。
- **通过标准：**值传递不改变调用者；其余按契约改变；空指针和空容器不解引用；能解释非空不等于有效；不通过实际悬空解引用“证明”正确。
- **当前状态：**部分完成：[10-13](日记/2026-10-13.md)、[10-14](日记/2026-10-14.md)、[W03 所有权纠错](week-03-review.md)。
- [ ] S08 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S08 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s09"></a>

### S09 对象生命周期、RAII 与智能指针

- **计划出处：**[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W13](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-13)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-10-19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-19)；[2026-10-20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-20)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**构造/析构、栈/堆、异常展开；unique_ptr/shared_ptr/weak_ptr、所有者与观察者、引用环；能给资源唯一释放责任。
- **前置与顺序：**S08。
- **学后产出：**禁止拷贝的资源包装类、正常/异常/获取失败记录、三种指针关系图与循环引用修复。
- **独立考核：**自行封装临时文件句柄，验证正常退出与主动抛异常均关闭；获取失败正确报错；构造一个双对象强引用环，再用弱回指修复。
- **通过标准：**获取成功的资源恰好释放一次；构造失败不假设该对象析构已运行；拷贝被禁止；弱观察过期可判断，无 owning 裸指针。
- **当前状态：**部分完成：[10-19](日记/2026-10-19.md)、[10-20](日记/2026-10-20.md)指导下验收通过。
- [ ] S09 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S09 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s10"></a>

### S10 深拷贝、移动语义与容器扩容

- **计划出处：**[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W13](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-13)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-10-21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-21)；[2026-10-25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-25)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**lvalue/rvalue、copy/move、noexcept、移动后有效状态与 Rule of Zero/Five 的基本取舍；不假设所有类型移动后都为空。
- **前置与顺序：**S08–S09。
- **学后产出：**小缓冲区类及复制/移动/自赋值测试、一次可重复扩容观察与对象状态说明。
- **独立考核：**为 [7,9] 构造深拷贝，修改副本不影响原件；转移到另一对象并验证你声明的 moved-from 契约；强制 vector 重新分配记录操作次数。
- **通过标准：**长度和值符合契约；自赋值安全、空对象可销毁；不依赖固定 capacity 增长倍数；解释 std::move 本身不是资源搬运实现。
- **当前状态：**部分完成：[10-21](日记/2026-10-21.md)、[10-24](日记/2026-10-24.md)有指导下拷贝/移动及空对象证据。
- [ ] S10 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S10 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s11"></a>

### S11 STL、lambda、模板与类型错误

- **计划出处：**[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[2026-10-22](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-22)；[2026-10-23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-23)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**vector/unordered_map、sort、迭代器失效、lambda/可调用对象、函数模板/推导；区分稳定排序要求与容器遍历顺序。
- **前置与顺序：**S07–S10。
- **学后产出：**排序分组和泛型过滤模块、int/double 测试、一个模板编译错误解析与迭代器反例说明。
- **独立考核：**按“延迟升序、相同值按 ID”排序并按模型分组；独立写可调用过滤器，测试整数/小数、空集合、全部命中/均不命中，并制造不支持类型的编译错误。
- **通过标准：**排序规则确定；分组不依赖 unordered_map 输出顺序；原输入变更规则明确；解释扩容后旧迭代器为何不可用；能定位实例化错误源头。
- **当前状态：**部分完成：[10-22](日记/2026-10-22.md)、[10-23](日记/2026-10-23.md)含完整示例/骨架与纠错。
- [ ] S11 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S11 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s12"></a>

### S12 CMake、gdb、sanitizer 与最小回归

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-09)；[2026-10-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-16)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**编译/链接选项、断点/step/backtrace/变量、ASan/UBSan 的覆盖边界、最小复现与回归测试；工具无报错不等于程序无缺陷。
- **前置与顺序：**S07–S11、S05。
- **学后产出：**调试构建配置、一份真实故障报告、修复前后记录、至少十组回归和环境说明。
- **独立考核：**仅在临时练习中构造一次越界或 use-after-free，分别用调试器和适用 sanitizer 定位；修复后运行正常/空/复制/移动等十组测试；保留原故障输入。
- **通过标准：**指出源码位置与根因；编译和链接均启用所需检查；修复后测试无相应报错；解释 ASan/UBSan 不能证明并发安全或捕获所有缺陷。
- **当前状态：**部分完成：[10-16](日记/2026-10-16.md)、[10-24](日记/2026-10-24.md)有指导定位与修复证据。
- [ ] S12 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S12 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第三组：系统、网络、并发与工程方法

既有成果先复习；队列、原子、容器按依赖穿插。


<a id="s13"></a>

### S13 Linux 进程、文件描述符与管道

- **计划出处：**[W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-10-26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-26)；[2026-10-27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-27)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**fork/exec/waitpid、退出码和僵尸回收；open/read/write/close、短读写/EINTR、pipe/重定向与 EOF；能对应实际 syscall。
- **前置与顺序：**S07、S09。
- **学后产出：**父子进程小程序、字节复制工具、管道消息示例及 strace 摘要；含错误路径。
- **独立考核：**父进程启动子进程并回收状态；复制含 0 字节的二进制文件；通过管道传递 17 字节并关闭不用的端；另测 exec 路径不存在、空文件。
- **通过标准：**二进制逐字节一致；正常/失败退出码分明；无遗留子进程；部分 I/O 正确推进；接收端最终看到 EOF，说明写端关闭条件。
- **当前状态：**部分完成：[10-26](日记/2026-10-26.md)、[10-27](日记/2026-10-27.md)通过；部分故障注入由助手执行。
- [ ] S13 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S13 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s14"></a>

### S14 虚拟内存、分页、mmap 与 page fault

- **计划出处：**[W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-10-28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-28)；[2026-11-01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**虚拟/物理地址、页表、映射与缺页、swap 的区别；文件映射生命周期、进程间隔离；不从虚拟地址相同推断物理共享。
- **前置与顺序：**S13、S08。
- **学后产出：**地址空间图、read/mmap 校验小工具及空文件/错误路径说明。
- **独立考核：**自建含非文本字节的文件，分别 read 和只读 mmap 计算长度与字节和；查看进程映射；为零长度文件和路径不存在设计处理。
- **通过标准：**两种方式结果相同；零长度不非法 mmap；资源释放；说明缺页可能不涉及磁盘、虚拟内存不等于 swap；不从一次运行推性能。
- **当前状态：**部分完成：[10-28](日记/2026-10-28.md)有四种输入与三条错误路径证据。
- [ ] S14 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S14 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s15"></a>

### S15 信号、阻塞调用与排错工具分工

- **计划出处：**[W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4)；[2026-10-29](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-29)；[2026-11-01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**SIGINT、退出标志、信号处理的受限操作、EINTR/SA_RESTART、EOF；strace 看系统调用，gdb 看用户态状态。
- **前置与顺序：**S13–S14。
- **学后产出：**可清理退出的循环程序、阻塞 read 调试日志、signal/restart 适用范围表。
- **独立考核：**启动只在普通代码中清理的读取程序，分别输入数据、发送 SIGINT、关闭输入得到 EOF；在支持环境比较有无 SA_RESTART，给等待设置超时兜底。
- **通过标准：**三条路径可解释；处理器不调用复杂 I/O；日志显示真实系统调用和状态；不假设所有信号都会立刻打断所有阻塞。
- **当前状态：**部分完成：[10-29](日记/2026-10-29.md)有主实验和 restart 反例；含纠错。
- [ ] S15 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S15 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s16"></a>

### S16 TCP、socket 与 epoll 基础

- **计划出处：**[W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4)；[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[2026-10-31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-31)；[2026-11-01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**TCP 字节流/连接/关闭、应用消息定界、部分 send/recv、阻塞与非阻塞、epoll 就绪含义；只需本机服务基础。
- **前置与顺序：**S13、S15。
- **学后产出：**本机 echo 小程序与两次不同长度记录、接收分块表、连接到关闭的时序图。
- **独立考核：**回环发送 b"hi" 和 b"hello socket!"；把接收缓冲设为 3 字节，循环收齐；主动关闭连接并识别 EOF；说明一次 epoll 可读通知不等于一条完整消息。
- **通过标准：**回显逐字节一致、退出正常；不假设每次 recv 固定分块；能区分 accept/recv/EOF；绑定回环，无需公网部署。
- **当前状态：**部分完成：[10-31](日记/2026-10-31.md)、[W04](week-04-review.md)有指导下实测；未证明多连接性能。
- [ ] S16 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S16 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s17"></a>

### S17 线程、mutex、atomic 与数据竞争

- **计划出处：**[W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5)；[2026-11-02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-02)；[2026-11-04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-04)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**共享地址空间、并发/并行、锁范围、join、数据竞争与未定义行为；顺序一致 atomic 入门、复合操作与 volatile 的边界。
- **前置与顺序：**S08、S13。
- **学后产出：**mutex/atomic 两版计数器、纸面交错图、20 轮正确性记录和同步选择说明。
- **独立考核：**2 线程各累加 100000 次，分别使用同一 mutex 和 atomic；每版跑 20 轮，再测 0 次；纸面解释无同步读改写可能覆盖。
- **通过标准：**每轮分别为 200000/0，均 join 后读数；不能靠无锁版“有次正确”证明安全；atomic 计数不替代队列复合操作的锁。
- **当前状态：**部分完成：[11-02](日记/2026-11-02.md)的 mutex/零次边界通过；atomic 与新独立考核未见证据。
- [ ] S17 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S17 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s18"></a>

### S18 条件变量、有界队列、停止与死锁

- **计划出处：**[W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[W32](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-32)；[2026-11-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-03)；[2026-11-07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-07)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**谓词与虚假唤醒、生产者消费者、满/空条件、shutdown/join、锁顺序；不要求无锁队列或完整线程池。
- **前置与顺序：**S17、S11；项目需要时补，不阻断 L0。
- **学后产出：**有界队列实现、接口/停止契约、固定种子压力与退出测试、锁关系图。
- **独立考核：**容量 3，2 生产者与 2 消费者处理唯一编号 0…999；明确 shutdown 后如何处理剩余数据；测试空队列等待、满队列等待、阻塞时关闭。
- **通过标准：**1000 个编号不丢不重；退出可 join；测试有超时失败机制；关闭唤醒等待者；谓词覆盖空/满/关闭，解释固定锁顺序避免的循环等待。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S18 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S18 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s19"></a>

### S19 CPU/GPU 层次、局部性、NUMA 与 SIMD/SIMT

- **计划出处：**[W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5)；[2026-11-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-05)；[2026-11-07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-07)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**cache line、顺序/跨步访问、false sharing、NUMA、CPU 向量指令和 GPU 线程执行；认识带宽/延迟，避免用术语替代证据。
- **前置与顺序：**S07、S17。
- **学后产出：**CPU/GPU 内存层次图、三种 stride 的访问计算与可选 perf 记录；注明缓存热度和权限缺口。
- **独立考核：**对 16 个连续 float32、64B cache line 的简化模型，列 stride=1/2/4 所触及的元素与缓存行；写遍历小程序验证校验和，能运行 perf 时才记录计数。
- **通过标准：**明确起始对齐与边界假设；跨步不同不误比不同工作量；能说明 false sharing 与 NUMA；perf 无权限则保留待测，不写性能结论。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S19 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S19 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s20"></a>

### S20 容器、依赖交付与运行手册

- **计划出处：**[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[2027-03-31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-31)；[2027-04-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-03)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**Docker 镜像/tag/digest、host driver 与 GPU runtime、端口/日志/健康检查、启动和重启；区分镜像可拉取与可复现运行。
- **前置与顺序：**S01、S05、S16；非 L0 强制前置。
- **学后产出：**仅 CPU 小服务的镜像/依赖清单、启动/健康检查/停止/重启说明；GPU 配置只写待验证项。
- **独立考核：**把本机返回固定 JSON 的小服务容器化，固定镜像标识，启动后核对内容，停止并重启；测试端口冲突和缺参数；无 Docker 权限先交配置并保留运行待验证。
- **通过标准：**同配置可复跑、端口不混淆、日志定位错误；镜像无密钥；运行证据缺失不勾考核；说明 GPU 容器仍依赖主机驱动。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S20 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S20 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s21"></a>

### S21 分布式与服务基础：队列、超时、取消、背压、SLO

- **计划出处：**[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W22](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-22)；[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[W32](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-32)；[2026-12-24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-24)；[2027-03-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-05)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**开放到达率/封闭并发、排队/执行、超时与取消不同、资源回收、失败重试和幂等；强一致/最终一致的基本区别、复制延迟读旧值的情景，不要求实现共识协议或搭集群。
- **前置与顺序：**S16–S18、S06。
- **学后产出：**CPU 任务队列模拟器、请求状态机、负载/拒绝/取消日志与小型容量设计。
- **独立考核：**用虚拟时间模拟单 worker 每任务 2 时间单位、等待容量 2，四请求同刻到达，明确容量是否含运行中；再取消一个等待任务并提交新任务，另设计超时后重试重复操作的反例；为“写已确认但副本尚未同步”的读取画时序，说明不同一致性承诺允许什么结果。
- **通过标准：**约定下每个 ID 有唯一状态轨迹；开始/完成/拒绝可手算；取消释放等待容量且不假定已完成任务可撤销；记录实际到达/拒绝；说明幂等键如何防重复副作用。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S21 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S21 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s22"></a>

### S22 实验方法、源码阅读与成果复现

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-05)；[2026-10-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-06)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[备份/使用约定](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#audit)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**输入契约、独立 reference、expected/actual、误差阈值、控制变量、冷/热、负结果；版本/源码锚点、最小 patch/回滚、回归与引用证据；可选公开贡献的贡献指南、license、格式检查和 issue/PR 状态。
- **前置与顺序：**S03、S05–S06；S12用于C++排错变式时补充。方法贯穿两项目，不要求先完成全部工具课。
- **学后产出：**一份非 GPU 小练习的可复现报告、原始记录、最小修复 diff、回归用例和三个自测问答；有公开贡献意向时，另列目标仓库贡献要求、检查结果和真实状态。
- **独立考核：**用自建排序/解析小工具构造可重复失败，先写预期，再定位源码符号并修复；只变一个输入条件，给反例/适用范围；隔天不看笔记回答三个问题，从干净目录复跑。
- **通过标准：**失败与通过输入保留；源码锚点含版本/路径/符号；声称的结果可追溯；无支持的数据写未知；文档修改不自动算运行通过，计时仪器不得混用。公开贡献为P1、额外投入总计不超过6h；是否提交由本人决定，未提交写本地补丁、未合并不写已合并，不为绿点凑提交。
- **当前状态：**部分完成：已有多日 expected/actual、边界、反例和失败复测；[日记索引](日记/README.md)。完整新报告/独立考核未执行。
- [ ] S22 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S22 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第四组：GPU 通用原理与张量/数学基础

只列通用知识与CPU/纸面练习；算子实现和GPU性能测量归指导项目。


<a id="s23"></a>

### S23 GPU/CUDA 执行模型与同步基础

- **计划出处：**[W06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-6)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2026-11-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-09)；[2026-11-10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-10)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**grid/block/thread/warp/SM、索引与尾部、grid-stride、SIMT/divergence、stream 顺序和同步作用域；概念算清即可，算子实现归项目。
- **前置与顺序：**S07–S08、S19；K1 前按需学。
- **学后产出：**线程索引表、执行层次图、三个同步/分支反例说明；无需交 vector add。
- **独立考核：**纸面设置 N=1003、block=128、grid=8，列有效/越界线程范围；改成 grid=2 分析 grid-stride 覆盖；判断“仅一部分线程经过 block barrier”的风险。
- **通过标准：**每个有效下标恰覆盖一次；尾部不访问越界；区分 block barrier 与整个设备同步；不能认为不同 block 默认可直接同步。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S23 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S23 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s24"></a>

### S24 GPU 存储层次与资源限制

- **计划出处：**[W06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-6)；[W08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-8)；[W09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-9)；[W10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-10)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2026-11-12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-12)；[2026-11-23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-23)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**global/shared/register、coalescing、bank conflict、warp shuffle/active mask、tiling 复用、register pressure 和 occupancy；理解约束，不追最高占用率。
- **前置与顺序：**S19、S23。
- **学后产出：**访问地址/同步范围表、带假设的 bank 映射草图和资源上界计算。
- **独立考核：**在简化模型中设 32 线程、32 banks、4B 元素且 bank=元素下标 mod 32；比较 tile[32][32] 与 tile[32][33] 的列访问；再分析不完整 warp 的掩码。
- **通过标准：**写清是假设模型而非本机测量；能指出冲突与 padding 的关系；不跨不活跃线程错误 shuffle；说明寄存器/共享内存可能限制驻留 block，occupancy 高不必然更快。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S24 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S24 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s25"></a>

### S25 GPU 计时与 Nsight 工具识读

- **计划出处：**[W06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-6)；[W08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-8)；[W09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-9)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-11-11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-11)；[2026-11-13](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-13)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**CUDA Event、异步 launch、同 stream 顺序与跨 stream Event 依赖、pinned/pageable host memory、拷贝与计算重叠的前提、预热/JIT/分配排除；nsys 时间线与 ncu 计数器/replay 的用途；权限与版本可用项。
- **前置与顺序：**S22–S24。
- **学后产出：**计时范围图、Event 正误伪代码审查、nsys/ncu 使用选择表；无须额外跑项目 profile。
- **独立考核：**审查三种描述：主机提交后立即停表、同 stream Event 并等待结束、包含首次 JIT/分配；对给定“CPU 空隙/内存流量/排队”问题选择所需证据，列实际项目待验证项。
- **通过标准：**区分提交时间、kernel 时间和服务墙钟；知道至少 20 次预热、每配置至少 100 次×3 批的原协议；profiler 运行不用作基准；无权限不伪造 metric；两个stream不自动保证重叠，需依赖关系、内存与硬件条件和timeline证据，实际overlap实验仍归E-K。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S25 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S25 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s26"></a>

### S26 算量、带宽、Roofline 与 Amdahl

- **计划出处：**[W06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-6)；[W09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-9)；[W21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-21)；[W29](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-29)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2026-11-12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-12)；[2026-12-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-03)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**FLOPs/bytes、单位 GB/GiB、算术强度、理论复用与真实 DRAM 流量；Roofline 上界和 Amdahl 端到端收益边界。
- **前置与顺序：**S19、S22–S24、S30 基础矩阵。
- **学后产出：**手算表、两张带假设的示意图和优化价值判断，不需要实现/测量 GPU 算子。
- **独立考核：**计算 FP32 数组加法每元素一次加法、两读一写的强度；对 M=2、N=4、K=3 的 GEMM 算量按 2MNK 口径计；热点占总时长 20%、局部快 2 倍时估端到端上界。
- **通过标准：**结果依次为 1/12 FLOP/B、48 FLOPs、约 1.111 倍；注明计数约定与其余部分不变；理论上界不能充当实测。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S26 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S26 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s27"></a>

### S27 Triton 语言与执行模型入门

- **计划出处：**[W10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-10)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2026-12-07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-07)；[2026-12-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-08)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**program_id、arange、mask、block/tile、JIT、BLOCK_SIZE/num_warps 与资源权衡；区别 Triton GPU 语言与同名服务产品。
- **前置与顺序：**S23–S25、S28。
- **学后产出：**program 与元素覆盖表、mask/dtype/stride 契约、JIT 与运行的时序说明；不重复 add/softmax/fused 实现。
- **独立考核：**对一维 N=10、BLOCK_SIZE=4，写三个 program 的索引和有效掩码；解释非连续输入不能默认连续；为两个 BLOCK_SIZE 提出正确性和资源检查问题。
- **通过标准：**覆盖 0…9 且不越界；正确区分 program 数量与 warp 数；知道编译在计时外；不把运行官方教程作为自己的优化成果。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S27 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S27 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s28"></a>

### S28 PyTorch/NumPy 张量、布局与广播

- **计划出处：**[W07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-7)；[W29](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-29)；[2026-11-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-16)；[2026-11-17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-17)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**shape/dtype/device、stride、索引、广播、contiguous、view/reshape 与可能的复制；能追踪维度和存储别名。
- **前置与顺序：**S02、S04；L0 近期按需补，CPU 可学。
- **学后产出：**CPU 张量练习、三种非连续输入的形状/步幅表及值核对；GPU 路径另按实际标记。
- **独立考核：**创建 shape=(2,3) 的 0…5 张量并转置；检查原/转置的 shape、stride 和展平顺序；与 shape=(3,) 向量广播相加，另测试不能广播的维度。
- **通过标准：**值与手算一致；至少三种非连续/切片情形；明确何时可能复制；不把 CPU 结果标为 GPU，错误输入不静默重排。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S28 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S28 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s29"></a>

### S29 训练与推理模式的最小区别

- **计划出处：**[W07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-7)；[2026-11-18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-18)；[2026-11-22](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-22)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**计算图、requires_grad、no_grad/inference_mode、eval/train 与 Dropout 等模块行为；不扩成模型训练课程。
- **前置与顺序：**S28；L0 近期补概念即可。
- **学后产出：**CPU 小模型的模式对照表、输出/梯度状态测试和固定随机性说明。
- **独立考核：**用含线性层和 Dropout 的极小模型，比较 train、eval、eval+no_grad 三种状态；另外观察 inference_mode 的输出张量限制，记录实际依赖版本。
- **通过标准：**指出 eval 不关闭梯度；no_grad 不自动切换模块行为；随机比较固定 seed 或多次观察，不要求 Dropout 每次必定不同；不报告 GPU 性能。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S29 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S29 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s30"></a>

### S30 矩阵运算、数值精度与稳定计算

- **计划出处：**[W08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-8)；[W09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-9)；[W10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-10)；[2026-11-23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-23)；[2026-11-30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-30)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**矩阵乘/转置/批维、GEMM 维度、softmax/RMSNorm/GELU 公式识读、浮点非结合、FP32/BF16/FP16/TF32 定位、atol/rtol。
- **前置与顺序：**S02、S04；GPU 和 attention 需要时穿插。
- **学后产出：**CPU 小矩阵计算、稳定 softmax 与误差阈值说明；至少正常/极值/坏 shape 测试，不做 GPU 算子。
- **独立考核：**手算 [[1,2],[3,4]] 乘 [[2,0],[1,2]]；对 [1000,1001] 计算稳定 softmax 并检查整体平移不变；比较不同归约顺序并解释容差。
- **通过标准：**矩阵结果 [[4,4],[10,8]]；softmax 有限、和近 1、两值比约为 e；不要求浮点逐位相等；明确 dtype 与 TF32 是不同层面的设置。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S30 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S30 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第五组：LLM 推理通用原理

L0近期先学 S33/S34 的词义和预算、S37 指标；其余随项目深入。


<a id="s31"></a>

### S31 Transformer、Attention 与 causal mask

- **计划出处：**[W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11)；[2026-12-14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-14)；[2026-12-20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-20)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**Q/K/V、缩放点积、mask、softmax、输出投影、残差/MLP 的位置和 shape；能从输入走通一个小 attention，不训练大模型。
- **前置与顺序：**S28–S30；L0 后逐步补。
- **学后产出：**一层数据流图、逐步 shape 表、CPU 小尺寸 attention reference 与因果测试。
- **独立考核：**取 B=1、S=3、H=2、Dhead=2 的自建张量，独立算 causal attention 并与可用 CPU 库对照；只修改第三个 token，检查前两个位置的输出。
- **通过标准：**公式和缩放正确；前两个位置不受未来 token 改动影响；shape 可逐项核查；参考实现不是 GPU/推理引擎优化结果。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S31 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S31 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s32"></a>

### S32 MHA/GQA/MQA 与 RoPE

- **计划出处：**[W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11)；[2026-12-15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-15)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**Q 头/KV 头共享与分组、head dimension、KV 复制/分片边界、RoPE 成对旋转与位置；注意按实际模型定义核对。
- **前置与顺序：**S31。
- **学后产出：**三种头布局表、KV 元素量对照、RoPE 的 CPU 数值小测试。
- **独立考核：**固定 Q heads=8、Dhead=4，比较 KV heads=8/2/1；给同一向量应用位置 0 的旋转与任一非零角度旋转，核查形状及每对分量平方和。
- **通过标准：**头映射合法；相同层数/长度/dtype 下 KV 比为 8:2:1；位置 0 在本旋转定义下不变、每对范数保持；不把 KV 减少等同相同比例加速。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S32 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S32 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s33"></a>

### S33 自回归、tokenizer、采样与 KV 重用

- **计划出处：**[W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11)；[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2026-12-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-16)；[2026-12-19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-19)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**token≠字符、chat template、终止条件、temperature/top-k/top-p/seed；prefill/decode、位置和缓存长度，区分 greedy 与采样。
- **前置与顺序：**S31–S32；L0 近期先补词义与输入输出。
- **学后产出：**手工三步生成时间线、CPU cache 追加示例、tokenizer/模板核查清单。
- **独立考核：**给定三步 token ID 轨迹与小 Q/K/V，逐步追加缓存并与全前缀 reference 对照；用概率 [0.6,0.3,0.1] 说明 greedy、top-k=2 与 top-p=0.8 的候选集合。
- **通过标准：**缓存只追加新位置、长度变化明确，逐步结果在容差内；候选集合的定义和重新归一化写清；固定 seed 不保证跨版本逐位一致；不实际启动模型服务。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S33 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S33 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s34"></a>

### S34 模型权重与 KV 显存预算

- **计划出处：**[W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11)；[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W13](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-13)；[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2026-12-17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-17)；[2026-12-20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-20)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**参数×字节、2×层数×总 token 数×KV 头×头维×字节；activation/workspace/图/allocator/碎片，GB/GiB；特殊架构不能套用普通 dense 公式。
- **前置与顺序：**S30、S32–S33；L0 选模型前按需补。
- **学后产出：**带公式/单位/假设的预算表与脚本；区分理论估算、实际分配和未测差额。
- **独立考核：**用纯演算配置 P=1e9、FP16，L=4、Hkv=2、D=16、B=2、S=128，求权重与 KV 字节；再把 S 加倍，并说明 TP=2 为何不能无条件把总显存除二。
- **通过标准：**权重 2,000,000,000B，KV 131,072B，S 加倍 KV 加倍；GiB 换算正确；不漏 workspace 等项；声明这不是任何真实模型的测量。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S34 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S34 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s35"></a>

### S35 请求调度、Continuous Batching 与 Chunked Prefill

- **计划出处：**[W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11)；[W16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-16)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[W32](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-32)；[2026-12-18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-18)；[2027-01-20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-20)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**并发/调度 batch/token budget、请求加入/完成、prefill/decode 强度、公平性/排队、chunked prefill 取舍；不以单一指标判断最优。
- **前置与顺序：**S21、S33、S37。
- **学后产出：**四请求虚拟时间线、每轮 token 预算表和两种调度策略的取舍说明。
- **独立考核：**设 R1/R2 在时刻0到达、R3/R4 稍后到达，输入长度分别 6/2/2/4、输出各2；自己声明单步成本与预算4的规则，分别模拟整段 prefill 与分块策略。
- **通过标准：**预算每轮不超限、已完成可离开新请求可加入；所有等待与输出时刻可复算；说明假设，不预设 chunking 必然改善全部指标；不记为服务基准。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S35 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S35 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s36"></a>

### S36 KV 分页、块表、Prefix Cache 与回收

- **计划出处：**[W16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-16)；[W20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-20)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2027-01-18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-18)；[2027-01-19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-19)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**逻辑 token/物理块、末块浪费、申请/释放/引用、前缀块命中与冷热、eviction；PagedAttention 存储管理与具体 attention kernel 区别。
- **前置与顺序：**S33–S35。
- **学后产出：**CPU 块分配模拟、三请求块表与碎片手算、共享/回收和冷/热验证表。
- **独立考核：**块大小4，三请求长度为3/5/8；先不共享计算分配和浪费，再对两个具有相同完整前缀块的请求引入共享，结束一个请求时检查引用计数与可回收块。
- **通过标准：**不共享分配20个 token 槽、浪费4；逻辑映射和共享引用一致；不能提前释放另一请求仍用块；冷热分开，命中不自动等同延迟下降。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S36 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S36 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s37"></a>

### S37 推理服务指标的离线计算

- **计划出处：**[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[2026-12-23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-23)；[2026-12-24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-24)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**TTFT/TPOT/E2E/ITL、输出吞吐、成功/拒绝/超时、观测窗口、单调墙钟；stream chunk 可能含多个 token，不能假定 chunk=token。
- **前置与顺序：**S06、S21、S33；L0→L1 近期优先。
- **学后产出：**仅离线事件的指标计算器、字段规范、0/1/多 token 与失败测试。
- **独立考核：**给 submit=0s、first=0.2s、last=0.8s、Nout=4，计算指标；另列 Nout=1/0、超时、含多 token chunk；统一窗口2s内两成功请求共输出10 token，计算输出吞吐。
- **通过标准：**TTFT=0.2s、E2E=0.8s、TPOT=0.2s/token、吞吐=5 token/s；Nout≤1 的 TPOT 为 NA；失败独列、不捏造逐 token ITL；说明客户端观察含排队/传输。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S37 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S37 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s38"></a>

### S38 vLLM 类推理引擎的系统分工与源码阅读方法

- **计划出处：**[W15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-15)；[W20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-20)；[W21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-21)；[W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23)；[W29](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-29)；[2027-01-11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-11)；[2027-01-12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-12)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**API/异步前端、跨进程消息、Engine/Scheduler/KV manager、executor/worker/runner/backend/采样/输出的职责；版本变化需核对真实源码。
- **前置与顺序：**S13、S21、S33–S36。
- **学后产出：**职责与边界概念图、源码检索检查表；实际版本的十锚点请求图留在指导项目中完成。
- **独立考核：**从空白画至少八个职责节点，标出三类进程/队列/设备边界；给“请求排队”“KV 不足”“backend 不支持”各列首先检查的日志与源码符号类型。
- **通过标准：**请求到输出的数据流闭合；概念职责不伪装特定版本调用栈；检索结果需版本/路径/符号/输入输出佐证；本考核不要求另跑一次完整引擎实验。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S38 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S38 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s39"></a>

### S39 SGLang 对比所需的通用机制（P1 深度）

- **计划出处：**[W20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-20)；[2027-02-15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-15)；[2027-02-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-16)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**TokenizerManager/Scheduler/ModelRunner 的职责、radix/prefix cache、eviction、Python/Rust 等语言边界；对比同模型/精度/负载/缓存/SLO。
- **前置与顺序：**S36、S38。
- **学后产出：**概念层架构对照、一页公平比较检查表和版本待核对项；不另启动第二服务。
- **独立考核：**对“引擎A缓存热、引擎B缓存冷；输出长度不同；各自默认参数”三项差异逐一指出混杂因素，重新设计三组代表负载的比较协议。
- **通过标准：**各负载硬件/模型/实际 token/精度/冷热/失败口径一致；默认值差异显式列出；不能断言旧源码语言边界仍成立；不写某引擎全面更快。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S39 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S39 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s40"></a>

### S40 量化原理与误差（P1 深度）

- **计划出处：**[W25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-25)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2027-03-22](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-22)；[2027-03-23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-23)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**weight-only/activation/KV dtype、scale、零点、裁剪与反量化、元数据成本；显存、质量、速度必须分开评价。
- **前置与顺序：**S30、S34。
- **学后产出：**CPU 小矩阵量化/反量化 reference、误差表和存储预算。
- **独立考核：**对 [-1,-0.5,0,0.5,1] 自选并声明对称 int8 规则，量化再恢复；另测全零、极值裁剪；比较 MSE/最大误差并计入 scale 存储。
- **通过标准：**范围/舍入/scale 定义明确；全零不除零；误差可复算；不声称 int8 必然快，不把不同模型权重的差异归为单一 kernel 优化。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S40 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S40 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s41"></a>

### S41 Speculative Decoding 的概率与开销（P1 深度）

- **计划出处：**[W25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-25)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2027-03-24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-24)；[2027-03-27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-27)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**draft/verify、接受率、拒绝后修正分布与回退、额外计算；greedy 一致性与采样分布保持不是同一论证。
- **前置与顺序：**S33、基础概率归一化。
- **学后产出：**算法流程伪代码、小离散分布的接受/拒绝手算与成本边界说明。
- **独立考核：**取目标 p=(0.6,0.4)、draft q=(0.8,0.2)，按正确的 speculative sampling 规则推两个候选的接受概率、拒绝后的残差分布和最终输出分布；再举额外开销超过节省的情形。
- **通过标准：**最终仍为目标 p；说明为何单纯总接受 draft 会偏移；概率和为1、回退有定义；不把纸面接受率当真实吞吐。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S41 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S41 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s42"></a>

### S42 MoE、Expert Parallel 与 token 路由（P1 深度）

- **计划出处：**[W25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-25)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2027-03-25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-25)；[2027-03-27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-27)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**router/top-k、专家稀疏激活、dispatch/combine、AllToAll、负载不均；top-k>1 可有合法的多专家副本。
- **前置与顺序：**S28、S31、S45 语义。
- **学后产出：**CPU token 路由/恢复小程序、路由 ID 与权重表、EP 数据流图。
- **独立考核：**对四个 token，先 top-1 分发给两个专家再恢复原顺序；扩到 top-2，令专家函数与权重均可手算，并包含一个空专家。
- **通过标准：**每个 token-expert 路由恰处理一次；top-1 不丢不重、top-2 按声明权重正确合并；最终 token 顺序恢复；不把副本误算重复错误，不训练模型。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S42 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S42 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s43"></a>

### S43 Pipeline Parallel 与 Prefill/Decode 分离（P1 深度）

- **计划出处：**[W25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-25)；[W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31)；[2027-03-26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-26)；[2027-03-27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-27)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**流水线阶段/microbatch/bubble、PD 分工、KV 传输、排队和部署成本；区分 PP/TP/EP。
- **前置与顺序：**S21、S34–S35、S48 基本概念。
- **学后产出：**流水线时间表、PD 数据路径图、带传输项的收益判断表。
- **独立考核：**在两阶段、每阶段2ms、四 microbatch、无重叠通信开销的假设下排流水线；另设每请求迁移64MiB KV、有效链路1GiB/s，算仅传输下界并判断节省20ms是否足够。
- **通过标准：**流水线时长10ms；传输下界62.5ms，单看该收益不足抵消传输；写清边界和假设；不把纸面系统设计当单卡 PD benchmark。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S43 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S43 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s44"></a>

### S44 TensorRT-LLM、Kubernetes 与 Ray 的定位（P2）

- **计划出处：**[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[2027-04-02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-02)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)。
- **需要自学：**推理 runtime/优化部署、容器资源编排、分布式 executor 的不同职责；本地多进程与集群边界；仅按目标岗位/实际需要深入。
- **前置与顺序：**S20、S38；可延后，不影响 L0。
- **学后产出：**一页职责/输入输出/运行前提对照及“何时不需要它”清单。
- **独立考核：**对“单卡本机实验”“多节点资源调度”“跨进程模型执行”“针对特定后端部署”四场景选择可能涉及的层次并说明理由，至少给一个无需 K8s/Ray 的方案。
- **通过标准：**不混淆资源调度和 token 调度；不假设 runtime 能解决所有运维问题；不用搭生产集群或新增第三引擎项目证明概念掌握。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S44 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S44 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第六组：通信与分布式推理基础

语义可以CPU自学；S49双卡、S51多节点实测另受硬件限制；P2可延后。


<a id="s45"></a>

### S45 Collective 语义：AllReduce / AllGather / ReduceScatter

- **计划出处：**[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-01-04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-04)；[2027-01-10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-10)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**rank、归约/拼接/分块、sum 语义、输入输出 shape；CPU 逻辑模拟与真实跨 GPU 通信严格区分。
- **前置与顺序：**S02、S28。
- **学后产出：**四 rank 的 CPU 语义参考、输入输出表、复合等价关系测试，显式标注模拟。
- **独立考核：**四 rank 各持长度4向量，rank r 的向量元素均为 r+1；分别实现三种 sum/拼接语义，并验证 ReduceScatter 后 AllGather 等价于 AllReduce；加入非均分长度的拒绝策略。
- **通过标准：**每 rank AllReduce 输出均为 [10,10,10,10]；scatter/gather shape 按契约；数据位置与值可手算；无 GPU 也可过语义考核，不能写 NCCL 性能。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S45 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S45 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s46"></a>

### S46 Ring/Tree 的通信成本模型

- **计划出处：**[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24)；[2027-01-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-05)；[2027-03-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-16)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**Ring 两阶段、Tree 归约/广播、α启动延迟与β秒/字节、步数与消息切分；模型上界与库自动选择不同。
- **前置与顺序：**S45、S06。
- **学后产出：**四 rank 两阶段示意、成本估算脚本与小/大消息曲线，注明理论数据。
- **独立考核：**自行声明一套 Ring 与二叉树模型，对 ranks=4、M=1KiB/1MiB、α=5μs、β=1ns/B 逐项计算启动与传输项，并改变一个参数解释排序变化。
- **通过标准：**次数/单位/切片大小一致；模型对所有字节计数自洽；说明为何理论较优不等于特定 NCCL 版本必选该算法，也不能代替实测。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S46 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S46 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s47"></a>

### S47 GPU 拓扑、P2P 与 transport

- **计划出处：**[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23)；[W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24)；[2027-01-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-06)；[2027-03-12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-12)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**PCIe/NVLink/NUMA、peer access、跨机网络与实际 transport；设备数量、拓扑图与运行日志是不同证据。
- **前置与顺序：**S19、S45。
- **学后产出：**拓扑词义图、本机只读检查清单和未知连接表；实际输出私有保存。
- **独立考核：**解析一份自己取得或明确标为样例的 topo -m 输出；列出“2卡≠必有NVLink”“同进程≠可P2P”“网络名≠实际transport”各需补什么证据。
- **通过标准：**真实与样例分开；不推断未知互连；知道 P2P 可达性需检查；能区分图中的物理路径和库选中的数据通路。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S47 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S47 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s48"></a>

### S48 Tensor Parallel 分片与通信字节

- **计划出处：**[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23)；[W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-01-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-09)；[2027-03-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-08)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**column/row parallel linear、拼接/归约、attention/MLP 通信位置、head divisibility、KV 头复制边界；tensor 字节不等于链路总流量。
- **前置与顺序：**S30–S32、S45–S47。
- **学后产出：**CPU 两分片 linear 参考、通信图、三种 token 数的消息字节表。
- **独立考核：**对 X(2×4)、W(4×6) 用确定小整数分别做列分片拼接与行分片局部和；另对 T=1/8/32、H=128、2B元素计算 T×H 消息字节。
- **通过标准：**与未分片结果一致；字节依次为256/2048/8192；分片轴/collective 位置正确；无跨设备就标语义模拟；不能盲目将 KV 容量按 TP 数平均除。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S48 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S48 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s49"></a>

### S49 nccl-tests 与真实通信验证（硬件条件化）

- **计划出处：**[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23)；[W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24)；[2027-01-07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-07)；[2027-01-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-08)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)。
- **需要自学：**commit/runtime/设备数、三 collective、消息 sweep、校验、algbw/busbw、NCCL_DEBUG/算法生效/超时；不另建浅第三仓库。
- **前置与顺序：**S45–S48；真实至少两卡才解锁运行考核。
- **学后产出：**有设备数检查的运行协议/脚本与日志字段表；借卡/租用前写单价×计划小时+存储/传输费用及总上限，不预填价格或自动购买；双卡可用后补三类 collective 原始结果、拓扑、短 trace 和分析。
- **独立考核：**在两张允许使用的 GPU 上，以8B至64MiB的受控消息范围完成三 collective 的校验与多轮测量；确认内存/时长预算，失败即记录并停止该配置；无双卡仅交协议。
- **通过标准：**准备与运行分开：单卡 -g1/CPU 模拟不能通过跨GPU考核；真实数据记录环境/版本/轮次/transport/错误；解释 algbw 与 busbw 的归一化口径，微基准不推出端到端加速。
- **当前状态：**待确认：现有记录仅单卡硬件快照，未见双卡实测；本项运行考核未开始、待双卡条件。
- [ ] S49 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S49 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s50"></a>

### S50 RDMA Verbs 基本语义（限量 P1）（P1 深度）

- **计划出处：**[W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-03-18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-18)；[2027-03-21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-21)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[原计划资料](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#resources)。
- **需要自学：**MR注册/权限、QP/CQ、Send/Recv 与 Read/Write、投递与完成、双边/单边；读 rdma-core 示例的数据路径，不开网络研究路线。
- **前置与顺序：**S16、S45、S47。
- **学后产出：**注册→投递→完成图、资源/队列职责表、一份样例代码阅读笔记；总量沿用原路线约8h概念预算。
- **独立考核：**对“发送端Send但接收端未准备接收”“向无权限MR执行Write”两个情景解释缺少的前置；区分本地完成、远端应用处理完成，并画正常交互。
- **通过标准：**注明具体操作和访问权限；双边/单边不混；不把 CQ 完成泛化为远端业务完成；无RNIC仍可考语义，无硬件性能结论。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S50 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S50 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s51"></a>

### S51 RoCE/IB/GPUDirect 与多节点前提

- **计划出处：**[W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-03-19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-19)；[2027-03-21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-21)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)。
- **需要自学：**RoCEv2、InfiniBand、PFC/ECN 概念、GPUDirect P2P 与 GDR 区别；GPU/RNIC/驱动/路由/权限/transport 一起决定可运行性。
- **前置与顺序：**S47、S50；概念 P1，真实多节点 GDR 为条件化 P2。
- **学后产出：**一页多节点前提与证据表、GDR/P2P路径图；硬件不具备时仅交语义，性能保持待测。
- **独立考核：**给“仅单卡”“同机双卡PCIe”“两机有GPU但无兼容RNIC”三情景，指出可做和不能声称的结果；若日后获专用多节点环境，另按冻结协议验证 transport 和完整日志。
- **通过标准：**能各用一句话说明 PFC/ECN；SoftRoCE 不冒充硬件卸载/GDR；不擅改共享交换机/生产网络；概念考核与多节点实测分别记录。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S51 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S51 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s52"></a>

### S52 高级库、编译层级与后端迁移的边界（P2）

- **计划出处：**[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[依赖与优先级](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#route)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)。
- **需要自学：**CUTLASS/CuTe/PTX/AI编译器的定位，框架→编译→指令的层次；Megatron/FSDP/DeepSpeed 是训练相关体系，国产后端迁移按设备/JD触发。
- **前置与顺序：**S23–S27、S38；主线稳定且真实需求明确才深入。
- **学后产出：**一页技术定位/前置/触发条件/止损表，不要求实现高级GEMM、编译器或分布式训练。
- **独立考核：**对“读GPU生成指令”“复用高级矩阵库”“移植另一后端”“理解训练分片”四情景标技术层次和最低学习范围；为当前单卡推理说明哪些可以延后。
- **通过标准：**PTX 不等于最终机器码；不把训练库当推理引擎替代；不新增光网络/拥塞控制论文路线；深入项保留选修，不作为求职或L0门槛。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S52 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S52 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第七组：算法与长期复做

按依赖自学并维护题族台账，不追加成每日项目强制项。


<a id="s53"></a>

### S53 算法：复杂度、数组与双指针

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[2026-10-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-05)；[2026-10-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-06)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**时间/额外空间、循环不变量、平均/最坏情形、数组遍历、原地压缩、排序前提和双指针排除；不以几组运行证明渐近复杂度。
- **前置与顺序：**S02；可用Python或C++，一种语言先完成。
- **学后产出：**两题实现、契约、复杂度/边界说明和一次从空白复做。
- **独立考核：**实现有序数组两数求和（返回不同下标）与稳定移动零；[1,3,5,7]目标8可返回(0,3)或(1,2)；[0,2,0,1]变为[2,1,0,0]；补空/单元素/重复值。
- **通过标准：**满足返回类型、不复用元素、不越界；移动零保持原对象/长度/非零顺序，O(n)时间O(1)额外空间；逐步解释指针为何可排除。
- **当前状态：**部分完成：[W02](week-02-review.md)、[错题记录](gpu-kernel-lab/tests/algorithm-errors.md)有多轮实现及纠错复做。
- [ ] S53 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S53 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s54"></a>

### S54 算法：哈希、计数与去重

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-18)；[W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26)；[2026-10-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-05)；[2026-10-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-06)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**set/map、首次/末次规则、两数求和先查再存、计数字典、固定字母表空间、哈希平均复杂度的前提。
- **前置与顺序：**S53、S02。
- **学后产出：**无序两数求和与异位词实现、反例及至少五组测试，不重复计旧题方法变式为新题。
- **独立考核：**[4]目标8应无解，[4,4]目标8应返回不同下标；异位词测试 "aab"/"aba" 为真、"aab"/"abb" 为假及双空串；自己设计先存后查的反例。
- **通过标准：**平均时间/最坏空间说明准确；返回契约一致、输入不变；固定26字母与任意字符集合的空间不同；能从空白重写核心。
- **当前状态：**部分完成：[10-20](日记/2026-10-20.md)、[W03](week-03-review.md)和[题目计数](gpu-kernel-lab/tests/algorithm-errors.md)有指导与复做证据。
- [ ] S54 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S54 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s55"></a>

### S55 算法：链表与栈

- **计划出处：**[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[2026-10-19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-19)；[2026-10-20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-20)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**节点/引用/原地反转、保存后继、栈LIFO、空栈返回契约、括号配对/嵌套；节点移动与链接改变不同。
- **前置与顺序：**S53。
- **学后产出：**原地链表反转及括号验证实现、对象身份/边界检查和复杂度说明。
- **独立考核：**反转 1→2→3 并检查原节点复用、尾指针为空；括号验证 "([])"为真、"([)]"/单右括号为假、空串为真；另实现忽略普通字符的变式。
- **通过标准：**空/单节点/重复值正确；链表O(n)/O(1)；括号返回bool、O(n)/O(n)；不把0当空栈；嵌套与次序均检查。
- **当前状态：**部分完成：[W04](week-04-review.md)有本人函数、导师测试及解释补充；新考核未执行。
- [ ] S55 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S55 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s56"></a>

### S56 算法：二分查找与边界不变量

- **计划出处：**[W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5)；[W15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-15)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-11-02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-02)；[2026-11-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-03)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**升序前提、闭/开区间选一种写清、命中/未命中、重复值、收缩与终止；不混用模板。
- **前置与顺序：**S53。
- **学后产出：**查找函数、八组测试、三轮纸面追踪及O(log n)/O(1)理由。
- **独立考核：**对[-3,0,4,4,9]分别查9、5、4；再测空、单元素命中/未命中、首元素与尾元素；重复值允许任一合法位置并先写契约。
- **通过标准：**不死循环、不越界、不改输入；未命中返回指定值；每步排除已知不匹配中点；复杂度来自候选减半及固定索引数量。
- **当前状态：**部分完成：[11-02](日记/2026-11-02.md)八组运行及纠错后解释通过；本人补全骨架，非闭卷完整实现。
- [ ] S56 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S56 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s57"></a>

### S57 算法：树的 DFS 与 BFS

- **计划出处：**[W06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-6)；[W07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-7)；[W15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-15)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；其余重复出处见逐日覆盖表；[2026-11-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-09)；[2026-11-10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-10)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**树节点、递归/显式栈、前中后序、层序队列、深度与栈空间；区分树与含环图。
- **前置与顺序：**S55。
- **学后产出：**DFS/BFS 两种遍历、深度函数、至少五类树测试和复杂度说明。
- **独立考核：**树 root=1、左2右3、2的左4：求前序 [1,2,4,3]、层序 [[1],[2,3],[4]]、最大深度3；补空树、单节点、退化链和不平衡树。
- **通过标准：**无漏重；访问O(n)，递归辅助空间按树高、BFS按最大宽度说明；空树深度约定0；知道深链可能触及递归限制。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S57 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S57 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s58"></a>

### S58 算法：堆与优先队列

- **计划出处：**[W08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-8)；[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-21)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-11-23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-23)；[2026-11-24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-24)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**最小/最大堆、push/pop、top-k、稳定性/相同优先级、空堆，O(log n)操作与完整排序的取舍。
- **前置与顺序：**S53–S54。
- **学后产出：**流式top-k或任务优先级小工具、重复值/空输入测试、复杂度与排序参考对照。
- **独立考核：**求 [3,1,5,5,2] 中最大的k=3个数，最终排序输出[5,5,3]；测试k=0、k>n、空输入，并写明异常/截断契约。
- **通过标准：**保留重复元素、不会空堆弹出；维护大小不超过声明上限；说明O(n log k)与额外空间，测试库排序只作独立参考。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S58 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S58 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s59"></a>

### S59 算法：图、DFS/BFS 与最短无权路径

- **计划出处：**[W10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-10)；[W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14)；[W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23)；[2026-12-07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-07)；[2026-12-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-08)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**邻接表、visited、连通分量、有向/无向、环与无权最短距离；访问集合与树遍历的区别。
- **前置与顺序：**S54–S57。
- **学后产出：**图遍历/最短路径实现、路径与距离核对、环/断连/孤点测试。
- **独立考核：**无向边(0,1),(1,2),(2,0),(2,3)，另有孤点4：求0到3最短距离2、0到4不可达；返回任一合法最短路径。
- **通过标准：**环不导致无限遍历、不可达明确；路径每条边存在且长度一致；O(V+E)理由，不能用DFS首次路径冒充最短路径。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S59 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S59 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s60"></a>

### S60 算法：滑动窗口

- **计划出处：**[W09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-9)；[W16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-16)；[W21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-21)；[2026-11-30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-30)；[2026-12-01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-01)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**固定/可变窗口、左右端维护状态、重复计数、不变量、窗口移动次数与适用前提。
- **前置与顺序：**S53–S54。
- **学后产出：**无重复最长子串实现、窗口追踪表、至少五组边界与暴力参考核对。
- **独立考核：**"abba"应为2、"abcabcbb"为3、空串0、"aaaa"为1；再设计重复字符跨左边界的输入并解释更新。
- **通过标准：**左边界不倒退；结果与小输入暴力枚举一致；平均O(n)的哈希前提写清；空间按字符集合说明，不把嵌套while直接判成平方。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S60 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S60 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s61"></a>

### S61 算法：动态规划入门与状态设计

- **计划出处：**[W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11)；[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W22](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-22)；[W25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-25)；[W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28)；[2026-12-14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-14)；[2026-12-15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-15)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**状态/转移/初值/遍历顺序、无解表示、滚动空间、最优子结构；能比较贪心失败反例。
- **前置与顺序：**S53、S57；不要求竞赛级题。
- **学后产出：**一维DP实现、状态表、至少五组测试和一次空间优化解释。
- **独立考核：**最少硬币：coins=[1,3,4]、amount=6 得2；coins=[2]、amount=3无解；amount=0得0；先写每个状态含义再自行实现。
- **通过标准：**无解契约明确、不从无效状态溢出；复杂度O(amount×币种数)及空间正确；解释贪心对6为何不是最优；拒绝零/负币值等坏输入。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S61 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S61 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s62"></a>

### S62 算法长期维护、去重与编码模拟

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-05)；[2026-10-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-06)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[依赖与优先级](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#route)。
- **需要自学：**模板→新题→复做→变式、错因/复杂度/边界、题族去重；保留超时与提示，达到能讲清而非凑题量。
- **前置与顺序：**S53–S61逐步积累；周内自主安排。
- **学后产出：**题目台账、错题与复做日期、混合编码记录；原计划80–100题为长期容量目标，不是当前新增门槛。
- **独立考核：**从已学类别中不看旧实现限时45分钟做两题；每题先口述思路再实现自测；隔日从空白复做一次，另选两道旧错题按可用时间练习。
- **通过标准：**分别记录题目/题族/方法/提示/用时/测试；未在时限内完成照实标记；11个原类别有入口，复做不增加新题；中等题30–40分钟是后续目标，非所有初学题硬门槛。
- **当前状态：**部分完成：[错题记录](gpu-kernel-lab/tests/algorithm-errors.md)已有数组/哈希/链表/栈及二分练习；全部类别和长期数量未完成。
- [ ] S62 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S62 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 第八组：非技术事项、求职、实习与毕业

按实际窗口/状态执行；材料可独立演练，真实外部结果不可由演练替代。


<a id="s63"></a>

### S63 学业约束、时间预算、日报与周复盘

- **计划出处：**[启动日](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#daily)；[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-03)；[2026-10-04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-04)；[阶段时间线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#timeline)；[硬件与减量](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#hardware)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)；[备份/使用约定](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#audit)。
- **需要自学：**课程/组会/科研/毕业材料、实际可用时间、缓冲周、暂停/恢复；本人自学汇报与项目证据分开、原预算与实际用时不相加。
- **前置与顺序：**无；持续维护，不按旧日期补课。
- **学后产出：**私有约束/未来四周日历、每日日志与周复盘、最早一个待办和恢复节点。
- **独立考核：**为“本周一场真实面试+一次组会+考试周”重排一周：总上限22h内给技术/算法/求职/复盘留位；再设计科研突占两周的6–8h保温或真实暂停方案。
- **通过标准：**不叠加超过上限；W7/W13/W18/W27缓冲可迁移；延后删等量选修不滚无限欠账；日报记录自学内容/材料/疑问与项目下一步，未知用时不填预算。
- **当前状态：**部分完成：已有[每日日记](日记/README.md)与周复盘；个人可用时段仍有未知，当前完整日历需本人确认。
- [ ] S63 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S63 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s64"></a>

### S64 岗位调研、资格核对与技能映射

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-09)；[2026-10-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-16)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[阶段时间线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#timeline)。
- **需要自学：**年份/毕业届次/实习类型、毕业范围/出勤/地点/专业；官网→官方ATS→单岗证据；样本词频与市场/录用概率不同。
- **前置与顺序：**S63；岗位窗口出现时优先。
- **学后产出：**私有岗位表，含官方来源/编号/检查日/毕业范围/出勤/技能/下一步；历史JD单独标记。
- **独立考核：**自己核查6–10条实际可访问JD，至少核对3条毕业/出勤条件；若当前没有合适在招，保留真实零结果和下次检查日；对一条标题含“2027”的岗位说明为何不能单凭标题判断。
- **通过标准：**每条状态有来源日期，未知不推断；区分校招/实习/社招参考；不沿用路线图2026-10-03快照宣称现在仍开放；样本不足不编概率或薪资。
- **当前状态：**部分完成：已有[10-23历史核查](日记/2026-10-23.md)记录；10-09缺证据和10-30跳过项保留，当前岗位表完整性待确认。
- [ ] S64 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S64 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s65"></a>

### S65 诚实简历、作品入口与可投准备度

- **计划出处：**[W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4)；[W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12)；[W17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-17)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-30)；[2026-11-01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[依赖与优先级](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#route)。
- **需要自学：**一页简历、2028毕业与真实出勤、系统/性能两种叙事、数字溯源、可复现入口、公开范围；区分学过/跟做/独立完成。
- **前置与顺序：**S22、S64及已有真实成果。
- **学后产出：**一页简历、岗位定制版、逐条证据表和readiness差距；个人资料仅私有保存。
- **独立考核：**只用已完成成果写两条简历bullet并逐项追到原始记录；制作系统/性能两个版本，检查事实一致；按原路线图10项readiness逐条评估，弱项给7日内可执行计划。
- **通过标准：**未测数字不预填、CPU模拟不写GPU优化、多卡未测不写经历；PDF一页、链接有效；8/10为原计划建议，简历/真实作品/资格出勤关键条件不能用总分替代。
- **当前状态：**部分完成：[10-30](日记/2026-10-30.md)已生成并核验私有简历v1；新项目尚无成果，后续版本/新考核未执行。
- [ ] S65 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S65 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s66"></a>

### S66 申请流程、漏斗、内推材料与反馈

- **计划出处：**[W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1)；[W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2)；[W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2026-10-09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-09)；[2026-10-16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-16)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[技能深度/招聘证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#market)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)。
- **需要自学：**有效申请/未回复/拒绝、渠道/下一步/截止日、简历匹配与面试短板；跟进和投递由本人决定执行，不因制作表格算已投递。
- **前置与顺序：**S64–S65。
- **学后产出：**私有申请台账/四周漏斗、150字自我介绍、真实渠道材料与一次策略复盘。
- **独立考核：**先用五条明确标注“虚构练习”的申请状态计算各阶段数量，再换真实台账核查；针对“几乎无面试”“多次同知识点失败”分别提出一项调整。
- **通过标准：**练习与真实申请不混；无回复不自动记拒绝；记录分母和样本局限；原计划每周复核6–10JD、优先3–5申请为容量建议，不凑数；不自动发送消息或提交申请。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S66 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S66 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s67"></a>

### S67 面试题库、技术模拟与反馈补强

- **计划出处：**[W17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-17)；[W18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-18)；[W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19)；[W33](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-33)；其余重复出处见逐日覆盖表；[2027-01-30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-30)；[2027-02-06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-06)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[依赖与优先级](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#route)。
- **需要自学：**C++/Linux/OS/Architecture/Network/GPU/CUDA/Triton/LLM/vLLM/NCCL/RDMA/Distributed/项目追问；回答须连到本人实例，按反馈只补最高频短板。
- **前置与顺序：**对应自学模块已覆盖一部分即可逐步练；S62、S65。
- **学后产出：**本人问答库、问题→回答→遗漏→改进→复查日、60分钟技术模拟及90分钟定向修补任务。
- **独立考核：**按20分钟编码/15分钟GPU或系统/20分钟项目/5分钟反馈录制一次模拟；若项目尚未开始，用已有基础成果并明确缺口；从遗漏中选三项，复查时换情境回答。
- **通过标准：**实际本人作答后才判；没做过的实验说未知并给验证方法；每题有例子和限制；真实面试替换学习预算；原W17起每1–2周模拟不要求按旧日期追赶。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S67 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S67 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s68"></a>

### S68 项目表达、系统设计、行为与中英文介绍

- **计划出处：**[W17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-17)；[W21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-21)；[W27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-27)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；其余重复出处见逐日覆盖表；[2027-01-29](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-29)；[2027-02-27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-27)；[项目通用前置与协议](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#projects)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)。
- **需要自学：**问题→证据→决策→局限，3/10/20分钟版本、最难十问；真实STAR案例、合作/失败/科研转向；两种长度英文自我介绍。
- **前置与顺序：**S22、S65、S67；项目讲稿仅使用已有证据。
- **学后产出：**三档讲稿、10问答、三个真实STAR、30秒/2分钟英文介绍与录音自查。
- **独立考核：**选一项已做基础成果，录制3分钟说明，再接受“为何这样选/失败过什么/证据在哪”追问；按单卡服务的容量约束画含OOM/取消/过载的设计图，不需运行服务。
- **通过标准：**限制与帮助程度明确；20分钟完整版含负结果；STAR区分本人行动和团队/助手工作；英文两版事实一致，姓名/岗位/时间正确；未做项目不虚构素材。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S68 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S68 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s69"></a>

### S69 团队筛选、机会状态与 Offer 比较

- **计划出处：**[W33](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-33)；[W34](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-34)；[2027-05-17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-17)；[2027-05-18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-18)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)。
- **需要自学：**mentor/review/核心任务/算力/转正节点/出勤；口头意向/书面offer/已签约/入职分开；正式条件与未知，未知填NA。
- **前置与顺序：**S63–S66。
- **学后产出：**至少8个团队问题、机会状态表、带来源与待确认项的比较/决策表。
- **独立考核：**比较两个明确标为练习的机会：A口头意向无期限、B有书面条件但出勤冲突；列需核实事项及下一步。真实机会出现后仅用实际书面信息更新。
- **通过标准：**不把口头意向记offer；比较基本工资/奖金/股权归属/城市成本须有实际信息；不代替本人接受；不根据品牌或“AI”标题推断任务质量。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S69 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S69 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s70"></a>

### S70 实习首月规划、反馈与转正证据

- **计划出处：**[W34](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-34)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-05-25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-25)；[2027-05-30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-30)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)；[阶段时间线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#timeline)。
- **需要自学：**首周确认任务/mentor/标准，2–4周小交付与baseline，5–8周跟进瓶颈/评审；每两周对齐，贡献清单/答辩/披露边界。
- **前置与顺序：**真实入职后执行；S63、S68–S69。
- **学后产出：**30天草案、交付/评审/反馈日志、贡献证据索引与转正节点表，按团队实际需求修订。
- **独立考核：**先用一个小型维护任务做计划演练：写明确验收人、输入输出、失败/回滚、评审节点；入职后用真实任务复现完整一轮，内部代码数据不公开。
- **通过标准：**计划演练与真实交付分开；只有团队评审/导师反馈/真实状态支持完成；实习期课外转4–6h/周维护；口头转正意向不替代书面结果。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S70 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S70 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s71"></a>

### S71 未获实习分支、提前批与秋招维护

- **计划出处：**[W33](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-33)；[W34](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-34)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-05-21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-21)；[2027-05-25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-25)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)；[算法与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#career)；[阶段时间线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#timeline)。
- **需要自学：**继续日常/暑期与C++/GPU平台覆盖、两周漏斗复核；2028届资格监控、实习未定保持外部机会、真实面试24h内复盘。
- **前置与顺序：**S64–S69；按真实结果选择分支。
- **学后产出：**未来两周分支计划、官方入口检查表、秋招简历框架和反馈短板清单。
- **独立考核：**分别为“有实习/待定/未获”编两周安排，标明每项日期/产出/上限；为提前批建立每周人工核查步骤；未公告写待公告，不预填准确开招日。
- **通过标准：**无实习分支不新建第三浅项目；原22h模板可为岗位6/短板6/核心项目6/算法复盘4，项目6h是既有指导任务不是新增自学；实习/回校/论文忙分别降载；不写虚假经历。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S71 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S71 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


<a id="s72"></a>

### S72 毕业、入职材料与长期保温

- **计划出处：**[W27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-27)；[W34](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-34)；[W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35)；[2027-04-08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-08)；[2027-05-28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-28)；[实习至毕业](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#later)；[阶段时间线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#timeline)。
- **需要自学：**论文/送审/答辩/离校的真实校历、导师协调、毕业证学位证时点、入职材料/签约期限的实际文件核对；延期重新查资格。
- **前置与顺序：**S63、S69–S71；月度维护，毕业优先。
- **学后产出：**私有毕业/入职节点表、负责人/证据/待确认清单、每周3–5h保温安排；无offer保持补录检查入口。
- **独立考核：**从学校/导师真实通知提取三个关键节点，与一份实际或明确标注练习的入职要求作冲突检查；为日期未知或可能延期写核查与重排步骤。
- **通过标准：**每个节点有来源/日期/负责人或明确未知；不把默认2028上半年当真实毕业日；签约/解约条件只核对实际文件不自行推法律结论；保温不挤占毕业交付。
- **当前状态：**待确认：仓库未见该主题完整学习记录，课下进度待本人汇报。
- [ ] S72 产出达到上述最低标准（完成后补实际日期/链接）。
- [ ] S72 独立考核通过（完成后补环境/输入/输出或推导/帮助程度）。


## 覆盖对照与排除说明

### 覆盖口径

已从HTML正文核对 **247个逐日主任务、245个P1扩展、35周介绍与其算法主题、每日固定项、A–E阶段、F/F′/G/H后续阶段及非逐日专题**。下面逐日行用于来源追踪，不是要求按247天再学一遍。日期标识只定位原任务，实际自学日期由本人汇报决定。

“主任务处置”中的S编号表示保留其通用知识或非项目工作；E-K/E-L表示该日另有核心项目内部任务，不在自学清单重复交付。同一行同时出现S与E，表示已拆分处理，而非整天删除。固定项和P1各自列出，不能因主任务属于项目便将其算法或求职项漏掉。

### 明确排除的内容

| 编号 | 排除范围 | 理由与保留去向 |
| --- | --- | --- |
| E-K | CUDA add/grid-stride/reduction/warp版/transpose/naive与tiled matmul的GPU实现、调参与实测；Triton add/softmax/fused与可选matmul；kernel bench/Event实际测量/nsys/ncu profile、pinned memory+双stream overlap、热点接入、项目验收与release | 均由GPU算子实验指导推进；通用执行/存储/计时/算量/Triton/张量原理保留S22–S30，表达保留S68。CPU小参考只用于基础理解，不替代项目正确性或性能验收。 |
| E-L | 模型下载/首次真实生成/服务启动；真实流式客户端与固定负载基线；vLLM冻结源码完整十锚点/请求trace；KV/prefix/chunked/OOM/admission调优；SGLang启动/实测比较；受控A/B、模型量化实测、TP1/TP2应用性能、观测/取消/容器运行手册接入、核心项目修复/端到端集成与release | 均由LLM推理性能实验指导推进；版本/统计/服务工程保留S01/S06/S20–S22；机制与离线计算保留S31–S43；基础通信和独立通信微基准保留S45–S51。真实模型性能不再包装成另一份自学作业。 |
| E-D | CUTLASS/CuTe/PTX/AI Compiler深挖、TensorRT-LLM第三引擎项目、Megatron/FSDP/DeepSpeed训练体系深挖、光网络支线、网络论文与复杂拥塞控制/DCQCN、超量博客、多引擎/多模型全矩阵 | 原计划已列延后/可砍或未安排为常规学习任务；角色定位及触发条件保留S44/S52，RDMA/RoCE必要概念保留S50–S51。条件变化再定具体范围，不杜撰一门新课。 |
| E-U | 路线图网页开发/布局/浏览器46项QA、109页打印等产品验收工作 | 属于计划制品的实现/审核记录，不是学习者必修；实际使用、JSON进度备份/恢复与状态口径保留S05/S63。 |
| E-T | 旧日历日期硬约束、自动补基础欠账、每日强制旧算法/P1/岗位核查、默认开招日或毕业日期 | 当前分工已取消机械排课；知识与方法仍覆盖，实际时间/资格按S63/S64/S71/S72核对。 |

NCCL语义、双卡微基准协议、RDMA接口等没有因为“设备不足”被删除：S49真实双卡运行、S51真实多节点验证须满足条件后再考，不能用模拟勾选实测。通信独立第三仓库不是当前必做产出；真实双卡证据不足时保留现有附录。

### A–H阶段与全局专题

| 原计划区域 | 清单去向 |
| --- | --- |
| A：启动、W01–W05 编程/系统基础 | S01–S19、S53–S56、S63–S65；保留既有证据，队列/atomic等未验证不补算通过 |
| B：W06–W10 GPU/Triton/PyTorch | S23–S30与算法S57–S60；实际算子/测量见E-K；缓冲/科研S63 |
| C：W11–W17 推理/通信/求职准备 | S31–S39、S45–S49、S61–S68；真实引擎/缓存实验见E-L |
| D：W18–W27 对比/归因/分布式/稳定性/申请 | S06/S20–S22/S26/S39–S51、算法与S63–S69；实际性能闭环见E-L/E-K |
| E：W28–W35 补强/表达/机会/切换 | S05/S09–S18/S21–S22/S62–S72；项目联动/回归/release见E-K/E-L |
| F：真实实习与转正；F′：未获实习 | S63/S66–S71；实习4–6h课外、未实习22h模板含既有指导项目；企业内部交付按真实权限 |
| G：提前批与秋招 | S64–S69/S71：官方资格、书面状态/截止日、每次面试复盘、实际预算 |
| H：毕业/补录/入职 | S63/S69/S72：校历、材料、毕业风险、技术保温；不按计划窗口虚构真实节点 |
| 执行仪表盘/路线优先级/资源与减量/浏览器使用 | S01/S05/S22/S44/S49–S52/S63：22h总预算、硬件证据、止损/暂停/恢复；网页开发见E-U |
| 招聘样本、41技能、15家公司入口 | S64核查范围与历史边界；技术映射见下表。公司入口仅作待复核目录，不在此声称仍在招 |
| 所有性能实验通用协议/权重与KV公式/源码阅读/成果表达 | S06/S22/S25–S26/S34/S37–S39/S48–S49/S65/S68；实际项目测量和版本化源码闭环见E-K/E-L |
| 资料区/阅读方法 | S01–S04/S07–S12/S13–S15/S23–S29/S31–S39/S45–S51；沿用原资料锚点，按主题查阅，不通读叠加全书 |
| 审核/隐私/不造数/进度备份 | S05/S22/S63/S65/S69–S72；发布QA不是学生考核 |

### 招聘技能表41项逐一映射

| 原技能 | 自学基础去向 | 项目边界 |
| --- | --- | --- |
| C++ | [S07](#s07)、[S08](#s08)、[S09](#s09)、[S10](#s10)、[S11](#s11)、[S12](#s12)、[S17](#s17)、[S18](#s18) | 保留通用学习 |
| Python | [S02](#s02)、[S03](#s03)、[S04](#s04)、[S06](#s06) | 保留通用学习 |
| Linux | [S13](#s13)、[S14](#s14)、[S15](#s15)、[S16](#s16) | 保留通用学习 |
| Operating System | [S13](#s13)、[S14](#s14)、[S15](#s15)、[S17](#s17)、[S18](#s18) | 保留通用学习 |
| Computer Architecture | [S19](#s19)、[S24](#s24)、[S26](#s26) | 保留通用学习 |
| Computer Network | [S16](#s16)、[S21](#s21)、[S50](#s50)、[S51](#s51) | 保留通用学习 |
| CUDA | [S23](#s23)、[S24](#s24)、[S25](#s25)、[S26](#s26) | E-K |
| Triton | [S27](#s27)、[S30](#s30) | E-K |
| CUTLASS | [S52](#s52) | E-D深入 |
| CuTe | [S52](#s52) | E-D深入 |
| PTX | [S52](#s52) | E-D深入 |
| Nsight Systems | [S25](#s25) | E-K/E-L实际profile |
| Nsight Compute | [S24](#s24)、[S25](#s25)、[S26](#s26) | E-K/E-L实际profile |
| PyTorch | [S28](#s28)、[S29](#s29)、[S30](#s30) | 项目reference不重复 |
| Transformer | [S31](#s31)、[S32](#s32) | 保留通用学习 |
| Attention | [S30](#s30)、[S31](#s31)、[S32](#s32) | 保留通用学习 |
| KV Cache | [S33](#s33)、[S34](#s34)、[S36](#s36) | E-L真实服务 |
| PagedAttention | [S36](#s36) | E-L源码/实测 |
| Continuous Batching | [S35](#s35) | E-L实测 |
| Prefix Caching | [S36](#s36)、[S39](#s39) | E-L实测 |
| Chunked Prefill | [S35](#s35) | E-L实测 |
| Speculative Decoding | [S41](#s41) | 实际引擎扩展仍选做 |
| Quantization | [S40](#s40) | E-L模型实测 |
| vLLM | [S38](#s38) | E-L完整源码/服务闭环 |
| SGLang | [S39](#s39) | E-L启动/源码与公平实测 |
| TensorRT-LLM | [S44](#s44) | E-D第三引擎项目 |
| Tensor Parallel | [S48](#s48) | E-L应用TP1/TP2；S49独立通信 |
| Pipeline Parallel | [S43](#s43) | 保留通用学习 |
| Expert Parallel | [S42](#s42) | 保留通用学习 |
| NCCL | [S45](#s45)、[S46](#s46)、[S47](#s47)、[S49](#s49) | 真实微基准条件化 |
| RDMA | [S50](#s50)、[S51](#s51) | 真实硬件条件化 |
| RoCE | [S51](#s51) | 不扩拥塞控制路线 |
| InfiniBand | [S47](#s47)、[S51](#s51) | 保留通用学习 |
| GPUDirect RDMA | [S51](#s51) | 多节点P2条件化 |
| Distributed Systems | [S21](#s21)、[S43](#s43)、[S48](#s48) | 保留通用学习 |
| Scheduler | [S18](#s18)、[S21](#s21)、[S35](#s35)、[S36](#s36) | E-L引擎具体实现 |
| Serving | [S20](#s20)、[S21](#s21)、[S22](#s22)、[S37](#s37) | E-L真实模型服务 |
| PD Disaggregation | [S43](#s43) | E-L应用实测 |
| MoE | [S42](#s42) | 保留通用学习 |
| Kubernetes | [S44](#s44) | P2定位，无生产集群 |
| Ray | [S44](#s44) | P2定位，无生产集群 |


### 全部固定项与P1的合并规则

下列R/X为来源分类编号，不是新的优先级。每个逐日行都指明对应分类；缓冲项和选做项继续允许按原条件休息/不做，不升级为每日强制考核。

| 编号 | 原固定项或P1内容 | 合并去向与限制 |
| --- | --- | --- |
| R0 | 两个启动日无额外固定练习 | 不补造 |
| R1 | 周一模板/周二新题/周三复做/周四变式，约20分钟，代码/复杂度/边界 | 当周算法主题对应S53–S61 + S62；是自主安排方法，不与项目预算重复加时 |
| R2 | 周五岗位/资格与下一步；W19起与本日求职合并 | S64/S66；不重复计时 |
| R3 | 周六记录原始结果和下一步；模拟面试已含总时长 | S22/S63；面试另见S67，不重复计时 |
| R4 | 周日错题复做/周复盘，题目去重和复做分账 | S62/S63；原40分钟是预算，不是运行证明或最低用时 |
| R5 | W07/W13/W18/W27缓冲：只复做一题、保留投递信息检查、课程科研优先 | S62/S63/S64；不照常添加全部新题/机制 |
| X0 | 两个启动日无P1 | 不补造 |
| X1 | 给当天结果补一个边界，非代码则核验来源与日期 | S22 + 当天主题；如果是项目输入边界则在E-K/E-L内做，不另开实验 |
| X2 | 三个自测问答，次日不看笔记回答，记录遗漏 | S22 + 当天主题；不靠助手代答通过 |
| X3 | 从空文件复做当周一题，复杂度与两个边界 | S62 + 当周算法主题，旧题不再计新题 |
| X4 | 一个反例/限制条件并说明适用范围 | S22 + 当天主题，不扩新主题 |
| X5 | 修复本周最早一个失败验收，保留失败/通过证据 | S12/S22；原失败无对象时保持待验证，不捏造；项目故障仍在对应项目 |
| X6 | 周六只扩一个输入/shape/配置，先写预期再记实际/局限 | S22 + 当天主题；GPU/引擎配置由E-K/E-L承担，无硬件只完善待测协议 |
| X7 | 周日复做两道旧错题，学业/面试冲突可不做，完成后休息 | S62；与同次固定复做去重，不叠加计题/用时 |
| X8 | 缓冲周仅有余力复核一份旧产出，无欠账休息，不新增长实验 | S22/S63；原工作日0.25h、周末1h是选修上限，不自动加课 |

### 35周专题与算法主题

| 原周次与日期范围 | 原专题 | 自学主任务/概念 | 算法主题去向 |
| --- | --- | --- | --- |
| [W01](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-1) 2026-10-05～2026-10-11 | W01 Python 与实验工具起步 | [S01](#s01)、[S02](#s02)、[S03](#s03)、[S05](#s05)、[S06](#s06)、[S54](#s54)、[S62](#s62)、[S63](#s63) | 数组与哈希 → [S53](#s53)、[S54](#s54) / [S62](#s62) |
| [W02](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-2) 2026-10-12～2026-10-18 | W02 C++ 能写、能编译、能调试 | [S03](#s03)、[S06](#s06)、[S07](#s07)、[S08](#s08)、[S12](#s12)、[S53](#s53)、[S62](#s62)、[S63](#s63) | 数组与双指针 → [S53](#s53) / [S62](#s62) |
| [W03](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-3) 2026-10-19～2026-10-25 | W03 C++ 生命周期与标准库 | [S09](#s09)、[S10](#s10)、[S11](#s11)、[S12](#s12)、[S62](#s62)、[S63](#s63) | 哈希与链表 → [S54](#s54)、[S55](#s55) / [S62](#s62) |
| [W04](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-4) 2026-10-26～2026-11-01 | W04 Linux、进程与第一版简历 | [S13](#s13)、[S14](#s14)、[S15](#s15)、[S16](#s16)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S65](#s65) | 链表与栈 → [S55](#s55) / [S62](#s62) |
| [W05](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-5) 2026-11-02～2026-11-08 | W05 并发、体系结构与 Python 过渡 | [S01](#s01)、[S04](#s04)、[S17](#s17)、[S18](#s18)、[S19](#s19)、[S62](#s62)、[S63](#s63) | 二分查找 → [S56](#s56) / [S62](#s62) |
| [W06](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-6) 2026-11-09～2026-11-15 | W06 第一支 CUDA Kernel 与可靠计时 | [S22](#s22)、[S23](#s23)、[S24](#s24)、[S25](#s25)、[S26](#s26)、[S62](#s62)、[S63](#s63) | 树与 DFS → [S57](#s57) / [S62](#s62) |
| [W07](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-7) 2026-11-16～2026-11-22 | W07 课程缓冲与 PyTorch 基础 | [S01](#s01)、[S12](#s12)、[S22](#s22)、[S28](#s28)、[S29](#s29)、[S62](#s62)、[S63](#s63) | 树与 BFS → [S57](#s57) / [S62](#s62) |
| [W08](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-8) 2026-11-23～2026-11-29 | W08 CUDA Reduction 与访存诊断 | [S22](#s22)、[S24](#s24)、[S25](#s25)、[S30](#s30)、[S62](#s62)、[S63](#s63) | 堆与优先队列 → [S58](#s58) / [S62](#s62) |
| [W09](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-9) 2026-11-30～2026-12-06 | W09 CUDA Matmul 与 Roofline | [S22](#s22)、[S24](#s24)、[S25](#s25)、[S26](#s26)、[S30](#s30)、[S62](#s62)、[S63](#s63) | 滑动窗口 → [S60](#s60) / [S62](#s62) |
| [W10](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-10) 2026-12-07～2026-12-13 | W10 Triton 从迁移到融合 | [S22](#s22)、[S24](#s24)、[S25](#s25)、[S27](#s27)、[S30](#s30)、[S62](#s62)、[S63](#s63) | 图与 DFS/BFS → [S59](#s59) / [S62](#s62) |
| [W11](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-11) 2026-12-14～2026-12-20 | W11 LLM Inference 前置闭环 | [S31](#s31)、[S32](#s32)、[S33](#s33)、[S34](#s34)、[S35](#s35)、[S62](#s62)、[S63](#s63) | 动态规划入门 → [S61](#s61) / [S62](#s62) |
| [W12](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-12) 2026-12-21～2026-12-27 | W12 单卡 vLLM Serving 与项目雏形 | [S01](#s01)、[S06](#s06)、[S16](#s16)、[S21](#s21)、[S22](#s22)、[S25](#s25)、[S33](#s33)、[S34](#s34)、[S37](#s37)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S65](#s65) | DP 与复习 → [S61](#s61)、[S62](#s62) / [S62](#s62) |
| [W13](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-13) 2026-12-28～2027-01-03 | W13 年末考试缓冲与实验整理 | [S06](#s06)、[S09](#s09)、[S10](#s10)、[S22](#s22)、[S34](#s34)、[S62](#s62)、[S63](#s63)、[S64](#s64) | 错题回访 → [S62](#s62) / [S62](#s62) |
| [W14](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-14) 2027-01-04～2027-01-10 | W14 NCCL 基础与通信实验设计 | [S45](#s45)、[S46](#s46)、[S47](#s47)、[S48](#s48)、[S49](#s49)、[S62](#s62)、[S63](#s63) | 堆与图复习 → [S58](#s58)、[S59](#s59) / [S62](#s62) |
| [W15](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-15) 2027-01-11～2027-01-17 | W15 vLLM 请求生命周期与 V1 源码 | [S38](#s38)、[S62](#s62)、[S63](#s63) | 二分与树复习 → [S56](#s56)、[S57](#s57) / [S62](#s62) |
| [W16](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-16) 2027-01-18～2027-01-24 | W16 KV 管理与调度机制实验 | [S35](#s35)、[S36](#s36)、[S62](#s62)、[S63](#s63) | 滑动窗口复习 → [S60](#s60) / [S62](#s62) |
| [W17](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-17) 2027-01-25～2027-01-31 | W17 主项目 v1 与可求职 70% 验收 | [S06](#s06)、[S22](#s22)、[S25](#s25)、[S62](#s62)、[S63](#s63)、[S65](#s65)、[S66](#s66)、[S67](#s67)、[S68](#s68) | 混合题 → [S62](#s62) / [S62](#s62) |
| [W18](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-18) 2027-02-01～2027-02-07 | W18 春节/科研机动周与投递保温 | [S22](#s22)、[S54](#s54)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S65](#s65)、[S66](#s66)、[S67](#s67) | 错题回访 → [S62](#s62) / [S62](#s62) |
| [W19](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-19) 2027-02-08～2027-02-14 | W19 暑期实习申请进入周循环 | [S06](#s06)、[S09](#s09)、[S10](#s10)、[S11](#s11)、[S13](#s13)、[S14](#s14)、[S16](#s16)、[S18](#s18)、[S37](#s37)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S65](#s65)、[S66](#s66)、[S67](#s67) | 链表与二分 → [S55](#s55)、[S56](#s56) / [S62](#s62) |
| [W20](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-20) 2027-02-15～2027-02-21 | W20 SGLang 对比周 | [S06](#s06)、[S36](#s36)、[S38](#s38)、[S39](#s39)、[S62](#s62)、[S63](#s63)、[S66](#s66) | 树与 BFS → [S57](#s57) / [S62](#s62) |
| [W21](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-21) 2027-02-22～2027-02-28 | W21 推理 Profiler 与性能归因 | [S22](#s22)、[S25](#s25)、[S26](#s26)、[S38](#s38)、[S62](#s62)、[S63](#s63)、[S66](#s66)、[S67](#s67)、[S68](#s68) | 堆与滑动窗口 → [S58](#s58)、[S60](#s60) / [S62](#s62) |
| [W22](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-22) 2027-03-01～2027-03-07 | W22 受控参数优化与复测 | [S06](#s06)、[S21](#s21)、[S22](#s22)、[S62](#s62)、[S63](#s63)、[S65](#s65)、[S66](#s66) | DP 复习 → [S61](#s61) / [S62](#s62) |
| [W23](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-23) 2027-03-08～2027-03-14 | W23 Tensor Parallel 与单卡替代路径 | [S01](#s01)、[S38](#s38)、[S47](#s47)、[S48](#s48)、[S49](#s49)、[S62](#s62)、[S63](#s63)、[S66](#s66)、[S67](#s67) | 图复习 → [S59](#s59) / [S62](#s62) |
| [W24](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-24) 2027-03-15～2027-03-21 | W24 NCCL 差异化与 RDMA 边界 | [S46](#s46)、[S47](#s47)、[S48](#s48)、[S49](#s49)、[S50](#s50)、[S51](#s51)、[S62](#s62)、[S63](#s63)、[S65](#s65)、[S66](#s66) | 混合题 → [S62](#s62) / [S62](#s62) |
| [W25](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-25) 2027-03-22～2027-03-28 | W25 量化、MoE、EP 与投机解码取舍 | [S40](#s40)、[S41](#s41)、[S42](#s42)、[S43](#s43)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S67](#s67) | DP 与树 → [S61](#s61)、[S57](#s57) / [S62](#s62) |
| [W26](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-26) 2027-03-29～2027-04-04 | W26 Serving 稳定性与基础设施保底 | [S20](#s20)、[S21](#s21)、[S34](#s34)、[S37](#s37)、[S44](#s44)、[S62](#s62)、[S63](#s63)、[S66](#s66) | 数组/哈希混合 → [S53](#s53)、[S54](#s54) / [S62](#s62) |
| [W27](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-27) 2027-04-05～2027-04-11 | W27 春季科研与面试缓冲 | [S05](#s05)、[S06](#s06)、[S22](#s22)、[S62](#s62)、[S63](#s63)、[S66](#s66)、[S67](#s67)、[S68](#s68)、[S72](#s72) | 错题回访 → [S62](#s62) / [S62](#s62) |
| [W28](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-28) 2027-04-12～2027-04-18 | W28 按面试反馈补系统基础 | [S09](#s09)、[S10](#s10)、[S13](#s13)、[S14](#s14)、[S18](#s18)、[S56](#s56)、[S57](#s57)、[S58](#s58)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S66](#s66)、[S67](#s67)、[S68](#s68) | DP 混合 → [S61](#s61) / [S62](#s62) |
| [W29](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-29) 2027-04-19～2027-04-25 | W29 两个主项目的连接与升级 | [S22](#s22)、[S25](#s25)、[S26](#s26)、[S28](#s28)、[S38](#s38)、[S62](#s62)、[S63](#s63)、[S66](#s66)、[S67](#s67)、[S68](#s68) | 混合题 → [S62](#s62) / [S62](#s62) |
| [W30](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-30) 2027-04-26～2027-05-02 | W30 复现性修复与有限开源窗口 | [S05](#s05)、[S12](#s12)、[S22](#s22)、[S62](#s62)、[S63](#s63)、[S65](#s65)、[S66](#s66) | 错题与混合 → [S62](#s62) / [S62](#s62) |
| [W31](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-31) 2027-05-03～2027-05-09 | W31 暑期机会收敛与单点补强 | [S23](#s23)、[S24](#s24)、[S33](#s33)、[S34](#s34)、[S35](#s35)、[S36](#s36)、[S40](#s40)、[S41](#s41)、[S42](#s42)、[S43](#s43)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S66](#s66)、[S67](#s67) | 综合题 → [S62](#s62) / [S62](#s62) |
| [W32](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-32) 2027-05-10～2027-05-16 | W32 终面表达与工程取舍 | [S18](#s18)、[S21](#s21)、[S22](#s22)、[S35](#s35)、[S62](#s62)、[S63](#s63)、[S66](#s66)、[S67](#s67)、[S68](#s68) | 混合题 → [S62](#s62) / [S62](#s62) |
| [W33](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-33) 2027-05-17～2027-05-23 | W33 Offer 评估与实习质量筛选 | [S62](#s62)、[S63](#s63)、[S64](#s64)、[S66](#s66)、[S67](#s67)、[S69](#s69)、[S71](#s71) | 错题回访 → [S62](#s62) / [S62](#s62) |
| [W34](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-34) 2027-05-24～2027-05-30 | W34 暑期结果与秋招前置 | [S05](#s05)、[S22](#s22)、[S62](#s62)、[S63](#s63)、[S65](#s65)、[S66](#s66)、[S69](#s69)、[S70](#s70)、[S71](#s71)、[S72](#s72) | 混合题 → [S62](#s62) / [S62](#s62) |
| [W35](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#week-35) 2027-05-31～2027-06-06 | W35 实习交接 / 未获实习继续推进 | [S25](#s25)、[S26](#s26)、[S27](#s27)、[S45](#s45)、[S48](#s48)、[S50](#s50)、[S51](#s51)、[S62](#s62)、[S63](#s63)、[S64](#s64)、[S65](#s65)、[S68](#s68)、[S70](#s70)、[S71](#s71)、[S72](#s72) | 错题回访 → [S62](#s62) / [S62](#s62) |


原算法数量梯度也保留为长期规划参考：W1–5约10–15题，W6–10累计22–30，W11–17累计40–55，W18–27累计65–85，W35目标80–100去重题；初期基础编码与方法变式按原台账口径，不伪装平台刷题或独立掌握。面试题库原W8起每周约3题、W17起每1–2周模拟，已并入S67；实际按本人时间和反馈调整。

### 247日逐项追踪（包含固定项和245个扩展项）

<details>
<summary>展开逐日来源与处置；供查漏，不作为每日排课表</summary>



#### 启动日 · 原阶段 A

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-10-03 资源与毕业底线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-03) | [S01](#s01)、[S05](#s05)、[S63](#s63) | R0 → — | X0 → — |
| [2026-10-04 创建工作区与基线自测](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-04) | [S01](#s01)、[S07](#s07)、[S63](#s63) | R0 → — | X0 → — |



#### W01 · 原阶段 A

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-10-05 变量与控制流](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-05) | [S02](#s02) | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2026-10-06 函数与容器](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-06) | [S02](#s02)、[S54](#s54) | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2026-10-07 文件与异常](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-07) | [S03](#s03) | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X3 → [S62](#s62)、[S53](#s53)、[S54](#s54) |
| [2026-10-08 命令行与环境](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-08) | [S01](#s01)、[S03](#s03) | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2026-10-09 Git 与调试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-09) | [S05](#s05) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2026-10-10 最小分析闭环](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-10) | [S06](#s06) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2026-10-11 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-11) | [S02](#s02)、[S03](#s03)、[S05](#s05)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W02 · 原阶段 A

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-10-12 类型与编译](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-12) | [S07](#s07) | R1 → [S53](#s53)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2026-10-13 指针与引用](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-13) | [S08](#s08) | R1 → [S53](#s53)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2026-10-14 数组与字符串](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-14) | [S08](#s08) | R1 → [S53](#s53)、[S62](#s62) | X3 → [S62](#s62)、[S53](#s53) |
| [2026-10-15 函数与结构体](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-15) | [S07](#s07)、[S08](#s08) | R1 → [S53](#s53)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2026-10-16 gdb 入门](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-16) | [S12](#s12) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2026-10-17 Python/C++ 对照](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-17) | [S03](#s03)、[S06](#s06)、[S07](#s07) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2026-10-18 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-18) | [S07](#s07)、[S53](#s53)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W03 · 原阶段 A

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-10-19 对象生命周期](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-19) | [S09](#s09) | R1 → [S54](#s54)、[S55](#s55)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2026-10-20 智能指针](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-20) | [S09](#s09) | R1 → [S54](#s54)、[S55](#s55)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2026-10-21 移动语义](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-21) | [S10](#s10) | R1 → [S54](#s54)、[S55](#s55)、[S62](#s62) | X3 → [S62](#s62)、[S54](#s54)、[S55](#s55) |
| [2026-10-22 STL 与 lambda](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-22) | [S11](#s11) | R1 → [S54](#s54)、[S55](#s55)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2026-10-23 template 基础](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-23) | [S11](#s11) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2026-10-24 内存错误检查](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-24) | [S12](#s12) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2026-10-25 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-25) | [S09](#s09)、[S10](#s10)、[S11](#s11)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W04 · 原阶段 A

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-10-26 进程与 syscall](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-26) | [S13](#s13) | R1 → [S55](#s55)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2026-10-27 文件描述符](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-27) | [S13](#s13) | R1 → [S55](#s55)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2026-10-28 虚拟内存](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-28) | [S14](#s14) | R1 → [S55](#s55)、[S62](#s62) | X3 → [S62](#s62)、[S55](#s55) |
| [2026-10-29 signal 与调试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-29) | [S15](#s15) | R1 → [S55](#s55)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2026-10-30 简历 v1](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-30) | [S64](#s64)、[S65](#s65) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2026-10-31 最小 socket 实验](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-10-31) | [S16](#s16) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2026-11-01 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-01) | [S13](#s13)、[S14](#s14)、[S15](#s15)、[S16](#s16)、[S65](#s65)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W05 · 原阶段 A

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-11-02 thread 与 mutex](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-02) | [S17](#s17) | R1 → [S56](#s56)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2026-11-03 condition variable](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-03) | [S18](#s18) | R1 → [S56](#s56)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2026-11-04 atomic](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-04) | [S17](#s17) | R1 → [S56](#s56)、[S62](#s62) | X3 → [S62](#s62)、[S56](#s56) |
| [2026-11-05 cache 与 NUMA](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-05) | [S19](#s19) | R1 → [S56](#s56)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2026-11-06 Python 工程补强](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-06) | [S04](#s04) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2026-11-07 基础阶段验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-07) | [S01](#s01)、[S18](#s18)、[S19](#s19) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2026-11-08 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-08) | [S04](#s04)、[S17](#s17)、[S18](#s18)、[S19](#s19)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W06 · 原阶段 B

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-11-09 执行模型](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-09) | [S23](#s23)、E-K | R1 → [S57](#s57)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-10 边界与 grid-stride](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-10) | [S23](#s23)、E-K | R1 → [S57](#s57)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-11 CUDA Event](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-11) | [S25](#s25)、E-K | R1 → [S57](#s57)、[S62](#s62) | X3 → [S62](#s62)、[S57](#s57) |
| [2026-11-12 访存与带宽](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-12) | [S24](#s24)、[S26](#s26)、E-K | R1 → [S57](#s57)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-13 Nsight Systems](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-13) | [S25](#s25)、E-K | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-14 完整基准脚手架](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-14) | [S22](#s22)、E-K | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-15 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-15) | [S22](#s22)、[S62](#s62)、[S63](#s63)、E-K | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W07 · 原阶段 B

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-11-16 张量与设备](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-16) | [S28](#s28) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-11-17 广播与索引](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-17) | [S28](#s28) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-11-18 推理模式](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-18) | [S29](#s29) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-11-19 欠账修复一](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-19) | [S22](#s22) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-11-20 欠账修复二](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-20) | [S01](#s01)、[S12](#s12)、E-K | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-11-21 科研与阶段复盘](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-21) | [S63](#s63) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-11-22 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-22) | [S28](#s28)、[S29](#s29)、[S62](#s62)、[S63](#s63)、E-K | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |



#### W08 · 原阶段 B

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-11-23 朴素 reduction](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-23) | [S24](#s24)、[S30](#s30)、E-K | R1 → [S58](#s58)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-24 优化 reduction](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-24) | [S24](#s24)、E-K | R1 → [S58](#s58)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-25 warp shuffle](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-25) | [S24](#s24)、E-K | R1 → [S58](#s58)、[S62](#s62) | X3 → [S62](#s62)、[S58](#s58) |
| [2026-11-26 Nsight Compute](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-26) | [S25](#s25)、E-K | R1 → [S58](#s58)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-27 transpose](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-27) | [S24](#s24)、E-K | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-28 归约实验验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-28) | [S24](#s24)、[S25](#s25)、E-K | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-11-29 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-29) | [S22](#s22)、[S62](#s62)、[S63](#s63)、E-K | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W09 · 原阶段 B

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-11-30 矩阵与 reference](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-11-30) | [S30](#s30)、E-K | R1 → [S60](#s60)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-01 shared-memory tiling](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-01) | [S24](#s24)、E-K | R1 → [S60](#s60)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-02 benchmark 公平性](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-02) | [S25](#s25)、[S30](#s30)、E-K | R1 → [S60](#s60)、[S62](#s62) | X3 → [S62](#s62)、[S60](#s60) |
| [2026-12-03 Roofline](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-03) | [S26](#s26) | R1 → [S60](#s60)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2026-12-04 Nsight Compute 深读](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-04) | [S25](#s25)、E-K | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-05 GEMM 阶段验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-05) | [S22](#s22)、[S26](#s26)、E-K | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-06 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-06) | [S22](#s22)、[S62](#s62)、[S63](#s63)、E-K | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W10 · 原阶段 B

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-12-07 Triton 执行模型](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-07) | [S27](#s27)、E-K | R1 → [S59](#s59)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-08 计时与 baseline](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-08) | [S25](#s25)、[S27](#s27)、E-K | R1 → [S59](#s59)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-09 稳定 softmax](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-09) | [S30](#s30)、E-K | R1 → [S59](#s59)、[S62](#s62) | X3 → [S62](#s62)、[S59](#s59) |
| [2026-12-10 调参与 profiling](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-10) | [S24](#s24)、[S27](#s27)、E-K | R1 → [S59](#s59)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-11 融合算子](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-11) | [S30](#s30)、E-K | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-12 Kernel Lab v1](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-12) | [S22](#s22)、E-K | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2026-12-13 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-13) | [S22](#s22)、[S62](#s62)、[S63](#s63)、E-K | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W11 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-12-14 Transformer 与 attention](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-14) | [S31](#s31) | R1 → [S61](#s61)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2026-12-15 MHA/GQA/MQA](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-15) | [S32](#s32) | R1 → [S61](#s61)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2026-12-16 Prefill 与 decode](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-16) | [S33](#s33) | R1 → [S61](#s61)、[S62](#s62) | X3 → [S62](#s62)、[S61](#s61) |
| [2026-12-17 模型显存手算](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-17) | [S34](#s34)、E-L | R1 → [S61](#s61)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-18 Batch 与 concurrency](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-18) | [S35](#s35) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2026-12-19 模型首次推理](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-19) | [S33](#s33)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-20 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-20) | [S31](#s31)、[S34](#s34)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W12 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-12-21 版本冻结](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-21) | [S01](#s01)、E-L | R1 → [S61](#s61)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-22 最小服务](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-22) | [S16](#s16)、[S33](#s33)、E-L | R1 → [S61](#s61)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-23 指标定义](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-23) | [S37](#s37)、E-L | R1 → [S61](#s61)、[S62](#s62) | X3 → [S62](#s62)、[S61](#s61) |
| [2026-12-24 负载与样本](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-24) | [S06](#s06)、[S21](#s21)、[S37](#s37)、E-L | R1 → [S61](#s61)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-25 显存与 GPU trace](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-25) | [S25](#s25)、[S34](#s34)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-26 项目 v0.1 与早投准备](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-26) | [S22](#s22)、[S64](#s64)、[S65](#s65)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2026-12-27 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-27) | [S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W13 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2026-12-28 实验错误审计](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-28) | [S06](#s06)、[S22](#s22)、E-L | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-12-29 C++ 回访](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-29) | [S09](#s09)、[S10](#s10) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-12-30 模型配置回访](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-30) | [S34](#s34) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2026-12-31 科研缓冲一](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2026-12-31) | [S63](#s63)、[S22](#s22) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-01-01 科研缓冲二](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-01) | [S63](#s63) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-01-02 年末求职检查](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-02) | [S64](#s64) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-01-03 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-03) | [S62](#s62)、[S63](#s63)、E-L | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |



#### W14 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-01-04 Collective 语义](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-04) | [S45](#s45) | R1 → [S58](#s58)、[S59](#s59)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-01-05 Ring 与 Tree](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-05) | [S46](#s46) | R1 → [S58](#s58)、[S59](#s59)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-01-06 拓扑与 transport](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-06) | [S47](#s47) | R1 → [S58](#s58)、[S59](#s59)、[S62](#s62) | X3 → [S62](#s62)、[S58](#s58)、[S59](#s59) |
| [2027-01-07 nccl-tests 准备](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-07) | [S49](#s49) | R1 → [S58](#s58)、[S59](#s59)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-01-08 NCCL_DEBUG](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-08) | [S49](#s49) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-01-09 TP 连接](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-09) | [S48](#s48) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-01-10 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-10) | [S45](#s45)、[S49](#s49)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W15 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-01-11 入口与路由](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-11) | [S38](#s38)、E-L | R1 → [S56](#s56)、[S57](#s57)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-12 AsyncLLM 与 EngineCore](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-12) | [S38](#s38)、E-L | R1 → [S56](#s56)、[S57](#s57)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-13 Scheduler](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-13) | [S38](#s38)、E-L | R1 → [S56](#s56)、[S57](#s57)、[S62](#s62) | X3 → [S62](#s62)、[S56](#s56)、[S57](#s57) |
| [2027-01-14 Worker 与 Model Runner](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-14) | [S38](#s38)、E-L | R1 → [S56](#s56)、[S57](#s57)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-15 Attention backend](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-15) | [S38](#s38)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-16 完整请求图](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-16) | [S38](#s38)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-17 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-17) | [S38](#s38)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W16 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-01-18 KV Cache Manager](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-18) | [S36](#s36)、E-L | R1 → [S60](#s60)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-19 PagedAttention](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-19) | [S36](#s36)、E-L | R1 → [S60](#s60)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-20 Continuous batching](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-20) | [S35](#s35)、E-L | R1 → [S60](#s60)、[S62](#s62) | X3 → [S62](#s62)、[S60](#s60) |
| [2027-01-21 Prefix caching](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-21) | [S36](#s36)、E-L | R1 → [S60](#s60)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-22 Chunked prefill](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-22) | [S35](#s35)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-23 机制验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-23) | [S35](#s35)、[S36](#s36)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-24 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-24) | [S35](#s35)、[S36](#s36)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W17 · 原阶段 C

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-01-25 实验矩阵冻结](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-25) | [S22](#s22)、E-L | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-26 Baseline 与重复性](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-26) | [S06](#s06)、E-L | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-27 Profile 与假设](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-27) | [S22](#s22)、[S25](#s25)、E-L | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-01-28 Modification](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-28) | [S22](#s22)、E-L | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-01-29 简历 v2 与 GitHub](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-29) | [S65](#s65)、[S68](#s68) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-01-30 可投门槛模拟面试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-30) | [S65](#s65)、[S66](#s66)、[S67](#s67) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-01-31 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-01-31) | [S65](#s65)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W18 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-02-01 岗位保温](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-01) | [S64](#s64)、[S66](#s66) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-02-02 编码短练](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-02) | [S54](#s54)、[S62](#s62) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-02-03 主项目重跑](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-03) | [S22](#s22)、E-L | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-02-04 科研占用登记](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-04) | [S63](#s63) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-02-05 简历修补](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-05) | [S65](#s65) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-02-06 恢复前验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-06) | [S63](#s63)、[S67](#s67) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-02-07 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-07) | [S62](#s62)、[S63](#s63) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |



#### W19 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-02-08 目标岗位分层](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-08) | [S64](#s64) | R1 → [S55](#s55)、[S56](#s56)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-02-09 简历定制与投递](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-09) | [S65](#s65)、[S66](#s66) | R1 → [S55](#s55)、[S56](#s56)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-02-10 C++ 面试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-10) | [S09](#s09)、[S10](#s10)、[S11](#s11) | R1 → [S55](#s55)、[S56](#s56)、[S62](#s62) | X3 → [S62](#s62)、[S55](#s55)、[S56](#s56) |
| [2027-02-11 Linux 面试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-11) | [S13](#s13)、[S14](#s14)、[S16](#s16)、[S18](#s18)、[S67](#s67) | R1 → [S55](#s55)、[S56](#s56)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-02-12 项目证据补齐](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-12) | [S06](#s06)、[S37](#s37)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-13 模拟与回访](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-13) | [S66](#s66)、[S67](#s67) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-02-14 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-14) | [S62](#s62)、[S63](#s63)、[S66](#s66) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W20 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-02-15 SGLang 版本与启动](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-15) | [S39](#s39)、E-L | R1 → [S57](#s57)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-16 统一 benchmark](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-16) | [S39](#s39)、E-L | R1 → [S57](#s57)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-17 架构路径](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-17) | [S38](#s38)、[S39](#s39)、E-L | R1 → [S57](#s57)、[S62](#s62) | X3 → [S62](#s62)、[S57](#s57) |
| [2027-02-18 cache 与 scheduler](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-18) | [S36](#s36)、[S39](#s39)、E-L | R1 → [S57](#s57)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-19 公平比较](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-19) | [S06](#s06)、[S39](#s39)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-20 选择与投递](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-20) | [S39](#s39)、[S66](#s66)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-21 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-21) | [S39](#s39)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W21 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-02-22 负载筛选](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-22) | [S22](#s22)、E-L | R1 → [S58](#s58)、[S60](#s60)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-23 Nsight Systems](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-23) | [S25](#s25)、E-L | R1 → [S58](#s58)、[S60](#s60)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-24 Nsight Compute](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-24) | [S25](#s25)、[S26](#s26)、E-L | R1 → [S58](#s58)、[S60](#s60)、[S62](#s62) | X3 → [S62](#s62)、[S58](#s58)、[S60](#s60) |
| [2027-02-25 源码回溯](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-25) | [S22](#s22)、[S38](#s38)、E-L | R1 → [S58](#s58)、[S60](#s60)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-26 优化决策](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-26) | [S26](#s26)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-02-27 模拟面试与证据](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-27) | [S66](#s66)、[S67](#s67)、[S68](#s68) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-02-28 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-02-28) | [S22](#s22)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W22 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-03-01 冻结 A/B](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-01) | [S22](#s22)、E-L | R1 → [S61](#s61)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-02 基准 A](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-02) | [S06](#s06)、E-L | R1 → [S61](#s61)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-03 实验 B](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-03) | [S22](#s22)、E-L | R1 → [S61](#s61)、[S62](#s62) | X3 → [S62](#s62)、[S61](#s61) |
| [2027-03-04 统计解释](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-04) | [S06](#s06)、E-L | R1 → [S61](#s61)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-05 回归与稳定性](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-05) | [S21](#s21)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-06 技术报告与投递](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-06) | [S22](#s22)、[S65](#s65)、[S66](#s66)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-07 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-07) | [S22](#s22)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W23 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-03-08 TP 数学](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-08) | [S48](#s48) | R1 → [S59](#s59)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-03-09 借卡可行性](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-09) | [S01](#s01)、[S49](#s49)、[S63](#s63) | R1 → [S59](#s59)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-03-10 Collective 尺寸](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-10) | [S48](#s48) | R1 → [S59](#s59)、[S62](#s62) | X3 → [S62](#s62)、[S59](#s59) |
| [2027-03-11 真实 TP 对照/替代](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-11) | [S48](#s48)、[S49](#s49)、E-L | R1 → [S59](#s59)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-12 Profiler 连接](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-12) | [S38](#s38)、[S47](#s47)、[S48](#s48)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-13 模拟与申请](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-13) | [S66](#s66)、[S67](#s67) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-03-14 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-14) | [S48](#s48)、[S49](#s49)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W24 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-03-15 消息大小曲线](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-15) | [S49](#s49) | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-03-16 Ring/Tree 对照](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-16) | [S46](#s46)、[S49](#s49) | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-03-17 Transport 与拓扑](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-17) | [S47](#s47)、[S48](#s48)、[S49](#s49) | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-03-18 RDMA Verbs](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-18) | [S50](#s50) | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-03-19 RoCE/IB/GPUDirect](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-19) | [S51](#s51) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-03-20 通信模块验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-20) | [S49](#s49)、[S65](#s65)、[S66](#s66) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-03-21 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-21) | [S49](#s49)、[S50](#s50)、[S51](#s51)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W25 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-03-22 量化理论](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-22) | [S40](#s40) | R1 → [S61](#s61)、[S57](#s57)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-03-23 量化实测边界](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-23) | [S40](#s40)、E-L | R1 → [S61](#s61)、[S57](#s57)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-24 Speculative decoding](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-24) | [S41](#s41) | R1 → [S61](#s61)、[S57](#s57)、[S62](#s62) | X3 → [S62](#s62)、[S61](#s61)、[S57](#s57) |
| [2027-03-25 MoE 与 EP](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-25) | [S42](#s42) | R1 → [S61](#s61)、[S57](#s57)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-03-26 PD 分离与 PP](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-26) | [S43](#s43)、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-27 模拟与优先级](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-27) | [S40](#s40)、[S41](#s41)、[S42](#s42)、[S43](#s43)、[S64](#s64)、[S67](#s67) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-03-28 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-28) | [S40](#s40)、[S41](#s41)、[S42](#s42)、[S43](#s43)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W26 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-03-29 超时与取消](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-29) | [S21](#s21)、E-L | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-30 背压与 SLO](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-30) | [S21](#s21)、[S37](#s37)、E-L | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-03-31 容器与依赖](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-03-31) | [S20](#s20)、E-L | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X3 → [S62](#s62)、[S53](#s53)、[S54](#s54) |
| [2027-04-01 观测与调试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-01) | [S21](#s21)、[S34](#s34)、[S37](#s37)、E-L | R1 → [S53](#s53)、[S54](#s54)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-04-02 Kubernetes/Ray 取舍](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-02) | [S44](#s44) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-04-03 稳定性验收与投递](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-03) | [S20](#s20)、[S21](#s21)、[S66](#s66)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-04-04 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-04) | [S20](#s20)、[S21](#s21)、[S62](#s62)、[S63](#s63)、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W27 · 原阶段 D

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-04-05 岗位漏斗](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-05) | [S66](#s66) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-04-06 算法修补](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-06) | [S62](#s62) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-04-07 项目修补](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-07) | [S06](#s06)、[S22](#s22)、E-L | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-04-08 学业缓冲一](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-08) | [S63](#s63)、[S72](#s72) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-04-09 学业缓冲二](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-09) | [S05](#s05) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-04-10 轻量模拟](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-10) | [S67](#s67)、[S68](#s68) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |
| [2027-04-11 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-11) | [S62](#s62)、[S63](#s63) | R5 → [S62](#s62)、[S63](#s63)、[S64](#s64) | X8 → [S22](#s22)、[S63](#s63) |



#### W28 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-04-12 C++ 生命周期](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-12) | [S09](#s09)、[S10](#s10) | R1 → [S61](#s61)、[S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-04-13 OS 与虚拟内存](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-13) | [S13](#s13)、[S14](#s14) | R1 → [S61](#s61)、[S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-04-14 并发与死锁](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-14) | [S18](#s18) | R1 → [S61](#s61)、[S62](#s62) | X3 → [S62](#s62)、[S61](#s61) |
| [2027-04-15 算法实战](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-15) | [S56](#s56)、[S57](#s57)、[S58](#s58)、[S62](#s62) | R1 → [S61](#s61)、[S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-04-16 项目故事](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-16) | [S68](#s68) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-04-17 投递复盘](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-17) | [S64](#s64)、[S66](#s66) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-04-18 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-18) | [S62](#s62)、[S63](#s63)、[S67](#s67) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W29 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-04-19 热点与边界](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-19) | [S26](#s26)、E-K、E-L | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-K/E-L |
| [2027-04-20 算子契约](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-20) | [S22](#s22)、[S28](#s28)、E-K | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2027-04-21 微基准复测](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-21) | [S25](#s25)、E-K | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-04-22 引擎接入评估](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-22) | [S22](#s22)、E-K、E-L | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-K/E-L |
| [2027-04-23 结果串联](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-23) | [S22](#s22)、[S38](#s38)、E-K、E-L | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题，项目部分E-K/E-L |
| [2027-04-24 模拟与求职](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-24) | [S66](#s66)、[S67](#s67)、[S68](#s68) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-04-25 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-25) | [S62](#s62)、[S63](#s63)、E-K、E-L | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W30 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-04-26 选题](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-26) | [S05](#s05)、[S22](#s22)、E-L | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-04-27 最小复现](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-27) | [S12](#s12)、[S22](#s22)、E-L | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-04-28 回归测试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-28) | [S12](#s12)、[S22](#s22)、E-L | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-04-29 补丁检查](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-29) | [S05](#s05)、[S12](#s12)、[S22](#s22)、E-L | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-04-30 贡献与简历边界](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-04-30) | [S05](#s05)、[S65](#s65) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-05-01 投递优先](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-01) | [S63](#s63)、[S66](#s66) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-05-02 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-02) | [S22](#s22)、[S62](#s62)、[S63](#s63) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W31 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-05-03 漏斗诊断](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-03) | [S66](#s66) | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-05-04 定向补强](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-04) | [S67](#s67) | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-05-05 推理面试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-05) | [S33](#s33)、[S34](#s34)、[S35](#s35)、[S36](#s36)、[S40](#s40)、[S41](#s41)、[S42](#s42)、[S43](#s43)、[S67](#s67) | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-05-06 GPU 面试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-06) | [S23](#s23)、[S24](#s24)、E-K | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题，项目部分E-K |
| [2027-05-07 求职推进](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-07) | [S66](#s66) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-05-08 模拟与保底](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-08) | [S64](#s64)、[S67](#s67) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-05-09 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-09) | [S62](#s62)、[S63](#s63)、[S66](#s66) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W32 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-05-10 项目深挖](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-10) | [S22](#s22)、[S68](#s68) | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-05-11 系统设计小题](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-11) | [S21](#s21)、[S35](#s35) | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-05-12 C++ 编码模拟](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-12) | [S18](#s18) | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-05-13 行为面试](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-13) | [S68](#s68) | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-05-14 申请检查](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-14) | [S63](#s63)、[S68](#s68) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-05-15 稳态维护](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-15) | [S22](#s22)、[S66](#s66)、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-L |
| [2027-05-16 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-16) | [S62](#s62)、[S63](#s63)、[S67](#s67) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W33 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-05-17 机会清单](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-17) | [S69](#s69) | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-05-18 团队问题](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-18) | [S69](#s69) | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-05-19 学业协调](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-19) | [S63](#s63)、[S69](#s69) | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-05-20 机会比较](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-20) | [S69](#s69) | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-05-21 未获 offer 分支](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-21) | [S64](#s64)、[S66](#s66)、[S71](#s71) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-05-22 模拟与决策](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-22) | [S67](#s67)、[S69](#s69) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-05-23 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-23) | [S62](#s62)、[S63](#s63)、[S69](#s69) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W34 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-05-24 结果核对](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-24) | [S66](#s66)、[S69](#s69) | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-05-25 有实习分支](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-25) | [S70](#s70)、[S71](#s71) | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-05-26 无实习分支](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-26) | [S22](#s22)、[S71](#s71)、E-L | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-05-27 秋招简历雏形](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-27) | [S65](#s65)、[S71](#s71) | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-05-28 学业检查](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-28) | [S63](#s63)、[S72](#s72) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-05-29 技术维护](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-29) | [S05](#s05)、[S22](#s22)、E-K、E-L | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题，项目部分E-K/E-L |
| [2027-05-30 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-30) | [S62](#s62)、[S63](#s63)、[S70](#s70)、[S71](#s71) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



#### W35 · 原阶段 E

| 原任务 | 主任务处置 | 固定项 | P1处置 |
| --- | --- | --- | --- |
| [2027-05-31 最终实习状态](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-05-31) | [S70](#s70)、[S71](#s71) | R1 → [S62](#s62) | X1 → [S22](#s22)；结合当天主题 |
| [2027-06-01 主项目演示](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-06-01) | [S68](#s68) | R1 → [S62](#s62) | X2 → [S22](#s22)；结合当天主题 |
| [2027-06-02 Kernel 复盘](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-06-02) | [S25](#s25)、[S26](#s26)、[S27](#s27)、[S68](#s68)、E-K | R1 → [S62](#s62) | X3 → [S62](#s62) |
| [2027-06-03 通信边界复盘](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-06-03) | [S45](#s45)、[S48](#s48)、[S50](#s50)、[S51](#s51)、[S65](#s65) | R1 → [S62](#s62) | X4 → [S22](#s22)；结合当天主题 |
| [2027-06-04 秋招监控启动](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-06-04) | [S64](#s64)、[S71](#s71) | R2 → [S64](#s64)、[S66](#s66) | X5 → [S12](#s12)、[S22](#s22)；结合当天主题 |
| [2027-06-05 夏季切换验收](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-06-05) | [S63](#s63)、[S70](#s70)、[S71](#s71)、[S72](#s72) | R3 → [S22](#s22)、[S63](#s63) | X6 → [S22](#s22)；结合当天主题 |
| [2027-06-06 周验收、错题与恢复](LLM-Inference-GPU-Systems-Roadmap-2026-2028.html#d-2027-06-06) | [S62](#s62)、[S63](#s63)、[S70](#s70)、[S71](#s71) | R4 → [S62](#s62)、[S63](#s63) | X7 → [S62](#s62) |



</details>

## 后续维护

完成一项后只补真实日期、产出路径、测试/推导结果与帮助程度，并更新对应勾选。若只学习了部分知识点，在当前状态中细分范围；仅完成报告不勾独立考核。重复归档不重计题数或抹去历史错误。

新自学汇报与实际日期的项目记录按[日记约定](日记/README.md)合并，不改变当前选定项目。本人结束/暂停后保存未完成操作、卡点、待答题和下次第一步；跨天仍由[当前项目计划](project-learning-plan.md)恢复原检查点，不把清单或历史日期映射变成每日任务。本次没有运行上述考核、安装依赖、启动课程或修改任何既有通过状态。
