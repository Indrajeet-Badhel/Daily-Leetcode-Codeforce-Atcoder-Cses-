class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> digitrange(nums.size());
        for(int i=0;i<nums.size();i++){
            int val=0;
            int smallest=INT_MAX;
            int largest=INT_MIN;
            int temp=nums[i];
            while(temp!=0){
                val=temp%10;
                smallest=min(smallest,val);
                largest=max(largest,val);
                temp=temp/10;
            }
            digitrange[i]=largest-smallest;
        }
        int ans=0;
        int valmax=*max_element(digitrange.begin(),digitrange.end());
        for(int i=0;i<nums.size();i++){
                if(digitrange[i]==valmax){
                    ans+=nums[i];
                }
        }return ans;
    }
};
