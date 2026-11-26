// 1103 Painting A Board（全局题号 693）
// http://dsa.openjudge.cn/index/1103/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// The CE digital company has built an Automatic Painting Machine (APM) to paint a flat board fully covered by adjacent non-overlapping rectangles of different sizes each with  a predefined color.
// 〔原题配图 http://media.openjudge.cn/images/1691_1.jpg〕
//
// To color the board, the APM has access to a set of brushes. Each brush has a distinct color C. The APM picks one brush with color C and paints all possible rectangles having predefined color C with the following restrictions:
// To avoid leaking the paints and mixing colors, a rectangle can  only  be painted if all rectangles immediately above it have already  been painted. For example rectangle labeled F in Figure 1 is painted only after rectangles C and D are painted. Note that each rectangle must be painted at once, i.e. partial painting of one rectangle is not allowed.
// You are to write a  program for APM  to paint a  given  board  so that the number of  brush pick-ups is minimum.  Notice that if one brush is picked up more than once, all pick-ups are counted.
//
// 输入
// The first line of the input file contains an integer M which is the number of test cases to solve  (1 <= M <= 10). For each test case, the first line contains an integer N, the number of rectangles, followed by N lines describing the rectangles. Each rectangle R is specified by 5 integers in one line: the y and x coordinates of the upper left corner of R, the y and x coordinates of the lower right corner of R, followed by the color-code of R.
// Note that:
// Color-code is an integer in the range of 1 .. 20.
// Upper left corner of the board coordinates is always (0,0).
// Coordinates are in the range of 0 .. 99.
// N is in the range of 1..15.
//
// 输出
// One line for each test case showing the minimum number of brush pick-ups.
//
// 样例输入
// 1
// 7
// 0 0 2 2 1
// 0 2 1 6 2
// 2 0 4 2 1
// 1 2 4 4 2
// 1 4 3 6 1
// 4 0 6 4 1
// 3 4 6 6 2
//
// 样例输出
// 3
//
// 来源
// Tehran 1999

