/* 描述
 * 有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（字符个数不包括字符串结尾处的'\0'。）将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。
 * 输入
 * 输入包括若干行，每一行为一组测试数据，格式为
 * str substr
 * 输出
 * 对于每一组测试数据，输出插入之后的字符串。
 * 样例输入
 * abcab eee
 * 12343 555
 * 样例输出
 *  abceeeab
 *  12345553*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str, substr;
    while(cin >> str >> substr) {
        int n = str.length();
        int max = static_cast<int>(str[0]), p = 0;
        for (int i = 0; i < n; ++i) {
            if (max < static_cast<int>(str[i])) {
                max = static_cast<int>(str[i]);
                p = i;
            }
        }
        string result = str.substr(0, p+1) + substr + str.substr(p+1, n);
        cout << result << endl;
    }
}