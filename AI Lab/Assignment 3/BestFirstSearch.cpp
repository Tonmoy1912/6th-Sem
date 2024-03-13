#include<bits/stdc++.h>
using namespace std;

class Astar{
    vector<int> order_of_node;
    vector<int> parent;
    // vector<vector<pair<int,int>>> adj;
    unordered_map<int,unordered_map<int,int>> &adj;
    vector<int> dis;
    vector<int> vis;
    int src,des;
    int n;

    int g(int next,int cur){
        return adj[cur][next]+dis[cur];
    }

    int h(int next){
        if(next==des){
            return 0;
        }
        return 1;
    }

    int fn(int cur,int next){
        return g(next,cur)+h(next);
    }
    public:

    Astar(unordered_map<int,unordered_map<int,int>> &adj,int n,int src,int des):adj(adj){
        this->n=n;
        this->src=src;
        this->des=des;
    }

    void a_star(){
        parent.resize(n,-1);
        dis.resize(n,10000000);
        vis.resize(n);
        dis[src]=0;
        // vis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({h(src),src});
        while(!pq.empty()){
            int node=pq.top().second;
            vis[node]=1;
            order_of_node.push_back(node);
            pq.pop();
            if(h(node)==0){
                break;
            }
            for(auto it:adj[node]){
                int next=it.first;
                //assuming all step cost is 1 hence the heuristic is consistent. hence graph search strategy will work
                if(!vis[next]){
                    int fval=fn(node,next);
                    pq.push({fval,next});
                    parent[next]=node;
                }
            }
        }
        if(parent[des]!=-1){
            cout<<"path found:"<<endl;
            vector<int> path;
            int cur=des;
            while(cur!=-1){
                path.push_back(cur);
                cur=parent[cur];
            }
            reverse(path.begin(),path.end());
            cout<<"path: "<<endl;
            for(auto it:path){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"No path found"<<endl;
        }
        cout<<"Order of node visited: "<<endl;
        for(auto it:order_of_node){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int main(){
    unordered_map<int,unordered_map<int,int>> adj;
    int n,e;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x][y]=wt;
        adj[y][x]=wt;
    }
    int src,des;
    cout<<"Enter the src"<<endl;
    cin>>src;
    cout<<"Enter the des"<<endl;
    cin>>des;
    Astar S(adj,n,src,des);
    S.a_star();
}