// C:中缀表达式的值

// 人们熟悉的四则运算表达式称为中缀表达式，例如(23+34*45/(5+6+7))。在程序设计语言中，可以利用堆栈的方法把中缀表达式转换成保值的后缀表达式（又称逆波兰表示法）
// ，并最终变为计算机可以直接执行的指令，得到表达式的值。

// 给定一个中缀表达式，编写程序，利用堆栈的方法，计算表达式的值。
// 输入
// 第一行为测试数据的组数N
// 接下来的N行，每行是一个中缀表达式。表达式中只含数字、四则运算符和圆括号，操作数都是正整数，数和运算符、括号之间没有空格。中缀表达式的字符串长度不超过600。
// 输出
// 对每一组测试数据输出一行，为表达式的值
// 样例输入
// 3
// 3+5*8
// (3+5)*8
// (23+34*45/(5+6+7))
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;



int main() {
    int n;
    cin >> n;
    string s;
    stack<int> num;
    stack<char> op;
    for (int z = 0; z < n; ++z) {
        cin >> s;
        ostringstream oss(s);
        int temp;
        oss << temp;
        num.push(temp;)

        for(int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                
            }
            else {
                op.push(s[i]);
            }
        }
    }
}