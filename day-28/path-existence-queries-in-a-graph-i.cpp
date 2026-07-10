#include <iostream>
#include <vector>
#include<queue>
using namespace std;
/*class Solution {
public:
  #include <queue>

int bfs(vector<vector<int>>& adj, int start, int target) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();   
        q.pop();                

        if (node == target) {
            return 1;
        }

        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return 0;
}
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n); 
        vector<bool> ans;
        for(int i=0;i<nums.size();i++){
            int target=nums[i];
            for(int j=i;j<nums.size();j++){
                if(abs(target-nums[j])<=maxDiff){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(auto& it :queries){
            int start =it[0];
            int target=it[1];
            int  result=bfs(adj,start,target);
            if(result){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
    
};*/
/* but this will fail cos of tlE
*/
/*class Solution {
public:
  #include <queue>

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int>visited(n,-1);
        vector<bool> ans;
        for(int i=0;i<nums.size();i++){
            int target=nums[i];
            for(int j=i;j<nums.size();j++){
                if(abs(target-nums[j])<=maxDiff){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                queue<int> q;
                q.push(i);
                visited[i]=i;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<adj[node].size();j++){
                        int next=adj[node][j];
                        if(visited[next]==-1){
                            visited[next]=i;
                            q.push(next);
                        }
                    }
                }
            }
        }
        
        for(auto& it :queries){
            int start =it[0];
            int target=it[1];
            if(visited[start]==visited[target]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
    
};*/
/*this willfail for memory limit */
class Solution {
public:
  #include <queue>

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       vector<bool> ans;
       vector<int> component(n);
       component[0] = 0;
        int id = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                id++;      
            }
            component[i] = id;
        }

        for(auto& it :queries){
            int start =it[0];
            int target=it[1];
            if(component[start]==component[target]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
    
};