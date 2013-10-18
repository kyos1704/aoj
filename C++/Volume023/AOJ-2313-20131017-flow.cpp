#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

#define clear_vec(v,n); v.clear();v.resize(n);

int N,E,Q;
vector<set<int> > edge;
vector<vector<int> > flow;
int f;

void add_flow(int from,int to){
  flow[from][to]++;
  flow[to][from]--;
}

vector<int> used;
int dfs_(int from,int end){
  if(from==end)return 1;
  used[from]=1;
  for(auto i=edge[from].begin();i!=edge[from].end();i++){
    int to = *i;
    if(used[to]==1)continue;
    if(flow[from][to]<1 && dfs_(to,end)==1){
      add_flow(from,to);
      return 1;
    }
  }
  return 0;
}

int dfs(int from,int end){
  clear_vec(used,N+1);
  return dfs_(from,end);
}

void add_edge(int a,int b){
  edge[a].insert(b);
  edge[b].insert(a);
}

void cut_edge(int a,int b){
  int ff = flow[a][b];
  flow[a][b]=flow[b][a]=0;
  edge[a].erase(b);
  edge[b].erase(a);

  if(ff<0){
    swap(a,b);
  }
  if(ff!=0){
    if(!dfs(a,b)){
      dfs(N,b),dfs(a,1);
      f--;
    }
  }
}

int input(){
  f=0;
  cin>>N>>E>>Q;
  clear_vec(edge,N+1);
  clear_vec(flow,N+1);
  for(int i=0;i<N+1;i++){
    clear_vec(flow[i],N+1);
  }
  for(int i=0;i<E;i++){
    int a,b;
    cin>>a>>b;
    add_edge(a,b);
  }
  return 0;
}

int solve(int m,int a,int b){
  switch(m){
    case 1:
      add_edge(a,b);
      if(dfs(1,N))f++;
      break;
    case 2:
      cut_edge(a,b);
      break;
  }
  return f;
}


void some_querys(){
  for(int i=0;i<Q;i++){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<solve(a,b,c)<<endl;
  }
}

int main(){
  input();
  while(dfs(1,N))f++;
  some_querys();
}
