
class solution{
    public:
    int kadane_val(vector<int>& arr) {
    int current_sum = 0;
    int best = INT_MIN;

    for (int x : arr) {
        current_sum = max(x, current_sum + x); 
        best = max(best, current_sum);         
    }

    return best;
}
/*int kadane_val(vector<int>& arr) {
        int sum = 0;
        int best = INT_MIN;

        for (int x : arr) {
            sum += x;
            best = max(best, best+sum);

            if (sum < 0)
                sum = 0;
        }

        return best;
    }*/
 vector<int>divisor(int n){
    vector<int> temp;
    for(int i=1;i*i<=n;i++){
        temp.push_back(i);
        if(i*i!=n)temp.push_back(n/i);
    }return temp;
 }
int divivsbilegame(vector<int>&nums){
    int bestk=2;
    int maxval=*max_element(nums.begin(),nums.end());
    int bestdiff=INT_MIN;
    for(int k=2;k<=maxval;k++){
        vector<int>temp(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                temp[i]=nums[i];
            }
            else{
                temp[i]=-nums[i];
            }
        }
        int diff=kadane_val(temp);
        if(diff>bestdiff){
            bestdiff=diff;
            bestk=k;
        }
        else if(diff==bestdiff || k<bestk){
            bestk=k;
        }

    }
    long long ans= 1LL*bestk*bestdiff;
    ans %= MOD;
        if (ans < 0)ans += MOD;
        return (int)ans;

}


}

/*class Solution {
public:
    const int MOD = 1000000007;

    int kadane_val(vector<int>& arr) {
        int current_sum = 0;
        int best = INT_MIN;

        for (int x : arr) {
            current_sum = max(x, current_sum + x);
            best = max(best, current_sum);
        }

        return best;
    }

    vector<int> divisor(int n) {
        vector<int> temp;

    if (n <= 1)
        return temp;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                temp.push_back(i);
                if (i != n / i)
                    temp.push_back(n / i);
            }
        }

        temp.push_back(n);

        return temp;
    }

    int divisibleGame(vector<int>& nums) {

        set<int> candidates;
        candidates.insert(2);      // Handles nums = [1]

        for (int x : nums) {
            vector<int> d = divisor(x);
            for (int k : d)
                candidates.insert(k);
        }

        int bestDiff = INT_MIN;
        int bestK = 2;

        for (int k : candidates) {

            vector<int> temp(nums.size());

            for (int i = 0; i < nums.size(); i++) {

                if (nums[i] % k == 0)
                    temp[i] = nums[i];
                else
                    temp[i] = -nums[i];
            }

            int diff = kadane_val(temp);

            if (diff > bestDiff) {
                bestDiff = diff;
                bestK = k;
            }
            else if (diff == bestDiff && k < bestK) {
                bestK = k;
            }
        }

        long long ans = 1LL * bestDiff * bestK;
        ans %= MOD;

        if (ans < 0)
            ans += MOD;

        return (int)ans;
    }
};*/
/**/
