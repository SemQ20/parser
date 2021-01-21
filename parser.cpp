#include "parser.hpp"

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

/* ????? */
/* uint32_t number_params(std::string& params){
    std::string tmp_str;
    uint32_t    num_params;
    for(size_t i = 0; i <= params.size(); ++i){
        if(has_param(params[i])){
            int tmp = 0;
            tmp_str += params[i];
                num_params += 1;
            if(atoi(&params[i + 1])){
                tmp = i + 1;
                while(atoi(&params[tmp]) && (tmp + 1 <= params.size())){
                    tmp_str += params[tmp];
                    tmp++;
                } // take first param
                if(tmp_str[0] == params[tmp]){
                    size_t k = 0;
                    while(tmp_str[k] == params[tmp]){
                        k++;
                        tmp++;
                    }
                    tmp_str = "";
                }
            }
        }
    }
    return num_params;
} */

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

char char_lesser(char ch_a, char ch_b){
    return ch_a > ch_b ? ch_b : ch_a;
}

char char_greater(char ch_a, char ch_b){
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

std::string& string_sort(std::string& _ptr){
    size_t expr_size = _ptr.size();
    std::string _mid = &_ptr[expr_size / 2];

    return _ptr;
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

   return std::make_pair(position, param);
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

