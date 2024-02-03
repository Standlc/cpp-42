#include <climits>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::pair;
using std::vector;

#include <iterator>
template <typename Iterator>
Iterator advance(Iterator it, int amount) {
    if (amount > 0) {
        for (int i = 0; i < amount; i++) {
            it++;
        }
    } else {
        for (int i = 0; i > amount; i--) {
            it--;
        }
    }
    return it;
}

template <typename T>
bool isSorted(T &vec, int pairSize) {
    for (typename T::iterator it = vec.begin(); it != vec.end(); it = advance(it, 1)) {
        typename T::iterator next = advance(it, 1);
        if (next == vec.end()) {
            break;
        }
        if (*it > *next) {
            cout << "\e[0;31m";
            return false;
        }
    }
    cout << "\e[1;0m";
    return true;
}

template <typename T>
void printVec(T &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

template <typename Iterator>
int dist(Iterator begin, Iterator end) {
    int i = 0;
    while (begin != end) {
        i++;
        begin++;
    }
    return i;
}

std::pair<int, int> getNextJacobsthal(bool reset = false) {
    static int curr = 1;
    static int next = 1;

    if (reset) {
        curr = 1;
        next = 1;
    }

    int temp = next;
    next = 2 * curr + next;
    curr = temp;
    return std::make_pair(curr, next);
}

// template <typename T>
// typename std::vector<T>::iterator binary(std::vector<T> &myList, const T &value) {
//     typename std::vector<T>::iterator left = myList.begin();
//     typename std::vector<T>::iterator right = myList.end();

//     while (left != right) {
//         typename std::vector<T>::iterator mid = advance(left, dist(left, right) / 2);

//         if (value < *mid) {
//             right = mid;
//         } else {
//             left = advance(mid, 1);
//         }
//     }

//     return left;
// }

template <typename T>
T binarySearch(T left, T right, int value, int pairSize) {
    // int jumpSize = (searchRange / 2 / pairSize * pairSize);
    // T middle = advance(vec.begin(), jumpSize);

    while (left != right) {
        T mid = advance(left, dist(left, right) / 2 / pairSize * pairSize);

        if (value < *mid) {
            right = mid;
        } else {
            left = advance(mid, pairSize);
        }
    }
    return left;
}

template <typename T>
T binaryInsert(T &chain, T &pend, int pairSize) {
    T result;
    T toInsert;

    for (typename T::iterator it = chain.begin(); it != chain.end();) {
        for (int i = 0; i < pairSize / 2; i++) {
            result.push_back(*(it++));
        }
        for (int i = 0; i < pairSize / 2; i++) {
            toInsert.push_back(*(it++));
        }
    }

    cout << "INSERT INTO: ";
    printVec(result);
    cout << "TO INSERT: ";
    printVec(toInsert);
    // cout << "\n";

    if (pend.size()) {
        typename T::iterator target = binarySearch(result.begin(), advance(result.end(), -pairSize / 2 + 1), *pend.begin(), pairSize / 2);
        result.insert(target, pend.begin(), pend.end());
    }

    // pair<int, int> jacob = getNextJacobsthal(true);
    // jacob.first = 0;
    // cout << "JACOB: \n";
    // for (int count = 0; count < chain.size() / pairSize; count++) {
    //     cout << jacob.second << "\n";
    //     jacob.second = jacob.second < toInsert.
    //     for (int i = jacob.second; i > jacob.first; i--) {
    //         typename T::iterator it = advance(toInsert.begin(), i);
    //         typename T::iterator targetIterator = binarySearch(result, *it, i, pairSize / 2);
    //         result.insert(targetIterator, it, advance(it, pairSize / 2));
    //     }
    //     jacob = getNextJacobsthal();
    // }

    typename T::iterator it = toInsert.begin();
    for (int i = 0; it != toInsert.end(); it = advance(it, pairSize / 2), i += pairSize / 2) {
        typename T::iterator target = binarySearch(result.begin(), advance(result.end(), -pairSize / 2 + 1), *it, pairSize / 2);
        cout << "inserting: " << *it << "\n";
        cout << "target: " << *target << "\n";
        result.insert(target, it, advance(it, pairSize / 2));
    }
    return result;
}

template <typename T>
T sort(T chain, int pairSize) {
    if (pairSize / 2 >= chain.size()) {
        return chain;
    }

    int pendSize = chain.size() % pairSize;
    typename T::iterator pendStart = advance(chain.end(), -pendSize);
    T pend(pendStart, chain.end());
    chain.erase(pendStart, chain.end());

    for (typename T::iterator it = chain.begin(); it != chain.end(); it = advance(it, pairSize)) {
        typename T::iterator next = advance(it, pairSize / 2);
        if (*it < *next) {
            T temp(next, advance(next, pairSize / 2));
            std::copy(it, next, next);
            std::copy(temp.begin(), temp.end(), it);
        }
    }

    T bigSorted = sort(chain, pairSize * 2);
    // return bigSorted;
    T insertSorted = binaryInsert(bigSorted, pend, pairSize);
    return insertSorted;
}

// void doTest(int value, int expected) {
//     vector<int> test = {5};
//     vector<int>::iterator target1 = binarySearch(test.begin(), test.end(), value, 1);
//     // vector<int>::iterator target1 = binary(test, value);
//     if (*target1 != expected) {
//         cout << "\e[1;31mfound: " << *target1 << " for: " << value;
//     } else {
//         cout << "\e[1;32mfound: " << *target1 << " for: " << value;
//     }
//     cout << "\n";
// }

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Error: a list of integers is required\n";
        return 1;
    }

    vector<int> vec;
    list<int> li;
    for (int i = 1; i < argc; i++) {
        int n = std::atoi(argv[i]);
        vec.push_back(n);
        li.push_back(n);
    }

    // doTest(1, 4);
    // doTest(6, 8);
    // doTest(15, 24);
    // doTest(3, 4);
    // doTest(56, 0);
    // doTest(-1, 0);

    // for (int i = 0; i < 10; i++) {
    //     std::pair<int, int> jacob = getNextJacobsthal();
    //     cout << jacob.first << "\n";
    // }

    vector<int> sortedVector = sort(vec, 2);
    cout << "\nRESULT: ";
    printVec(sortedVector);
    cout << isSorted(sortedVector, 1) << "\n";

    // list<int> sortedList = sort(li, 2);
    // cout << isSorted(sortedList, 1) << "\n";

    return 0;
}