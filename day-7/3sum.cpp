method 1:-class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniquetriplets;

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            set<int> s;

            for (int j = i + 1; j < nums.size(); j++) {
                int tofind = target - nums[j];

                if (s.find(tofind) != s.end()) {
                    vector<int> triplet = {nums[i], nums[j], tofind};
                    sort(triplet.begin(), triplet.end());
                    uniquetriplets.insert(triplet);
                }

                s.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(uniquetriplets.begin(),
                                uniquetriplets.end());
        return ans;
    }
};
method 2 :- #include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    uniqueTriplets.insert(triplet);
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
    }
};
method 3:- 
	