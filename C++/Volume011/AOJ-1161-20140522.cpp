#include<bits/stdc++.h>
using namespace std;
vector<string> in;
void init(){
  in.clear();
}
int input(){
  init();
  int n;
  cin>>n;
  if(n==0)return false;
  in.resize(n);
  for(int i=0;i<n;i++){
    cin>>in[i];
  }
  return true;
}
int istop[30];
void top(){
  for(int i=0;i<30;i++){
    istop[i]=0;
  }
  for(int i=0;i<in.size();i++){
    if(in[i].size()!=1){
      istop[in[i][0]-'A']=true;
    };
  }
}
bool isTop(char c){
  return istop[c-'A'];
}

vector<pair<int,char>> num;
void convert(){
  map<char,int> dp;
  dp.clear();
  for(int i=0;i<in.size();i++){
    int c = 1;
    if(i==in.size()-1)c*=-1;
    for(int j=0;j<in[i].size();j++){
      dp[in[i][in[i].size()-j-1]] += c;
      c*=10;
    }
  }
  num.clear();
  for(auto i:dp){
    num.push_back(make_pair(i.second,i.first));
  }
  sort(num.begin(),num.end());
}

vector<int> used;
int tmp;
int req(int n){
  if(n==num.size()){
    return tmp == 0;
  }
  if(n==0) tmp = 0;
  if(tmp>0)return 0;
  int res = 0;
  for(int i=0;i<10;i++){
    if(isTop(num[n].second)&&i==0)continue;
    if(!used[i]){
      tmp += num[n].first * i;
      used[i]=true;
      int tt= req(n+1);
      res += tt;
      used[i]=false;
      tmp -= num[n].first * i;
    }
  }
  return res;
}

int solve(){
  top();
  convert();
  used.resize(10);
  for(int i=0;i<10;i++){
    used[i]=0;
  }
  return req(0);
}

int main(){
  while(input()){
    cout<<solve()<<endl;
  }
}
