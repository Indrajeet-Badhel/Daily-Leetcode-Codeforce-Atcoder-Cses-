class solution{
    public:
     vector<int> abc(vector<int>& nums){
        vector<int>sortednums(nums);
        map<int,int> numtorank;
        sort(sortednums.begin(),sortednums.end());
        int rank=1;
        numtorank[sortednums[0]]=rank;
        for(int i=1;i<sortednums.size();i++){
            if(sortednums[i]!=sortednums[i-1]){
                rank++;
            }
            numtorank[sortednums[i]]=rank;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(numtorank[nums[i]]);
        }
        return ans;

     }
}
/*using set*/
class solution{
    public:
     vector<int> abc(vector<int>& nums){
        set<int>sortednums(nums.begin(),nums.end());
        map<int,int> numtorank;
        int rank=1;
        for(auto& num:sortednums){
            numtorank[num]=rank;
            rank++;
        }
       for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
        return arr;

     }
}