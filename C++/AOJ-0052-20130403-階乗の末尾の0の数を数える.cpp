#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int ans=0;
  int n;
  while(cin>>n,n!=0){
    ans=0;
    while(n!=0){
      n/=5;
      ans+=n;
    }
    cout<<ans<<endl;
  }
}
