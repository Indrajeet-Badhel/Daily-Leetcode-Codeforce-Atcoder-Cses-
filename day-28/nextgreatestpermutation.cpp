#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int in1=-1;
        int in2=-1;
        bool decreasing=true;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                in1=i;
                decreasing=false;
                break;
            }
        }
        if(decreasing){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]>nums[in1]){
                    in2=i;
                    break;
                }
            }
            swap(nums[in1],nums[in2]);
            reverse(nums.begin()+in1+1,nums.end());
    }
    }
};