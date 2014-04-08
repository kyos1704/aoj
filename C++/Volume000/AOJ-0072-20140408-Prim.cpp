#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;


class union_find{
private:
  vector<int> parents;
  vector<int> rank;
public:
  union_find(int n){
    parents.resize(n);
    rank.resize(n);
    for(int i=0;i<n;i++){
      parents[i]=i;
      rank[i]=0;
    }
  }
  int find(int x){
    if(parents[x]==x){
      return x;
    }else{
      return parents[x]=find(parents[x]);
    }
  }
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
      parents[x]=y;
    }else{
      parents[y]=x;
      if(rank[x]==rank[y])rank[x]++;
    }
  }
  bool same(int x,int y){
    return (find(x)==find(y));
  }
};

struct E{
  int from,to,cost;
};
bool operator<(E a, E b){
  return a.cost>b.cost;
}
int n;
vector<vector<E>> edge;

bool input(){
  cin>>n;
  if(n==0)return false;
  int m;
  cin>>m;
  edge.clear();
  edge.resize(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    char cc;
    cin>>a>>cc>>b>>cc>>c;
    edge[a].push_back(E{a,b,c});
    edge[b].push_back(E{b,a,c});
  }
  return true;
}

int solve(){
  priority_queue<E> que;
  union_find uf(n);
  for(int i=0;i<edge[0].size();i++){
    que.push(edge[0][i]);
  }
  int ans =0;
  while(!que.empty()){
    E now = que.top();que.pop();
    if(uf.same(now.from,now.to))continue;
    uf.unite(now.from,now.to);
    ans += now.cost/100-1;
    for(int i=0;i<edge[now.to].size();i++){
      que.push(edge[now.to][i]);
    }
  }
  return ans;
}


int main(){
  while(input()){
    cout<<solve()<<endl;
  }
}
