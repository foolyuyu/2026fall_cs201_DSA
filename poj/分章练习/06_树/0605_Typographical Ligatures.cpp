// 0605 Typographical Ligatures（全局题号 2416）
// http://dsa.openjudge.cn/tree/0605/
// 总时间限制 1000ms  内存限制 131072kB
//
// 描述
// Typesetting involves the presentation of textual material in graphic form on paper or some other medium. Close as it is related to our daily life, typesetting exhibits certain complexities which may be unfamiliar and sometimes unimaginable to the layman. The use of typographical ligatures is one such complexity.
// Compare the two appearances of the word “define” in Figure 7. Figure 7(a) illustrates the word typeset with the “fi” ligature as Knuth’s TeX does. The letters “f” and “i” are combined into a single glyph. Figure 7(b) shows the word typeset without the ligature as Microsoft Word does. The letters “f” and “i” remain separate. Other examples include the “ff”, “ffi”, “fl” and “ffl” ligatures, as shown in Figure 8. Perhaps the most notable ligature in active use is the “&” (ampersand), which originated from “et”, the Latin word for “and”.
// deﬁne  |    |  define  |
// (a)  |    |  (b)  |
//
// Figure 7: The word “define” typeset with and without the “fi” ligature
// eﬀect  |    |  oﬃce  |    |  reﬂect  |    |  waﬄe  |
//
// Figure 8: Examples of the “ff”, “ffi”, “fl” and “ffl” ligatures
// Ligatures are primarily intended to improve spacing between letters. Despite that their impact on legibility is debated and that their use is declining, some people insist that they are an essential part of quality typesetting. In order to typeset ligatures, separate glyphs have to be used since ligatures generally differ from direct combinations of their constituent letters in most cases.
// Given some text, count the number of glyphs that have to be used to typeset it. Only the “ff”, “fi”, “ffi”, “fl”, and “ffl” ligatures are considered. Note that they are case-sensitive. Ligatures are recognized following the leftmost longest rule—find the leftmost match, then the longest match if there are any ties. Each distinct letter, ligature or punctuation mark requires a separate glyph. However, if a letter appears only in ligatures and nowhere else, it shall not be assigned a glyph. Furthermore, left single and double quotes differ from their right counterparts. Spaces do not require a glyph.
//
// 输入
// The input contains a single test case consisting of some text. The text is given on multiple lines not longer than 100 characters each. The text contains only letters (lowercase and uppercase), punctuation marks and spaces. Punctuation marks include periods, commas, semicolons, colons, single and double quotes, exclamation and question marks. Quotes are represented by “`” (left single quote), “'” (right single quote), “``” (left double quote) and “''” (right double quote), respectively. They are also recognized following the leftmost longest rule. The input ends where EOF is met.
//
// 输出
// Print the number of glyphs that have to be used to typeset the given text.
//
// 样例输入
// ```define, effect; office.
// reflect? waffle!'''
//
// 样例输出
// 23
//
// 提示
// The text in the sample is typeset as Figure 9. The 23 used glyphs are listed in Figure 10 in the order of their first appearances in Figure 9.
// “‘deﬁne, eﬀect; oﬃce.
// reﬂect? waﬄe!”’  |
//
// Figure 9: Result of typesetting the text in the sample
// “  |  ‘  |  d  |  e  |  ﬁ  |  n  |  ,  |  ﬀ  |
// c  |  t  |  ;  |  o  |  ﬃ  |  .  |  r  |  ﬂ  |
// ?  |  w  |  a  |  ﬄ  |  !  |  ”  |  ’  |    |
//
// Figure 10: Glyphs appearing in Figure 9
//
// 来源
// PKU Campus 2008, frkstyc

