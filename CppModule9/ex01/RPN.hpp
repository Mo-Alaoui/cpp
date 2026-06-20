#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>


class RPN
{
private:
    void applyOperator(std::stack<int>& operandStack, const std::string& operatorToken);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int evaluate(const std::string& expression);
};

#endif