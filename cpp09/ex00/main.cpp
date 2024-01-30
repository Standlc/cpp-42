#include <map>
#include <iostream>

int main() {
    std::map<int, int> map;

    map[3] = 3;
    map[2] = 2;
    map[1] = 1;
    map[4] = 3;
    map[0] = 1;

    std::map<int, int>::iterator it = map.begin();
    std::map<int, int>::iterator end = map.end();
    while (it != end) {
        std::cout << it->first << " " << it->second << "\n";
        it++;
    }
}