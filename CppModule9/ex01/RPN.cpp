#include "RPN.hpp"

int RPN::evaluate(const std::string& expression)
{
    std::stack<int> operandStack;
    std::stringstream ss(expression);
    std::string term;

    while (ss >> term)
    {   
        if (term == "/" || term == "*" || term == "-" || term == "+")
        {
            applyOperator(operandStack, term);
            continue;
        }
        
        std::stringstream numberParser(term);
        int number;
        if (numberParser >> number)
        {
            if (number < 0 || number > 9)
                throw std::runtime_error("Error");
            operandStack.push(number);
        }
        else 
            throw std::runtime_error("Error");
    }
    if (operandStack.empty())
        throw std::runtime_error("Error: empty expression");
    int res = operandStack.top(); operandStack.pop();
    if (!operandStack.empty())
        throw std::runtime_error("Error");

    return (res);
}

void RPN::applyOperator(std::stack<int>& operandStack, const std::string& operatorToken)
{

    if (operandStack.empty() || operandStack.size() == 1)
        throw std::runtime_error("Error");
    
    int rhs = operandStack.top(); operandStack.pop();
    int lhs = operandStack.top(); operandStack.pop();
    
    if      (operatorToken == "+") operandStack.push(lhs + rhs);
    else if (operatorToken == "-") operandStack.push(lhs - rhs);
    else if (operatorToken == "*") operandStack.push(lhs * rhs);
    else if (operatorToken == "/")
    {
        if (rhs == 0) 
            throw std::runtime_error("Error: division by zero");
        operandStack.push(lhs / rhs);
    }
}

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}
