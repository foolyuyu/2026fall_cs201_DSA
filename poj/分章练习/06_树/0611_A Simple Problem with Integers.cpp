// 0611 A Simple Problem with Integers（全局题号 2244）
// http://dsa.openjudge.cn/tree/0611/
// 总时间限制 5000ms  单个测试点时间限制 2000ms  内存限制 131072kB
//
// 描述
// You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.
//
// 输入
// The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
// The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
// Each of the next Q lines represents an operation.
// "C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
// "Q a b" means querying the sum of Aa, Aa+1, ... , Ab.
//
// 输出
// You need to answer all Q commands in order. One answer in a line.
//
// 样例输入
// 10 5
// 1 2 3 4 5 6 7 8 9 10
// Q 4 4
// Q 1 10
// Q 2 4
// C 3 6 3
// Q 2 4
//
// 样例输出
// 4
// 55
// 9
// 15
//
// 提示
// The sums may exceed the range of 32-bit integers.
//
// 来源
// POJ Monthly--2007.11.25, Yang Yi

