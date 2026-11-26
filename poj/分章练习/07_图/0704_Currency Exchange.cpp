// 0704 Currency Exchange（全局题号 862）
// http://dsa.openjudge.cn/graph/0704/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// Several currency exchange points are working in our city. Let us suppose that each point specializes in two particular currencies and performs exchange operations only with these currencies. There can be several points specializing in the same pair of currencies. Each point has its own exchange rates, exchange rate of A to B is the quantity of B you get for 1A. Also each exchange point has some commission, the sum you have to pay for your exchange operation. Commission is always collected in source currency.
// For example, if you want to exchange 100 US Dollars into Russian Rubles at the exchange point, where the exchange rate is 29.75, and the commission is 0.39 you will get (100 - 0.39) * 29.75 = 2963.3975RUR.
// You surely know that there are N different currencies you can deal with in our city. Let us assign unique integer number from 1 to N to each currency. Then each exchange point can be described with 6 numbers: integer A and B - numbers of currencies it exchanges, and real R_(AB), C_(AB), R_(BA) and C_(BA) - exchange rates and commissions when exchanging A to B and B to A respectively.
// Nick has some money in currency S and wonders if he can somehow, after some exchange operations, increase his capital. Of course, he wants to have his money in currency S in the end. Help him to answer this difficult question. Nick must always have non-negative sum of money while making his operations.
//
// 输入
// The first line of the input contains four numbers: N - the number of currencies, M - the number of exchange points, S - the number of currency Nick has and V - the quantity of currency units he has. The following M lines contain 6 numbers each - the description of the corresponding exchange point - in specified above order. Numbers are separated by one or more spaces. 1<=S<=N<=100, 1<=M<=100, V is real number, 0<=V<=10^(3).
// For each point exchange rates and commissions are real, given with at most two digits after the decimal point, 10^(-2)<=rate<=10^(2), 0<=commission<=10^(2).
// Let us call some sequence of the exchange operations simple if no exchange point is used more than once in this sequence. You may assume that ratio of the numeric values of the sums at the end and at the beginning of any simple sequence of the exchange operations will be less than 10^(4).
//
// 输出
// If Nick can increase his wealth, output YES, in other case output NO to the output file.
//
// 样例输入
// 3 2 1 20.0
// 1 2 1.00 1.00 1.00 1.00
// 2 3 1.10 1.00 1.10 1.00
//
// 样例输出
// YES
//
// 来源
// Northeastern Europe 2001, Northern Subregion

