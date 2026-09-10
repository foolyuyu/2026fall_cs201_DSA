// problem-sync:start
// #region 题目
// 题目：05443. 兔子与樱花
// 日期：0910
// 难度：Medium
// 标签：Dijkstra, Floyd-Warshall
// 平台：openjudge
// 通过率：395/401 人（98.5%）
// 原题：http://cs101.openjudge.cn/practice/05443
// 模板指纹：e98b092c7a2ab4b20ef0478796958fcdb4cdf4b19ee215cc49a3046b777fc410
// 【题目描述】
// 总时间限制:
// 1000ms
// 内存限制:
// 65535kB
// 描述
// 很久很久之前，森林里住着一群兔子。有一天，兔子们希望去赏樱花，但当他们到了上野公园门口却
// 忘记了带地图。现在兔子们想求助于你来帮他们找到公园里的最短路。
// 输入
// 输入分为三个部分。
// 第一个部分有P+1行（P<30），第一行为一个整数P，之后的P行表示上野公园的地点, 字符串长度不
// 超过20。
// 第二个部分有Q+1行（Q<50），第一行为一个整数Q，之后的Q行每行分别为两个字符串与一个整数，
// 表示这两点有直线的道路，并显示二者之间的矩离（单位为米）。
// 第三个部分有R+1行（R<20），第一行为一个整数R，之后的R行每行为两个字符串，表示需要求的路
// 线。
// 输出
// 输出有R行，分别表示每个路线最短的走法。其中两个点之间，用->(矩离)->相隔。
// 样例输入
// 6
// Ginza
// Sensouji
// Shinjukugyoen
// Uenokouen
// Yoyogikouen
// Meijishinguu
// 6
// Ginza Sensouji 80
// Shinjukugyoen Sensouji 40
// Ginza Uenokouen 35
// Uenokouen Shinjukugyoen 85
// Sensouji Meijishinguu 60
// Meijishinguu Yoyogikouen 35
// 2
// Uenokouen Yoyogikouen
// Meijishinguu Meijishinguu
// 样例输出
// Uenokouen->(35)->Ginza->(80)->Sensouji->(60)->Meijishinguu->(35)->Yoyogikouen
// Meijishinguu
// #endregion
// problem-sync:end

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P, Q, R;
    cin >> P;
    vector<string> place(P);
    for (int i = 0; i < P; ++i) {
        cin >> place[i];
    }
    cin >> Q;
    string s, d;
    int distance;
    vector<vector<int>> dist(P, vector<int>(P)); // 记录最短距离
    vector<vector<string>> route(P, vector<string>(P)); // 记录最短距离对应路径

    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            dist[i][j] = INT_MAX;
        }
        dist[i][i] = 0;
        route[i][i] = place[i];
    }
    for (int i = 0; i < Q; ++i) {
        cin >> s >> d >> distance;
        int x = find(place.begin(), place.end(), s) - place.begin();
        int y = find(place.begin(), place.end(), d) - place.begin();
        dist[x][y] = dist[y][x] = distance;
        route[x][y] = route[x][x] + "->(" + to_string(distance) + ")->";
        route[y][x] = route[y][y] + "->(" + to_string(distance) + ")->"; // 为了防止路径重复，目的地我在最后打印出来的时候加上
    }

    for (int k = 0; k < P; ++k) {
        // 选择某个点作为中转点，看看它是否能让已知路径变得简单
        for (int i = 0; i < P; ++i) {
            if (dist[i][k] == INT_MAX) {
                continue;
            }
            for (int j = i + 1; j < P; ++j) {
                if (dist[j][k] == INT_MAX) {
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[j][k]) {
                    dist[j][i] = dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j] = route[i][k] + route[k][j];
                    route[j][i] = route[j][k] + route[k][i];
                }
            }
        }
    }

    cin >> R;
    for (int i = 0; i < R; ++i) {
        cin >> s >> d;
        auto x = find(place.begin(), place.end(), s) - place.begin();
        auto y = find(place.begin(), place.end(), d) - place.begin();
        if (x == y) {
            cout << route[x][x] << endl;
        }
        else {
            cout << route[x][y] << route[y][y] << endl;
        }
        
        
    }   


    return 0;
}
