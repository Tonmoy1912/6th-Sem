#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,char> m1;
	m1["SELECT"]='s';
	m1["WHERE"]='w';
	m1["AND"]='&';
	m1["OR"]='^';
	m1["NOT"]='!';
	m1["GROUP"]='g';
	m1["ORDER"]='o';
	m1["BY"]='b';
	m1["INSERT"]='i';
	m1["INTO"]='e';
	m1["VALUES"]='v';
	m1["DELETE"]='d';
	m1["FROM"]='f';
	m1["$_string_const"]='c';
	m1["="]='=';
	m1[","]=',';
	m1[";"]=';';
	m1[">"]='>';
	m1["<"]='<';
	m1["("]='(';
	m1[")"]=')';
	m1["*"]='*';
    for(auto it: m1){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}