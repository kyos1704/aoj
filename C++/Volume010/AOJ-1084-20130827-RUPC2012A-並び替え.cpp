#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

int n,k;
vector<int> c;

void init(){
  c.clear();
}

bool input(){
  cin>>n>>k;
  if(n==0&&k==0)return false;
  for(int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    c.push_back(tmp);
  }
  return true;
}

int cal(vector<int> cc){
  int res = 0;
  int tmp = 1;
  for(int i=0;i<cc.size();i++){
    if(i<k){
      tmp *= cc[i];
    }else{
      tmp /= cc[i-k];
      tmp *= cc[i];
    }
    res = max(res,tmp);
  }
  return res;
}

int solve(){
  int cc = cal(c);
  
  vector<int> tmp = c;
  int ccc=0;
  for(int i=0;i<tmp.size();i++){
    for(int j=0;j<tmp.size();j++){
      swap(tmp[i],tmp[j]);
      ccc = max(ccc,cal(tmp));
      tmp = c;
    }
  } 
  return ccc - cc;
}

int main(){
  while(init(),input()){
    int ans = solve();
    if(ans<0){
      cout<<"NO GAME"<<endl;
    }else{
      cout<< ans <<endl;
    }
  }
  return 0;
}
