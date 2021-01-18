#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

std::string                         parse_logic_expr    (std::string& expr);
bool                                has_symbol          (char ch);
bool                                has_logic_not       (char ch);
std::pair<std::string, std::string> detect_param        (std::string& str);
bool                                has_not_true_param  (char ch);
bool                                has_param           (char ch);
uint32_t                            number_params       (std::string& params);
#endif // __PARSER_HPP