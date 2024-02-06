#include<bits/stdc++.h>
using namespace std;

class Solution{
    void print_vector(vector<int> &ans){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    void helper_dfs(vector<vector<int>> &adj,int node,int parent,vector<int> &vis,vector<int> &ans,int &cur_b,int destination,int b){
        if(cur_b>b){
            return ;
        }
        vis[node]=1;
        ans.push_back(node);
        if(node==destination){
            cout<<"Destination found in breadth "<<cur_b<<endl;
            print_vector(ans);
            ans.pop_back();
            cur_b=b+1;
            return ;
        }
        bool leaf=true;
        for(auto it:adj[node]){
            if(it!=parent){
                leaf=false;
                if(!vis[it]){
                    helper_dfs(adj,it,node,vis,ans,cur_b,destination,b);
                }
            }
        }
        if(leaf){
            cout<<"Destination not found in breadth "<<cur_b<<endl;
            cur_b++;
            print_vector(ans);
        }
        ans.pop_back();
    }
    public:
    //Assuming 0 is default root of the graph
    void ibs(int n,vector<pair<int,int>> &edges,int destination,int b){
        //creating adjacency list
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<int> vis(n);
        vector<int> ans;
        //Assuming 0 is default root of the graph
        int cur_b=1;
        helper_dfs(adj,0,-1,vis,ans,cur_b,destination,b);
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
    int destination,b;
    // cout<<"Enter the destination"<<endl;
    cin>>destination;
    // cout<<"Enter the depth"<<endl;
    cin>>b;
    Solution s;
    // vector<int> dfs=s.dfs(n,edges);
    s.ibs(n,edges,destination,b);
    // cout<<"Nodes visited in dfs traversal"<<endl;
    // for(auto it:dfs){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    return 0;
}