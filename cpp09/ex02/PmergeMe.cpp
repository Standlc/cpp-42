#include "PmergeMe.hpp"

// ---------------
// DEBUG FUNCTIONS

template <typename T>
bool isSorted(T &numbers, int pairSize) {
    for (typename T::iterator it = numbers.begin(); it != numbers.end(); it = advanceIt(it, pairSize)) {
        typename T::iterator next = advanceIt(it, pairSize);
        if (next == numbers.end()) {
            break;
        }
        if (*it > *next) {
            cout << "\e[0;31m";
            return false;
        }
    }
    cout << "\e[1;32m";
    return true;
}

template <typename T>
void debugPrintNumbers(T &numbers, int pairSize) {
    isSorted(numbers, pairSize);
    cout << "OK \e[0m";
    cout << "\e[1;30msize " << numbers.size() << " \e[0m";
    cout << "[ ";
    typename T::iterator it = numbers.begin();
    for (; it != numbers.end(); it++) {
        cout << *it << " ";
    }
    cout << "]";
    cout << "\e[\n";
}

// DEBUG FUNCTIONS
// ---------------

template <typename Iterator>
Iterator advanceIt(Iterator it, int amount) {
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

template <typename Iterator>
int dist(Iterator begin, Iterator end) {
    int i = 0;
    while (begin != end) {
        i++;
        begin++;
    }
    return i;
}

std::pair<int, int> getNextJacobsthal(bool reset) {
    static int curr = 0;
    static int next = 1;

    if (reset) {
        curr = 0;
        next = 1;
    }

    int temp = next;
    next = 2 * curr + next;
    curr = temp;
    return std::make_pair(curr, next);
}

template <typename T>
T binarySearch(T left, T right, int value, int pairSize) {
    while (left != right) {
        T mid = advanceIt(left, dist(left, right) / 2 / pairSize * pairSize);

        if (value == *mid) {
            return mid;
        }
        if (value < *mid) {
            right = mid;
        } else {
            left = advanceIt(mid, pairSize);
        }
    }
    return left;
}

template <typename T>
T binaryInsert(T &chain, T &pend, int pairSize) {
    T result;
    T toInsert;
    int newPairSize = pairSize / 2;

    for (typename T::iterator it = chain.begin(); it != chain.end();) {
        for (int i = 0; i < newPairSize; i++) {
            result.push_back(*(it++));
        }
        for (int i = 0; i < newPairSize; i++) {
            toInsert.push_back(*(it++));
        }
    }

    if (pend.size()) {
        typename T::iterator target = binarySearch(result.begin(), result.end(), *pend.begin(), newPairSize);
        result.insert(target, pend.begin(), pend.end());
    }

    pair<int, int> jacob = getNextJacobsthal(true);
    jacob.first = 0;
    for (size_t count = 0; count < toInsert.size();) {
        for (int i = jacob.second; i > jacob.first; i--) {
            size_t indexToInsert = (i - 1) * newPairSize;
            if (indexToInsert >= toInsert.size()) {
                continue;
            }
            typename T::iterator it = advanceIt(toInsert.begin(), indexToInsert);
            typename T::iterator maxRangeIt = advanceIt(result.begin(), indexToInsert + count + newPairSize);
            typename T::iterator target = binarySearch(result.begin(), maxRangeIt, *it, newPairSize);
            result.insert(target, it, advanceIt(it, newPairSize));
            count += newPairSize;
        }
        jacob = getNextJacobsthal();
    }
    return result;
}

template <typename T>
T mergeInsert(T chain, size_t pairSize) {
    if (pairSize / 2 >= chain.size()) {
        return chain;
    }

    int pendSize = chain.size() % pairSize;
    typename T::iterator pendStart = advanceIt(chain.end(), -pendSize);
    T pend(pendStart, chain.end());
    chain.erase(pendStart, chain.end());

    for (typename T::iterator it = chain.begin(); it != chain.end(); it = advanceIt(it, pairSize)) {
        typename T::iterator next = advanceIt(it, pairSize / 2);
        if (*it < *next) {
            T temp(next, advanceIt(next, pairSize / 2));
            std::copy(it, next, next);
            std::copy(temp.begin(), temp.end(), it);
        }
    }

    T bigSorted = mergeInsert(chain, pairSize * 2);
    T insertSorted = binaryInsert(bigSorted, pend, pairSize);
    return insertSorted;
}

template vector<int>::iterator advanceIt(vector<int>::iterator it, int amount);
template bool isSorted(vector<int> &vec, int pairSize);
template void debugPrintNumbers(vector<int> &vec, int pairSize);
template int dist(vector<int>::iterator begin, vector<int>::iterator end);
template vector<int>::iterator binarySearch(vector<int>::iterator left, vector<int>::iterator right, int value, int pairSize);
template vector<int> binaryInsert(vector<int> &chain, vector<int> &pend, int pairSize);
template vector<int> mergeInsert(vector<int> chain, size_t pairSize);

template list<int>::iterator advanceIt(list<int>::iterator it, int amount);
template bool isSorted(list<int> &vec, int pairSize);
template void debugPrintNumbers(list<int> &vec, int pairSize);
template int dist(list<int>::iterator begin, list<int>::iterator end);
template list<int>::iterator binarySearch(list<int>::iterator left, list<int>::iterator right, int value, int pairSize);
template list<int> binaryInsert(list<int> &chain, list<int> &pend, int pairSize);
template list<int> mergeInsert(list<int> chain, size_t pairSize);
