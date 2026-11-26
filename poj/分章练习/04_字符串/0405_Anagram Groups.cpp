// 0405 Anagram Groups（全局题号 1410）
// http://dsa.openjudge.cn/string/0405/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// World-renowned Prof. A. N. Agram's current research deals with large anagram groups. He has just found a new application for his theory on the distribution of characters in English language texts. Given such a text, you are to find the largest anagram groups.
//
// A text is a sequence of words. A word w is an anagram of a word v if and only if there is some permutation p of character positions that takes w to v. Then, w and v are in the same anagram group. The size of an anagram group is the number of words in that group. Find the 5 largest anagram groups.
//
// 输入
// The input contains words composed of lowercase alphabetic characters, separated by whitespace(or new line). It is terminated by EOF. You can assume there will be no more than 30000 words.
//
// 输出
// Output the 5 largest anagram groups. If there are less than 5 groups, output them all. Sort the groups by decreasing size. Break ties lexicographically by the lexicographical smallest element. For each group output, print its size and its member words. Sort the member words lexicographically and print equal words only once.
//
// 样例输入
// undisplayed
// trace
// tea
// singleton
// eta
// eat
// displayed
// crate
// cater
// carte
// caret
// beta
// beat
// bate
// ate
// abet
//
// 样例输出
// Group of size 5: caret carte cater crate trace .
// Group of size 4: abet bate beat beta .
// Group of size 4: ate eat eta tea .
// Group of size 1: displayed .
// Group of size 1: singleton .
//
// 来源
// Ulm Local 2000

