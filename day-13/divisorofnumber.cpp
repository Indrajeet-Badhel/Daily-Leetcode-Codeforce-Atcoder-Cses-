/*You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.



A number which completely divides another number is called it's divisor.


Example 1

Input: n = 6

Output = [1, 2, 3, 6]

Explanation: The divisors of 6 are 1, 2, 3, 6.

Example 2

Input: n = 8

Output: [1, 2, 4, 8]

Explanation: The divisors of 8 are 1, 2, 4, 8.*/
//my version
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int>divisor;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                divisor.push_back(i);
            }
            else{
                continue;
            }
        }
        return divisor;
    }
}; 
// ai optimsed cersion 
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> divisor;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisor.push_back(i);        // first divisor
                if (i != n / i) {            // avoid duplicate when i == sqrt(n)
                    divisor.push_back(n / i); // paired divisor
                }
            }
        }
        return divisor;
    }
};
/*Divisors always come in pairs

Take n = 36.

If 2 divides 36, then:

36 / 2 = 18

So 2 and 18 are a pair.

Similarly:

1 ↔ 36
2 ↔ 18
3 ↔ 12
4 ↔ 9
6 ↔ 6

Notice that once you reach 6 (√36), the pairs start repeating.*/
// but sorting has to be done is larger value is required
vector<int> divisors(int n) {
    vector<int> divisor;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);

            if (i != n / i) {
                divisor.push_back(n / i);
            }
        }
    }

    sort(divisor.begin(), divisor.end());
    return divisor;
}
// two vector apporch beteter 
vector<int> small, large;

for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
        small.push_back(i);

        if (i != n / i) {
            large.push_back(n / i);
        }
    }
}

vector<int> ans = small;

for (int i = large.size() - 1; i >= 0; i--) {
    ans.push_back(large[i]);
}