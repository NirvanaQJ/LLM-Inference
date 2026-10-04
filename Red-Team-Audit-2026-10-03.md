# Red-Team 审核记录 · 2026-10-03

最终产物：LLM-Inference-GPU-Systems-Roadmap-2026-2028.html

## 结论

已修复已发现的 Critical / High 问题，无已知阻断使用的问题。此结论针对学习路线与交互文档，不保证录用结果，不代表任何 GPU 基准已实际完成。

## 实质修正

- 招聘资格：明确 2027 年暑期实习和 2028 届毕业身份，未来开招日均标为行动窗口或待官方公告。
- 零基础：前五周优先 Python/C++/Linux；加入 W5 未通过的恢复路线。
- 单卡边界：不将 CPU 语义模拟或单卡多进程写成多卡 NCCL/TP 性能；多机 RDMA 独立条件化。
- 70% 路线：正常周 15.5/22h 的核心任务包含项目、简历、算法与求职，非仅学习前置知识。
- 预算：35 周、四个 12h 缓冲周；正常 22h；实习后课外降至 4–6h。
- 开源贡献：自身项目修复为主，向上游公开贡献仅 P1，总投入上限 6h。
- 招聘统计：8 条可读官方 JD 内容，仅 2 家公司；列样本偏差，不代表全市场。薪资项因缺可靠样本统一中性。
- 版本：vLLM v0.30.0 / SGLang v0.5.21 为查阅基线，具体源码锚点需冻结 checkout 验证；避免旧 runner/cache 图。
- 资源：替换失效 CUDA 文档地址，记录 SGLang 文档重定向。
- 页面：P0/P1/里程碑分账，筛选不改变分母；存储异常可导出；用户文本转义。
- 打印：修复暗色背景残留，压缩为 109 页完整 A4；含 247 天，不遗漏折叠/筛选内容。

## 浏览器验证

- 通过：247 consecutive core days
- 通过：245 optional tasks
- 通过：unique task IDs
- 通过：dates 2026-10-03 through 2027-06-06
- 通过：732.5h total; 518h P0
- 通过：no external page dependencies
- 通过：storage enabled
- 通过：one-day total 0.4%
- 通过：week 0 count 1/2
- 通过：phase A 1/37
- 通过：weighted progress 0.2%
- 通过：optional independent
- 通过：checkbox persists after reload
- 通过：notes persist
- 通过：search narrows days
- 通过：filter leaves total unchanged
- 通过：empty search state
- 通过：phase B filter 35 days
- 通过：P1 hidden
- 通过：zero GPU caveat
- 通过：early hiring response
- 通过：job created
- 通过：job text escaped
- 通过：job dashboard updated
- 通过：job edit persists
- 通过：backup includes data
- 通过：CSV export complete
- 通过：malformed import preserves data
- 通过：import updates all progress to 100%
- 通过：readiness independent 10/10
- 通过：phase end correct
- 通过：completion points to later phase
- 通过：no page overflow at 1440px
- 通过：no page overflow at 1024px
- 通过：no page overflow at 768px
- 通过：no page overflow at 390px
- 通过：no page overflow at 320px
- 通过：mobile task check works
- 通过：print exposes 247 tasks
- 通过：print expands all details
- 通过：print has white background
- 通过：print PDF generated
- 通过：print restores filters
- 通过：storage failure warning visible
- 通过：memory-only mode still works
- 通过：no JavaScript runtime errors

## 额外静态检查

- HTML ID 无重复。
- 内部锚点无缺失。
- 247 天日期连续：2026-10-03 至 2027-06-06。
- 245 个 P1 扩展；25 个项目/求职/readiness 里程碑。
- 总预算 732.5h，P0 518h。
- 单文件无外部 JavaScript、CSS、网络请求。

## 保留的限制

- 原始招聘样本偏向百度/NVIDIA，其他公司多只取得入口或岗位目录，不能伪作完整 JD。
- 未获 NVIDIA GPU 型号/显存/驱动信息；W0 要先确认兼容性。
- 企业 2027/2028 后续招聘日期与学校毕业节点须滚动核查。
- localStorage 对文件路径/浏览器敏感；每周导出 JSON，不支持自动跨设备同步。
- 测试覆盖当前 Chrome；其他浏览器可能有文件存储差异，页面提供降级提示。
