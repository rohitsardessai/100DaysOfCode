#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSequence(vector<int> list)
{
    int currentSeqLen = 1;
    int longestSeqLen = 1;

    for (auto it = list.begin(); it < (list.end() - 1); it++) {
        int currentValue = *it;
        int nextValue = *(it + 1);
        if (currentValue < nextValue) {
            currentSeqLen++;
        } else {
            if (currentSeqLen > longestSeqLen) {
                longestSeqLen = currentSeqLen;
            }
            currentSeqLen = 1;
        }
    }
    if (currentSeqLen > longestSeqLen) {
        longestSeqLen = currentSeqLen;
    }
    return longestSeqLen;
}

int main()
{
    cout << endl;
    vector<int> list = {5, 8, 3, 7, 9, 1, 2, 6, 12, 13, 22};

    for (auto it = list.begin(); it < list.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    int longestSeqLen = longestIncreasingSequence(list);

    cout << "Longest sequence length is " << longestSeqLen;

    cout << endl;
    return 0;
}