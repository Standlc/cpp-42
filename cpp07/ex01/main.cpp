#include "iter.hpp"

template <typename T>
void testFunction(T &element) {
    std::cout << "element: " << element << "\n";
}

void printElement(int &a) {
    a += 1;
    std::cout << a << '\n';
}

void mutateElement(std::string &str) {
    str += "?";
    std::cout << "after: " << str << "\n";
}

int main() {
    int arr1[] = {0, 1, 2, 3, 4};
    std::cout << "template function call: \n";
    iter(arr1, 5, testFunction);

    std::cout << "\n+= 1 \n";
    iter(arr1, 5, printElement);

    std::cout << "\n+= '?' \n";
    std::string arr2[] = {"hey", "my", "name", "is", "jeff"};
    iter(arr2, 5, mutateElement);

    return 0;
}