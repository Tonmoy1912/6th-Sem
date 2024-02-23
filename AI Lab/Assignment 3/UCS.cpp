#include<bits/stdc++.h>
using namespace std;

int main(){
    // cout<<"Enter the number of nodes"<<endl;
    int n;
    cin>>n;
    // cout<<"Enter the number of edges"<<endl;
    int e;
    cin>>e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++){
        // cout<<"Enter the edge no "<<i+1<<":"<<endl;
        int x,y,cost;
        cin>>x>>y>>cost;
        adj[x].push_back({y,cost});
        adj[y].push_back({x,cost});
    }
    return;
}