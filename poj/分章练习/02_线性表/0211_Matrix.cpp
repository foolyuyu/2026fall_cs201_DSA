// 0211 Matrix（全局题号 1080）
// http://dsa.openjudge.cn/linearlist/0211/
// 总时间限制 2000ms  内存限制 65536kB
//
// 描述
// Given an n*n matrix A, whose entries Ai,j are integer numbers ( 0 <= i < n, 0 <= j < n ). An operation SHIFT at row i ( 0 <= i < n ) will move the integers in the row one position right, and the rightmost integer will wrap around to the leftmost column.
// 〔原题配图 http://media.openjudge.cn/images/g1080/2078_1.jpg〕
//
// You can do the SHIFT operation at arbitrary row, and as many times as you like. Your task is to minimize
// max_(0<=j< n){Cj|Cj=Σ_(0<=i< n)A_(i,j)}
//
// 输入
// The input consists of several test cases. The first line of each test case contains an integer n. Each of the following n lines contains n integers, indicating the matrix A. The input is terminated by a single line with an integer −1. You may assume that 1 <= n <= 7 and |A_(i,j)| < 10^(4).
//
// 输出
// For each test case, print a line containing the minimum value of the maximum of column sums.
//
// 样例输入
// 2
// 4 6
// 3 7
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// -1
//
// 样例输出
// 11
// 15
//
// 来源
// Shanghai 2004 Preliminary

