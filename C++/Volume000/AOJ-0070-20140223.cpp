#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int n,s;
vector<vector<vector<int>>> dp;
int DP(int nn,int ss,int k){
  //cout<<nn<<" "<<ss<<" "<<k<<endl;
  if(nn==0)return ss==0;
  if(ss<0 || s<ss || n>10 )return 0;
  if(dp[nn][ss][k]!=-1)return dp[nn][ss][k];
  dp[nn][ss][k]++;
  for(int i=0;i<10;i++){
    if(!(k&(1<<i)))dp[nn][ss][k]+=DP(nn-1,ss-nn*i,k+(1<<i));
  }
  return dp[nn][ss][k];
}
 
int solve(){
  return DP(n,s,0);
}
 
int main(){
  dp.resize(11);
  for(int i=0;i<dp.size();i++){
    dp[i].resize(1*1+2*2+3*3+4*4+5*5+6*6+7*7+8*8+9*9+100);
    for(int j=0;j<dp[i].size();j++){
      dp[i][j].resize(1<<10);
      for(int k=0;k<dp[i][j].size();k++){
        dp[i][j][k]=-1;
      }
    }
  }
  while(cin>>n>>s){
    if(s<dp[0].size()){
      cout<<solve()<<endl;
    }else{
      cout<<0<<endl;
    }
  }
}
