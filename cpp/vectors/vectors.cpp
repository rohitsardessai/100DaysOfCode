#include <iostream>
#include <string>
#include <vector>
// using namespace std;

class Student
{
    std::string name;
    int age;
    float percentage;

public:
    Student(std::string new_name, int new_age, float new_percentage)
    {
        name = new_name;
        age = new_age;
        percentage = new_percentage;
    }

    std::string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    float getPercentage()
    {
        return percentage;
    }
};

void vectorOfClass()
{
    std::vector<Student> students;

    Student student1("John", 30, 50.78);
    Student student2("Mary", 25, 26.8);
    Student student3("Sally", 43, 92.5);
    Student student4("Antonio", 29, 60.1);

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);

    for (auto student : students) {
        std::cout << "Name: " << student.getName();
        std::cout << ", Age: " << student.getAge();
        std::cout << ", Percentage: " << student.getPercentage() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void vectorOfInt()
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
}

int main()
{
    vectorOfInt();

    vectorOfClass();

    return 0;
}