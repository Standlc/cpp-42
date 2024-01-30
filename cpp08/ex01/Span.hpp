#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

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
    Span(unsigned int n);
    Span();
    ~Span();
    Span(const Span &s);
    Span(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    Span &operator=(const Span &s);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    int size();
};

#endif