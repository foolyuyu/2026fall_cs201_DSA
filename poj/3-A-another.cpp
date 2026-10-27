// A:滑动窗口

// 给定一个长度为n（n<=10^6）的数组。有一个大小为k的滑动窗口从数组的最左端移动到最右端。你可以看到窗口中的k个数字。窗口每次向右滑动一个数字的距离。
// 你的任务是得到滑动窗口在每个位置时的最大值和最小值。


// 输入
// 输入包括两行。
// 第一行包括n和k，分别表示数组的长度和窗口的大小。
// 第二行包括n个数字。
// 输出
// 输出包括两行。
// 第一行包括窗口从左至右移动的每个位置的最小值。
// 第二行包括窗口从左至右移动的每个位置的最大值。
// 样例输入
// 8 3
// 1 3 -1 -3 5 3 6 7
// 样例输出
// -1 -3 -3 -3 3 3
// 3 3 5 5 6 7

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    deque<int> maxi, mini;
    vector<int> maxi_list, mini_list;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < k) {
            while (!maxi.empty() && a[maxi.back()] <= a[i]) {
                maxi.pop_back();
            }
            maxi.push_back(i);

            while (!mini.empty() && a[mini.back()] >= a[i]) {
                mini.pop_back();
            }
            mini.push_back(i);
            if (i == k - 1) {
                maxi_list.push_back(a[maxi.front()]);
                mini_list.push_back(a[mini.front()]);
            }
        } //先把前k个的搞出来
        else {
            
            if (maxi.front() == i - k) {
                maxi.pop_front();
            }
            if (mini.front() == i - k) {
                mini.pop_front();
            }
            // 如果刚好滑走的那一个值是当前最大值，才做弹出
            while (!maxi.empty() && a[maxi.back()] <= a[i]) {
                maxi.pop_back();
            }
            maxi.push_back(i);
            while (!mini.empty() && a[mini.back()] >= a[i]) {
                mini.pop_back();
            }
            mini.push_back(i);
            // 把滑动多出来的那个值经过检验，放到最后
            
            maxi_list.push_back(a[maxi.front()]);
            mini_list.push_back(a[mini.front()]);
        }
    }
    for (int i = 0; i < n - k + 1; ++i) {
        cout << mini_list[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n - k + 1; ++i) {
        cout << maxi_list[i] << " ";
    }
    cout << endl;
}