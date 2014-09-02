#include<bits/stdc++.h>
using namespace std;

long long a,b;
bool input(){
  cin>>a>>b;
  return !(a==0&&b==0);
}

vector<int> solve(){
  vector<int> res(3);
  int n = b-a;
  res[2] = n/1000;
  n = n%1000;
  res[1] = n/500;
  n = n%500;
  res[0] = n/100;
  return res;
}


int main(){
  while(input()){
    auto ans = solve();
    for(int i= 0;i<ans.size();i++){
      cout<<ans[i];
      if(i!=ans.size()-1){
        cout<<" ";
      }else{
        cout<<endl;
      }
    }
  }
}
