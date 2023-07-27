/**
 * @file employees_under_manager.cpp
 * @author Rohit Sardessai
 * @brief Given a dictionary of employees and managers, find the number of employees under each manager. From GeeksForGeeks
 * @version 0.1
 * @date 2023-07-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Taken from: https://www.geeksforgeeks.org/find-number-of-employees-under-every-manager/
Given a dictionary that contains mapping of employee and his manager as a number of (employee, manager) pairs like below.

{ "A", "C" },
{ "B", "C" },
{ "C", "F" },
{ "D", "E" },
{ "E", "F" },
{ "F", "F" }

In this example C is manager of A,
C is also manager of B, F is manager
of C and so on.
Write a function to get no of employees under each manager in the hierarchy not just their direct reports. It may be assumed that an employee directly reports to only one manager. In the above dictionary the root node/ceo is listed as reporting to himself.

Output should be a Dictionary that contains following.

A - 0
B - 0
C - 2
D - 0
E - 1
F - 3
*/

map<string, int> getReportingCount(const unordered_map<string, string> employeeDict)
{
    unordered_map<string, vector<string>> reversedDict;

    for (auto it = employeeDict.begin(); it != employeeDict.end(); it++) {
        string employee = it->first;
        string manager = it->second;
        // cout << employee << ", " << manager << endl;

        if (reversedDict.find(manager) == reversedDict.end()) {
            // manager does not exist yet
            vector<string> tmp;
            tmp.push_back(employee);
            reversedDict[manager] = tmp;
        } else {
            reversedDict[manager].push_back(employee);
        }
    }

    // cout << endl;
    // for (const auto &employee : reversedDict) {
    //     cout << employee.first << " ";
    //     for (const auto &subEmployee : employee.second) {
    //         cout << subEmployee << " ";
    //     }
    //     cout << endl;
    // }

    map<string, int> result;

    for (auto it = employeeDict.begin(); it != employeeDict.end(); it++) {
        if (reversedDict.find(it->first) == reversedDict.end()) {
            if (result.find(it->first) == result.end()) { // if the employee does not exist in result
                result[it->first] = 0;
            } else {
                break;
            }
        } else {
            result[it->first] = reversedDict[it->first].size();
        }
    }

    return result;
}

int main()
{
    unordered_map<string, string> employeeDict = {
        {"A", "C"},
        {"B", "C"},
        {"C", "F"},
        {"D", "E"},
        {"E", "F"},
        {"F", "F"}};

    // employeeDict.insert(pair<string, string>("A", "B"));

    for (auto employee : employeeDict) {
        cout << employee.first << " " << employee.second << endl;
    }

    map<string, int> reportingCount = getReportingCount(employeeDict); // use map in order to get a sorted result

    cout << endl;
    for (auto manager : reportingCount) {
        cout << manager.first << " " << manager.second << endl;
    }

    return 0;
}