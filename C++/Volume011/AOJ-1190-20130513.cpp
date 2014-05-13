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
  double R(double h){
    return sqrt(max(r*r-h*h,0.0));
  }
};
 
// UVA 453 (Intersecting Circles)
pair<P, P> circle_circle_intersect(const P& c1, const double& r1, const P& c2, const double& r2) {
  P A = conj(c2-c1), B = (r2*r2-r1*r1-(c2-c1)*conj(c2-c1)), C = r1*r1*(c2-c1);
  P D = B*B-4.0*A*C;
  P z1 = (-B+sqrt(D))/(2.0*A)+c1, z2 = (-B-sqrt(D))/(2.0*A)+c1;
  return pair<P, P>(z1, z2);
}
 
// solve //
vector<C> in;
void init(){
  in.clear();
}
bool input(){
  int n;
  cin>>n;
  if(n==0)return false;
  for(int i=0;i<n;i++){
    double x,y,r;
    cin>>x>>y>>r;
    in.push_back(C{P{x,y},r});
  }
  return true;
}
bool judge2(P p,double m){
  for(int i=0;i<in.size();i++){
    double dist = abs(in[i].p - p);
    if(dist - EPS > in[i].R(m)){
      return false;
    }
  }
  return true;
}
bool judge(double m){
  //cerr<<"judge::"<<m<<" ";
  for(int i=0;i<in.size();i++){
    if(m>=in[i].r)return false;
  }
  for(int i=0;i<in.size();i++){
    for(int j=0;j<in.size();j++){
      const double dist = abs(in[i].p-in[j].p);
      if(dist>in[i].R(m)+in[j].R(m)){
        return false;
      }
    }
  }
  if(in.size()==1)return true;
  //cerr<<" val ";
  for(int i=0;i<in.size();i++){
    if(judge2(in[i].p,m))return true;
    for(int j=0;j<in.size();j++){
      const double dist = abs(in[i].p-in[j].p);
      if(dist+in[i].R(m)<=in[j].R(m)+EPS)continue;
      if(dist+in[j].R(m)<=in[i].R(m)+EPS)continue;
      pair<P,P> p = circle_circle_intersect(in[i].p,in[i].R(m),in[j].p,in[j].R(m));
      if(judge2(p.first,m))return true;
      if(judge2(p.second,m))return true;
    }
  }
  return false;
}
 
double req(double l,double r){
  double m = (l+r)/2;
  if(abs(l-r)<EPS)return r;
  if(judge(m)){
    //cerr<<"true"<<endl;
    return req(m,r);
  }else{
    //cerr<<"false"<<endl;
    return req(l,m);
  }
}
 
double solve(){
  double ans = req(0.5,301.0);
  return ans;
}
 
 
int main(){
  while(init(),input()){
    cout<<fixed<<setprecision(10)<<solve()<<endl;
  }
}
