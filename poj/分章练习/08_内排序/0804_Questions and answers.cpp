// 0804 Questions and answers（全局题号 1373）
// http://dsa.openjudge.cn/sort/0804/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// The database of the Pentagon contains a top-secret information. We don't know what the information is — you know, it's top-secret, — but we know the format of its representation. It is extremely simple. We don't know why, but all the data is coded by the natural numbers from 1 up to 5000. The size of the main base (we'll denote it be N) is rather big — it may contain up to 100 000 those numbers. The database is to process quickly every query. The most often query is: "Which element is i-th by its value?"— with i being a natural number in a range from 1 to N.
//
// Your program is to play a role of a controller of the database. In the other words, it should be able to process quickly queries like this.
//
// 输入
// The standard input of the problem consists of two parts. At first, a database is written, and then there's a sequence of queries. The format of database is very simple: in the first line there's a number N, in the next N lines there are numbers of the database one in each line in an arbitrary order. A sequence of queries is written simply as well: in the first line of the sequence a number of queries K (1 <= K <= 100) is written, and in the next K lines there are queries one in each line. The query "Which element is i-th by its value?" is coded by the number i. A database is separated from a sequence of queries by the string of three symbols "#".
//
// 输出
// The output should consist of K lines. In each line there should be an answer to the corresponding query. The answer to the query "i" is an element from the database, which is i-th by its value (in the order from the least up to the greatest element).
//
// 样例输入
// 5
// 7
// 121
// 123
// 7
// 121
// ###
// 4
// 3
// 3
// 2
// 5
//
// 样例输出
// 121
// 121
// 7
// 123
//
// 来源
// Ural State University Internal Contest October'2000 Junior Session

