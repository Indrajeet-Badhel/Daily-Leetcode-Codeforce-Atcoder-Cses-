my version /*class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<int>gcdPairs;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            gcdPairs.push_back(__gcd(nums[i], nums[j]));
        }
    }
    sort(gcdPairs.begin(),gcdPairs.end());
    vector<int>ans;
    for(auto &query : queries){
        ans.push_back(gcdPairs[query]);
    }
    return ans;

    }
};*/
/*class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1, 0);
        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];
            exact[g] = cnt * (cnt - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exact[g] -= exact[multiple];
        }

        // Prefix sums
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {

            // Find first prefix > q
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};*/