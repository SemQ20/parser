#include "parser.hpp"

int main()
{
    std::string t = "x1x2x3x4x3x1x4"; // 4
    std::cout << number_params(t) << '\n';
    return 0;
}
