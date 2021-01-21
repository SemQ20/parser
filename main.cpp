#include "parser.hpp"

int main()
{
    std::string t = "x1x2x3x4x3x1x4"; // 4
    auto[pos, param] = detect_param(t,5);
    std::cout << pos << '\n' << param << '\n';
    return 0;
}
