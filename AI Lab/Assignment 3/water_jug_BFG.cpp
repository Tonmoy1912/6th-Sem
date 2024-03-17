#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s;//closed list
int total_count=0;

struct Node
{
    pair<int, int> val;
    int level;
    int cost;
    Node *parent;
};

int getCost(pair<int, int> &a, int target)
{
    return min(abs(a.first - target) + a.second, a.first + abs(a.second - target));
}

Node *createNode(int x, int y, Node *parent, int level)
{
    Node *node = new Node();
    node->val.first = x;
    node->val.second = y;
    node->parent = parent;
    node->level = level;
    node->cost = 10000000;
    return node;
}

void printNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    pair<int, int> &p = node->val;
    cout << p.first << " " << p.second << endl;
}

void printPath(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printPath(node->parent);
    printNode(node);
}

struct com
{
    bool operator()(Node *a, Node *b)
    {
        return (a->cost) > (b->cost);
    }
};

vector<pair<int, int>> expand(int x, int y, pair<int, int> p)
{
    vector<pair<int, int>> arr;
    arr.push_back({p.first, 0});
    arr.push_back({0, p.second});
    //l to r
    arr.push_back({(min(x, p.first + p.second)), (max(p.first + p.second - x, 0))});
    //r to l
    arr.push_back({(max(p.second+p.first-y,0)),(min(p.second+p.first,y))});
    arr.push_back({p.first,y});
    arr.push_back({x,p.second});
    return arr;
}

void solve(int x, int y, int target)
{
    Node *root = createNode(0, 0, NULL, 0);
    root->cost = getCost(root->val, target);
    priority_queue<Node *, vector<Node *>, com> pq;
    // graph search
    s.insert(root->val);
    pq.push(root);
    while (!pq.empty())
    {
        total_count++;
        cout<<total_count<<" ";
        if(total_count>10000000){
            return ;
        }
        Node *min = pq.top();
        pq.pop();
        if(min->cost==0){
            cout<<endl<<endl;
            cout<<"solution path:"<<endl;
            printPath(min);
            return ;
        }
        vector<pair<int, int>> arr = expand(x, y, min->val);
        for(auto &it:arr){
            if(!s.count(it)){
                Node *child=createNode(it.first,it.second,min,min->level+1);
                child->cost=getCost(child->val,target);
                pq.push(child);
                s.insert(child->val);
            }
        }
    }
}

int main()
{
    int x,y,target;
    x=5,y=3,target=4;
    solve(x,y,target);
    return 0;
}