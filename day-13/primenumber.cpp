/*Any integer can be expressed as:

6k
6k + 1
6k + 2
6k + 3
6k + 4
6k + 5
*/
/*very prime > 3 is of the form 6k ± 1*/
/*So i takes values:

5, 11, 17, 23, 29, ...

These are all numbers of the form:

6k - 1

Now look at i + 2:

7, 13, 19, 25, 31, ...

These are all numbers of the form:

6k + 1

Let's make a table:

i	i+2
5	7
11	13
17	19
23	25
29	31*/
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
};
//wrong buged fail for 49 this not prime but it is of the form 6k+1
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}