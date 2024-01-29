#include "h.hpp"

void testSwap() {
    int intA = 5;
    int intB = 10;
    std::string str1 = "hello";
    std::string str2 = "world";

    std::cout << "SWAP\n";
    std::cout << "swap(" << intA << ", " << intB << ")\n";
    swap(intA, intB);
    std::cout << "intA: " << intA << "\n";
    std::cout << "intB: " << intB << "\n";

    std::cout << "\n";

    std::cout << "swap(" << str1 << ", " << str2 << ")\n";
    swap(str1, str2);
    std::cout << "str1: " << str1 << "\n";
    std::cout << "str2: " << str2 << "\n";

    std::cout << "\n\n";
}

void testMinMax() {
    int intA = 5;
    int intB = 10;

    std::cout << "MIN\n";
    std::cout << "min(5, 10) => " << min(intA, intB) << '\n';
    std::cout << "min(10, 5) => " << min(intB, intA) << '\n';

    std::cout << "\n";

    std::cout << "MAX\n";
    intA = 5;
    intB = 10;
    std::cout << "max(5, 10) => " << max(intA, intB) << '\n';
    std::cout << "max(10, 5) => " << max(intB, intA) << '\n';

    std::cout << "\n";
}

int main() {
    {
        std::cout << "Custom Tests:\n";
        testSwap();
        testMinMax();
    }

    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    return 0;
}