#include <iostream>
#include <string>
#include <vector>

std::string parse_logic_expr(std::string& expr){
    std::string params {expr[0]};
    std::string math_operators;
    int j               = 0;
    int num_params      = 0;
    int num_math_params = 0;
    int count_param     = 0;

    if(atoi(&expr[1]) && !(params[0] == '!') && !(params[0] == '~')){
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

    for(int i = j; i != expr.size(); ++i){
        
    }
    std::cout << j << '\n';
    return params;
}

int main()
{
    std::string logic_expr = "x1+!x2+!(x3*x4)+(x3*!x1)+x4";
    auto res = parse_logic_expr(logic_expr);
    std::cout << res << '\n';
    return 0;
}
