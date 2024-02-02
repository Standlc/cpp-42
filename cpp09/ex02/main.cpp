#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;

typedef std::vector<std::vector<int>> Pairs;
typedef std::vector<int> VectorInt;

// template <typename T>
// class GroupedIterator
// {
// private:
//     typename std::vector<T>::iterator current;

// public:
//     GroupedIterator(typename std::vector<T>::iterator it) : current(it) {}

//     std::vector<T> operator*()
//     {
//         return *current;
//     }

//     GroupedIterator<T> &operator++()
//     {
//         ++current;
//         return *this;
//     }

//     bool operator==(const GroupedIterator<T> &other) const
//     {
//         return current == other.current;
//     }

//     bool operator!=(const GroupedIterator<T> &other) const
//     {
//         return current != other.current;
//     }
// };

// VectorInt makeCopy(VectorInt &vec, int start, int size)
// {
//     VectorInt res;
//     for (int i = start; i < start + size; i++)
//     {
//         res.push_back(vec[i]);
//     }
//     return res;
// }

void printVec(VectorInt &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

// 0 1 2 3 4 5 6 7
// 0 0 2 2 4 4 6 6

// 0 1 2 3 4 5 6 7
// 0 0 0 0 4 4 4 4

VectorInt::iterator binarySearch(VectorInt &vec, int value, int pairSize)
{
    VectorInt::iterator it = vec.begin() + (vec.size() / 2 / (pairSize / 2));
    cout << "first: " << *it << "\n";
    size_t jump = vec.size() / 4;

    while (true)
    {
        cout << *it << " < " << value << "\n";
        if (*it < value)
        {
            it = it - jump;
            if (it <= vec.begin() || !jump)
            {
                return vec.begin();
            }
        }
        else
        {
            it = it + jump;
            if (it >= vec.end() || !jump)
            {
                return vec.end();
            }
        }
        jump /= 2;
    }
    cout << "\n";
    return it;
}

VectorInt binaryInsert(VectorInt &vec, int pairSize)
{
    VectorInt res;

    for (VectorInt::iterator it = vec.begin(); vec.end() - it > 0; it += pairSize)
    {
        for (int i = 0; i < pairSize / 2; i++)
        {
            res.push_back(*(it + i));
        }
    }

    cout << "inserting into: ";
    printVec(res);

    for (VectorInt::iterator it = vec.begin() + pairSize / 2; vec.end() - it > 0; it += pairSize)
    {
        cout << "inserting: " << *it << "\n";
        VectorInt::iterator target = binarySearch(res, *it, pairSize);
        cout << "target: " << *target << "\n";
        res.insert(target, it, it + pairSize / 2);
        cout << "after: ";
        printVec(res);
    }

    return res;
}

VectorInt sort(VectorInt &vec, int pairSize)
{
    cout << "Pair size: " << pairSize << "\n";
    if (pairSize >= vec.size())
    {
        return vec;
    }

    VectorInt::iterator it = vec.begin();
    for (; vec.end() - (it + pairSize + pairSize - 1) > 0; it += pairSize * 2)
    {
        VectorInt::iterator next = it + pairSize;
        if (*it < *next)
        {
            cout << *it << "<" << *next << "\n";
            VectorInt temp(next, next + pairSize);
            std::copy(it, next, next);
            std::copy(temp.begin(), temp.end(), it);
            cout << "\n";
        }
    }

    cout << "pend: ";
    VectorInt pend(it, vec.end());
    printVec(pend);

    vec.erase(it, vec.end());
    VectorInt sorted = sort(vec, pairSize * 2);

    cout << "sorted: ";
    printVec(sorted);

    VectorInt insertSorted = binaryInsert(sorted, pairSize * 2);

    // if (pend.size())
    // {
    //     VectorInt::iterator target = binarySearch(insertSorted, *pend.begin());
    //     cout << "target: " << *target << "\n";
    //     insertSorted.insert(target, pend.begin(), pend.end());
    // }

    cout << "\n";
    return insertSorted;
}

// [7, 10, 9, 5, 8]

// [(7, 10), (5, 9), 8]

// (9, 10)
// [((5, 9), (7, 10))]

// [7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6]

// [(7, 8), (5, 9), (0, 11), (1, 2), (3, 10), (4, 6)]

// [((7, 8), (5, 9)), ((1, 2), (0, 11)), ((4, 6), (3, 10))]

// [(((7, 8), (5, 9)), ((1, 2), (0, 11))), (((4, 6), (3, 10)))]

// [(((7, 8), (5, 9)), ((1, 2), (0, 11)))] | (((4, 6), (3, 10)))

//     1
// 5 4 3 2

template <typename T>
void test(std::vector<T> vec)
{
    test(vec);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "Error: a list of integers is required\n";
        return 1;
    }

    VectorInt vec;
    for (int i = 1; i < argc; i++)
    {
        int n = std::atoi(argv[i]);
        vec.push_back(n);
    }

    std::pair<std::pair<int, int>, std::pair<int, int>> pair = {{1, 2}, {3, 4}};
    cout << *(reinterpret_cast<int *>(&(pair))) << "\n";

    // VectorInt sorted = sort(vec, 1);
    // printVec(sorted);

    return 0;
}