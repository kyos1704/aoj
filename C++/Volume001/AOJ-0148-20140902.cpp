#include<bits/stdc++.h>
using namespace std;

const int N = 39;

string solve(int n){
  n = n %N;
  if(n==0)n = N;
  return "3C" + (n<10?"0"+to_string(n):to_string(n));
}

int main(){
  int n;
  while(cin>>n){
    cout<<solve(n)<<endl;
  };
  
}
