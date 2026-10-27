// A:全在其中
// 你设计了一个新的加密技术，可以用一种聪明的方式在一个字符串的字符间插入随机的字符串从而对信息进行编码。由于专利问题，
// 我们将不会详细讨论如何在原有信息中产生和插入字符串。不过，为了验证你的方法，有必要写一个程序来验证原来的信息是否全在最后的字符串之中。
// 给定两个字符串s和t，你需要判断s是否是t的“子列”。也就是说，如果你去掉t中的某些字符，剩下字符将连接而成为s。

// 输入
// 输入包括多个测试样例。每一个都是由空格分隔的由字母数字ASCII字符组成的两个特定的字符串s和t。s和t的长度不超过100000。
// 输出
// 对于每个测试样例，如果s是t的“子列”，则输出”Yes”，否则输出”No”
// 样例输入
// sequence subsequence
// person compression
// VERDI vivaVittorioEmanueleReDiItalia
// caseDoesMatter CaseDoesMatter
// 样例输出
// Yes
// No
// Yes
// No
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s, t;
    while (cin >> s >> t) {
        int position = 0;
        bool isFind = false;
        for (int i = 0; i < s.length(); ++i) {
            int target = s[i];
            isFind = false;
            for (int j = position; j < t.length(); ++j) {
                if (target == t[j]) {
                    position = j + 1; // 记录下来当前位置的下一个位置，便于接着查找
                    isFind = true;
                    break;
                }
            }
            if (!isFind) {
                cout << "No" << endl;
                break;
            }
        }
        if (isFind) {
            cout << "Yes" << endl;
        }

    }
    

}