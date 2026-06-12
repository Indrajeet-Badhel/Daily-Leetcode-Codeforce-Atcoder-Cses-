/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/

/*brute force code*/
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int num : nums1)
            res.push_back(num);

        for (int num : nums2)
            res.push_back(num);

        sort(res.begin(), res.end());

        int n = res.size();

        if (n % 2 == 1) {
            return res[n / 2];
        } else {
            return (res[n / 2 - 1] + res[n / 2]) / 2.0;
        }
    }
};*/
class Solution {
public:  
 double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
if(a.size()>b.size())return findMedianSortedArrays(b,a);
int n=a.size(),m=b.size();
int left =(n+m+1)/2;
int low=0, high=n;
while(low<=high){
    int mid1=(low+high)/2;
    int mid2=left-mid1;
    int l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;
    if(mid1<n)r1=a[mid1];
    if(mid2<m)r2=b[mid2];
    if(mid1>0)l1=a[mid1-1];
    if(mid2>0)l2=b[mid2-1];
    if(l1<=r2 && l2<=r1){
        if((n+m)%2==0)return (max(l1,l2)+min(r1,r2))/2.0;
        else return max(l1,l2);
    }
    else if(l1>r2)high=mid1-1;
    else low=mid1+1;
}
}};