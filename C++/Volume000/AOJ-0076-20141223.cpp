#include<bits/stdc++.h>

using namespace std;

typedef complex<double> P;
#define X real()
#define Y imag()

P solve(int n){
  P res(0,1);
  for(int i=1;i<n;i++){
    P v = res ;
    v *= exp( P(0.0,3 * 90.0 * M_PI / 180.0) );
    v /= abs(v);
    res += v;
  }
  return res;
}
int main(){
  int n;
  while(cin>>n,n!=-1){
    auto ans = solve(n);
    cout<<ans.Y<<endl<<ans.X<<endl;
  }
}
