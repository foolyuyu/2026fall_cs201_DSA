// 0401 英语数字转换器（全局题号 1123）
// http://dsa.openjudge.cn/string/0401/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// 在这个问题中，将用英语给你一个或多个整数。你的任务是将这些数字转换成整型表示。数字范围从-999,999,999到999,999,999.下面是你的程序必须考虑的详尽的英语单词表：
// negative, zero, one, two, three, four,five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen,fifteen, sixteen, seventeen, eighteen, nineteen, twenty, thirty, forty, fifty,sixty, seventy, eighty, ninety, hundred, thousand, million
//
// 输入
// 输入包括多个样例，注意：
//
// 1.负数前面有词negative
//
// 2.当能用thousand的时候，将不用hundred。例如1500将写为"one thousand five hundred",而不是"fifteen hundred".
//
// 输入将以一个空行结束
//
// 输出
// 输出将是每一个单独一行，每一个后面一个换行符
//
// 样例输入
// six
// negative seven hundred twenty nine
// one million one hundred one
// eight hundred fourteen thousand twenty two
//
// 样例输出
// 6
// -729
// 1000101
// 814022
//
// 来源
// CTU Open 2004,UVA 486

