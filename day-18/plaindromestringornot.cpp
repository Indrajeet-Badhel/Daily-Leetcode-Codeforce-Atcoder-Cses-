bool recursionfunction(string &s, int start, int end) {
    if (start >= end) return true;

    if (!isalnum(s[start])) 
        return recursionfunction(s, start + 1, end);   // recurse again

    if (!isalnum(s[end])) 
        return recursionfunction(s, start, end - 1);   // recurse again

    if (tolower(s[start]) != tolower(s[end])) 
        return false;

    return recursionfunction(s, start + 1, end - 1);
}
/*class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};*/