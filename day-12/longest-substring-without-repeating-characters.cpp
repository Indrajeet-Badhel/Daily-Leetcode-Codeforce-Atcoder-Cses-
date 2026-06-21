class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charset;

        int maxlength = 0;
        int left = 0;

        for(int right = 0; right < s.length(); right++) {

            while(charset.find(s[right]) != charset.end()) {
                charset.erase(s[left]);
                left++;
            }

            charset.insert(s[right]);

            maxlength = max(maxlength, right - left + 1);
        }

        return maxlength;
    }
};