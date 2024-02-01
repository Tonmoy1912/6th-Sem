#include<bits/stdc++.h>
using namespace std;

class Solution{
    void print_vector(vector<int> &ans){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    void helper_dfs(vector<vector<int>> &adj,int node,int parent,vector<int> &vis,vector<int> &ans){
        vis[node]=1;
        ans.push_back(node);
        bool leaf=true;
        for(auto it:adj[node]){
            if(it!=parent){
                leaf=false;
                if(!vis[it]){
                    helper_dfs(adj,it,node,vis,ans);
                }
            }
        }
        if(leaf){
            print_vector(ans);
        }
        ans.pop_back();
    }
    public:
    //Assuming 0 is default root of the graph
    void ibs(int n,vector<pair<int,int>> &edges){
        //creating adjacency list
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<int> vis(n);
        vector<int> ans;
        //Assuming 0 is default root of the graph
        helper_dfs(adj,0,-1,vis,ans);
        // return ans;
    }
};

int main(){
    // cout<<"Enter the number of nodes"<<endl;
    int n;
    cin>>n;
    vector<pair<int,int>> edges;
    // cout<<"Enter the number of edges"<<endl;
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        // cout<<"Enter the edge no "<<i+1<<":"<<endl;
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    Solution s;
    // vector<int> dfs=s.dfs(n,edges);
    s.ibs(n,edges);
    // cout<<"Nodes visited in dfs traversal"<<endl;
    // for(auto it:dfs){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    return 0;
}