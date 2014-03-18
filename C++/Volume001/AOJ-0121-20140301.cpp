#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

map<vector<int>,int> dp;

vector<vector<int>> next(vector<int> pre){
  vector<vector<int>> res;
  int zero = pre[0];
  if(zero!=1&&zero!=5){
    vector<int> tmp = pre;
    swap(tmp[zero],tmp[zero-1]);
    tmp[0]=zero-1;
    res.push_back(tmp);
  }
  if(zero!=4&&zero!=8){
    vector<int> tmp = pre;
    swap(tmp[zero],tmp[zero+1]);
    tmp[0]=zero+1;
    res.push_back(tmp);
  }
  if(zero>4){
    vector<int> tmp = pre;
    swap(tmp[zero-4],tmp[zero]);
    tmp[0]=zero-4;
    res.push_back(tmp);
  }else{
    vector<int> tmp = pre;
    swap(tmp[zero],tmp[zero+4]);
    tmp[0]=zero+4;
    res.push_back(tmp);
  }
  return res;
}

void init(){
  vector<int> s = {1,0,1,2,3,4,5,6,7};
  queue<vector<int>> q;
  dp.clear();
  dp[s] = 0;
  q.push(s);
  while(!q.empty()){
    vector<int> tmp = q.front();q.pop();
    vector<vector<int>> n = next(tmp);
    for(int i=0;i<n.size();i++){
      if(dp.count(n[i])==0){
        dp[n[i]]=dp[tmp]+1;
        q.push(n[i]);
      }
    }
  }
}

int main(){
  init();
  vector<int> in(9);
  while(cin>>in[1]>>in[2]>>in[3]>>in[4]>>in[5]>>in[6]>>in[7]>>in[8] ){
    for(int i=1;i<in.size();i++){
      if(in[i]==0){
        in[0]=i;
      }
    }
    cout<<dp[in]<<endl;
    in.clear();
    in.resize(9);
  }
}
