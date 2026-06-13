class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // pointer for the next position to place non-val element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // overwrite at position k
                k++;
            }
        }
        return k;
    }
};