class Solution {
public:
    void reverseString(vector<char>& s) {

        int start = 0;
        int end = s.size() - 1;

        while(start <= end){

            swap(s[start], s[end]);

            start++;
            end--;
        }
    }
};

/*using recursion*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }

private:
    void reverse(vector<char>& s, int start, int end) {
        if (start >= end) {
            return;
        }
        swap(s[start], s[end]);
        reverse(s, start + 1, end - 1);
    }
};