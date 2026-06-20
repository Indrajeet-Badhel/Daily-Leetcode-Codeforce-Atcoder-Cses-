/*You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

However, there are city restrictions on the heights of the new buildings:

The height of each building must be a non-negative integer.
The height of the first building must be 0.
The height difference between any two adjacent buildings cannot exceed 1.
Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

Return the maximum possible height of the tallest building.

 

Example 1:


Input: n = 5, restrictions = [[2,1],[4,1]]
Output: 2
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
Example 2:


Input: n = 6, restrictions = []
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
Example 3:


Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
 

Constraints:

2 <= n <= 109
0 <= restrictions.length <= min(n - 1, 105)
2 <= idi <= n
idi is unique.
0 <= maxHeighti <= 109*/
/*Brute Force*/
/*class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions){
        vector<int> maxHeights(n+1,n-1);
        maxHeights[1]=0;
        for(auto &restriction:restrictions){
            maxHeights[restriction[0]]=restriction[1];
        }
        for(int i=2;i<=n;i++){
            maxHeights[i]=min(maxHeights[i],maxHeights[i-1]+1);
            
        }
        for(int i=n-1;i>=1;i--){
            maxHeights[i]=min(maxHeights[i],maxHeights[i+1]+1);
        }
        return *max_element(maxHeights.begin(),maxHeights.end());
    }
};*/
/*optimesd no need to travers the whone n buikldings just tranverses he one in the ristriction*/
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions){
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        for(int i=1;i<restrictions.size();i++){
            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+restrictions[i][0]-restrictions[i-1][0]);
        }
        for(int i=restrictions.size()-2;i>=0;i--){
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+restrictions[i+1][0]-restrictions[i][0]);
        }
        int maxHeight=0;
        for(int i=1;i<restrictions.size();i++){
            int left=restrictions[i-1][0];
            int right=restrictions[i][0];
            int leftHeight=restrictions[i-1][1];
            int rightHeight=restrictions[i][1];
            int maxPossibleHeight=(leftHeight+rightHeight+(right-left))/2;
            maxHeight=max(maxHeight,maxPossibleHeight);
        }
        return maxHeight;
    }