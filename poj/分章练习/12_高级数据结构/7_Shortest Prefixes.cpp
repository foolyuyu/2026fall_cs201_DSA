// 7 Shortest Prefixes（全局题号 1003）
// http://dsa.openjudge.cn/advance/7/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// A prefix of a string is a substring starting at the beginning of the given string. The prefixes of "carbon" are: "c", "ca", "car", "carb", "carbo", and "carbon". Note that the empty string is not considered a prefix in this problem, but every non-empty string is considered to be a prefix of itself. In everyday language, we tend to abbreviate words by prefixes. For example, "carbohydrate" is commonly abbreviated by "carb". In this problem, given a set of words, you will find for each word the shortest prefix that uniquely identifies the word it represents.
//
// In the sample input below, "carbohydrate" can be abbreviated to "carboh", but it cannot be abbreviated to "carbo" (or anything shorter) because there are other words in the list that begin with "carbo".
//
// An exact match will override a prefix match. For example, the prefix "car" matches the given word "car" exactly. Therefore, it is understood without ambiguity that "car" is an abbreviation for "car" , not for "carriage" or any of the other words in the list that begins with "car".
//
// 输入
// The input contains at least two, but no more than 1000 lines. Each line contains one word consisting of 1 to 20 lower case letters.
//
// 输出
// The output contains the same number of lines as the input. Each line of the output contains the word from the corresponding line of the input, followed by one blank space, and the shortest prefix that uniquely (without ambiguity) identifies this word.
//
// 样例输入
// carbohydrate
// cart
// carburetor
// caramel
// caribou
// carbonic
// cartilage
// carbon
// carriage
// carton
// car
// carbonate
//
// 样例输出
// carbohydrate carboh
// cart cart
// carburetor carbu
// caramel cara
// caribou cari
// carbonic carboni
// cartilage carti
// carbon carbon
// carriage carr
// carton carto
// car car
// carbonate carbona
//
// 来源
// Rocky Mountain 2004

