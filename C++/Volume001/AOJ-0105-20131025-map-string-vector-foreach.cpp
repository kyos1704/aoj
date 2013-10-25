#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main(){
  string s;
  int n;
  map<string,vector<int>> list;
  while(cin>>s>>n){
    list[s].push_back(n);
  }
  for(auto &i: list){
    cout<<i.first<<endl;
    auto &list = i.second;
    sort(list.begin(),list.end());
    for(int j=0;j<list.size()-1;j++){
      cout<<list[j]<<" ";
    }cout<<list[list.size()-1]<<endl;
  }
}
