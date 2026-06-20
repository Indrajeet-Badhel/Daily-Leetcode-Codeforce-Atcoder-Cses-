class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude(gain.size()+1,0);
        for(int i=0;i<gain.size();i++){
            int a=gain[i];
            int b=altitude[i];
            altitude[i+1]=b+a;
        }
        int ans = altitude[0];
        for(int x : altitude)
        ans = max(ans, x);
        return ans;

    }
};