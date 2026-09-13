# problem-sync:start
# #region 题目
# 题目：05443. 兔子与樱花
# 顺序：006
# 难度：未标注
# 标签：未标注
# 平台：openjudge
# 通过率：422/428 人（98.6%）
# 原题：http://cs101.openjudge.cn/practice/05443/
# 模板指纹：5f9490cc5dfd7f9f26607b3e33c8de291ae5edac6a271bc204488b04ffb202f7
# 【题目描述】
# 总时间限制:
# 1000ms
# 内存限制:
# 65535kB
# 描述
# 很久很久之前，森林里住着一群兔子。有一天，兔子们希望去赏樱花，但当他们到了上野公园门口却
# 忘记了带地图。现在兔子们想求助于你来帮他们找到公园里的最短路。
# 输入
# 输入分为三个部分。
# 第一个部分有P+1行（P<30），第一行为一个整数P，之后的P行表示上野公园的地点, 字符串长度不
# 超过20。
# 第二个部分有Q+1行（Q<50），第一行为一个整数Q，之后的Q行每行分别为两个字符串与一个整数，
# 表示这两点有直线的道路，并显示二者之间的矩离（单位为米）。
# 第三个部分有R+1行（R<20），第一行为一个整数R，之后的R行每行为两个字符串，表示需要求的路
# 线。
# 输出
# 输出有R行，分别表示每个路线最短的走法。其中两个点之间，用->(矩离)->相隔。
# 样例输入
# 6
# Ginza
# Sensouji
# Shinjukugyoen
# Uenokouen
# Yoyogikouen
# Meijishinguu
# 6
# Ginza Sensouji 80
# Shinjukugyoen Sensouji 40
# Ginza Uenokouen 35
# Uenokouen Shinjukugyoen 85
# Sensouji Meijishinguu 60
# Meijishinguu Yoyogikouen 35
# 2
# Uenokouen Yoyogikouen
# Meijishinguu Meijishinguu
# 样例输出
# Uenokouen->(35)->Ginza->(80)->Sensouji->(60)->Meijishinguu->(35)->Yoyogikouen
# Meijishinguu
# #endregion
# problem-sync:end

import sys


def solve() -> None:
    data = sys.stdin.read().split()
    # TODO: 在这里编写解答。
    _ = data


if __name__ == "__main__":
    solve()
