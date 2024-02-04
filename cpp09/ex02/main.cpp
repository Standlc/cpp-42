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

void fillContainers(int argc, char **argv, vector<int> &vec, list<int> &li) {
    for (int i = 1; i < argc; i++) {
        int n = toUnsignedIntOrThrow(std::string(argv[i]));
        vec.push_back(n);
        li.push_back(n);
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Error: a list of integers is required\n";
        return 1;
    }

    vector<int> vec;
    list<int> li;

    try {
        fillContainers(argc, argv, vec, li);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
        return 1;
    }

    cout << "Before:\t";
    printNumbers(vec);

    long startSortVector = getNow();
    vector<int> sortedVector = mergeInsert(vec, 2);
    long timeSortVector = getNow() - startSortVector;

    long startSortList = getNow();
    list<int> sortedList = mergeInsert(li, 2);
    long timeSortList = getNow() - startSortList;

    cout << "After:\t";
    printNumbers(sortedVector);

    cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeSortVector << "ms\n";
    cout << "Time to process a range of " << li.size() << " elements with std::list : " << timeSortList << "ms\n";

    // debugPrintNumbers(sortedVector, 1);
    // debugPrintNumbers(sortedList, 1);
    return 0;
}

// typename T::iterator it = toInsert.begin();
// for (int i = 0; it != toInsert.end(); it = advance(it, pairSize / 2), i += pairSize / 2) {
//     typename T::iterator target = binarySearch(result.begin(), result.end(), *it, pairSize / 2);
//     // cout << "inserting: " << *it << "\n";
//     // cout << "target: " << *target << "\n";
//     result.insert(target, it, advance(it, pairSize / 2));
// }