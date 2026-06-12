/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.*/
#include <bits/stdc++.h>
using namespace std;
/* horizontal scanning approach */
/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty())return "";
       string prefix=strs[0];
       for(int i =1;i<strs.size();i++){
        while(strs[i].find(prefix)!=0){
            prefix=prefix.substr(0,prefix.size()-1);
            if(prefix.empty())return "";
        }

       }
       return prefix;
    }
};*/
/* vertical scanning approach */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        for(int i =0;i<strs[0].size();i++){
            char c = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i<strs[j].size() && strs[j][i]==c){
                    continue;
                }else{
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};