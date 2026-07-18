class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool>seen(nums.size()+1,false);
        for(auto& num :nums){
            if(num>0&&num<=nums.size()){
                seen[num]=true;
            }
        }
        for(int i=1;i<=nums.size();i++){
            if(seen[i]==false){
                return i;
            }
        }
        return nums.size()+1;
    }
};