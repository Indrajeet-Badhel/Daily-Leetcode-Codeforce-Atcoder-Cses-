class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n+1);
        for(auto& r:roads){
            int a =r[0];
            int b=r[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n+1,false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        while(!q.empty()){
            int city =q.front();
            q.pop();
            for(auto& neigh:graph[city]){
                if(!visited[neigh]){
                    visited[neigh]=true;
                    q.push(neigh);
                }
            }

        }
        int minScore=INT_MAX;
        for(auto& r: roads){
            int a=r[0],b=r[1],dist=r[2];
            if(visited[a]&&visited[b]){
                minScore=min(minScore,dist);
            }
        }return minScore;


    }
};
/*
class solution {
public:
int minScore(int n,vector<vector<int>>& node){
vector<vector<int,int>> graph(n+1);
for(auto& it:node){
int a=it[0];
int b=it[1];
int c=it[2];
graph[a].push_back(b,c);
graph[b].push_back(a,c);}

vector<bool> visited(n+1,false);
queue<int> q;
q.push(1);
visited[1]=true;
while(!q.empty()){
int city=q.front();
q.pop();
int ans=INT_MAX;
for(auto& neigh:graph[city]){
 int v= neigh.first;
 int dis=neigh.second;
  ans=min(ans,dis);
   if(!vis[v]){
    vis[v] = 1;
    q.push(v);
    }
}}*/