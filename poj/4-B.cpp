// B:字符串乘方
// 给定两个字符串a和b,我们定义a*b为他们的连接。例如，如果a=”abc” 而b=”def”， 则a*b=”abcdef”。 
// 如果我们将连接考虑成乘法，一个非负整数的乘方将用一种通常的方式定义：a^0=””(空字符串)，a^(n+1)=a*(a^n)。

// 输入
// 每一个测试样例是一行可打印的字符作为输入，用s表示。s的长度至少为1，且不会超过一百万。最后的测试样例后面将是一个点号作为一行。
// 输出
// 对于每一个s，你应该打印最大的n，使得存在一个a，让s=a^n
// 样例输入
// abcd
// aaaa
// ababab
// .
// 样例输出
// 1
// 4
// 3
#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main() {
    string s;
    while (cin >> s) {
        if (s == ".") {
            break;
        }
        else {
            int n = s.length();
            queue<int> a; // 从小到大的质因数队列
            for (int i = 2; i * i<= n; ++i) {
                while (n % i == 0) {
                    n /= i;
                    a.push(i);
                }
            }
            if (n > 1) {
                a.push(n);
            }
            n = s.length();
            int total = 1;
            while (!a.empty()) {
                int k = a.front();
                a.pop();
                int len = n / k;
                bool canAn = true;
                for (int i = len; i < n; ++i) {
                    if (s[i] != s[i % len]) {
                        canAn = false;
                        break;
                    }
                }
                if (canAn) {
                    s = s.substr(0,len);
                    n = len;
                    total *= k;
                }
            }
            cout << total << endl;
        }
    }
}