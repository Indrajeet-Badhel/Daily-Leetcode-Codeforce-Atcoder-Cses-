/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104*/
/*brute force*/
/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx=0;
        int found=0;
        for(int i : nums){
            while(!found){
            if (i==target){
                idx++;
            }
            if (i>target){
                return idx;
                found =1;
            }
            else{
                return target;
                found=0;
            }
            }


        }
        return 0;
    }};*/

    /*log(n)-binary search approch */
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // found exact match
            } else if (nums[mid] < target) {
                left = mid + 1; // search right half
            } else {
                right = mid - 1; // search left half
            }
        }
        
        // If not found, 'left' is the correct insertion index
        return left;
    }
};
