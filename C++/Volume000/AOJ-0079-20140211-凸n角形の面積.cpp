#include<iomanip>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long double ll;
typedef pair<ll,ll> pll;
vector<pll> list;
pll operator-(pll a,pll b){
  return pll(a.first-b.first,a.second-b.second);
}

ll dist(pll a){
  return sqrt(a.first*a.first + a.second*a.second);
}

ll cal(pll a,pll b,pll c){
  ll ab = dist(a-b);
  ll bc = dist(b-c);
  ll ca = dist(c-a);
  ll z = (ab+bc+ca)/2;
  return sqrt(z*(z-ab)*(z-bc)*(z-ca));
}

ll solve(){
  ll ans=0;
  for(int i=2;i<list.size();i++){
    ans+=cal(list[0],list[i-1],list[i]);
  }
  return ans;
}
int main(){
  char c;
  ll x,y;
  while(cin>>x>>c>>y){
    list.push_back(pll(x,y));
  }
  cout<<solve()<<endl;
}
