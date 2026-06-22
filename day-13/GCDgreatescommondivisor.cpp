/*my code */
/*class Solution {
public:
    int GCD(int n1,int n2) {
        if(n1>n2)return GCD(n2,n1);
        int gdc=INT_MIN;
        for(int i=0;i<n1;i++){
            int a=n1;
            int b=n2;
            while(a>0){
                a=a/i;
            }
            while(b>0){
                b=b/i;
            }
            if(a==0 && b==0){
                gdc =max(gdc,i);
            }
            else{
                continue;
            }
        }
        return gdc;
    }
};*/
/* using euclidean algorithm  */
class solution{
    public:
    int GCD(int n1,int n2){
        if(n1>n2){
            return GCD(n2,n1);
        }
        while(n1!=0){
            int temp=n1;
            n1=n2%n1;
            n2=temp;
        }
        return n2;
    }
};