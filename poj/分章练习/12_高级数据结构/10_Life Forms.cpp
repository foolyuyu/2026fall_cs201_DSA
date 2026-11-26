// 10 Life Forms（全局题号 2441）
// http://dsa.openjudge.cn/advance/10/
// 总时间限制 5000ms  内存限制 65536kB
//
// 描述
// You may have wondered why most extraterrestrial life forms resemble humans, differing by superficial traits such as height, colour, wrinkles, ears, eyebrows and the like. A few bear no human resemblance; these typically have geometric or amorphous shapes like cubes, oil slicks or clouds of dust.
// The answer is given in the 146th episode of Star Trek - The Next Generation, titled The Chase. It turns out that in the vast majority of the quadrant's life forms ended up with a large fragment of common DNA.
// Given the DNA sequences of several life forms represented as strings of letters, you are to find the longest substring that is shared by more than half of them.
//
// 输入
// Standard input contains several test cases. Each test case begins with 1 ≤ n ≤ 100, the number of life forms. n lines follow; each contains a string of lower case letters representing the DNA sequence of a life form. Each DNA sequence contains at least one and not more than 1000 letters. A line containing 0 follows the last test case.
//
// 输出
// For each test case, output the longest string or strings shared by more than half of the life forms. If there are many, output all of them in alphabetical order. If there is no solution with at least one letter, output "?". Leave an empty line between test cases.
//
// 样例输入
// 3
// abcdefg
// bcdefgh
// cdefghi
// 3
// xxx
// yyy
// zzz
// 0
//
// 样例输出
// bcdefg
// cdefgh
//
// ?

