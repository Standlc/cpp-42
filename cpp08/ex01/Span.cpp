#include "Span.hpp"

Span::Span(unsigned int size) : _size(size) {}

Span::Span() : _size(0) {}

Span::Span(Span const &s) {
    *this = s;
}

Span::~Span() {}

Span &Span::operator=(Span const &s) {
    if (&s == this) {
        return *this;
    }
    _arr = s._arr;
    _size = s._size;
    return *this;
}

void Span::insert(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    long long size = end - begin; 
    if (size < 0 || size > UINT_MAX) {
        _size = 0;
        throw lengthError();
    }

    _size = size;
    unsigned int i = 0;
    while (begin != end && i < _size) {
        _arr.insert(_arr.begin() + i, *begin);
        begin++;
        i++;
    }
}

void Span::addNumber(int number) {
    if (_arr.size() + 1 > _size) {
        throw insertOutOfRange();
    }
    _arr.push_back(number);
}

void adjacentDifference(std::vector<int> &arr, std::vector<int> &target) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        target[i] = std::abs(arr[i + 1] - arr[i]);
    }
}

int Span::shortestSpan() {
    if (_arr.size() <= 1) {
        throw spanTooSmall();
    }

    std::vector<int> tmp = _arr;
    std::sort(tmp.begin(), tmp.end());

    std::vector<int> diff(tmp.size() - 1);
    adjacentDifference(tmp, diff);

    return (*std::min_element(diff.begin(), diff.end()));
}

int Span::longestSpan() {
    if (_arr.size() <= 1) {
        throw spanTooSmall();
    }

    std::vector<int>::iterator max_element_it = std::max_element(_arr.begin(), _arr.end());
    std::vector<int>::iterator min_element_it = std::min_element(_arr.begin(), _arr.end());
    return (std::abs(*max_element_it - *min_element_it));
}

int Span::size() {
    return _size;
}

std::vector<int> Span::data() {
    return _arr;
}