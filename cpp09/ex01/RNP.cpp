#include "RNP.hpp"

std::string getNextElement(std::string str)
{
    static size_t start = 0;
    static size_t end = 0;

    start = str.find_first_not_of(" ", end);
    if (start == std::string::npos)
    {
        return "";
    }

    end = str.find(" ", start);
    std::string substr = str.substr(start, end - start);
    return substr;
}

bool isNumber(std::string &str)
{
    bool isNegative = str[0] == '-';
    if (isNegative && str.length() == 1)
    {
        return false;
    }
    return str.find_first_not_of("0123456789", isNegative ? 1 : 0) == std::string::npos;
}

bool isOperator(std::string &str)
{
    return str.length() == 1 && str.find_first_of("-+*/") != std::string::npos;
}

float plus(float a, float b)
{
    return a + b;
}

float minus(float a, float b)
{
    return a - b;
}

float times(float a, float b)
{
    return a * b;
}

float divided(float a, float b)
{
    return a / b;
}

void handleOperation(std::stack<float> &stack, char currOperator)
{
    std::string operators = "-+*/";
    float (*operations[])(float, float) = {minus, plus, times, divided};

    size_t operationType = operators.find_first_of(currOperator);
    float (*operation)(float, float) = operations[operationType];

    float a = stack.top();
    stack.pop();
    float b = stack.top();
    stack.pop();

    stack.push(operation(b, a));
}

float RNP(std::string operation)
{
    std::stack<float> stack;

    std::string currElement = getNextElement(operation);
    while (currElement != "")
    {
        if (isNumber(currElement))
        {
            float number = std::strtof(&currElement[0], NULL);
            stack.push(number);
        }
        else
        {
            if (!isOperator(currElement) || stack.size() < 2)
            {
                throw std::invalid_argument("invalid token: " + currElement);
            }
            handleOperation(stack, currElement[0]);
        }
        currElement = getNextElement(operation);
    }

    if (stack.empty() || stack.size() != 1)
    {
        throw std::invalid_argument("invalid or empty operaiton");
    }
    return stack.top();
}
