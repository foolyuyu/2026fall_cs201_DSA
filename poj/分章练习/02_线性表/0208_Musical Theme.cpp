// 0208 Musical Theme（全局题号 745）
// http://dsa.openjudge.cn/linearlist/0208/
// 总时间限制 1000ms  内存限制 300000kB
//
// 描述
// A musical melody is represented as a sequence of N (1<=N<=20000)notes that are integers in the range 1..88, each representing a key on the piano. It is unfortunate but true that this representation of melodies ignores the notion of musical timing; but, this programming task is about notes and not timings.
// Many composers structure their music around a repeating &qout;theme&qout;, which, being a subsequence of an entire melody, is a sequence of integers in our representation. A subsequence of a melody is a theme if it:
// is at least five notes long
// appears (potentially transposed -- see below) again somewhere else in the piece of music
// is disjoint from (i.e., non-overlapping with) at least one of its other appearance(s)
//
// Transposed means that a constant positive or negative value is added to every note value in the theme subsequence.
// Given a melody, compute the length (number of notes) of the longest theme.
// One second time limit for this problem's solutions!
//
// 输入
// The input contains several test cases. The first line of each test case contains the integer N. The following n integers represent the sequence of notes.
// The last test case is followed by one zero.
//
// 输出
// For each test case, the output file should contain a single line with a single integer that represents the length of the longest theme. If there are no themes, output 0.
//
// 样例输入
// 30
// 25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18
// 82 78 74 70 66 67 64 60 65 80
// 0
//
// 样例输出
// 5
//
// 提示
// Use scanf instead of cin to reduce the read time.
//
// 来源
// LouTiancheng@POJ

