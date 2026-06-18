/*to convert the num to bool you can perform the following method
method1 :- 
6 % 2 = 0
6 / 2 = 3

3 % 2 = 1
3 / 2 = 1

1 % 2 = 1
1 / 2 = 0

Collected = 011
*/ 
/*my version */
class Solution {
public:
    bool consecutiveSetBits(int n) {
        bool prev=false;
        int sum =0;
        while(n>0){
            bool current=n%2;
            n/=2;
            if(current==true&&prev==true){
                sum++;
            }
            prev=current;
        }
        return sum==1;

    }
};
