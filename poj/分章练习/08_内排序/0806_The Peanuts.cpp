// 0806 The Peanuts（全局题号 930）
// http://dsa.openjudge.cn/sort/0806/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// Mr. Robinson and his pet monkey Dodo love peanuts very much.  One day while they were having a walk on a country road, Dodo found a sign by the road, pasted with a small piece of paper, saying "Free Peanuts Here! " You can imagine how happy Mr. Robinson and Dodo were.
//
// There was a peanut field on one side of the road.  The peanuts were planted on the intersecting points of a grid as shown in Figure-1.  At each point, there are either zero or more peanuts. For example, in Figure-2, only four points have more than zero peanuts, and the numbers are 15, 13, 9 and 7 respectively.  One could only walk from an intersection point to one of the four adjacent points, taking one unit of time. It also takes one unit of time to do one of the following:  to walk from the road to the field, to walk from the field to the road, or pick peanuts on a point.
// 〔原题配图 http://media.openjudge.cn/images/g930/1928_1.jpg〕
//
// According to Mr. Robinson's requirement, Dodo should go to the plant with the most peanuts  first. After picking them, he should then go to the next plant with the most peanuts, and so on.  Mr. Robinson was not so patient as to wait for Dodo to pick all the peanuts and he asked Dodo to return to the road in a certain period of time. For example, Dodo could pick 37 peanuts within 21 units of time in the situation given in Figure-2.
//
// Your task is, given the distribution of the peanuts and a certain period of time, tell how many peanuts Dodo could pick.  You can assume that each point contains a different amount of peanuts, except 0, which may appear more than once.
//
// 输入
// The first line of input contains the test case number T (1 <= T <= 20). For each test case, the first line contains three integers, M, N and K (1 <= M, N <= 50, 0 <= K <= 20000).  Each of the following M lines contain N integers. None of the integers will exceed 3000.  (M * N) describes the peanut field. The j-th integer X in the i-th line means there are X peanuts on the point (i, j). K means Dodo must return to the road in K units of time.
//
// 输出
// For each test case, print one line containing the amount of peanuts Dodo can pick.
//
// 样例输入
// 2
// 6 7 21
// 0 0 0 0 0 0 0
// 0 0 0 0 13 0 0
// 0 0 0 0 0 0 7
// 0 15 0 0 0 0 0
// 0 0 0 9 0 0 0
// 0 0 0 0 0 0 0
// 6 7 20
// 0 0 0 0 0 0 0
// 0 0 0 0 13 0 0
// 0 0 0 0 0 0 7
// 0 15 0 0 0 0 0
// 0 0 0 9 0 0 0
// 0 0 0 0 0 0 0
//
// 样例输出
// 37
// 28
//
// 来源
// Beijing 2004 Preliminary@POJ

