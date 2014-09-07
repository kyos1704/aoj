#include<bits/stdc++.h>
using namespace std;
vector<pair<string,int>> l;
vector<string> my;

bool input(){
  l.clear();
  my.clear();
  int n,m;
  cin>>n>>m;
  if(n==0)return false;
  for(int i=0;i<n;i++){
    string s;
    int nn;
    cin>>s>>nn;
    l.push_back(make_pair(s,nn));
  }
  for(int i=0;i<m;i++){
    string s;
    cin>>s;
    my.push_back(s);
  }
  return true;
}

int judge2(string a,string b){
  for(int i=0;i<a.size();i++){
    if(b[i] == '*')continue;
    if(a[i] == b[i])continue;
    return false;
  }
  return true;
}

int judge(string s){
  for(auto i:l){
    if(judge2(s,i.first)){
      return i.second;
    }
  }
  return 0;
}

int solve(){
  int ans = 0;
  for(int i=0;i<my.size();i++){
    ans += judge(my[i]);
  }
  return ans;
}

int main(){
  while(input()){
    cout<<solve()<<endl;
  }
}
