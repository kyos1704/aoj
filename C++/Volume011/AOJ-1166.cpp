#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<sstream>
using namespace std;
#define DEBUG 0
int w,h;
bool start(){
  string s;
  getline(cin,s);
  stringstream ss(s);
  ss>>w>>h;
  return w!=0&&h!=0;
}
typedef pair<int,int> pii;
#define X first
#define Y second
vector<string> f;
struct S{
  int c;
  pii p;
};
bool operator<(S a,S b){
  return a.c>b.c;
}
const int vx[]= {0,0,1,-1};
const int vy[]= {1,-1,0,0};
const bool check(int x,int y){
  return (0<=x)&&(x<f.size())&&(0<=y)&&(y<f[x].size());
}
int find(pii start,pii end){
  priority_queue<S> q;
  q.push(S{1,start});
  vector<vector<int>> dp(f.size(),vector<int>(f[0].size(),-1));
  while(!q.empty()){
    S now = q.top();q.pop();
    if(dp[now.p.X][now.p.Y]!=-1)continue;
    dp[now.p.X][now.p.Y]=now.c;
    for(int i=0;i<4;i++){
      const int x = now.p.X+vx[i];
      const int y = now.p.Y+vy[i];
      if(check(x,y)&&f[x][y]!='1'){
        q.push(S{now.c+(f[x][y]=='*'),pii(x,y)});
      }
    }
  }
  if(DEBUG){for(auto i:dp){for(auto j:i)cerr<<setw(4)<<(j)<<" ";cerr<<endl;}cerr<<endl;}
  return dp[end.X][end.Y];
}



int solve(){
  f.clear();f.resize(2*h-1);
  for(int i=0;i<f.size();i++){
    getline(cin,f[i]);
    if(i%2==0)f[i]=f[i]+=' ';
  }
  for(int i=0;i<f.size();i+=2){
    for(int j=0;j<f[i].size();j+=2){
      f[i][j]='*';
    }
  }
  for(int i=0;i<f.size();i++){
    for(int j=0;j<f[i].size();j++){
      if(f[i][j]==' '){
        f[i][j]='1';
      }
    }
  }
  if(DEBUG){for(auto i:f)cerr<<i<<endl;cerr<<endl;}
  return find(pii(0,0),pii(f.size()-1,f[f.size()-1].size()-1));
}

int main(){
  while(start()){
    cout<<max(0,solve())<<endl;
  }
}
