/**
 * @file pair_sum.cpp
 * @author Rohit Sardessai
 * @brief Given an list of numbers, find a pair that adds up to a given target. Ex. given {1, 2, 3, 9} and target 10, identify that 1 and 9 add up to 10.
 * @version 0.1
 * @date 2023-07-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> getRandomIntegers(int size, int minValue, int maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minValue, maxValue);

    std::vector<int> randomIntegers;
    randomIntegers.reserve(size);

    for (int i = 0; i < size; ++i) {
        randomIntegers.push_back(distribution(gen));
    }

    return randomIntegers;
}

bool findPair(std::vector<int> &vec, int targetSum)
{
    int leftIndex = 0;
    int rightIndex = vec.size() - 1;

    while (leftIndex < rightIndex) {
        int sum = vec[leftIndex] + vec[rightIndex];

        if (sum == targetSum) {
            return true;
        }
        if (sum < targetSum) {
            leftIndex++;
        } else {
            rightIndex--;
        }
    }
    return false;
}

int main()
{
    int listLen;

    std::cout << "Enter the size of the list: ";
    std::cin >> listLen;

    std::vector<int> randomNumbers = getRandomIntegers(listLen, 0, (2 * listLen));

    std::sort(randomNumbers.begin(), randomNumbers.end());

    for (int number : randomNumbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    int sumToSearch;
    std::cout << "Enter the sum to look for: ";
    std::cin >> sumToSearch;

    std::cout << "Response: " << findPair(randomNumbers, sumToSearch) << std::endl;

    return 0;
}