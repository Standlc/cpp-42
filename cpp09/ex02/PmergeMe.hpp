#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <climits>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::list;
using std::pair;
using std::vector;

template <typename Iterator>
Iterator advanceIt(Iterator it, int amount);

template <typename T>
bool isSorted(T &vec, int pairSize);

template <typename T>
void debugPrintNumbers(T &vec, int pairSize);

template <typename Iterator>
int dist(Iterator begin, Iterator end);

pair<int, int> getNextJacobsthal(bool reset = false);

template <typename T>
T binarySearch(T left, T right, int value, int pairSize);

template <typename T>
T binaryInsert(T &chain, T &pend, int pairSize);

template <typename T>
T mergeInsert(T chain, size_t pairSize);

#endif