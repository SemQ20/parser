#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Parser

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_suite.hpp>
#include "../parser.hpp"
#include <cmath>


BOOST_AUTO_TEST_CASE(parser_output_test_n1){
    std::string logic_expr = "x1+!x2+!(x3*x4)+(x3*!x1)+x4";
    BOOST_CHECK(parse_logic_expr(logic_expr) == "x1x2x3x4x3x1x4");
}
/* ******************************************* Tests for has_symbol **************************************** */
BOOST_AUTO_TEST_CASE(has_symbol_test_1){
    char test_symbol = '!';
    BOOST_CHECK(has_symbol(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_2){
    char test_symbol = '~';
    BOOST_CHECK(has_symbol(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_3){
    char test_symbol = '+';
    BOOST_CHECK(has_symbol(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_4){
    char test_symbol = '*';
    BOOST_CHECK(has_symbol(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_5){
    char test_symbol = '(';
    BOOST_CHECK(has_symbol(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_6){
    char test_symbol = ')';
    BOOST_CHECK(has_symbol(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_7){
    char test_symbol = '6';
    BOOST_CHECK(has_symbol(test_symbol) == false);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_8){
    std::string test_symbol = "x";
    BOOST_CHECK(has_symbol(test_symbol[0]) == false);
}

BOOST_AUTO_TEST_CASE(has_symbol_test_9){
    BOOST_CHECK(has_symbol('%') == false);
}
/* *********************************************************************************************************** */

/* ******************************************* Tests for has_logic_not *************************************** */
BOOST_AUTO_TEST_CASE(has_logic_not_test_1){
    char test_symbol = '!';
    BOOST_CHECK(has_logic_not(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_logic_not_test_2){
    char test_symbol = '~';
    BOOST_CHECK(has_logic_not(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_logic_not_test_3){
    char test_symbol = '6';
    BOOST_CHECK(has_logic_not(test_symbol) == false);
}
/* *********************************************************************************************************** */

BOOST_AUTO_TEST_CASE(has_not_true_param_test_1){
    char test_symbol = '0';
    BOOST_CHECK(has_not_true_param(test_symbol) == true);
}

BOOST_AUTO_TEST_CASE(has_param_test_1){
    std::string test_symbol = "A";
    BOOST_CHECK(has_param(test_symbol[0]) == true);
}
/* *********************************************************************************************************** */
BOOST_AUTO_TEST_CASE(detect_param_test_1){
    std::string test_symbol = "!x12345+!x2";
    std::pair<std::string, std::string> p{"x12345x2", "!+!"};
    BOOST_CHECK(detect_param(test_symbol) == p);
}

BOOST_AUTO_TEST_CASE(detect_param_test_2){
    std::string test_symbol = "!x12345+(!x2)";
    std::pair<std::string, std::string> p{"x12345x2", "!+(!)"};
    BOOST_CHECK(detect_param(test_symbol) == p);
}

BOOST_AUTO_TEST_CASE(detect_param_test_3){
    std::string test_symbol = "!x12345+(!x2)+!x4+!(!x3+!x4)";
    std::pair<std::string, std::string> p{"x12345x2x4x3x4", "!+(!)+!+!(!+!)"};
    BOOST_CHECK(detect_param(test_symbol) == p);
}

BOOST_AUTO_TEST_CASE(detect_param_test_4){
    std::string test_symbol = "-!x12345+(!x2)+!x4+!(!x3+!x4)";
    std::pair<std::string, std::string> p{"x12345x2x4x3x4", "!+(!)+!+!(!+!)"};
    BOOST_CHECK(detect_param(test_symbol) == p);
}
/* *********************************************************************************************************** */

BOOST_AUTO_TEST_CASE(number_params_test_1){
    std::string test_symbol = "x1x2x4x3x4";
    std::cout << number_params(test_symbol) << '\n';
    BOOST_CHECK(number_params(test_symbol) == 4);
}