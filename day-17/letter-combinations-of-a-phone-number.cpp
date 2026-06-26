/*my version */
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        unordered_map<char, vector<string>> mp;

        mp['2'] = {"a","b","c"};
        mp['3'] = {"d","e","f"};
        mp['4'] = {"g","h","i"};
        mp['5'] = {"j","k","l"};
        mp['6'] = {"m","n","o"};
        mp['7'] = {"p","q","r","s"};
        mp['8'] = {"t","u","v"};
        mp['9'] = {"w","x","y","z"};

        vector<string> ans;

        for (char d : digits) {

            if (ans.empty()) {
                ans = mp[d];
            }
            else {
                vector<string> temp;

                for (string s : ans) {
                    for (string ch : mp[d]) {
                        temp.push_back(s + ch);
                    }
                }

                ans = temp;
            }
        }

        return ans;
    }
};/*Iterative Logic

Initially ans is empty.

For each digit:

If ans is empty (first digit), simply copy its letters into ans.
Otherwise,
create a temporary vector
for every string in ans
for every letter of current digit
push old + letter into temp
assign ans = temp*/

/*logoic using backtracking 
*/
class solution{
 public:
 vector<string> ans;
 void helper(int index,string digits,map<char,string> &mp,string &current){
    if(index==digits.size()){
        ans.push_back(current);
        return; 
    }
    char ch = digits[index];
    for(char c:mp[ch]){
        current.push_back(c);
        helper(index+1,digits,mp,current);
        current.pop_back();
    }
  }
  vector<string> lettercombination(string digits){
    if(digits.empty()) return ans;
    map<char,string> mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    string current;
    helper(0,digits,mp,current);
    return ans;

  }

};