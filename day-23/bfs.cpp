#include <iostream.h>
using namespace  std; 
class solution{
    public:
    vector <int> bfsgraph(int V,vector <int> adj){
        int visited[n]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            bfs.push(node);

            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return bfs;
    }
}
/*space complexity = o(3N)*/
/*time complextity=o(n)+o(2E)*/