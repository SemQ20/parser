#include "parser.hpp"

int main()
{
    std::string x1 = "x1x3x4x1x2x6";
    std::string sw_str = "x6x3x4x1x2x1";
    std::size_t left_border  = 0;
    std::size_t right_border = x1.size() - 1;
    std::pair<std::size_t, std::string> lp{0,""};
    std::pair<std::size_t, std::string> rp{x1.size(),""};
    lp = detect_param(x1, left_border);
    rp = detect_param(x1, right_border);
    auto[_mid_pos, _mid]  = detect_param(x1, (std::size_t)x1.size()/2);
    std::string x2 = "x1";
    std::string x3 = "x6";
    swap_str(x1, _mid, _mid_pos, rp.second, rp.first); // need correct swap function for odd size of string expression
    std::cout << x1 << '\n';
    return 0;
}
