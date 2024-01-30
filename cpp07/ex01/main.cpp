#include "iter.hpp"

template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

void addToElement(int &a) {
    a += 1;
}

void addToString(std::string &str) {
    str += "?";
}

int main() {
    int arr1[] = {0, 1, 2, 3, 4};
    std::cout << "\e[1;30mInt array\n\e[1;0m";
    iter(arr1, 5, printElement);

    std::cout << "\n\n\e[0;33m+= 1 \n\e[1;0m";
    iter(arr1, 5, addToElement);
    iter(arr1, 5, printElement);

    std::string arr2[] = {"hey", "my", "name", "is", "jeff"};
    std::cout << "\n\n\e[1;30mString array\n\e[1;0m";
    iter(arr2, 5, printElement);

    std::cout << "\e[0;33m\n\n+= '?' \n\e[1;0m";
    iter(arr2, 5, addToString);
    iter(arr2, 5, printElement);

    std::string arrEmpyt[] = {};
    std::cout << "\n\n\e[1;30mEmpty arr (expecting to see nothing)\n\e[1;0m";
    iter(arrEmpyt, 0, printElement);

    std::cout << "\e[0;33m\n\n+= 'stuff' (expecting no changes)\n\e[1;0m";
    iter(arrEmpyt, 0, addToString);
    iter(arrEmpyt, 0, printElement);

    return 0;
}