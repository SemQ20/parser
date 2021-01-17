#include "parser.hpp"

bool has_symbol(char ch){
    if(ch == '!' || ch == '~' || ch == '+' || ch == '*' || ch == '(' || ch == ')'){
        return true;
    }
    return false;
}

std::string parse_logic_expr(std::string& expr){
    std::string params {expr[0]};
    std::string math_operators;
    int j               = 0;
    int num_params      = 0;
    int num_math_params = 0;
    int count_param     = 0;

    if(atoi(&expr[1]) && !has_symbol(expr[0])){
        params     += expr[1];   // detect param with number like: x1
        j          += 1;         // set first element of loop
        num_params += 1;         // detect first parameter
    }else
    {
        if(expr[0] == '!' || expr[0] == '~'){
            params[0] = expr[1];
            math_operators += expr[0];
        }
        if(atoi(&expr[2])){
            params     += expr[2];
            j          += 2;
            num_params += 1;         // detect first parameter
        }
        math_operators += expr[3];
        j += 1;
    }
    for(size_t i = j; i <= expr.size(); ++i){

    }
    return params;
}

