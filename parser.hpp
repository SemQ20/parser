#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>

std::string                         parse_logic_expr      (std::string& expr);
bool                                has_symbol            (char ch);
bool                                has_logic_not         (char ch);
std::pair<std::string, std::string> detect_params         (std::string& _str);
std::pair<std::size_t, std::string> detect_param          (std::string& _str, std::size_t position);
bool                                has_not_true_param    (char ch);
bool                                has_param             (char ch);
//uint32_t                            number_params         (std::string& params);
std::string&                        string_sort           (std::string& _ptr);
std::string                         get_first_param_in_str(std::string& _ptr);
char                                correct_param         (std::string& _ptr, int position);
char                                char_lesser           (char ch_a, char ch_b);
char                                char_greater          (char ch_a, char ch_b);

#endif // __PARSER_HPP