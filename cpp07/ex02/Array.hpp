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
        for (unsigned int i = 0; i < other.size(); i++) {
        }
    }

    Array(const Array &other) {
        *this = other;
    }

    ~Array() {
        delete[] _arr;
    }

    unsigned int size() const {
        return _size;
    }
};

// template <typename T>
// class Array {
//    private:
//     unsigned int _size;
//     T *_arr;

//    public:
//     Array();
//     Array(unsigned int size);
//     Array &operator=(const Array &other);
//     Array(const Array &other);
//     ~Array();
//     unsigned int size() const;
// };

#endif