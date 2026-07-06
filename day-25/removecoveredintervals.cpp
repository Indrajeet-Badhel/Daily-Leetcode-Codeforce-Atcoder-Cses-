class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
        if (a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    });
    
    int maxelement=-1;
    int count=0;
    for(const auto& it: intervals){
        if(it[1]>maxelement){
            maxelement=it[1];
            count++;
        }
    }
return count;
    }
};