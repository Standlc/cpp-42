#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
    return std::find(container.begin(), container.end(), n);
}

#endif