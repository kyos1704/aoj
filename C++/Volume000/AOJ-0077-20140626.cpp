#include<bits/stdc++.h>
using namespace std;

string in;

void init(){
  in = "";
}
bool input(){
  return !!(cin>>in);
}

string solve(){
  string ans("");
  for(int i=0;i<in.size();i++){
    if(in[i]=='@'){
      int tmp = in[i+1]-'0';
      for(int j=0;j<tmp;j++){
        ans += in[i+2];
      }
      i+=2;
    }else{
      ans += in[i];
    }
  }
  return ans;
}

int main(){
  while(init(),input()){
    cout<<solve()<<endl;
  }
}
