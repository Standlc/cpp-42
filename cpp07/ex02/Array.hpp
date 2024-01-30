#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
   private:
    unsigned int _size;
    T *_arr;

   public:
    Array() {
        _arr = new T[0];
        _size = 0;
    }

    Array(unsigned int size) {
        _arr = new T[size];
        _size = size;
    }

    Array &operator=(const Array &other) {
        delete[] _arr;
        _size = other.size();
        _arr = new T[_size];
        for (unsigned int i = 0; i < other.size(); i++) {
            _arr[i] = other[i];
        }
        return *this;
    }

    Array(const Array &other) {
        _arr = NULL;
        *this = other;
    }

    ~Array() {
        delete[] _arr;
    }

    T &operator[](unsigned int i) const {
        if (i < 0 || i >= _size) {
            throw std::invalid_argument("Invalid index for accessing array.");
        }
        return _arr[i];
    }

    unsigned int size() const {
        return _size;
    }
};

#endif