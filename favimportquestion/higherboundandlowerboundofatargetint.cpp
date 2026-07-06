class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low=lower_bound(nums.begin(), nums.end(), target);
        auto high=upper_bound(nums.begin(), nums.end(), target);
       int k= (high-nums.begin());
       if(k-1>=0&&nums[k-1]!=target) return {-1,-1};
       int l=low-nums.begin();
        if (low == nums.end() || *low != target)
            return {-1, -1};
       return {l,k-1};
    }
};*/