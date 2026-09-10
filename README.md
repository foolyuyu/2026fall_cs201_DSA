# 2026fall-cs201: DS Algo（数据结构与算法）

*Updated 2026-09-06 19:40 GMT+8*  
 *Compiled by Hongfei Yan (2026 Fall)*  
*项目仓库：[GMyhf/2026fall-cs201](https://github.com/GMyhf/2026fall-cs201/)*

------

## 1 题解 & 教材资源

- **题解**：[fuynaloft.github.io/sol101/](https://fuynaloft.github.io/sol101/)

- **核心教材**：以课件为主，辅以以下参考书目：

  - 数据结构与算法：Python 讲算法，C++ 讲实现，https://gmyhf.github.io/dsa-modernization/

  - 《Python数据结构与算法分析（第3版）》 Miller, Ranum, College

  - 《算法笔记》 胡凡、曾磊
  
  - 《算法导论（第3版）》 Cormen, Leiserson 等


- **AI 拓展**：
  *   教材：*Build a Large Language Model (From Scratch)* (Sebastian Raschka)
  *   [配套代码库](https://github.com/rasbt/LLMs-from-scratch)
  *   重点掌握《Test Yourself On Build a Large Language Model》中的核心概念与问题。

------

## 2 数算A-1班 课程安排

- **上课时间**：1–16 周，每周三 3–4 节（10:10–12:00），每周五 1–2 节（08:00–09:50）
- **上课地点**：理教 407（150 座位）
- **期末机考**：待定
- **考试时间**：2026年12月30日 上午
  - 地点：待定

## 3 预习与环境搭建指南

> 课程主要使用 C++ 和 Python。

- **开发工具推荐**：
  
  - 编辑器/IDE：PyCharm, VS Code
  - 环境配置指南：
    *   [Python 开发环境搭建 (Mac & Windows)](https://github.com/GMyhf/2026spring-cs201/blob/main/Python_Development_Setup_Mac_Windows.md)
    *   [在 VS Code 中配置 C++ 编程环境](https://github.com/GMyhf/2026spring-cs201/blob/main/Writing_First_C%2B%2B_Program_in_VS-Code.md)
- **AI辅助自学平台**：

  - **小北智学平台**：登录 [zx.pku.edu.cn](https://zx.pku.edu.cn/)，加入“**数据结构与算法A/B-YHF班**”课程。可利用 **AI 助教** 进行问答式学习。如有疑问，请通过邮件联系：[yanhf@pku.edu.cn](mailto:yanhf@pku.edu.cn)

  *   **提问举例**：“请详细总结本课程知识库的内容”，“本课程的大纲和核心内容有哪些？”


------

### 编程强化训练建议

为夯实基础并培养算法思维，建议在开课前按以下路径进行针对性练习：

1.  **LeetCode 热题 100 (Top 100 Liked)**
    *   [在线练习链接](https://leetcode.cn/studyplan/top-100-liked/)
    *   重点掌握基础数据结构与高频算法题。
2.  **课程组精选每日选作题**
    *   [题目列表链接](https://github.com/GMyhf/2026fall-cs201/blob/main/DSA_problem_list_at_2026fall.md)
    *   **练习建议**：题目分为 Easy、Medium (M)、Tough (T) 三个等级。要求熟练完成所有 Easy 和 Medium 题目，鼓励勇于挑战 Tough 题目。

------

## 4 重要注意事项

建议在开课前完成 **LeetCode 热题 100**。

*   **预习范围**：可暂不包含“链表”（14题）和“二叉树”（15题）。
*   **目标**：通过刷题消除编程语言隔阂，确保能跟上数算课程的教学节奏。

------



**总结**：
本课程在传统“数据结构与算法”的基础上，融入了 **AI 大模型原理** 元素。希望同学们通过“预习 + 算法实战 + AI 辅助”的复合模式，在掌握经典算法的同时，理解现代智能技术的基石。

------

## 5 本地题目同步工具

运行下面的命令，会先从课程上游仓库刷新秋季题单，然后直接在 `problems/` 中创建 C++ 解答文件：

```bash
python3 tools/sync_problems.py
```

每道题对应一个 `日期_题号.cpp` 文件，题目信息直接位于源码顶部，不需要在多层目录和文档之间跳转。再次运行不会覆盖已经写过的解答：同一道题更换日期时会保留代码并自动改名；老师替换题目时会删除未作答的旧模板，但保留已经写过的旧题，同时创建新题。运行同步前请先保存编辑器中的源码。常用选项：

```bash
# 同时创建 C++ 和 Python 模板
python3 tools/sync_problems.py --language both

# 离线运行，不刷新上游题单
python3 tools/sync_problems.py --no-refresh

# 预览同步结果，不修改文件
python3 tools/sync_problems.py --dry-run
```

同步时会把题面、输入输出、样例和通过率写到源码顶部的可折叠注释中。OpenJudge 题使用普通 `main()` 模板，在原题网页提交；LeetCode 题使用官方函数模板，并带有 VS Code LeetCode 扩展可识别的标记。

### LeetCode Hot 100

仓库打开后，VS Code 会推荐安装 **LeetCode** 扩展。安装后切换到 `leetcode.cn` 并登录账号，即可在生成的源码中使用 `Description`、`Test` 和 `Submit` 检查是否 AC。

首次下载 Hot 100 题面和官方 C++ 模板：

```bash
python3 tools/sync_hot100.py
```

文件会直接生成在 `leetcode-hot100/`。后续运行默认只下载新增题目；需要重新获取全部题面的最新通过率时使用：

```bash
python3 tools/sync_hot100.py --update-details
```

也可以在 VS Code 中打开命令面板，选择 **Tasks: Run Task**，再选择“题单：同步每日题目”或“题单：同步 LeetCode Hot 100”。
