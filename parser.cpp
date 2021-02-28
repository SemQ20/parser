#include "parser.hpp"
/* TODO: Add comments */

std::size_t most_long_param = 0;

bool has_symbol(char ch){
    if(ch == '!' || ch == '~' || ch == '+' || ch == '*' || ch == '(' || ch == ')'){
        return true;
    }
    return false;
}

bool has_logic_not(char ch){
    if(ch == '!' || ch == '~'){
        return true;
    }
    return false;
}

bool has_not_true_param(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}

bool has_param(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return true;
    }
    return false;
}

std::string string_lesser(std::string& ch_a, std::string& ch_b){
    return ch_a > ch_b ? ch_b : ch_a;
}

std::string string_greater(std::string& ch_a, std::string& ch_b){
    return ch_a > ch_b ? ch_a : ch_b;
}

char correct_param(std::string& _ptr, int position){
    if(_ptr[position] == 'x'){
        return _ptr[position];
    }else{
        _ptr[position] = 'x';
        return _ptr[position];
    }
}

std::pair<std::size_t, std::string>
detect_param(std::string& _str, std::size_t position){
    std::size_t tmp = position + 1;
    std::string param;
    if(has_param(_str[position])){
        param += _str[position];
        if(atoi(&_str[tmp])){
            while(atoi(&_str[tmp])){
                param += _str[tmp];
                tmp++;
            }
        }
   }
   if(!has_param(_str[position])) {
        tmp = position;
        while(atoi(&_str[tmp])){
            tmp--;
        }
       return detect_param(_str, tmp);
    }
   return std::make_pair(tmp - 2, param);
}

std::string get_first_param_in_str(std::string& _ptr){
    std::string tmp_str;
    uint32_t    num_params;
    if(has_param(_ptr[0])){
            int tmp = 0;
            tmp_str += _ptr[0];
            if(atoi(&_ptr[1])){
                tmp = 1;
                while(atoi(&_ptr[tmp]) && (tmp + 1 <= _ptr.size())){
                    tmp_str += _ptr[tmp];
                    tmp++;
                } // take first param
                if(tmp_str[0] == _ptr[tmp]){
                    size_t k = 0;
                    while(tmp_str[k] == _ptr[tmp]){
                        k++;
                        tmp++;
                    }
                }
            }
        }
    return tmp_str;
}

std::string detect_param_wot_pos(std::string& _str, std::size_t position){
    std::size_t tmp = position + 1;
    std::string param;
    if(has_param(_str[position])){
        param += _str[position];
        if(atoi(&_str[tmp])){
            while(atoi(&_str[tmp])){
                param += _str[tmp];
                tmp++;
            }
        }
   }
   if(!has_param(_str[position])) {
        tmp = position;
        while(atoi(&_str[tmp])){
            tmp--;
        }
       return detect_param_wot_pos(_str, tmp);
    }

   return param;
}

std::string& swap_str(std::string& _str, std::string& lvalue, std::size_t lvalue_pos,
                                         std::string& rvalue, std::size_t rvalue_pos){
    std::size_t i = 0;
    std::string tmp = lvalue;
    std::size_t offset_lvalue = lvalue_pos + (std::size_t)lvalue.size() - 1; 
    std::size_t offset_rvalue = rvalue_pos + (std::size_t)rvalue.size() - 1;
    while (lvalue_pos <= offset_lvalue){
        _str[lvalue_pos] = rvalue[i];
        ++lvalue_pos;
        ++i;
    }
    i = 0;
    while (rvalue_pos <= offset_rvalue){
        _str[rvalue_pos] = tmp[i];
        rvalue_pos++;
        i++;
    }
    return _str;
}

std::string& string_sort(std::string& _ptr){
    std::string tmp;
    bool sorted;
    std::pair<std::size_t, std::string> lp{0,""};
    std::pair<std::size_t, std::string> rp{_ptr.size(),""};
    auto[_mid_pos, _mid] = detect_param(_ptr, (std::size_t)_ptr.size()/2);
    //std::cout << _mid_pos << ", " << _mid << '\n';
    //std::cout << _ptr.size() << '\n';
    std::size_t left_border  = 0;
    std::size_t right_border = _ptr.size() - 1;
    if(is_sorted_str(_ptr)) {
        return _ptr; 
    }else{
        while(!(left_border == _mid_pos) && !(right_border == _mid_pos)){
            auto[_mid_pos, _mid]     = detect_param(_ptr, (std::size_t)_ptr.size()/2);
            lp = detect_param(_ptr, left_border);
            rp = detect_param(_ptr, right_border);
            //std::cout << lp.second << ", " << rp.second << '\n';
        if(_mid < lp.second){ //if _mid < left_param
            //std::cout << _mid_pos << ", " << _mid << ", " << lp.second << '\n';
            swap_str(_ptr, lp.second, lp.first, _mid, _mid_pos);
            //std::cout << _ptr << '\n';
        }
        if(_mid > rp.second){ //if _mid > left_param
            //std::cout << _mid << ", " << lp.second << '\n';
            swap_str(_ptr, _mid, _mid_pos, rp.second, rp.first);
            //std::cout << _ptr << '\n';
        }
            left_border  += lp.second.size(); // left to middle position
            right_border -= rp.second.size(); // right to middle position
        }
        //std::cout << _ptr << '\n';
        if(sorted = is_sorted_str(_ptr)){
            return _ptr;
        }
        else{
            return string_sort(_ptr);
        }
    }
    return _ptr;
}

std::pair<std::string, std::string>
detect_params(std::string& _str){
    std::string param;
    std::string math_operators;
    for(int i = 0; i <= _str.size(); ++i){
        if(has_symbol(_str[i])){
            math_operators += _str[i];
        }
        if(has_param(_str[i])){
            param += correct_param(_str, i);
            if(atoi(&_str[i + 1])){
                int tmp = i + 1;
                while(atoi(&_str[tmp]) && (tmp + 1 <= _str.size())){
                    param += _str[tmp];
                    tmp++;
                }
            }
        }
    }
    if(most_long_param <= 0){
        most_long_param_str(param);   
    }
    return std::make_pair(param, math_operators);
}

std::string parse_logic_expr(std::string& expr){
    int num_params      = 0;
    int num_math_params = 0;
    // detect for number in [0,1], like: 1X3, !1X4
    assert((has_not_true_param(expr[0])) == true);
    assert((has_not_true_param(expr[1])) == true);

    auto[params, math_operators] = detect_params(expr);

    return params;
}

bool is_sorted_str(std::string& _str){
    std::size_t begin = 0;
    std::size_t i     = 0;
    std::pair<std::size_t, std::string> lp{0,""};
    std::pair<std::size_t, std::string> rp{_str.size(),""};
    std::size_t right_border = _str.size();
    while(begin <= _str.size() - (1 + most_long_param)){ 
        lp = detect_param(_str, begin);
        rp = detect_param(_str, begin + (std::size_t)lp.second.size());
        if(lp.second < rp.second || lp.second == rp.second){
            begin += lp.second.size();
        }else{
            return false;
        }
    }
    return true;
}

void most_long_param_str(std::string& expr){
    std::size_t tmp = 0;
    std::string param_tmp;
    for(std::size_t i = 0; i <= expr.size() - 1;){
        param_tmp = detect_param_wot_pos(expr, i);
        if(param_tmp.size() > tmp){
            tmp = param_tmp.size();
        }
        i += param_tmp.size(); 
    }
    most_long_param = tmp;
}