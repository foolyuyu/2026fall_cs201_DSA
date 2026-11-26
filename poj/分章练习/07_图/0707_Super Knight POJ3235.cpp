// 0707 Super Knight POJ3235（全局题号 2485）
// http://dsa.openjudge.cn/graph/0707/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// A super knight moves in the infinite n-dimensional space. Each move it can perform is described by a vector – a vector (a_(1), a_(2), …, a_(n)) indicates that a move from the square (with coordinates) (x_(1), x_(2), …, x_(n)) to the square (x_(1) + a_(1), x_(2) + a_(2), …, x_(n) + a_(n)) or (x_(1) − a_(1), x_(2) − a_(2), …, x_(n) − a_(n)) is possible. Each knight has a prescribed set of such vectors, describing the moves this knight can make. For each knight we assume that this knight can reach anywhere in the space if it is allowed (but actually disallowed) to move along a fractional part of a vector.
// We say two knights are equivalent, if they can reach exactly the same squares starting from the square (0, 0, …, 0) (by making many moves, perhaps). (Let us point out that equivalent knights may reach these squares in different number of moves). It can be shown that for every knight there exists an equivalent one whose moves are described by only n vectors.
// Given a set of  m (m > n) vectors describing the moves of a super knight, determine an equivalent knight as mentioned above.
//
// 输入
// The input contains exactly one test case. The first line of input contains two integers m and n (2 ≤ n < m ≤ 100, n ≤ 10, n · m ≤ 200). The next m lines each contains an integral n-dimensional vector (a_(1), a_(2), …, a_(n)). It is guaranteed that for all i (1 ≤ i ≤ n) if n = 2, |a_(i)| ≤ 10^(3), otherwise |a_(i)| ≤ 10^(2).
//
// 输出
// Output n n-dimensional vectors describing the moves of an equivalent knight, each on a separate line.
//
// 样例输入
// 3 2
// 1 0
// 0 5
// 0 7
//
// 样例输出
// 1 0
// 0 1
//
// 提示
// Do not output any number longer than 50 digits. The test cases are designed that to each one there is a solution not involving any number exceeding 10^(20) by magnitude.

