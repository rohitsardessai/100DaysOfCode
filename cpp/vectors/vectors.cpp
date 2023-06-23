#include <iostream>
#include <vector>
// using namespace std;

int main()
{
    std::vector<int> numbers;

    for (int i = 0; i < 10; i++) {
        numbers.push_back(i);
    }
    numbers.insert((numbers.begin() + 1), 15);
    *(numbers.begin() + 4) = 22;

    for (auto it = numbers.begin(); it < numbers.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}