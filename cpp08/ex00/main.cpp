#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void populateContainer(T &container) {
    for (int i = 0; i < 10; i++) {
        container.push_back(i);
    }
}

template <typename T>
void printFoundOrNot(T element, T end) {
    if (element == end) {
        std::cout << "\e[0;31mnot found\n";
    } else {
        std::cout << "\e[0;32mfound\n";
    }
}

template <typename T>
void printContainer(T &c) {
    std::cout << "[";
    for (typename T::iterator i = c.begin(); i != c.end(); i++) {
        std::cout << *i << ",";
    }
    std::cout << "]\n";
}

template <typename T>
void test_easyfind(T &container, std::string title) {
    std::cout << "\e[0;34m" << title << " ";
    printContainer(container);

    int n = 3;
    std::cout << "\e[0;33msearching for: \e[0;36m" << n << " ";
    printFoundOrNot(easyfind(container, n), container.end());
    std::cout << "\n";

    n = 7;
    std::cout << "\e[0;33msearching for: \e[0;36m" << n << " ";
    printFoundOrNot(easyfind(container, n), container.end());
    std::cout << "\n";

    n = 20;
    std::cout << "\e[0;33msearching for: \e[0;36m" << n << " ";
    printFoundOrNot(easyfind(container, n), container.end());
    std::cout << "\n";
}

int main() {
    std::vector<int> vec;
    // filling container with 0->10
    populateContainer(vec);
    std::vector<int> emptyVector;
    std::list<int> li;
    populateContainer(li);
    std::list<int> emptyList;

    test_easyfind(vec, "vector");
    test_easyfind(li, "list");
    test_easyfind(emptyVector, "empty vector");
    test_easyfind(li, "empty list");

    return 0;
}