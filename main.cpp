#include "parser.hpp"

int main()
{
    std::string t = "x1x2x3x4x3x1x4"; // 4
    auto t1 = string_sort(t);
    std::cout << t1 << '\n';
    return 0;
}
