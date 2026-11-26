// 0402 References（全局题号 708）
// http://dsa.openjudge.cn/string/0402/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// Editors of an electronic magazine make draft versions of the documents in the form of text files. However, publications should meet some requirements, in particular, concerning the rules of reference use. Unfortunately, lots of the draft articles violate some rules. It is desirable to develop a computer program that will make a publication satisfy all the rules from a draft version.
//
// Let's call a "paragraph" a set of lines in the article going one after another, so that paragraphs are separated by at least one empty line (an "empty line" is a line that containing no characters different from spaces). Any paragraph can contain an arbitrary number of references. A reference is a positive integer not greater than 999 enclosed in square brackets (for example: [23]). There will be no spaces between the brackets and the number. The square brackets are not used in any other context but reference.
//
// There can be two types of paragraph - "regular" and "reference description". Reference description differs from the regular paragraph because it begins with the reference it describes, for example:
//
// [23] It is the description ...
//
// The opening square bracket will be at the first position of the first line of the "reference description" paragraph (i.e. there will be no spaces before it). No reference description paragraph will contain references inside itself.
//
// Each reference will have exactly one corresponding description and each description will have at least one reference to it.
//
// To convert a draft version to a publication you have to use the following rules.
//
// References should be renumbered by the successive integer numbers starting from one in the order of their first appearance in the regular paragraphs of the source draft version of the document.
// Reference descriptions should be placed at the end of the article ordered by their number.
// The order of "regular" paragraphs in the document should be preserved.
// Your program should not make any other changes to the paragraphs.
//
// 输入
// The input file will be a text file containing a draft article your program should process. All lines will be no more than 80 characters long. Any reference description will contain no more than 3 lines. The input file will contain up to 40000 lines.
//
// 输出
// The output file contains the result of processing. All paragraphs should be separated by one "true" empty line (i.e. a line that contains no characters at all). There should be no empty lines before the first paragraph.
//
// 样例输入
// [5] Brownell, D, "Dynamic Reverse Address Resolution Protocol
//     (DRARP)", Work in Progress.
//
// The Reverse Address Resolution Protocol (RARP) [10] (through the
// extensions defined in the Dynamic RARP (DRARP) [5]) explicitly
// addresses the problem of network address discovery, and includes an
// automatic IP address assignment mechanism.
//
// [10] Finlayson, R., Mann, T., Mogul, J., and M. Theimer, "A Reverse
//         Address Resolution Protocol", RFC 903, Stanford, June 1984.
//
// [16] Postel, J., "Internet Control Message Protocol", STD 5, RFC 792,
//         USC/Information Sciences Institute, September 1981.
//
//
// The Trivial File Transfer Protocol (TFTP) [20] provides for transport
// of a boot image from a boot server.  The Internet Control Message
// Protocol (ICMP) [16] provides for informing hosts of additional routers
// via "ICMP redirect" messages.
//
// [20] Sollins, K., "The TFTP Protocol (Revision 2)",  RFC 783, NIC,
//      June 1981.
//
// Works [10], [16] and [20] can be obtained via Internet.
//
// 样例输出
// The Reverse Address Resolution Protocol (RARP) [1] (through the
// extensions defined in the Dynamic RARP (DRARP) [2]) explicitly
// addresses the problem of network address discovery, and includes an
// automatic IP address assignment mechanism.
//
// The Trivial File Transfer Protocol (TFTP) [3] provides for transport
// of a boot image from a boot server.  The Internet Control Message
// Protocol (ICMP) [4] provides for informing hosts of additional routers
// via "ICMP redirect" messages.
//
// Works [1], [4] and [3] can be obtained via Internet.
//
// [1] Finlayson, R., Mann, T., Mogul, J., and M. Theimer, "A Reverse
//         Address Resolution Protocol", RFC 903, Stanford, June 1984.
//
// [2] Brownell, D, "Dynamic Reverse Address Resolution Protocol
//     (DRARP)", Work in Progress.
//
// [3] Sollins, K., "The TFTP Protocol (Revision 2)",  RFC 783, NIC,
//      June 1981.
//
// [4] Postel, J., "Internet Control Message Protocol", STD 5, RFC 792,
//         USC/Information Sciences Institute, September 1981.
//
// 来源
// Northeastern Europe 1997

