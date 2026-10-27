// 描述

// 首先老师有一个匹配模版，比如是“aa[123]bb”这一个字符串，同学们交的各种作业字符串如aa1bb、aa2bb、aa3bb都算是正确匹配看，而aacbb就是错误的字符串。
// （即待查字符串对应于模版方括号内的部分，应该为方括号内字符串的一个子字符）。
// 我们需要做的就是按照模版，找出正确的字符串和所在的行。

// 输入
// 输入的第一行为一个整数n，表示有多少个学生的作业，即有多少行需要检查的字符串。（1<=n<=50)
// 中间为n行字符串，代表着n个学生们写的作业。每个字符串长度小于50。
// 最后一行为1行字符串，代表着老师给的匹配模板。
// 输出
// 输出合格的字符串的行号和该字符串。（中间以空格隔开）
// 样例输入
// 4
// Aab
// a2B
// ab
// ABB
// a[a2b]b
// 样例输出
// 1 Aab
// 2 a2B
// 4 ABB
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
int main() {
    int n;
    cin >> n;
    queue<string> s;
    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        s.push(temp);
    }
    cin >> temp;
    size_t left = temp.find('['), right = temp.find(']');
    string front = temp.substr(0,left), 
           test = temp.substr(left + 1, right - left - 1), 
           back = temp.substr(right + 1, temp.length() - right - 1);

    for (int i = 0; i < n; ++i) {
        temp = s.front();
        s.pop();
        bool right = true;
        for (int j = 0; j < front.length(); ++j) {
            if (tolower(front[j]) != tolower(temp[j])) {
                right = false;
                break;
            }
        }
        if (right) {
            for (int j = 1; j < back.length() + 1; ++j) {
                if (tolower(back[back.length() - j]) != tolower(temp[temp.length() - j])) {
                    right = false;
                    break;
                }
            }
            if (right) {
                int p = 0;
                // if (temp.length() - front.length() - back.length() == 0) {
                //     continue;
                // }
                right = false;
                for (int j = front.length(); j < temp.length() - back.length(); ++j) {
                    right = false;
                    for (int k = p; k < test.length(); ++k) {
                        if (tolower(temp[j]) == tolower(test[k])) {
                            p = k + 1;
                            right = true;
                        }
                    }
                }
                if (right) {
                    cout << i+1 << " " << temp << endl;
                }
            }
        }
        
    }
    
    
}