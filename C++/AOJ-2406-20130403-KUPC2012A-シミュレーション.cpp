#include<iostream>
using namespace std;
int t,e;

bool solve(int x){
  for(int i=t-e;i<=t+e;i++){
    if(i%x==0)return 1;
  }
  return 0;
}

int main(){
  int n;
  cin>>n;
  int ans=0;
  cin>>t>>e;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(solve(x)){
      ans=i+1;
    }
  }
  if(ans){
    cout<<ans<<endl;
  }else{
    cout<<-1<<endl;
  }
}
