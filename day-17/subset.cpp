/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.*/

class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int>& nums, vector<int>& current) {
        if(index == nums.size()) {
            ans.push_back(current);
            return;
        }
        for(int i=index;i<nums.size();i++){
            current.push_back(nums[i]);
            helper(i+1, nums, current);
            current.pop_back();
            helper(i+1, nums, current);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int > current;
        helper(0, nums, current);
        return ans;
};