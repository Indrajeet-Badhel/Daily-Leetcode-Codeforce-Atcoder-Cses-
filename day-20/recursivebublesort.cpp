#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &nums,int i,int j){
    if(i==nums.size()-1){
        return;
    }
    if(j==nums.size-i-1){
        helper(nums,i+1,0);
        return;
    }

    if(nums[j]<nums[j-1]){
        swap(nums[j-1],nums[j]);
    }
    helper(nums,i,j+1);
}
vector<int>bubblesort(vector<int> &nums){
    helper(nums,0,0);
    return nums;
}