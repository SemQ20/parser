#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

std::string                         parse_logic_expr      (std::string& expr);
bool                                has_symbol            (char ch);
bool                                has_logic_not         (char ch);
std::pair<std::string, std::string> detect_params         (std::string& _str);
std::pair<std::size_t, std::string> detect_param          (std::string& _str, std::size_t position);
std::string                         detect_param_wot_pos  (std::string& _str, std::size_t position);
bool                                has_not_true_param    (char ch);
bool                                has_param             (char ch);
//uint32_t                            number_params         (std::string& params);
std::string                         string_sort           (std::string& _ptr);
std::string                         get_first_param_in_str(std::string& _ptr);
char                                correct_param         (std::string& _ptr, int position);
std::string                         string_lesser         (std::string& ch_a, std::string& ch_b);
std::string                         string_greater        (std::string& ch_a, std::string& ch_b);
std::string&                        swap_str              (std::string& _str, std::string& lvalue, std::size_t lvalue_pos,
                                                                              std::string& rvalue, std::size_t rvalue_pos);

#endif // __PARSER_HPP