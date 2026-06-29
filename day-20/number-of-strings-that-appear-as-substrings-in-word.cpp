/*Intuition
For each string in patterns, we only need to check whether it appears as a substring of word. C++ provides the built-in find() function, which returns the starting index of the substring if it exists; otherwise, it returns string::npos. Count every pattern that is found.

Approach
Initialize a counter to 0.
Iterate through each string in patterns.
Use word.find(pattern) to check if the pattern exists in word.
If the result is not string::npos, increment the counter.
Return the final count.
Complexity
Time complexity: O(P × N × M) in the worst case, where:

P = number of patterns
N = length of word
M = average length of a pattern
Space complexity: O(1)

Code
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string &s : patterns) {
            if (word.find(s) != string::npos) {
                count++;
            }
        }

        return count;
    }
};*/