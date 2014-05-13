#include<bits/stdc++.h>
using namespace std;
/////////////////
// 2D geometry //
/////////////////

// 2D geometry basic //
const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
#define X real
#define Y imag
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
typedef vector<P> G;
struct C {
  P p; double r;
  C(const P &p, double r) : p(p), r(r) { }
};
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

// UVA 453 (Intersecting Circles)
pair<P, P> circle_circle_intersect(const P& c1, const double& r1, const P& c2, const double& r2) {
  P A = conj(c2-c1), B = (r2*r2-r1*r1-(c2-c1)*conj(c2-c1)), C = r1*r1*(c2-c1);
  P D = B*B-4.0*A*C;
  P z1 = (-B+sqrt(D))/(2.0*A)+c1, z2 = (-B-sqrt(D))/(2.0*A)+c1;
  return pair<P, P>(z1, z2);
}

//////////
// data //
//////////

struct E{
  int n1,n2;
  double l;
};
bool operator<(E a,E b){
  return a.l>b.l;
}
vector<C> in;
vector<vector<P>> node;
vector<vector<vector<E>>> edge;

void init(){
  in.clear();
  node.clear();
  edge.clear();
}

bool input(){
  int n;
  cin>>n;
  if(n==0)return false;
  for(int i=0;i<n;i++){
    double x,y,r;
    cin>>x>>y>>r;
    in.push_back(C(P(x,y),r));
  }
  return true;
}

double dist(int a,int b,int n,int m){
  const P tmp = node[a][b]-node[n][m];
  return sqrt(tmp.X()*tmp.X() + tmp.Y()*tmp.Y());
}
bool valid(int a,int b,int n,int m){
  P vec = node[n][m] - node[a][b];
  for(int i=a+1;i<n;i++){
    int tmpa = ccw(node[a][b],node[n][m],node[i][0]);
    int tmpb = ccw(node[a][b],node[n][m],node[i][1]);
    if(!(abs(tmpa)==1 && tmpa==(-1*tmpb))){
      return false;
    }
  }
  return true;
}
void set_edge(int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<node[i].size();j++){
      if(valid(i,j,n,m)){
        edge[i][j].push_back(E{n,m,dist(i,j,n,m)}); 
      }
    }
  }
}

void make_g(){
  //make_node;
  node.resize(in.size()+1);
  node[0].push_back(in[0].p);
  for(int i=1;i<in.size();i++){
    auto tmp = circle_circle_intersect(in[i-1].p,in[i-1].r,in[i].p,in[i].r);
    node[i].push_back(tmp.first);
    node[i].push_back(tmp.second);
  }
  node[in.size()].push_back(in[in.size()-1].p);
  //meke_edge
  edge.resize(node.size());
  for(int i=0;i<node.size();i++){
    edge[i].resize(node[i].size());
    for(int j=0;j<node[i].size();j++){
      set_edge(i,j);
    }
  }

  for(int i=0;i<edge.size();i++){
    for(int j=0;j<edge[i].size();j++){
      //cerr<<"node:"<<i<<","<<j<<endl;
      for(int k=0;k<edge[i][j].size();k++){
        //cerr<<"  "<<edge[i][j][k].n1<<","<<edge[i][j][k].n2<<" "<<edge[i][j][k].l<<endl;
      }
    }
  }
}

double solve_dist(){
  priority_queue<E> q;
  q.push(E{0,0,0});
  vector<vector<double>> dp(node.size());
  for(int i=0;i<dp.size();i++){
    dp[i] = vector<double>(node[i].size(),-1);
  }
  while(!q.empty()){
    E now = q.top();q.pop();
    if(dp[now.n1][now.n2]!=-1)continue;
    dp[now.n1][now.n2] = now.l;
    const auto e = edge[now.n1][now.n2];
    for(int i=0;i<e.size();i++){
      q.push(E{e[i].n1,e[i].n2,now.l+e[i].l});
    }
  }
  for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[i].size();j++){
      //cerr<<"("<<i<<","<<j<<")::"<<dp[i][j]<<endl;
    }
  }
  return dp[node.size()-1][node[node.size()-1].size()-1];
}


long double solve(){
  make_g();
  return solve_dist();
}

int main(){
  while(init(),input()){
    cout<<fixed<<setprecision(10)<<solve()<<endl;
  }
}
