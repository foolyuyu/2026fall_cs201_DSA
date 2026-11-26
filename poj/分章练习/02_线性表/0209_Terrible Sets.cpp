// 0209 Terrible Sets（全局题号 1084）
// http://dsa.openjudge.cn/linearlist/0209/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// Let N be the set of all natural numbers {0 , 1 , 2 , . . . }, and R be the set of all real numbers. wi, hi for i = 1 . . . n are some elements in N, and w0 = 0.
// Define set B = {< x, y > | x, y ∈ R and there exists an index i > 0 such that 0 <= y <= hi ,∑_(0<=j<=i-1)wj <= x <= ∑_(0<=j<=i)wj}
// Again, define set S = {A| A = WH for some W , H ∈ R^(+) and there exists x0, y0 in N such that the set T = { < x , y > | x, y ∈ R and x0 <= x <= x0 +W and y0 <= y <= y0 + H} is contained in set B}.
// Your mission now. What is Max(S)?
// Wow, it looks like a terrible problem. Problems that appear to be terrible are sometimes actually easy.
// But for this one, believe me, it's difficult.
//
// 输入
// The input consists of several test cases. For each case, n is given in a single line, and then followed by n lines, each containing wi and hi separated by a single space. The last line of the input is an single integer -1, indicating the end of input. You may assume that 1 <= n <= 50000 and w_(1)h_(1)+w_(2)h_(2)+...+w_(n)h_(n) < 10^(9).
//
// 输出
// Simply output Max(S) in a single line for each case.
//
// 样例输入
// 3
// 1 2
// 3 4
// 1 2
// 3
// 3 4
// 1 2
// 3 4
// -1
//
// 样例输出
// 12
// 14
//
// 来源
// Shanghai 2004 Preliminary

