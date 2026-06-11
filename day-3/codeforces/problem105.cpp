
/*Sequence terms are:

k=1 → 1 → sum of digits = 1

k=2 → 12 → sum = 3

k=3 → 123 → sum = 6

k=4 → 1234 → sum = 10

k=5 → 12345 → sum = 15

k=6 → 123456 → sum = 21
Now check divisibility by 3:

1 → not divisible

3 → divisible

6 → divisible

10 → not divisible

15 → divisible

21 → divisible

So the pattern is: not divisible, divisible, divisible, not divisible, divisible, divisible…

2. Generalizing the Pattern:
For every 3 consecutive numbers, 2 of them are divisible by 3.
So for n numbers, we have (n/3) groups of 3 numbers, each contributing 2 divisible numbers.
If n%3 == 2, then there's an extra pair of numbers where the second one is divisible by 3...i.e. 
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long  n;
    cin>>n;
    int result =(n/3)*2;
    if(n%3==2)result++;
    cout <<result;
    return 0;
}
    