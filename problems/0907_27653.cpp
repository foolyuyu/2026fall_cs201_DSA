// problem-sync:start
// #region 题目
// 题目：27653. Fraction类
// 日期：0907
// 难度：Easy
// 标签：OOP
// 平台：openjudge
// 通过率：376/381 人（98.7%）
// 原题：http://cs101.openjudge.cn/pctbook/E27653/
// 模板指纹：e98b092c7a2ab4b20ef0478796958fcdb4cdf4b19ee215cc49a3046b777fc410
// 【题目描述】
// 总时间限制:
// 1000ms
// 内存限制:
// 65536kB
// 描述
// 实现用户定义的类，一个常用的例子是构建实现抽象数据类型Fraction的类。我们已经看到，Python
// 提供了很多数值类。但是在有些时候，需要创建“看上去很像”分数的数据对象。
// 像 3/5​ 这样的分数由两部分组成。斜线左侧的值称作分子，可以是任意整数。斜线右侧的值称作分
// 母，可以是任意大于0的整数（负的分数带有负的分子）。尽管可以用浮点数来近似表示分数，但我
// 们在此希望能精确表示分数的值。
// Fraction对象的表现应与其他数值类型一样，针对分数进行加、减、乘、除等运算，也能够使用标准
// 的斜线形式来显示分数，比如3/5。此外，所有的分数方法都应该返回结果的最简形式。这样一来，
// 不论进行何种运算，最后的结果都是最简分数。
// 出于练习考虑，只需要支持一种分数加运算。
// 输入
// 空格分割的一行字符串。第一个分数的分子 第一个分数的分母 第二个分数的分子 第二个分数的分
// 母
// 输出
// 输出相加的结果。使用标准的斜线形式来显示分数，并且要求是最简分数。
// 样例输入
// 1 4 1 2
// 样例输出
// 3/4
// 提示
// OOP
// 来源
// yan, https://runestone.academy/ns/books/published/pythonds3/Introduction/ObjectOrientedProgrammingin
// #endregion
// problem-sync:end

#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return abs(b);
    }
    else {
        return abs(gcd(b, a % b));
    }
}


class Fraction {
public:
    int son, mum;

    Fraction(int son, int mum) : son{son}, mum{mum} {}
    Fraction operator+(Fraction& F) {
        int mum_result = this->mum * F.mum / gcd(this->mum, F.mum);
        int son_result = this->son * (mum_result / this->mum) + F.son * (mum_result / F.mum);
        int a = gcd(mum_result, son_result);
        return Fraction(son_result / a, mum_result / a);
    }
    friend ostream& operator<< (ostream& os, const Fraction& F) {
        os << F.son << "/" << F.mum;
        return os;
    }
};


int main() {
    int son_1, son_2, mum_1, mum_2;
    cin >> son_1 >> mum_1 >> son_2 >> mum_2;
    Fraction a(son_1, mum_1), b(son_2, mum_2);
    cout << (a + b) << endl;


    return 0;
}
