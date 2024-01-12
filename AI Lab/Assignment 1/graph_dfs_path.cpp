#include<bits/stdc++.h>
using namespace std;

class Solution{
    void helper_dfs(vector<vector<int>> &adj,int node,int parent,vector<int> &vis,vector<int> &ans){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(it!=parent){
                if(!vis[it]){
                    helper_dfs(adj,it,node,vis,ans);
                }
            }
        }
    }
    public:
    //Assuming 0 is default root of the graph
    vector<int> dfs(int n,vector<pair<int,int>> &edges){
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
        return ans;
    }

    void helper_dfs_path(vector<vector<int>> &adj,int node,int prev,vector<int> &vis,vector<int> &parent){
        vis[node]=1;
        for(auto it:adj[node]){
            if(it!=prev){
                if(!vis[it]){
                    parent[it]=node;
                    helper_dfs_path(adj,it,node,vis,parent);
                }
            }
        }
    }

    vector<int> dfs_path(int n,vector<pair<int,int>> &edges,int source,int destination){
        //creating adjacency list
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<int> vis(n);
        vector<int> ans;
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        helper_dfs_path(adj,source,-1,vis,parent);
        int cur=destination;
        while(parent[cur]!=cur){
            ans.push_back(cur);
            cur=parent[cur];
        }
        ans.push_back(cur);
        reverse(ans.begin(),ans.end());
        return ans;
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
    vector<int> dfs=s.dfs(n,edges);
    cout<<"Nodes visited in dfs traversal"<<endl;
    for(auto it:dfs){
        cout<<it<<" ";
    }
    cout<<endl;
    int source,destination;
    // cout<<"Enter the source"<<endl;
    cin>>source;
    // cout<<"Enter the destination"<<endl;
    cin>>destination;
    vector<int> path=s.dfs_path(n,edges,source,destination);
    cout<<"Search path in dfs"<<endl;
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}