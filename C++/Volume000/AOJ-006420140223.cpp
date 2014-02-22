#include<iostream>
#include<string>
#include<sstream>
#include<utility>
using namespace std;
pair<int,string> f(string s){
  stringstream ss(s);
  int n;string res;
  ss>>n>>res;
  return make_pair(n,res);
}
int main(){
  string s;
  int ans = 0;
  while(cin>>s){
    while(true){
      while((s[0]<'0'||'9'<s[0]) && s.size()!=0)s=s.substr(1);
      if(s.size()==0)break;
      pair<int,string> tmp;
      tmp= f(s);
      ans += tmp.first;
      s = tmp.second;
    }
  }
  cout<<ans<<endl;
}
