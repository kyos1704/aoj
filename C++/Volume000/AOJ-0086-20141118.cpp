#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;

int input(){
  edge.clear();
  edge.resize(110);
  while(1){
    int a,b;
    if(!(cin>>a>>b))return false;
    if(a==0)break;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  return true;
}

bool solve(){
  for(int i=2;i<edge.size();i++){
    if(edge[i].size()%2!=0){
      return false;
    }
  }
  if(edge[0].size()%2!=1)return false;
  if(edge[1].size()%2!=1)return false;
  return true;
}

int main(){
  while(input()){
    if(solve()){
      cout<<"OK"<<endl;
    }else cout<<"NG"<<endl;
  }
}
