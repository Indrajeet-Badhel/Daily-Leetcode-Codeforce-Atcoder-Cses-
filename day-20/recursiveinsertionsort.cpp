class Solution {
public:
    void helper(vector<int>& nums, int i, int j) {
        // Outer recursion finished — whole array processed
        if (i == nums.size())
            return;

        // Inner "while" base case: reached start, or no longer out of order
        if (j == 0 || nums[j - 1] <= nums[j]) {
            helper(nums, i + 1, i + 1); // move to next element to insert
            return;
        }

        // Swap and keep bubbling left
        swap(nums[j - 1], nums[j]);
        helper(nums, i, j - 1);
    }

    vector<int> insertionSort(vector<int>& nums) {
        helper(nums, 1, 1); // start at i = 1, j = 1 (same as the for-loop's initial state)
        return nums;
    }
};