/*my code class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){if(i+1<nums.size())return{i,i+1};
            else{
                return {i,i};
            }
            }
        }
        return{-1,-1};
    }
};*/
/*o(logn){
}*/
class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;   // Search further left
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;    // Search further right
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurrence(nums, target),
                lastOccurrence(nums, target)};
    }
};
/*
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