#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> in;

int input(){
  string s;
  if(!(cin>>s))return false;
  in.clear();in.resize(15);
  for(int i=0;i<s.size();i++){
    in[s[i]-'0']++;
  }
  return true;
}

bool dfs(vector<int> &list){
  if(list[0]==4){
    for(int i=0;i<10;i++){
      if(list[i]==2)return true;
    }
    return false;
  }
  for(int i=1;i<10;i++){
    if(list[i]>=3){
      vector<int> tmp = list;
      tmp[i]-=3;
      tmp[0]++;
      if(dfs(tmp))return true;
    }
  }
  for(int i=1;i<10-2;i++){
    if(list[i]>0&&list[i+1]>0&&list[i+2]>0){
      vector<int> tmp = list;
      tmp[i]--;tmp[i+1]--;tmp[i+2]--;
      tmp[0]++;
      if(dfs(tmp))return true;
    }
  }
  return false;
}

bool judge(int n){
  vector<int> list = in;
  list[n]++;
  return dfs(list);
}

vector<int> solve(){
  vector<int> res;
  for(int i=1;i<10;i++){
    if(in[i]==4)continue;
    if(judge(i)){
      res.push_back(i);
    }
  }
  return res;
}

int main(){
  while(input()){
    vector<int> ans;
    ans = solve();
    if(ans.empty()){
      cout<<0<<endl;
    }else{
      for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" ";
      }cout<<ans[ans.size()-1]<<endl;
    }
  }
}
