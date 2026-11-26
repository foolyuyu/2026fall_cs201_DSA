// 0506 Flooded!（全局题号 879）
// http://dsa.openjudge.cn/binarytree/0506/
// 总时间限制 1000ms  内存限制 65536kB
//
// 描述
// To enable homebuyers to estimate the cost of flood insurance, a real-estate firm provides clients with the elevation of each 10-meter by 10-meter square of land in regions where homes may be purchased. Water from rain, melting snow, and burst water mains will collect first in those squares with the lowest elevations, since water from squares of higher elevation will run downhill. For simplicity, we also assume that storm sewers enable water from high-elevation squares in valleys (completely enclosed by still higher elevation squares) to drain to lower elevation squares, and that water will not be absorbed by the land.
// From weather data archives, we know the typical volume of water that collects in a region. As prospective homebuyers, we wish to know the elevation of the water after it has collected in low-lying squares, and also the percentage of the region's area that is completely submerged (that is, the percentage of 10-meter squares whose elevation is strictly less than the water level). You are to write the program that provides these results.
//
// 输入
// The input consists of a sequence of region descriptions. Each begins with a pair of integers, m and n, each less than 30, giving the dimensions of the rectangular region in 10-meter units. Immediately following are m lines of n integers giving the elevations of the squares in row-major order. Elevations are given in meters, with positive and negative numbers representing elevations above and below sea level, respectively. The final value in each region description is an integer that indicates the number of cubic meters of water that will collect in the region. A pair of zeroes follows the description of the last region.
//
// 输出
// For each region, display the region number (1, 2, ...), the water level (in meters above or below sea level) and the percentage of the region's area under water, each on a separate line. The water level and percentage of the region's area under water are to be displayed accurate to two fractional digits. Follow the output for each region with a blank line.
//
// 样例输入
// 3 3
// 25 37 45
// 51 12 34
// 94 83 27
// 10000
// 0 0
//
// 样例输出
// Region 1
// Water level is 46.67 meters.
// 66.67 percent of the region is under water.
//
// 来源
// World Finals 1999

