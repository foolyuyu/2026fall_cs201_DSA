# 第三章作业

### 1

给定一个只保存 `int` 的栈 `S`，原有基本操作如下：

* `S.push(x)`：将 `x` 压入栈中。
* `S.pop()`：将栈顶元素出栈，并返回该元素。
* `S.top()`：返回栈顶元素。

请在不增加新的容器类数据结构的前提下，对上述操作进行必要的重写，并增加：

* `S.getMax()`：返回栈中的最大元素。

要求所有操作的时间复杂度均为 $O(1)$。可以在原栈中额外压入辅助整数；无需考虑栈空或栈满。请给出各操作的伪代码，并简要说明辅助信息的含义。

思路：
	由于题目不允许额外使用新的容器，我们可以在每一个真正的数据后面，再压入一个辅助整数。这个辅助整数表示从栈底到当前数据为止的最大值。
	所以栈中的结构为：
	`x1, max1, x2, max2, ..., xn, maxn`
	其中 `maxi = max(x1, x2, ..., xi)`。这样栈顶永远是当前栈的最大值。

为了区分重写后的操作和原本的栈操作，下面用 `rawPush`、`rawPop`、`rawTop` 表示原本的压栈、出栈和读取栈顶操作。

```text
push(x):
    if S.empty():
        nowMax = x
    else:
        nowMax = max(x, S.rawTop())  // 此时栈顶保存的是原来的最大值
    S.rawPush(x)
    S.rawPush(nowMax)

pop():
    S.rawPop()                       // 先弹出辅助的最大值
    return S.rawPop()                // 再弹出并返回真正的数据

top():
    nowMax = S.rawPop()              // 暂时取下辅助信息
    x = S.rawTop()
    S.rawPush(nowMax)                // 恢复栈的结构
    return x

getMax():
    return S.rawTop()
```

每个操作都只执行了常数次基本栈操作，所以时间复杂度均为 $O(1)$。每存入一个数据需要额外存入一个整数，所以额外空间复杂度为 $O(n)$。

---

### 2

由 $n$ 对左右括号组成的字符串中，若从左到右扫描时任意前缀内左括号数都不少于右括号数，且最终两者数量相等，则称为合法括号序列。

请回答长度为 $2n$ 的合法括号序列共有多少种，并写出递推关系、初始条件以及通项公式。另列出 $n = 3$ 时的全部合法序列。

长度为 $2n$ 的合法括号序列数量是第 $n$ 个 Catalan 数，记为 $C_n$。

考虑一个合法括号序列最左边的左括号，与它配对的右括号会把剩余部分分成两个合法括号序列。假设括号内部有 $k$ 对括号，那么右侧还有 $n-1-k$ 对括号。因此递推关系为

$$
C_n = \sum_{k=0}^{n-1} C_k C_{n-1-k},\quad n \ge 1
$$

初始条件为

$$
C_0 = 1
$$

这里将空序列记为一种合法情况，这样递推式在 $k=0$ 时仍然成立。

通项公式为

$$
C_n = \frac{1}{n+1}\binom{2n}{n}
$$

简单解释一下，任意排列 $n$ 个左括号和 $n$ 个右括号共有 $\binom{2n}{n}$ 种，其中不合法序列有 $\binom{2n}{n+1}$ 种，因此

$$
C_n = \binom{2n}{n}-\binom{2n}{n+1}
=\frac{1}{n+1}\binom{2n}{n}
$$

当 $n=3$ 时，$C_3=5$，全部合法序列为：

```text
((()))
(()())
(())()
()(())
()()()
```

---

### 3

浏览器使用两个栈实现“后退”和“前进”：

* 栈 `Back` 保存可后退的页面；栈 `Forward` 保存可前进的页面。
* 变量 `current` 表示当前页面；访问新页面时，原当前页面压入 `Back`，并清空 `Forward`。
* `back()`（后退）：若 `Back` 非空，将 `current` 压入 `Forward`，再弹出 `Back` 的栈顶作为新的 `current`；否则不操作。
* `forward()`（前进）：若 `Forward` 非空，将 `current` 压入 `Back`，再弹出 `Forward` 的栈顶作为新的 `current`；否则不操作。

请回答：

