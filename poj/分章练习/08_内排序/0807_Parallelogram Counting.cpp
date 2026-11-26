// 0807 Parallelogram Counting（全局题号 973）
// http://dsa.openjudge.cn/sort/0807/
// 总时间限制 5000ms  内存限制 65536kB
//
// 描述
// There are n distinct points in the plane, given by their integer coordinates. Find the number of parallelograms whose vertices lie on these points. In other words, find the number of 4-element subsets of these points that can be written as {A, B, C, D} such that AB || CD, and BC || AD. No four points are in a straight line.
//
// 输入
// The first line of the input contains a single integer t (1 <= t <= 10), the number of test cases. It is followed by the input data for each test case.
// The first line of each test case contains an integer n (1 <= n <= 1000). Each of the next n lines, contains 2 space-separated integers x and y (the coordinates of a point) with magnitude (absolute value) of no more than 1000000000.
//
// 输出
// Output should contain t lines.
// Line i contains an integer showing the number of the parallelograms as described above for test case i.
//
// 样例输入
// 2
// 6
// 0 0
// 2 0
// 4 0
// 1 1
// 3 1
// 5 1
// 7
// -2 -1
// 8 9
// 5 7
// 1 1
// 4 8
// 2 0
// 9 8
//
// 样例输出
// 5
// 6
//
// 来源
// Tehran Sharif 2004 Preliminary

