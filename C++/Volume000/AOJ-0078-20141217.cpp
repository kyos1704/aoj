#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> anser;
int n;
bool input(){
  cin>>n;
  if(n==0)return false;
  return true;
}

void solve(){
  int c = n/2;
  int h = n/2+1;
  anser.clear();
  anser.resize(n);
  for(int i=0;i<n;i++){
    anser[i].resize(n);
  }
  int count = 1;
  while(1){
    if(anser[h][c]==0){
      anser[h][c] = count;
    }else{
      h=(h+n+1)%n;
      c=(c+n-1)%n;
      anser[h][c] = count;
    }
    count++;
    h=(h+n+1)%n;
    c=(c+n+1)%n;
    if(count == 1+n*n)return ;
  }
}

void output(){
  const auto ans = anser;
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      printf("%4d",ans[i][j]);
    }cout<<endl;
  }
}

int main(){
  while(input()){
    solve();
    output();
  }
}