1. 仅用 `push`、`pop`、`empty` 描述 `visit(p)`、`back()` 和 `forward()`。
2. 初始时 `current = Home`，两个栈均为空，依次执行：
   ```text
   visit(A), visit(B), back(), visit(C), back(), forward(), back()
   ```
   写出最后的 `current`，以及两个栈中从栈底到栈顶保存的页面。

1. 三个操作的伪代码如下：

```text
visit(p):
    push(Back, current)
    current = p
    while not empty(Forward):
        pop(Forward)              // 访问新页面后，之前的前进记录失效

back():
    if not empty(Back):
        push(Forward, current)
        current = pop(Back)

forward():
    if not empty(Forward):
        push(Back, current)
        current = pop(Forward)
```

2. 按照顺序模拟，两个栈均按从栈底到栈顶书写：

| 操作 | current | Back | Forward |
|---|---|---|---|
| 初始 | Home | 空 | 空 |
| `visit(A)` | A | Home | 空 |
| `visit(B)` | B | Home, A | 空 |
| `back()` | A | Home | B |
| `visit(C)` | C | Home, A | 空 |
| `back()` | A | Home | C |
| `forward()` | C | Home, A | 空 |
| `back()` | A | Home | C |

所以最后 `current = A`，`Back` 从栈底到栈顶为 `Home`，`Forward` 从栈底到栈顶为 `C`。

---

### 4

已知栈的三个基本操作定义如下：

* `push(S, x)`：将元素 `x` 压入栈 `S`。
* `pop(S)`：弹出并返回栈 `S` 的栈顶元素。
* `isEmpty(S)`：判断栈 `S` 是否为空。

请设计一种方法，用两个普通栈 `S1`、`S2` 实现队列的三个基本操作：

* `enQueue(x)`：将元素插入队尾。
* `deQueue()`：删除并返回队首元素。
* `isEmpty()`：判断队列是否为空。

要求：

1. 说明两个栈各自保存什么，并写出 `enQueue` 与 `deQueue` 的伪代码。
2. 分析单次操作的最坏时间复杂度。
3. 若依次执行以下操作序列：
   ```text
   enQueue(5), enQueue(8), deQueue(), enQueue(2), enQueue(7), deQueue(), deQueue()
   ```
   请写出每次 `deQueue()` 的返回结果，并给出操作结束后队列中从队首到队尾的元素。

1. 使用 `S1` 作为入队栈，新元素直接压入 `S1`；使用 `S2` 作为出队栈，`S2` 的栈顶就是队首元素。

当需要出队且 `S2` 为空时，将 `S1` 中的所有元素依次弹出并压入 `S2`。经过一次倒序后，最早进入 `S1` 的元素就会出现在 `S2` 的栈顶。

```text
enQueue(x):
    push(S1, x)

deQueue():
    if isEmpty(S2):
        while not isEmpty(S1):
            push(S2, pop(S1))
    return pop(S2)

isEmpty():
    return isEmpty(S1) and isEmpty(S2)
```

只有当 `S2` 为空时才把 `S1` 中的元素倒入，否则新进入的元素会排在旧元素前面，破坏先进先出的顺序。

2. `enQueue` 和 `isEmpty` 的单次最坏时间复杂度均为 $O(1)$。`deQueue` 在 `S2` 非空时为 $O(1)$；最坏情况下需要将 `S1` 中的 $n$ 个元素全部转移到 `S2`，所以单次最坏时间复杂度为 $O(n)$。

虽然一次 `deQueue` 最坏为 $O(n)$，但是每个元素最多只会从 `S1` 转移到 `S2` 一次，所以均摊下来每次操作的时间复杂度为 $O(1)$。

3. 操作过程如下，栈内元素均按从栈底到栈顶书写：

| 操作 | S1 | S2 | 返回值 |
|---|---|---|---|
| `enQueue(5)` | 5 | 空 | |
| `enQueue(8)` | 5, 8 | 空 | |
| `deQueue()` | 空 | 8 | 5 |
| `enQueue(2)` | 2 | 8 | |
| `enQueue(7)` | 2, 7 | 8 | |
| `deQueue()` | 2, 7 | 空 | 8 |
| `deQueue()` | 空 | 7 | 2 |

三次 `deQueue()` 的返回结果依次为 $5,8,2$。操作结束后队列中只剩下元素 $7$，所以从队首到队尾为 `7`。
