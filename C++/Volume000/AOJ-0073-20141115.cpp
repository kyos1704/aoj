#include<bits/stdc++.h>
using namespace std;

double x,y;

bool input(){
  cin>>x>>y;
  return (x!=0)||(y!=0);
}


double solve(){
  double tmp = sqrt((x/2)*(x/2)+y*y);
  return (x*x) + 4* x*tmp/2;
}

int main(){
  while(input()){
    cout<<setprecision(100)<<solve()<<endl;
  }
}
