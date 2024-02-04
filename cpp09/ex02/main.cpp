#include <sys/time.h>

#include <climits>
#include <sstream>

#include "PmergeMe.hpp"

long getNow() {
    struct timeval tp;

    gettimeofday(&tp, NULL);
    long ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
}

template <typename T>
void printNumbers(T &numbers) {
    typename T::iterator it = numbers.begin();
    size_t printed = 0;
    for (; it != numbers.end() && printed < 5; it++, printed++) {
        cout << *it << " ";
    }
    if (printed < numbers.size()) {
        cout << "[...]";
    }
    cout << "\n";
}

int toUnsignedIntOrThrow(std::string str) {
    std::stringstream ss(str);
    double n;
    ss >> n;
    if (ss.fail() || n < 0 || n > UINT_MAX) {
        throw std::invalid_argument("invalid input");
    }
    return n;
}

template <typename T>
void fillContainerOrThrow(int argc, char **argv, T &container) {
    for (int i = 1; i < argc; i++) {
        int n = toUnsignedIntOrThrow(std::string(argv[i]));
        container.push_back(n);
    }
}

template <typename T>
long testSort(int argc, char **argv, T &container) {
    long startSort = getNow();
    fillContainerOrThrow(argc, argv, container);
    T sortedContainer = mergeInsert(container, 2);
    container = sortedContainer;
    long timeSort = getNow() - startSort;
    return timeSort;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Error: a list of integers is required\n";
        return 1;
    }

    vector<int> unsortedVector;
    fillContainerOrThrow(argc, argv, unsortedVector);

    vector<int> vec;
    long timeSortVector;
    try {
        timeSortVector = testSort(argc, argv, vec);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
        return 1;
    }

    long timeSortList;
    list<int> li;
    try {
        timeSortList = testSort(argc, argv, li);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
        return 1;
    }

    cout << "Before:\t";
    printNumbers(unsortedVector);
    cout << "After:\t";
    printNumbers(vec);
    cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeSortVector << "ms\n";
    cout << "Time to process a range of " << li.size() << " elements with std::list : " << timeSortList << "ms\n";

    debugPrintNumbers(vec, 1);
    debugPrintNumbers(li, 1);
    return 0;
}
