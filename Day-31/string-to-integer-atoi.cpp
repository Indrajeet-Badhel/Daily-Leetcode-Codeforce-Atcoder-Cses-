class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size();
        while(i<n&&s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n&&(s[i]=='+'||s[i]=='-')){
            if(s[i]=='-')sign=-1;
            i++;
        }
        long ans=0;
        while(i<n&&isdigit(s[i])){
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if(ans*sign>INT_MAX)return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return ans*sign;
    }
};