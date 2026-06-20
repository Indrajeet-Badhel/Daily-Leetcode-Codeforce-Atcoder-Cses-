class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;

        while(left<right){
            while(left<right&&!isalnum(s[left])){
                left++;
            }
            while(left<right&&!isalnum(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }

        right--;
        left++;
        }
        return true;
    }
};
/*class Solution:
    def isPalindrome(self, s: str) -> bool:

        left = 0
        right = len(s) - 1

        while left < right:

            while left < right and not s[left].isalnum():
                left += 1

            while left < right and not s[right].isalnum():
                right -= 1

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True*/