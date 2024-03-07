

#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int n,vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> visited(n,0);
    vector<int> distance(n,INT_MAX);
    distance[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int dist=pq.top().first;
        visited[node]=1;
        pq.pop();
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int wt=it.second;
            if(distance[adjnode]>wt+distance[node])
            {
                distance[adjnode]=wt+distance[node];
                pq.push({distance[adjnode],adjnode});
            }
        }
    }
    return distance;
}
void dijkstra_path(int src,int dest,int n,vector<vector<pair<int,int>>> &adj,vector<int> &parent)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> visited(n,0);
    vector<int> distance(n,INT_MAX);
    distance[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int dist=pq.top().first;
        visited[node]=1;
        pq.pop();
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int wt=it.second;
            if(distance[adjnode]>wt+distance[node])
            {
                parent[adjnode]=node;
                distance[adjnode]=wt+distance[node];
                pq.push({distance[adjnode],adjnode});
            }
        }
    }
    cout<<"the parent vector is:";
    for(auto it:parent)
    cout<<it<<" ";
    cout<<endl;
    int node=dest;
	if(distance[node]==INT_MAX){
		cout<<"No path exist"<<endl;
		return;
	}
    cout<<"The soln path is:";
    cout<<node<<"->";
    while(parent[node]!=-1)
    {
        if(node==src)
        cout<<parent[node];
        else
        cout<<parent[node]<<"->";
        node=parent[node];
    }
    cout<<endl;
}
int main(){
    int n,x,y;
    // cout<<"Enter the number of elements in the graph:";
    cin>>n;
    int e;
    // cout<<"Enter the number of edges in the graph:";
    cin>>e;
    vector<vector<pair<int,int>>> adj(n);
    int wt;
    for(int i=0;i<e;i++)
    {
        // cout<<"Enter the edge:";
        cin>>x>>y;
        // cout<<"Enter the edge weight=";
        cin>>wt;
        // cout<<"Edge ["<<x<<","<<y<<"]="<<wt<<endl;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }
    vector<int> parent(n,-1);
    // vector<int> distance= dijkstra(n,adj);
    // cout<<"the distance vector is :";
    // for(auto it:distance)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    int src,des;
    // cout<<"/n"<<"enter the source nd the destination node respectively:";
    cin>>src>>des;
    dijkstra_path(src,des,n,adj,parent);
}