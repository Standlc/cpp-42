#include <numeric>

#include "Span.hpp"

void fillSpan(Span& span) {
    for (int i = 0; i < span.size(); i++) {
        int randomNumber = rand() % 10000;
        span.addNumber(randomNumber);
    }
}

int main() {
    std::srand(time(0));

    {
        Span sp = Span(5);
        std::cout << "\e[1;33mCreating Span size " << sp.size() << " \e[1;30m(expecting min 2, max 14)\n";
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "\e[1;0mmin span: \e[1;36m" << sp.shortestSpan() << std::endl;
        std::cout << "\e[1;0mmax span: \e[1;36m" << sp.longestSpan() << "\n\n";
    }

    {
        Span sp2(2);
        fillSpan(sp2);
        std::cout << "\e[1;33mCreating Span size " << sp2.size() << " ";
        std::cout << "\e[1;30m(expecting min == max)\n";
        std::cout << "\e[1;0mmin span: \e[1;36m" << sp2.shortestSpan() << "\n";
        std::cout << "\e[1;0mmax span: \e[1;36m" << sp2.longestSpan() << "\n\n";

        Span spSuperBig(100000);
        fillSpan(spSuperBig);
        std::cout << "\e[1;33mCreating Span size " << spSuperBig.size() << " ";
        std::cout << "\e[1;30m(expecting min 0, max 9999)\n";
        std::cout << "\e[1;0mmin span: \e[1;36m" << spSuperBig.shortestSpan() << "\n";
        std::cout << "\e[1;0mmax span: \e[1;36m" << spSuperBig.longestSpan() << "\n\n";

        try {
            Span sp(1);
            std::cout << "\e[1;33mTesting Span(1).shortestSpan(): ";
            sp.shortestSpan();
        } catch (const std::exception& e) {
            std::cerr << "\e[1;32m" << e.what() << '\n';
        }

        try {
            Span sp(1);
            std::cout << "\e[1;33mTesting Span(1).longestSpan(): ";
            sp.longestSpan();
        } catch (const std::exception& e) {
            std::cerr << "\e[1;32m" << e.what() << '\n';
        }

        try {
            Span sp(2);
            std::cout << "\e[1;33mTesting insert out of range: ";
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
        } catch (const std::exception& e) {
            std::cerr << "\e[1;32m" << e.what() << '\n';
        }

        std::vector<int> someVector;
        size_t size = 10;
        for (size_t i = 0; i < size; i++) {
            someVector.push_back(i);
        }

        Span spanFromIterators;
        spanFromIterators.insert(someVector.begin(), someVector.end());
        try {
            std::cout << "\n\e[1;33mCreating Span from iterator range, size " << spanFromIterators.size() << " \e[1;30m(expecting min 1, max 9)\n";
            std::vector<int> spanData = spanFromIterators.data();
            std::cout << "original: ";
            for (unsigned int i = 0; i < size; i++) {
                std::cout << someVector[i] << " ";
            }
            std::cout << "\nresult: ";
            for (unsigned int i = 0; i < size; i++) {
                std::cout << spanData[i] << " ";
            }
            std::cout << "\n\e[1;0mmin span: \e[1;36m" << spanFromIterators.shortestSpan() << "\n";
            std::cout << "\e[1;0mmax span: \e[1;36m" << spanFromIterators.longestSpan() << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        
        Span other = spanFromIterators;
        try {
            std::cout << "\n\e[1;33mCreating Span from invalid iterator range \e[1;30m(expecting to catch error): ";
            Span spanFromIteratorsError;
            spanFromIteratorsError.insert(someVector.end(), someVector.begin());
        }
        catch(const std::exception& e) {
            std::cerr << "\e[1;32m" << e.what() << '\n';
        }
    }
    return 0;
}