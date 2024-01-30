#include "MutantStack.hpp"
#include <vector>

int main()
{
    {
        MutantStack<int> mstack;
        std::cout << "\e[1;33mCreated MutanStack< int > size " << mstack.size() << "\n\e[1;0m";
        std::cout << "\n\t\e[1;33mpush()ing 0 => 9\n\e[1;0m";
        for (int i = 0; i < 10; i++)
        {
            mstack.push(i);
        }

        std::cout << "\n\t\e[1;33mIterating with iterator\n\e[1;0m";
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator itEnd = mstack.end();
        std::cout << "\t[ ";
        while (it != itEnd)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "]";

        std::cout << "\n\n\t\e[1;33mPop()ing x3\n\e[1;0m";
        mstack.pop();
        mstack.pop();
        mstack.pop();
        it = mstack.begin();
        itEnd = mstack.end();
        std::cout << "\t[ ";
        while (it != itEnd)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "]";

        MutantStack<int> copy = mstack;
        std::cout << "\n\n\t\e[1;33mCreated new MutanStack< int > copy\n\e[1;0m";
        it = copy.begin();
        itEnd = copy.end();
        std::cout << "\t[ ";
        while (it != itEnd)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "]";
    }

    {
        MutantStack<std::string> mstack;
        std::cout << "\n\n\e[1;33mCreated MutanStack< string > size " << mstack.size() << "\n\e[1;0m";
        std::cout << "\n\t\e[1;33mpush()ing 'hello' x10\n\e[1;0m";
        for (int i = 0; i < 10; i++)
        {
            mstack.push("hello");
        }

        std::cout << "\n\t\e[1;33mIterating with iterator\n\e[1;0m";
        MutantStack<std::string>::iterator it = mstack.begin();
        MutantStack<std::string>::iterator itEnd = mstack.end();
        std::cout << "\t[ ";
        while (it != itEnd)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "]";

        std::cout << "\n\n\t\e[1;33mPop()ing x3\n\e[1;0m";
        mstack.pop();
        mstack.pop();
        mstack.pop();
        it = mstack.begin();
        itEnd = mstack.end();
        std::cout << "\t[ ";
        while (it != itEnd)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "]";

        MutantStack<std::string> copy = mstack;
        std::cout << "\n\n\t\e[1;33mCreated new MutanStack< int > copy\n\e[1;0m";
        it = copy.begin();
        itEnd = copy.end();
        std::cout << "\t[ ";
        while (it != itEnd)
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << "]";
    }

    {
        MutantStack<int> mstack;
        for (int i = 0; i < 10; i++)
        {
            mstack.push(i);
        }
        std::stack<int> stack(mstack);
        std::cout << "\n\n\e[1;33mCreated std::stack< int > from MutantStack size" << stack.size() << "\n\e[1;0m";
    }
}