/*You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

You are also given an integer k.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

 

Example 1:

Input: s = "a#b%*", k = 1

Output: "a"

Explanation:

i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
The final result is "ba". The character at index k = 1 is 'a'.

Example 2:

Input: s = "cd%#*#", k = 3

Output: "d"

Explanation:

i	s[i]	Operation	Current result
0	'c'	Append 'c'	"c"
1	'd'	Append 'd'	"cd"
2	'%'	Reverse result	"dc"
3	'#'	Duplicate result	"dcdc"
4	'*'	Remove the last character	"dcd"
5	'#'	Duplicate result	"dcddcd"
The final result is "dcddcd". The character at index k = 3 is 'd'.

Example 3:

Input: s = "z*#", k = 0

Output: "."

Explanation:

i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
The final result is "". Since index k = 0 is out of bounds, the output is '.'.

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters and special characters '*', '#', and '%'.
0 <= k <= 1015
The length of result after processing s will not exceed 1015.*/
/*brute force code*/
#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    char kthChar(string s, long long k) {
        string result;
        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) result.pop_back();
            }
            else if (c == '#') {
                result += result;
            }
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
            else {
                result.push_back(c);
            }
        }
        // Now check k
        if (k < 0 || k >= (long long)result.size()) {
            return '.';
        }
        return result[k];
    }
};

int main() {
    Solution sol;
    cout << sol.kthChar("a#b%*", 1) << endl;   // Expected 'a'
    cout << sol.kthChar("cd%#*#", 3) << endl;  // Expected 'd'
    cout << sol.kthChar("z*#", 0) << endl;     // Expected '.'
    return 0;
}
*/
/*optimized code*/
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        // Forward pass: compute length after each operation
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = len[i] * 2;
            }
            else {
                len[i + 1] = len[i];
            }
        }

        if (k < 0 || k >= len[n]) return '.';

        // Backtrack
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                // This character was appended at position len[i]
                if (k == len[i]) return ch;
            }
            else if (ch == '*') {
                // deletion doesn't change k when going backwards
            }
            else if (ch == '#') {
                // string doubled: map k back into first half
                k %= len[i];
            }
            else {
                // If this operation was reverse-string,
                // map index back accordingly
                if (len[i] > 0) {
                    k = len[i] - 1 - k;
                }
            }
        }

        return '.';
    }
};