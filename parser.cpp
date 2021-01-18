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
uint32_t number_params(std::string& params){
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
}

std::pair<std::string, std::string> 
detect_param(std::string& str){
    std::string param;
    std::string math_operators;
    for(int i = 0; i <= str.size(); ++i){
        if(has_symbol(str[i])){
            math_operators += str[i];
        }
        if(has_param(str[i])){
            param += str[i];
            if(atoi(&str[i + 1])){
                int tmp = i + 1;
                while(atoi(&str[tmp]) && (tmp + 1 <= str.size())){
                    param += str[tmp];
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

    auto[params, math_operators] = detect_param(expr);

    return params;
}

