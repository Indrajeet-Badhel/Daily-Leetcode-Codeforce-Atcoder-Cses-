/*Given an integer n, return true if and only if it is an Armstrong number.

A k-digit number n is an Armstrong number if the sum of each digit raised to the power k equals n.

Example 1

Input

n = 153

Output

true

Explanation

153 has 3 digits

1^3 + 5^3 + 3^3
= 1 + 125 + 27
= 153

So it is an Armstrong number.

Example 2

Input

n = 123

Output

false

Explanation

1^3 + 2^3 + 3^3
= 1 + 8 + 27
= 36

36 != 123, so it is not an Armstrong number.

Constraints
1 <= n <= 10^8

Function Signature
Java
public boolean isArmstrong(int n)
C++
bool isArmstrong(int n)
Python
def isArmstrong(self, n: int) -> bool:
Hidden Test Cases (likely)

LeetCode doesn't reveal all tests, but these are typical:

Input: 1
Output: true
Input: 5
Output: true
Input: 10
Output: false
Input: 370
Output: true
Input: 371
Output: true
Input: 407
Output: true
Input: 9474
Output: true
Input: 9475
Output: false
Simple Approach
Count digits k.
Extract every digit.
Add (digit ^ k) to a sum.
Return whether the sum equals the original number.

Complexity

Time:  O(log n)
Space: O(1)
*/
class Solution {
public:
    bool isarmstrong(int n){
        int original =n;
        int sum=0;
        int k=0;
        while(n>0){
            k++;
            n=n/10;
        }
        n=original;
        while(n>0){
            int digit=n%10;
            sum+=pow(digit,k);
            n=n/10;
        }
        return sum==original;
    }