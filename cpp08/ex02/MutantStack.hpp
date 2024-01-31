#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T, typename sequence = std::deque<T> >
class MutantStack : public std::stack<T, sequence>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack &other) {
        *this = other;
    }
    MutantStack &operator=(const MutantStack &other)
    {
        MutantStack::stack::operator=(other);
        return *this;
    }
    ~MutantStack(){};

    typedef typename sequence::iterator iterator;
    typedef typename sequence::reverse_iterator reverse_iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    reverse_iterator rend()
    {
        return this->c.rend();
    }
};

#endif