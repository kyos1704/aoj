#include<complex>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long double ld;
typedef complex<ld> P;
#define X real
#define Y imag
vector<P> data;

namespace std{
  bool operator<(P a,P b){
    return a.X()!=b.X()? a.X()<b.X():a.Y()<b.Y(); 
  }
}

double cross(P a,P b){
  return imag(conj(a)*b);
}

double dot(P a,P b){
  return real(conj(a)*b);
}

int ccw(P a,P b,P c){
  b-=a;c-=a;
  if(cross(b,c)>0)return 1;     //counter clockwise
  if(cross(b,c)<0)return -1;    //clockwise
  if(dot(b,c)<0)return 2;       //c--a--b on line
  if(norm(b)<norm(c))return -2; //a--b--c on line
  return 0;
}

vector<P> convex_hull(vector<P> ps){
  sort(ps.begin(),ps.end());
  vector<P> ch(ps.size()*2);
  int k=0;
  for(int i=0;i<ps.size();ch[k++]=ps[i++]){
    while(k>=2 && ccw(ch[k-2],ch[k-1],ps[i])<=0)--k;
  }
  for(int i=ps.size()-2,t=k+1;i>=0;ch[k++]=ps[i--]){
    while(k>=t&&ccw(ch[k-2],ch[k-1],ps[i])<=0)--k;
  }
  ch.resize(k-1);
  return ch;
}

int solve(){
  vector<P> res = convex_hull(data);
  return res.size();
}


int main(){
  int n;
  while(cin>>n){
    if(n==0)break;
    data.clear();
    for(int i=0;i<n;i++){
      ld a,b;
      char c;
      cin>>a>>c>>b;
      data.push_back(P(a,b));
    }
    cout<<n-solve()<<endl;
  }
}
