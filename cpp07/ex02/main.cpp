#include "Array.hpp"
#include <string>

int main() {
    // int
    Array<int> integerArr(3);
    std::cout << "\e[0;33mIterating trough Array<int> size: " << integerArr.size() << "\n";
    for (unsigned int i = 0; i < integerArr.size(); i++) {
        integerArr[i] = i;
    }
    for (unsigned int i = 0; i < integerArr.size(); i++) {
        std::cout << "\e[0;0mintegerArr[" << i << "]: " <<  integerArr[i] << "\n";
    }
    std::cout << std::endl;

    // copy Array
    std::cout << "\e[0;33mcopying prev arr inside new Array<int>\n";
    Array<int> integerArr2 = integerArr;
    for (unsigned int i = 0; i < integerArr.size(); i++) {
        std::cout << "\e[0;0mintegerArr2[" << i << "]: " <<  integerArr2[i] << "\n";
    }
    std::cout << std::endl;

    // bad index
    try
    {
        std::cout << "\e[0;33maccessing out of range element \e[1;30m(expecting to catch error)\n";
        integerArr[10];
    }
    catch(const std::exception& e)
    {
        std::cerr << "\e[0;31m" << e.what() << '\n';
    }
    std::cout << std::endl;

    // string
    Array<std::string> stringArr(2);
    std::cout << "\e[0;33mAssigning values to Array<std::string> size: " << stringArr.size() << "\n";
    stringArr[0] = "hello, ";
    stringArr[1] = "world!";
    std::cout << "\e[0;0m";
    std::cout << "stringArr[0]: " << stringArr[0] << "\n";
    std::cout << "stringArr[1]: " << stringArr[1] << "\n";
    return 0;
}