int val(vector<int>&arr){
    int sum=0;
    int maxval=INT_MIN;
    for(int i=0;i<arr.size();i++){
        sum+=nums[i];
        if(sum>maxval){
            maxval=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxval;
}