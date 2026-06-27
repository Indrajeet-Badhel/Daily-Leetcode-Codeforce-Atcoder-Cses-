class Solution {
public: 
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto &p : mp){
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};