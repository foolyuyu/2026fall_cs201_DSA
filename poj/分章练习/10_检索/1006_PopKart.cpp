// 1006 PopKart（全局题号 2412）
// http://dsa.openjudge.cn/retrieval/1006/
// 总时间限制 5000ms  内存限制 131072kB
//
// 描述
// Xiao Feng is a big fan of the online multiplayer racing game PopKart. Among various types of play, Xiao Feng prefers the Speed Game, in which players compete to be the fastest racer. In order to win the races, apart from solid driving skills, the player must also own a top-class kart. Results of races among experienced players are mostly decided by the karts which they ride.
// Now a new generation of karts has hit the market. Xiao Feng wants to purchase one of them. Two factors prevents him from going straightly for the best ones. First, the available (virtual) funds are limited. Second and more importantly, it is a non-trivial task to decide which karts are the best.
// To find out the best karts that he can afford, Xiao Feng employs a simple scheme to classify the karts by their performance.
// The performance of a kart is characterized by two parameters—the straight-line speed v and the drift speed w. A kart is said to be superior to another if and only if it is superior in either speed and not inferior in the other. All karts to which no other karts are superior are classified as karts of class 1. For each m ≥ 2, all karts to which only karts of classes 1 through m − 1 are superior are classified as karts of class m.
// Given the straight-line and drift speeds of n karts, classify them as specified above.
//
// 输入
// The input contains a single test case. The first line contains n (1 ≤ n ≤ 10^(5)). The remaining n lines each contain two integers v and w (0 ≤ v, w < 10^(6)), the straight-line and drift speeds of a kart.
//
// 输出
// For each class in increasing order of m, print a list of karts of that class using the format
// “k: (v_(1),w_(1)) (v_(2),w_(2)) ⋯ (v_(k),w_(k))”
// where k is the number of karts of that class, and (v_(1), w_(1)), (v_(2), w_(2)), …, (v_(k), w_(k)) are their straight-line and drift speeds. The k pairs of speeds shall be sorted so that v_(i) < v_(j) ∨ (v_(i) = v_(j) ∧ w_(i) ≤ w_(j)) for any 1 ≤ i < j ≤ k (“∨” and “∧” represent logical OR and AND, respectively).
//
// 样例输入
// 4
// 1 2
// 2 1
// 2 3
// 3 2
//
// 样例输出
// 2: (2,3) (3,2)
// 2: (1,2) (2,1)
//
// 来源
// PKU Campus 2008, xfxyjwf

