#include <iostream>

class Employee
{
private:
    std::string name;
    std::string department;
    int age;

public:
    // Constructor:
    Employee(std::string name, std::string department, int age)
        : name(name), department(department), age(age)
    {
        // this->name = name;
        // this->department = department;
        // this->age = age;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setDepartment(std::string department)
    {
        this->department = department;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    std::string getDepartment()
    {
        return this->department;
    }

    std::string getName()
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

    virtual void printInfo()
    {
        std::cout << std::endl;
        std::cout << "Employee info: " << std::endl;
        std::cout << "\tEmployee name: " << getName() << std::endl;
        std::cout << "\tEmployee department: " << getDepartment() << std::endl;
        std::cout << "\tEmployee age: " << getAge() << std::endl;
        std::cout << std::endl;
    }
};

class Developer : public Employee
{
private:
    std::string domain;

public:
    Developer(std::string name, std::string department, int age, std::string domain)
        : Employee(name, department, age), domain(domain) {}

    void setDomain(std::string domain)
    {
        this->domain = domain;
    }

    std::string getDomain()
    {
        return this->domain;
    }

    void printInfo() override
    {
        std::cout << std::endl;
        std::cout << "Developer info: " << std::endl;
        std::cout << "\tDeveloper name: " << getName() << std::endl;
        std::cout << "\tDeveloper department: " << getDepartment() << std::endl;
        std::cout << "\tDeveloper age: " << getAge() << std::endl;
        std::cout << "\tDeveloper domain: " << getDomain() << std::endl;
        std::cout << std::endl;
    }
};

int main()
{
    Employee employee("John", "Engineering", 27);

    // std::cout << "Employee name: " << employee.getName() << std::endl;
    // std::cout << "Employee department: " << employee.getDepartment() << std::endl;
    // std::cout << "Employee age: " << employee.getAge() << std::endl;

    employee.printInfo();

    Developer dev1("Margaret Thatcher", "Engineering", 36, "Embedded Software");
    dev1.printInfo();

    return 0;
}