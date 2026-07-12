class Solution {
public:
    bool areNumbersAscending(string s) {
        int i=0;
        int n=s.size();
        int prev=0;
        int curr=0;
        while(i<n){
            if(isdigit(s[i])){
                int curr=0;
                while(i<n&&isdigit(s[i])){
                    curr=curr*10+s[i]-'0';
                    i++;
                }
                if(curr>prev){
                    prev=curr;
                }
                else{
                    return false;
                }
            }
            i++;
        }return true ;

    }
};