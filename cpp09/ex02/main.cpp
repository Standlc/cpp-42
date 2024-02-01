#include <iostream>
#include <vector>
#include <cstdlib>

typedef std::vector<std::vector<int>> Pairs;

std::vector<int> makeCopy(std::vector<int> &vec, int start, int size)
{
    std::vector<int> res;
    for (int i = start; i < start + size; i++)
    {
        res.push_back(vec[i]);
    }
    return res;
}

void copyIn(std::vector<int> &in, std::vector<int> &copy)
{
}

void printVec(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

std::vector<int> sort(std::vector<int> &vec, int pairSize)
{
    if (pairSize == vec.size())
    {
        return vec;
    }

    printVec(vec);
    for (size_t i = 0; i < vec.size() - pairSize; i += pairSize * 2)
    {
        // if (i + pairSize - 1 >= vec.size()) {
        //     break;
        // }
        std::cout << "i: " << i << " " << vec[i] << "<" << vec[i + pairSize] << "\n";
        if (vec[i] < vec[i + pairSize])
        {
            std::vector<int> temp = makeCopy(vec, i, pairSize);
            printVec(temp);
            for (int j = i; j < i + pairSize; j++)
            {
                vec[j] = vec[j + pairSize];
                vec[j + pairSize] = temp[j - i];
            }
            // printVec(vec);
        }
    }

    // return vec;
    std::cout << "\n";
    std::vector<int> sorted = sort(vec, pairSize * 2);

    

    return sorted;
}

// [7, 8, 5, 9, 11, 0, 2, 1, 10, 3, 4, 6]
// [(7, 8), (5, 9), (0, 11), (1, 2), (3, 10), (4, 6)]
// [((7, 8), (5, 9)), ((1, 2), (0, 11)), ((4, 6), (3, 10))]
// [(((7, 8), (5, 9)), ((1, 2), (0, 11))), (((4, 6), (3, 10)))]
// [(((7, 8), (5, 9)), ((1, 2), (0, 11)))] | (((4, 6), (3, 10)))

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error: a list of integers is required\n";
        return 1;
    }

    std::vector<int> vec;
    for (int i = 1; i < argc; i++)
    {
        int n = std::atoi(argv[i]);
        // std::cout << n << "\n";
        vec.push_back(n);
    }

    std::vector<int> sorted = sort(vec, 1);

    printVec(sorted);

    return 0;
}