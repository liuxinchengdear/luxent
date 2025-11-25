// #include "include/util.hpp"

// using namespace util;

//     void DataGenerator::makeData(int T) {
//     int n, q;
//     n = 1000'000'000, q = 1'000'00;
//     if (T <= 3) n = 8, q = 10;
//     else if (T <= 5) n = 1'00'000;
//     println(n, q);
//     int lim = 1'000'00;
//     for (int i = 1; i <= q; ++i) {
//         if (T == 10) {
//         if (i != q) println(1, 1, n, lim);
//         else println(2, 1, n);
//         } else {
//         int op = mod1(2);
//         auto [l, r] = randRange(1, n);
//         if (op == 1) {
//             println(op, l, r, mod1(lim));
//         } else {
//             println(op, l, r);
//         }
//         }
//     }
//     }

// int main() {
//     std::string pre_path = getenv("PROJECT_ROOT");
//     util::DataGenerator::run(
//         "data",  // 数据名称
//         10,      // 测试数据数量
//         0,       // 样例数据数量
//         "std.exe",   //标程的可执行文件名
//         "data",  // 测试数据路径
//         "sample" // 样例数据路径
//     );
// }


#include <bits/stdc++.h>

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string ss = std::string(getenv("PROJECT_ROOT")) + "\\data\\data.in";

    freopen(ss.c_str(), "w", stdout);

    std::string output =  R"(1 2 3 5
6 0 10 4
2 1 8 3)";
    std::cout << output << std::endl;
    return 0;
}