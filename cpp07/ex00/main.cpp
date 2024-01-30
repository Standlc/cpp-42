#include "h.hpp"

void testSwap() {
    int intA = 5;
    int intB = 10;
    std::string str1 = "hello";
    std::string str2 = "world";

    std::cout << "\e[0;33mSWAP\n\e[1;0m";
    std::cout << "\e[0;34mswap(" << intA << ", " << intB << ")\n\e[1;0m";
    swap(intA, intB);
    std::cout << "intA: " << intA << "\n";
    std::cout << "intB: " << intB << "\n";

    std::cout << "\n";

    std::cout << "\e[0;34mswap(" << str1 << ", " << str2 << ")\n\e[1;0m";
    swap(str1, str2);
    std::cout << "str1: " << str1 << "\n";
    std::cout << "str2: " << str2 << "\n";

    std::cout << "\n\n";
}

void testMinMax() {
    int intA = 5;
    int intB = 10;

    std::cout << "\e[0;33mMIN\n\e[1;0m";
    std::cout << "\e[0;34mmin(5, 10) => \e[1;0m" << min(intA, intB) << '\n';
    std::cout << "\e[0;34mmin(10, 5) => \e[1;0m" << min(intB, intA) << '\n';

    std::cout << "\n";

    std::cout << "\e[0;33mMAX\n\e[1;0m";
    intA = 5;
    intB = 10;
    std::cout << "\e[0;34mmax(5, 10) => \e[1;0m" << max(intA, intB) << '\n';
    std::cout << "\e[0;34mmax(10, 5) => \e[1;0m" << max(intB, intA) << '\n';

    std::cout << "\n";
}

int main() {
    {
        std::cout << "\e[0;33mCustom Tests:\n\e[1;0m";
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