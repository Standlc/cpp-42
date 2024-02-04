#include "RNP.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: am operation is required as a single argument\n";
        return 1;
    }

    try
    {
        float result = RNP(argv[1]);
        std::cout << "result: " << result << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    return 0;
}