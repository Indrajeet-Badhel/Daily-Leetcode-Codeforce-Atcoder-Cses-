/*class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        unordered_map<long long, vector<pair<int,int>>> mp;

        set<vector<int>> ans;

        // Store all pair sums
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                long long currSum = (long long)nums[i] + nums[j];

                long long need = (long long)target - currSum;

                if(mp.count(need)) {

                    for(auto &p : mp[need]) {

                        int a = p.first;
                        int b = p.second;

                        // Make sure indices are distinct
                        if(a != i && a != j &&
                           b != i && b != j) {

                            vector<int> quad = {
                                nums[a],
                                nums[b],
                                nums[i],
                                nums[j]
                            };

                            sort(quad.begin(), quad.end());

                            ans.insert(quad);
                        }
                    }
                }

                mp[currSum].push_back({i,j});
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};*/2
/*above will fail at duplicate 22222  $ larger space but time complexity is o(n^2)*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        int n = nums.size();

        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int left = j+1;
                int right = n-1;

                while(left < right)
                {
                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if(sum == target)
                    {
                        st.insert({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
}; /*twopointer approch time complexity: O(n^3)*/