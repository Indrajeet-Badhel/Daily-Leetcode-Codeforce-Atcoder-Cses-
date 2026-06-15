/*Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1*/
class Solution {
public:
    int nextGreaterElement(int n) {
    string str=to_string(n);
    vector<int> digits;
for(char c : str)
    digits.push_back(c-'0');
    
    int i=digits.size()-2;
    while(i>=0&&digits[i]>=digits[i+1]){
        i--;
    }
    if(i<0)return -1;
    int j=digits.size()-1;
    while(j>=0&&digits[j]<=digits[i]){
        j--;
    }
    swap(digits[i],digits[j]);
    reverse(digits.begin()+i+1,digits.end());
    long long num=0;
    for(int i:digits){
        num=num*10+i;
    }
     if (num > INT_MAX) return -1;
        return (int)num;
    }
};
/*Goal

Find the smallest number greater than the current number using the same digits.

Step 1: Find Pivot

Move from right to left and find the first digit where:

digits[i] < digits[i+1]

Example:

1 2 4 6 5 3
    ^
   pivot = 4

Everything after pivot is guaranteed to be in descending order.

6 5 3
Step 2: Find Just Larger Element

From the right, find the first digit greater than pivot.

pivot = 4

6 5 3
  ^
  5

Why from the right?

Because it gives the smallest possible increase.

Step 3: Swap
1 2 4 6 5 3
      ↕
1 2 5 6 4 3

Now the number is larger.

Step 4: Make Suffix Minimum

After swap:

6 4 3

To get the next greater number, make the remaining part as small as possible.

3 4 6

Result:

125346
Why Reverse Works?

Before swap:

6 5 3

Descending.

After swap:

6 4 3

Still descending.

Smallest arrangement = ascending order.

6 4 3
↓ reverse
3 4 6

So:

reverse(begin+i+1, end);

is equivalent to sorting but faster.

When Answer Doesn't Exist

If the entire number is decreasing:

9 8 7 6 5

No pivot exists.

Already the largest permutation.

return -1;
One-Line Memory Trick

Pivot → Just Larger → Swap → Reverse Suffix

or

"Find where increasing is possible, increase it a little, then make the rest as small as possible."
*/