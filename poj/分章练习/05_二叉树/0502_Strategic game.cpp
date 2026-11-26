// 0502 Strategic game（全局题号 465）
// http://dsa.openjudge.cn/binarytree/0502/
// 总时间限制 2000ms  内存限制 65536kB
//
// 描述
// Bob enjoys playing computer games, especially strategic games, but sometimes he cannot find the solution fast enough and then he is very sad. Now he has the following problem. He must defend a medieval city, the roads of which form a tree. He has to put the minimum number of soldiers on the nodes so that they can observe all the edges. Can you help him?
//
// Your program should find the minimum number of soldiers that Bob has to put for a given tree.
//
// For example for the tree:
// 〔原题配图 http://media.openjudge.cn/images/g465/1463_1.jpg〕
//
// the solution is one soldier ( at the node 1).
//
// 输入
// The input contains several data sets in text format. Each data set represents a tree with the following description:
//
// 	the number of nodes
// 	the description of each node in the following format
// node_identifier:(number_of_roads) node_identifier_(1) node_identifier_(2) ... node_identifier_(number_of_roads)
// or
// node_identifier:(0)
//
// 	The node identifiers are integer numbers between 0 and n-1, for n nodes (0 < n <= 1500);the number_of_roads in each line of input will no more than 10. Every edge appears only once in the input data.
//
// 输出
// The output should be printed on the standard output. For each given input data set, print one integer number in a single line that gives the result (the minimum number of soldiers). An example is given in the following:
//
// 样例输入
// 4
// 0:(1) 1
// 1:(2) 2 3
// 2:(0)
// 3:(0)
// 5
// 3:(3) 1 4 2
// 1:(1) 0
// 2:(0)
// 0:(0)
// 4:(0)
//
// 样例输出
// 1
// 2
//
// 来源
// Southeastern Europe 2000

