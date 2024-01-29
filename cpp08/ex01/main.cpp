#include <random>

#include "Span.hpp"

void fillSpan(Span& span) {
    for (int i = 0; i < span.size(); i++) {
        int randomNumber = rand() % 10000;
        // std::cout << randomNumber << "\n";
        span.addNumber(randomNumber);
    }
}

int main() {
    std::srand(time(0));

    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "\e[1;33mmin span: \e[1;36m" << sp.shortestSpan() << std::endl;
        std::cout << "\e[1;33mmax span: \e[1;36m" << sp.longestSpan() << "\n\n";
    }

    {
        Span sp(10);
        fillSpan(sp);
        std::cout << "\e[1;33mmin span: \e[1;36m" << sp.shortestSpan() << "\n";
        std::cout << "\e[1;33mmax span: \e[1;36m" << sp.longestSpan() << "\n\n";

        Span sp2(2);
        fillSpan(sp2);
        std::cout << "\e[0;0m(two number should result in same min and max span)\n";
        std::cout << "\e[1;33mmin span: \e[1;36m" << sp2.shortestSpan() << "\n";
        std::cout << "\e[1;33mmax span: \e[1;36m" << sp2.longestSpan() << "\n\n";

        Span spSuperBig(100000);
        fillSpan(spSuperBig);
        std::cout << "\e[0;0m(most likely min span will be 0 and max span 999: two identical numbers)\n";
        std::cout << "\e[1;33mmin span: \e[1;36m" << spSuperBig.shortestSpan() << "\n";
        std::cout << "\e[1;33mmax span: \e[1;36m" << spSuperBig.longestSpan() << "\n\n";

        try {
            Span sp(1);
            std::cout << "\e[1;33mTesting expection: ";
            sp.shortestSpan();
        } catch (const std::exception& e) {
            std::cerr << "\e[0;31m" << e.what() << '\n';
        }

        try {
            Span sp(1);
            std::cout << "\e[1;33mTesting expection: ";
            sp.longestSpan();
        } catch (const std::exception& e) {
            std::cerr << "\e[0;31m" << e.what() << '\n';
        }

        try {
            Span sp(2);
            std::cout << "\e[1;33mTesting expection: ";
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
        } catch (const std::exception& e) {
            std::cerr << "\e[0;31m" << e.what() << '\n';
        }
    }
    return 0;
}