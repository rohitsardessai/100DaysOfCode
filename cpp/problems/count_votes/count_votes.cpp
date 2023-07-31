/**
 * @file count_votes.cpp
 * @author Rohit Sardessai
 * @brief Count votes porblem from GeeksForGeeks. More details below.
 * @version 0.1
 * @date 2023-07-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
Taken from: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Example 1:

Input:
n = 13
Votes[] = {john,johnny,jackie,johnny,john
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}
Output: john 4
Explanation: john has 4 votes casted for
him, but so does johny. john is
lexicographically smaller, so we print
john and the votes he received.
Example 2:

Input:
n = 3
Votes[] = {andy,blake,clark}
Output: andy 1
Explanation: All the candidates get 1
votes each. We print andy as it is
lexicographically smaller.
Your Task:
You only need to complete the function winner() that takes an array of strings arr, and n as parameters and returns the name of the candiate with maximum votes and the number of votes the candidate got as an array of size 2.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
*/

vector<string> winner(string arr[], int n)
{
    map<string, int> votes;
    for (int i = 0; i < n; i++) {
        if (votes.find(arr[i]) == votes.end()) {
            votes.insert(pair<string, int>(arr[i], 1));
        } else {
            votes[arr[i]] = votes[arr[i]] + 1;
        }
    }

    int maxVotes = 0;
    string winnerName = "";
    for (const auto &entry : votes) {
        if (entry.second > maxVotes) {
            maxVotes = entry.second;
            winnerName = entry.first;
        } else if (entry.second == maxVotes && entry.first < winnerName) {
            winnerName = entry.first;
        }
    }

    vector<string> result;
    result.push_back(winnerName);
    result.push_back(to_string(maxVotes));

    return result;
}

int main()
{
    int n;
    cout << "Enter the number of candidates: ";
    cin >> n;

    string arr[n];
    cout << "Enter the candidate names:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> result = winner(arr, n);
    cout << "The winner is: " << result[0] << " with " << result[1] << " votes.\n";

    return 0;
}
