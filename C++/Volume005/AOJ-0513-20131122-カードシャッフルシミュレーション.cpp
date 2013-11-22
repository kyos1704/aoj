#include<vector>
#include<iostream>
using namespace std;
int n,m;
bool input(){
  if(!(cin>>n>>m)){
    return false;
  }
  return true;
}

vector<int> ans;
void init(){
  ans.clear();
  ans.resize(2*n);
  for(int i=0;i<ans.size();i++){
    ans[i]=i+1;
  }
}
void kk(int k){
  vector<int> t[2];
  for(int i=0;i<k;i++){
    t[1].push_back(ans[i]);
  }
  for(int i=k;i<2*n;i++){
    t[0].push_back(ans[i]);
  }
  for(int i=0;i<t[1].size();i++){
    t[0].push_back(t[1][i]);
  }
  ans=t[0];
}
void r(){
  vector<int> t[2];
  for(int i=0;i<n;i++){
    t[0].push_back(ans[i]);
  }
  for(int i=n;i<2*n;i++){
    t[1].push_back(ans[i]);
  }
  for(int i=0;i<ans.size();i++){
    ans[i]=t[i%2][i/2];
  }
}
void s(int n){
  if(n==0){
    r();
  }else{
    kk(n);
  }
}

int main(){
  input();
  init();
  for(int i=0;i<m;i++){
    int tmp;
    cin>>tmp;
    s(tmp);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
