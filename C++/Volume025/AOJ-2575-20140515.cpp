#include<bits/stdc++.h>
using namespace std;
string AIZUNYAN = "AIZUNYAN";
string AIDUNYAN = "AIDUNYAN";
bool check(string s){
  sort(s.begin(),s.end());
  string tmp = AIDUNYAN;
  sort(tmp.begin(),tmp.end());
  return tmp==s;
}
int main(){
  string s;
  cin>>s;
  string ans = s;
  for(int i=0;i+7<s.size();i++){
    if(check(s.substr(i,8))){
      for(int j=0;j<8;j++){
        ans[i+j]=AIZUNYAN[j];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
