#include<bits/stdc++.h>
using namespace std;

vector<string> getToken(string &input){
    set<char> s={'=',',',';','>','<','(',')','*'};

    vector<string> arr;
    string temp;
    int n=input.size();
    bool string_flag=false;
    for(int i=0;i<n;i++){
        if(input[i]==' ' || input[i]=='\n'){
            if(string_flag){
                temp.push_back(input[i]);
            }
            else{
                if(!temp.empty()){
                    arr.push_back(temp);
                }
                temp.clear();
            }
        }
        else if(input[i]==',' || input[i]==';' || s.count(input[i])){
            if(string_flag){
                temp.push_back(input[i]);
            }
            else{
                if(!temp.empty()){
                    arr.push_back(temp);
                }
                temp.clear();
                temp.push_back(input[i]);
                arr.push_back(temp);
                temp.clear();
            }
        }
        else if(input[i]=='\''){
            if(string_flag){
                string_flag=false;
                arr.push_back("$_string_const");
                temp.clear();
            }
            else{
                string_flag=true;
                if(!temp.empty()){
                    arr.push_back(temp);
                }
                temp.clear();
            }
        }
        else{
            temp.push_back(input[i]);
        }
    }
    return arr;
}

int main(){
    string input;
    cout<<"Enter the SQL Statement"<<endl;
    getline(cin,input,';');
    input.push_back(' ');
    input.push_back(';');
    // cout<<input<<endl;

    vector<string> arr=getToken(input);

    for(auto it:arr){
        cout<<it<<"--";
    }
    cout<<endl;
    return 0;
}