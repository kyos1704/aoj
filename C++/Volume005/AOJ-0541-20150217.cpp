#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<int>> f;

bool input(){
  int x,y;
  cin>>x>>y;
  cin>>n;
  f.clear();
  if(x==y&&y==n&&n==0)return false;
  f.resize(x);
  for(int i=0;i<f.size();i++){
    f[i].resize(y);
  }
  for(int i=0;i<f.size();i++){
    for(int j=0;j<f[i].size();j++){
      cin>>f[i][j];
    }
  }
  return true;
}

bool inside(vector<vector<int>> &c,int x,int y){
  if(x<0)return false;
  if(y<0)return false;
  if(c.size()<=x)return false;
  if(c[x].size()<=y)return false;
  return true;
}

pair<int,int> solve(){
  vector<vector<int>> change;
  change.resize(f.size());
  for(int i=0;i<change.size();i++){
    change[i].resize(f[i].size());
  }
  change[0][0] = n-1;
  for(int i=0;i<change.size();i++){
    for(int j=0;j<change[i].size();j++){
      if(change[i][j] <= 0)continue;
      if(inside(change,i+1,j))change[i+1][j] += change[i][j]/2;
      if(inside(change,i,j+1))change[i][j+1] += change[i][j]/2;
      if(change[i][j]%2){
        if(f[i][j]==0){
          if(inside(change,i+1,j))change[i+1][j]++;
        }else{
          if(inside(change,i,j+1))change[i][j+1]++;
        }
      }
    }
  }
  /*
  for(auto i:f){
    for(auto j:i){
      cout<<j<<" ";
    }cout<<endl;
  }cout<<endl;
  for(auto i:change){
    for(auto j:i){
      cout<<j<<" ";
    }cout<<endl;
  }cout<<endl;
  */
  for(int i=0;i<change.size();i++){
    for(int j=0;j<change[i].size();j++){
      if(change[i][j]%2==1){
        f[i][j] = !f[i][j];
      }
    }
  }
  /*
  for(auto i:f){
    for(auto j:i){
      cout<<j<<" ";
    }cout<<endl;
  }cout<<endl;
  */
  pair<int,int> res(0,0);
  while(res.first<change.size()&&res.second<change[0].size()){
    if(f[res.first][res.second]==0){
      res.first++;
    }else{
      res.second++;
    }
  }
  res.first++;
  res.second++;
  return res;
}


int main(){
  while(input()){
    auto ans = solve();
    cout<<ans.first<<" "<<ans.second<<endl;
  }
}
