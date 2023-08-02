#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int getFactorial(int number)
{
    int factorial = 1;
    while (number > 0) {
        factorial *= number;
        number--;
    }
    return factorial;
}

void printFibonacciSeq(int max)
{
    if (max < 1) {
        cout << "Invalid" << endl;
    } else if (max == 1) {
        cout << "0" << endl;
    } else if (max == 2) {
        cout << "0 1";
    } else {
        cout << "0 1 ";
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 2; i <= max; i++) {
            int fibonacciNumber = prev1 + prev2;
            cout << fibonacciNumber << " ";
            prev2 = prev1;
            prev1 = fibonacciNumber;
        }
        cout << endl;
    }
}

int freqOfNumber(long number, int i)
{
    int freq = 0;
    while (number > 0) {
        if (number % 10 == i) {
            freq++;
        }
        number /= 10;
    }
    return freq;
}
void duplicate(int &a, int &b, int &c)
{
    a *= 2;
    b *= 2;
    c *= 2;
}

bool checkPalindrome(int num)
{
    int originalNum = num;
    int reversedNum = 0;
    while (num > 0) {
        int digit = num % 10;
        reversedNum = (reversedNum * 10) + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

bool checkAnagram(std::string str1, std::string str2)
{
    std::unordered_set<char> str1_set;

    for (int i = 0; i < str1.length(); i++) {
        str1_set.insert(str1[i]);
    }

    for (int i = 0; i < str2.length(); i++) {
        if (str1_set.find(str2[i]) == str1_set.end()) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str1, str2;
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    if (checkAnagram(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }

    long number = 115352413215123;
    int i = 3;

    int x = 2, y = 4, z = 5;
    duplicate(x, y, z);
    cout << x << y << z << endl;

    cout << "Freq: " << freqOfNumber(number, i) << endl;

    cout << "Enter a number: " << endl;
    int num;
    cin >> num;

    cout << "Is palindrome: " << checkPalindrome(num) << endl;

    return 0;

    cout << "Factorial: " << getFactorial(num) << endl;

    cout << endl
         << "Fibonacci Seq:" << endl;
    printFibonacciSeq(num);
    cout << endl;
    return 0;
}