// 0307 Power Hungry Cows（全局题号 947）
// http://dsa.openjudge.cn/stack/0307/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// FJ's cows would like to be able to compute integer powers P (1 <= P <= 20,000) of numbers very quickly, but need your help.  Because they're going to be computing powers of very large numbers, they can only keep around two work variables for intermediate results.
//
// The first of those work variables is initialized to the number (denoted x) for which they are calculating the power; the other is initialized to 1. The cows can both multiply and divide any pair of the work variables and store the result in any work variable, but all results are stored as integers.
//
// For example, if they want to compute x^31, one way to perform the calculation is:
//                                               WV1  WV2
//                                       Start:   x    1
//    Multiply first by first, store in second:   x   x^2
//                   Multiply second by second:   x   x^4
//                   Multiply second by second:   x   x^8
//                   Multiply second by second:   x   x^16
//                   Multiply second by second:   x   x^32
//                      Divide second by first:   x   x^31
// Thus, x^31 can computed in six operations.  Given the power to be computed and the the number of work variables, find the minimum number of operations to calculate the power.
//
// 输入
// A single line with one integer: P.
//
// 输出
// A single line with a single integer that is the minimum number of operations it requires to compute the power.
//
// 样例输入
// 31
//
// 样例输出
// 6
//
// 来源
// USACO 2002 February

