/*faster run time */
class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        vector <int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}; /*for less memory space */
class Solution {
public:
    int fibonaci(int n){
       if(n == 0) return 0;  
        if (n == 1) return 1;  
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
    int fib(int n) {
        return fibonaci(n);
    }
};