#include<iostream>
#include<iomanip>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

struct edge{
  edge(){};
  edge(int to,int cost){
    p=to;
    c=cost;
  }
  int p,c;
};
bool operator<(edge a,edge b){
  return a.c>b.c;
}
int s,e,money,pay;
vector<vector<edge> > edges;


void init(){
  edges.clear();
}

bool input(){
  char t;
  int n;
  if(!(cin>>n))return false;
  edges.resize(n);
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int a,b,c,d;
    cin>>a>>t>>b>>t>>c>>t>>d;
    a--;b--;
    edges[a].push_back(edge(b,c));
    edges[b].push_back(edge(a,d));
  }
  cin>>s>>t>>e>>t>>money>>t>>pay;
  s--,e--;
  return true;
}

int path_cost(int start,int end){
  priority_queue<edge> q;
  vector<int> dp(edges.size());
  for(int i=0;i<dp.size();i++){
    dp[i]=-1;
  }
  q.push(edge(start,0));
  while(!q.empty()){
    edge now = q.top();q.pop();
    
    if(dp[now.p]!=-1)continue;
    dp[now.p]=now.c;
    
    if(now.p==end)return now.c;
    
    for(int i=0;i<edges[now.p].size();i++){
      edge to = edges[now.p][i];
      q.push(edge(to.p,now.c+to.c));
    }

  }
  return dp[end];
}


int solve(){
  int tmp=0;
  tmp += path_cost(s,e);
  tmp += path_cost(e,s);
  return money - tmp - pay;
}


int main(){
  while(init(),input()){
    cout<<solve()<<endl;
  }
}


