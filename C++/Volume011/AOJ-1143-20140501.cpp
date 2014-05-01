#include<bits/stdc++.h>
using namespace std;
typedef complex<int> P;
#define X real()
#define Y imag()
namespace std{
  bool operator<(P a,P b){
    if(a.X!=b.X){
      return a.X<b.X;
    }else{
      return a.Y<b.Y;
    }
  }
};
struct S{
  int c;
  vector<P> l;
};
vector<P> in;
vector<P> block;
P goal;
bool input(){
  in.clear();
  block.clear();
  int n;
  cin>>n;
  if(n==0)return false;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    in.push_back(P(a,b));
  }
  int k=0;
  cin>>k;
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    block.push_back(P(a,b));
  }
  int x,y;
  cin>>x>>y;
  goal = P(x,y);
  return true;
}
 
const vector<P> border = { {-1,0}, {-1,1}, {0,1}, {1,0},{1,-1},{0,-1}};
 
bool block_check(vector<P>& ll,int moved){
  for(int i=0;i<block.size();i++){
    if(ll[moved]==block[i]){
      return false;
    }
  }
  return true;
}
 
bool border_check(vector<P>& ll){
  for(int i=0;i<ll.size();i++){
    for(int j=i+1;j<ll.size();j++){
      if(ll[i]==ll[j])return false;
    }
  }
  for(int k=0;k<ll.size();k++){
    int c =0;
    for(int i=0;i<border.size();i++){
      for(int j=0;j<ll.size();j++){
        if(ll[j]-ll[k]==border[i]){
          c++;
        }
      }
    }
    if(k==0||k==ll.size()-1){
      if(c!=1)return false;
    }else{
      if(c!=2)return false;
    }
  }
  return true;
}
 
vector<vector<P>> moved(vector<P>& ll,int moved){
  if(moved==0){
    int i;
    for(i=0;i<border.size();i++){
      if((ll[moved+1]-ll[moved])==border[i]){
        break;
      }
    }
    vector<P> a=ll,b=ll;
    a[moved]=border[(i+1)%border.size()]+ll[moved];
    b[moved]=border[(i-1+border.size())%border.size()]+ll[moved];
    vector<vector<P>> res;
    if(block_check(a,moved))res.push_back(a);
    if(block_check(b,moved))res.push_back(b);
    return res;
  }else if(moved== ll.size()-1){
    int i;
    for(i=0;i<border.size();i++){
      if((ll[moved-1]-ll[moved])==border[i]){
        break;
      }
    }
    vector<P> a=ll,b=ll;
    a[moved]=border[(i+1)%border.size()]+ll[moved];
    b[moved]=border[(i-1+border.size())%border.size()]+ll[moved];
    vector<vector<P>> res;
    if(block_check(a,moved))res.push_back(a);
    if(block_check(b,moved))res.push_back(b);
    return res;
  }else{
    int x=-1;
    for(int i=0;i<border.size();i++){
      if(border[i]==(ll[moved-1]-ll[moved])||border[i]==(ll[moved+1]-ll[moved])){
        if(border[(i+2)%border.size()]==(ll[moved-1]-ll[moved])||border[(i+2)%border.size()]==(ll[moved+1]-ll[moved])){
          x=i;
          break;
        }
      }
    }
    if(x==-1)return {};
    vector<P> a = ll;
    a[moved] = border[(x+1)%border.size()]+ll[moved];
    vector<vector<P>> res;
    if(block_check(a,moved))res.push_back(a);
    return res;
  }
}
 
vector<vector<P>> genEdge(vector<P> ll,set<vector<P>>& outvisited){
  vector<vector<P>> res;
  set<vector<P>> visited;
  queue<S> q;
  q.push(S{-2,ll});
  visited.insert(ll);
  while(!q.empty()){
    S now = q.front();q.pop();
    for(int i=now.c+2;i<now.l.size();i++){
      const vector<vector<P>> tmp = moved(now.l,i);
      for(auto j:tmp){
        if(visited.count(j)>0){
          continue;
        }
        q.push(S{i,j});
        visited.insert(j);
        if(outvisited.count(j)==0 && border_check(j)){
          res.push_back(j);
        }
      }
    }
  }
  return res;
}
 
int solve(){
  set<vector<P>> visited;
  queue<S> q;
  q.push(S{0,in});
  visited.insert(in);
  while(!q.empty()){
    S now = q.front();q.pop();
    P tmp = now.l[0]-goal;
    if(max(abs(tmp.X),abs(tmp.Y))>20-now.c)continue;
    if(now.l[0] == goal){
      return now.c;
    }
    const vector<vector<P>> edge = genEdge(now.l,visited);
    for(auto i:edge){
      if(visited.count(i)){
        continue;
      }
      visited.insert(i);
      q.push(S{now.c+1,i});
    }
  }
  return -1;
}
 
int main(){
  while(input()){
    cout<<solve()<<endl;
  }
}
