// 0717 Catenyms（全局题号 1339）
// http://dsa.openjudge.cn/graph/0717/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// A catenym is a pair of words separated by a period such that the last letter of the first word is the same as the last letter of the second. For example, the following are catenyms:
// dog.gopher
// gopher.rat
// rat.tiger
// aloha.aloha
// arachnid.dog
// A compound catenym is a sequence of three or more words separated by periods such that each adjacent pair of words forms a catenym. For example,
//
// aloha.aloha.arachnid.dog.gopher.rat.tiger
//
// Given a dictionary of lower case words, you are to find a compound catenym that contains each of the words exactly once.
//
// 输入
// The first line of standard input contains t, the number of test cases. Each test case begins with 3 <= n <= 1000 - the number of words in the dictionary. n distinct dictionary words follow; each word is a string of between 1 and 20 lowercase letters on a line by itself.
//
// 输出
// For each test case, output a line giving the lexicographically least compound catenym that contains each dictionary word exactly once. Output "***" if there is no solution.
//
// 样例输入
// 2
// 6
// aloha
// arachnid
// dog
// gopher
// rat
// tiger
// 3
// oak
// maple
// elm
//
// 样例输出
// aloha.arachnid.dog.gopher.rat.tiger
// ***
//
// 来源
// Waterloo local 2003.01.25

