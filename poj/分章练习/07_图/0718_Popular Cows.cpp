// 0718 Popular Cows（全局题号 1188）
// http://dsa.openjudge.cn/graph/0718/
// 总时间限制 2000ms  内存限制 65536kB
//
// 描述
// Every cow's dream is to become the most popular cow in the herd.  In a herd of N (1 <= N <= 10,000) cows, you are given up to M (1 <= M <= 50,000) ordered pairs of the form (A, B) that tell you that cow A thinks that cow B is popular.  Since popularity is transitive, if A thinks B is popular and B thinks C is popular, then A will also think that C is
// popular, even if this is not explicitly specified by an ordered pair in the input.  Your task is to compute the number of cows that are considered popular by every other cow.
//
// 输入
// * Line 1: Two space-separated integers, N and M
//
// * Lines 2..1+M: Two space-separated numbers A and B, meaning that A thinks B is popular.
//
// 输出
// * Line 1: A single integer that is the number of cows who are considered popular by  every other cow.
//
// 样例输入
// 3 3
// 1 2
// 2 1
// 2 3
//
// 样例输出
// 1
//
// 提示
// Cow 3 is the only cow of high popularity.
//
// 来源
// USACO 2003 Fall

