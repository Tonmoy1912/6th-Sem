#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    public:
    //Assuming 0 is default root of the graph
    

    // bool dls(int n,vector<pair<int,int>> &edges,int source,int destination,int depth){
    //     //creating adjacency list
    //     vector<vector<int>> adj(n);
    //     for(auto &it:edges){
    //         adj[it.first].push_back(it.second);
    //         adj[it.second].push_back(it.first);
    //     }
    //     vector<int> vis(n);
    //     return dls_helper(adj,source,destination,depth,);
    // }

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

    bool helper_dls_path(vector<vector<int>> &adj,int node,int prev,int destination,vector<int> &vis,vector<int> &parent,int depth){
        vis[node]=1;
        if(depth<0){
            return false;
        }
        if(node==destination){
            return true;
        }
        for(auto it:adj[node]){
            if(it!=prev){
                if(!vis[it]){
                    parent[it]=node;
                    bool t=helper_dls_path(adj,it,node,destination,vis,parent,depth-1);
                    if(t){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    vector<int> dls_path(int n,vector<pair<int,int>> &edges,int source,int destination,int depth){
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
        bool t=helper_dls_path(adj,source,-1,destination,vis,parent,depth);
        if(t){
            int cur=destination;
            while(parent[cur]!=cur){
                ans.push_back(cur);
                cur=parent[cur];
            }
            ans.push_back(cur);
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }

    void ids(int n,vector<pair<int,int>> &edges,int source,int destination,int depth){
        for(int i=0;i<=depth;i++){
            vector<int> path=dls_path(n,edges,source,destination,i);
            if(path.empty()){
                cout<<"Destination not found for depth: "<<i<<endl;
            }
            else{
                cout<<"\nDestination found for depth: "<<i<<endl;
                cout<<"path:"<<endl;
                for(auto it:path){
                    cout<<it<<" ";
                }
                cout<<endl;
                break;
            }
        }
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
    int source,destination,depth;
    cin>>source>>destination>>depth;
    s.ids(n,edges,source,destination,depth);
    // vector<int> path=s.dls_path(n,edges,source,destination,depth);
    // if(path.empty()){
    //     cout<<"Destination not found in the given depth";
    // }
    // else{
    //     cout<<"Destination found"<<endl;
    //     cout<<"DLS path:"<<endl;
    //     for(auto it:path){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}