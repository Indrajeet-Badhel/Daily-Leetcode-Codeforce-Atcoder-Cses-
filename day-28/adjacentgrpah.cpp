#include <iostream>
#include <vector>
using namespace std;
int main(){
    int V=3;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);
    for(int i=0;
    i<V;i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}