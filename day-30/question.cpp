class Solution {
public:
    pair<int,int> dfs(vector<vector<int>>& adj,vector<bool>& visited,int start){
         stack<int> st;
         int nodecount=1;
         int edgecount=0;
        st.push(start);
        visited[start] = true;
        while(!st.empty()){
            int node= st.top();
            edgecount+=adj[node].size();
            st.pop();
            for(auto& ele:adj[node]){
                if(!visited[ele]){
                    visited[ele] = true;
                    st.push(ele);
                    nodecount++;
                }
            }
        }return {edgecount/2,nodecount};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for (auto & it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i =0;i<n;i++){
            if (!visited[i]){
                pair<int,int>temp=dfs(adj,visited,i);
                int edgecount=temp.first;
                int numberofnode=temp.second;
                int expectededgecount=(numberofnode*(numberofnode-1))/2;
                if(edgecount==expectededgecount)ans++;
            }
        }return ans;

    }
};
we used the logci of k(k-1)/2 cos for 1=1 edge for 2=1 ; for 3 = 6 for 4 its 6 thsi is nothing but 1+2+3+...(k-1)  sum for k nodes
so f the expected node edgees issame as the actual node edge than its a complete this has nothing to do wiht cycclic or uncyclic
dont loop for preoperty  look mathaematically ..
