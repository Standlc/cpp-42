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
    for (typename T::iterator it = vec.begin(); it + pairSize < vec.end(); it = advance(it, pairSize)) {
        if (*it > *(it + pairSize)) {
            cout << "\e[0;31m";
            return false;
        }
    }
    cout << "\e[1;0m";
    return true;
}

void printVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

template <typename T>
typename T::iterator binarySearch(T &vec, int value, int searchRange, int pairSize) {
    int jumpSize = (searchRange / 2 / pairSize * pairSize);
    typename T::iterator middle = advance(vec.begin(), jumpSize);

    if (jumpSize / 2 / pairSize * pairSize >= pairSize) {
        jumpSize = jumpSize / 2 / pairSize * pairSize;
    }
    if (!jumpSize) {
        jumpSize = pairSize;
    }
    while (true) {
        typename T::iterator nextMiddle = middle;

        if (value > *middle) {
            nextMiddle = advance(middle, jumpSize);
            if (nextMiddle == vec.end()) {
                return vec.end();
            }
        } else {
            nextMiddle = advance(middle, -jumpSize);
            // if (nextMiddle < vec.begin()) {
            //     return vec.begin();
            // }
            if (middle == vec.begin() && value <= *middle) {
                return vec.begin();
            }
            if (jumpSize == pairSize && value > *nextMiddle) {
                return middle;
            }
        }

        middle = nextMiddle;
        if (jumpSize / 2 / pairSize * pairSize >= pairSize) {
            jumpSize = jumpSize / 2 / pairSize * pairSize;
        }
    }
    return middle;
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

    if (pend.size()) {
        typename T::iterator targetIterator = binarySearch(result, *pend.begin(), result.size(), pairSize / 2);
        result.insert(targetIterator, pend.begin(), pend.end());
    }

    typename T::iterator it = advance(toInsert.begin(), pairSize / 2);
    for (int i = 0; it != toInsert.end(); it = advance(it, pairSize / 2), i += pairSize / 2) {
        typename T::iterator targetIterator = binarySearch(result, *it, i, pairSize / 2);
        result.insert(targetIterator, it, advance(it, pairSize / 2));
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
    T insertSorted = binaryInsert(bigSorted, pend, pairSize);
    return insertSorted;
}

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

    vector<int> sortedVector = sort(vec, 2);

    list<int> sortedList = sort(li, 2);

    list<int>::iterator it = li.begin();
    // it += 1;

    cout << "\nRESULT: ";
    // printVec(sortedVector);
    cout << isSorted(sortedVector, 1);
    // cout << isSorted(sortedList, 1);

    return 0;
}