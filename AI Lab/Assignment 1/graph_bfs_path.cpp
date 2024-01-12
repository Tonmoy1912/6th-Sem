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

    vector<int> bfs(int n,vector<pair<int,int>> &edges){
        //creating adjacency list
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<int> vis(n);
        vector<int> ans;
        vis[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }

    vector<int> bfs_path(int n,vector<pair<int,int>> &edges,int source,int destination){
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
        vis[source]=1;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            if(node==destination){
                break;
            }
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                    parent[it]=node;
                }
            }
        }
        // int cur=destination;
        // while(parent[cur]!=cur){
        //     ans.push_back(cur);
        //     cur=parent[cur];
        // }
        // ans.push_back(cur);
        // reverse(ans.begin(),ans.end());
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
    int source,destination;
    cin>>source;
    cin>>destination;
    vector<int> path=s.bfs_path(n,edges,source,destination);
    cout<<"Search path in bfs"<<endl;
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}