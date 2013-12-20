#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
struct P{
  P(){};
  P(int a,int b){
    x=a,y=b;
  }
  int x,y;
  void move(int,int);
};
struct S{
  S(){};
  S(P a,P b){
    t=a;
    k=b;
  }
  P t,k;
  void move(int);
};
 
P size;
S f_pos;
vector<vector<int> > f;
bool input(){
  size=P();
  f_pos=S();
  f.clear();
  cin>>size.y>>size.x;
  if(size.x==0&&size.y==0)return false;
  cin>>f_pos.t.y>>f_pos.t.x;
  cin>>f_pos.k.y>>f_pos.k.x;
  vector<int> t;
  for(int i=0;i<size.y+2;i++){
    t.push_back(1);
  }
  f.push_back(t);
  for(int i=0;i<size.x;i++){
    vector<int> tt;
    tt.push_back(1);
    for(int j=0;j<size.y;j++){
      int tmp;
      cin>>tmp;
      tt.push_back(tmp);
    }
    tt.push_back(1);
    f.push_back(tt);
  }
  f.push_back(t);
  return true;
}
int cost[60][60][60][60];
const int vx[]={0,0,1,-1};
const int vy[]={1,-1,0,0};
void S::move(int i){
  t.move(vx[i],vy[i]);
  k.move(-vx[i],-vy[i]);
}
void P::move(int a,int b){
  if(f[x+a][y+b]!=1){
    x+=a;
    y+=b;
  }
}
int solve(){
  memset(cost,-1,sizeof(cost));
  queue<S> q;
  q.push(f_pos);
  cost[f_pos.t.x][f_pos.t.y][f_pos.k.x][f_pos.k.y]=0;
  while(!q.empty()){
    S now = q.front();q.pop();
    for(int i=0;i<4;i++){
      S tmp = now;
      tmp.move(i);
      if(cost[tmp.t.x][tmp.t.y][tmp.k.x][tmp.k.y]!=-1)continue;
 
      cost[tmp.t.x][tmp.t.y][tmp.k.x][tmp.k.y] = cost[now.t.x][now.t.y][now.k.x][now.k.y]+1;
      if(cost[tmp.t.x][tmp.t.y][tmp.k.x][tmp.k.y]>=100){
        return -1;
      }else if( (tmp.t.x==tmp.k.x)&&(tmp.t.y==tmp.k.y) ){
        return cost[tmp.t.x][tmp.t.y][tmp.k.x][tmp.k.y];
      }else{
        q.push(tmp);
      }
    }
  }
  return -1;
}
int main(){
  while(input()){
    /*
    for(int i=0;i<f.size();i++){
      for(int j=0;j<f[i].size();j++){
        cout<<f[i][j];
      }cout<<endl;
    }cout<<endl;
    */
    int ans= solve();
    if(ans==-1||ans>=100){
      cout<<"NA"<<endl;
    }else{
      cout<<ans<<endl;
    }
  }
}
