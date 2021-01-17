#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Parser

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_suite.hpp>
#include "../parser.hpp"
#include <cmath>


BOOST_AUTO_TEST_CASE(parser_output_test_n1){
    std::string logic_expr = "x1+!x2+!(x3*x4)+(x3*!x1)+x4";
    BOOST_CHECK(parse_logic_expr(logic_expr) == "x1");
    std::cout << "test_one_is_ok" << '\n';
}

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