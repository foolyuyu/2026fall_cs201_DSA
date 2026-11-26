// 0705 Truck History（全局题号 791）
// http://dsa.openjudge.cn/graph/0705/
// 总时间限制 2000ms  内存限制 65536kB
//
// 描述
// Advanced Cargo Movement, Ltd. uses trucks of different types. Some trucks are used for vegetable delivery, other for furniture, or for bricks. The company has its own code describing each type of a truck. The code is simply a string of exactly seven lowercase letters (each letter on each position has a very special meaning but that is unimportant for this task). At the beginning of company's history, just a single truck type was used but later other types were derived from it, then from the new types another types were derived, and so on.
//
// Today, ACM is rich enough to pay historians to study its history. One thing historians tried to find out is so called derivation plan -- i.e. how the truck types were derived. They defined the distance of truck types as the number of positions with different letters in truck type codes. They also assumed that each truck type was derived from exactly one other truck type (except for the first truck type which was not derived from any other type). The quality of a derivation plan was then defined as
// 1/Σ_((t_(o),t_(d)))d(t_(o),t_(d))
//
// where the sum goes over all pairs of types in the derivation plan such that t_(o) is the original type and t_(d) the type derived from it and d(t_(o),t_(d)) is the distance of the types.
// Since historians failed, you are to write a program to help them. Given the codes of truck types, your program should find the highest possible quality of a derivation plan.
//
// 输入
// The input consists of several test cases. Each test case begins with a line containing the number of truck types, N, 2 <= N <= 2 000. Each of the following N lines of input contains one truck type code (a string of seven lowercase letters). You may assume that the codes uniquely describe the trucks, i.e., no two of these N lines are the same. The input is terminated with zero at the place of number of truck types.
//
// 输出
// For each test case, your program should output the text "The highest possible quality is 1/Q.", where 1/Q is the quality of the best derivation plan.
//
// 样例输入
// 4
// aaaaaaa
// baaaaaa
// abaaaaa
// aabaaaa
// 0
//
// 样例输出
// The highest possible quality is 1/3.
//
// 来源
// CTU Open 2003

