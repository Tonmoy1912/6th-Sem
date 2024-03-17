#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> visiting_order;
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<int> test;
        test.push(0);
        set<int> check;
        while(test.size()){
            int front=test.front();
            visiting_order.push_back(front);
            test.pop();
            if(front==target){
                cout<<"Visiting order of nodes"<<endl;
                for(auto it: visiting_order){
                    cout<<it<<" ";
                }
                cout<<endl;
                return true;
            }
            int val=front+x;
            if(val>=0 && val<=x+y && check.find(val)==check.end()){
                check.insert(val);
                test.push(val);
            }
            val=front-x;
            if(val>=0 && val<=x+y && check.find(val)==check.end()){
                check.insert(val);
                test.push(val);
            }
            val=front+y;
            if(val>=0 && val<=x+y && check.find(val)==check.end()){
                check.insert(val);
                test.push(val);
            }
            val=front-y;
            if(val>=0 && val<=x+y && check.find(val)==check.end()){
                check.insert(val);
                test.push(val);
            }
        }
        cout<<"No solution found"<<endl;
        return false;
    }
};

int main(){
    Solution s;
    s.canMeasureWater(5,3,4);
    return 0;
}