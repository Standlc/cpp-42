#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <climits>

class Span {
   private:
    unsigned int _size;
    std::vector<int> _arr;

    struct insertOutOfRange : public std::exception {
        const char *what() const throw() {
            return "Span is full (insert out of range)";
        }
    };

    struct spanTooSmall : public std::exception {
        const char *what() const throw() {
            return "Span is either empty or has only one element";
        }
    };

    class lengthError : public std::exception {
        const char *what() const throw() {
            return "Length from iterators is negative";
        }
    };

   public:
    Span();
    Span(unsigned int n);
    Span(const Span &s);
    Span &operator=(const Span &s);
    ~Span();

    void insert(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    int size();
    std::vector<int> data();
};

#endif