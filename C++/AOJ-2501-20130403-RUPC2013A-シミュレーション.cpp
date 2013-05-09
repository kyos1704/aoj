#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int n;
int a,b,c,d;

int solve(){
  int ans=INT_MAX;
  for(int i=1;i<=n+1000;i++){
    int dx,dy;
    int tmp;
    dy=abs(a/i-b/i);
    dx=abs(a%i-b%i);
    tmp=dy+dx;
    dy=abs(c/i-d/i);
    dx=abs(c%i-d%i);
    tmp+=dy+dx;
    ans=min(tmp,ans);
  }
  return ans;
}


int main(){
  cin>>n>>a>>b>>c>>d;
  a--;b--;c--;d--;
  cout<<solve()<<endl;
}
