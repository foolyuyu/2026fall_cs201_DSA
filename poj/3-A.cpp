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
#include <set>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<int> window;
    int l = 0, r = k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < k) {
            window.insert(a[i]);
        }
    }
    vector<int> maxi(n - k + 1), mini(n - k + 1);
    for (int i = 0; i < n - k + 1; ++i) {
        mini[i] = *window.begin();
        maxi[i] = *prev(window.end());
        if (i == n - k) {
            break;
        }
        window.erase(window.find(a[l++]));
        window.insert(a[r++]);
    }
    for (int i = 0; i < n - k + 1; ++i) {
        cout << mini[i];
        if (i == n - k) {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }
    for (int i = 0; i < n - k + 1; ++i) {
        cout << maxi[i];
        if (i == n - k) {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }
    

}