// B:堆栈基本操作
// 依次读入序列元素1,2,...,n进栈，每进一个元素，机器可要求下一个元素进栈或弹栈，如此进行。给定一个输入序列，
// 判断栈空时弹出的元素构成的序列是否可能等于给定的序列，如果是则输出栈的操作过程，否则输出“NO”。

// 第一行为n的值（即序列元素个数）
// 第二行为给定的输入序列（序列元素均为整型）

// 如果输入序列能够由题目规定的操作得到，则输出对栈的操作过程
// 否则直接输出“NO”
// 样例输入
// 7
// 4 5 3 6 2 7 1
// 样例输出
// PUSH 1
// PUSH 2
// PUSH 3
// PUSH 4
// POP 4
// PUSH 5
// POP 5
// POP 3
// PUSH 6
// POP 6
// POP 2
// PUSH 7
// POP 7
// POP 1

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main() {
    int n, temp;
    cin >> n;
    int cur = 1; // 记录当前数字到哪里了
    stack<int> num;
    queue<int> a;
    queue<string> answer;
    
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp > n || temp <= 0) {
            cout << "NO" << endl;
            return 0;
        }
        a.push(temp);
        // 把目标序列塞进a里面
    }

    bool canExpress = 1;
    for (int i = 0; i < n; ++i) {
        int target = a.front();
        a.pop(); // 先从队列里面找到目标数字
        ostringstream oss;
        while (cur <= n && (num.empty() || target > num.top())) {
            // 栈为空 or 栈顶 < 目标数字，尝试着继续从尾部添加数字，直到相等
            oss.str("");
            oss << "PUSH " << cur;
            answer.push(oss.str());
            num.push(cur++);
        }
        if (!num.empty() &&target == num.top()) {
            // 栈顶 == 目标数字，弹栈
            oss.str("");
            oss << "POP " << num.top();
            answer.push(oss.str());
            num.pop(); 
        }
        else {
            // 栈顶 > 目标数字，那么再往下进栈的数字只会更大，说明不能表示这个序列，直接回复NO
            canExpress = 0;
            break;
        }
    }
    
    if (canExpress) {
        while (!answer.empty()) {
            cout << answer.front() << endl;
            answer.pop();
        }
    }
    else {
        cout << "NO" << endl;
    }

}
