#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string s;
int n;
string to_s(int i){
  stringstream ss;
  ss<<i;
  string res;
  ss>>res;
  return res;
}


string convert(string s){
  string res="";
  int t=s.find_first_not_of(s[0]);
  while(t!=-1){
    res+=to_s(t)+s[0];
    s=s.substr(t);
    t=s.find_first_not_of(s[0]);
  }
  res+=to_s(s.size())+s[0];
  return res;
}

string solve(){
  string res=s;
  for(int i=0;i<n;i++){
    res = convert(res);
  }
  return res;
}

int main(){
  while(cin>>n,n!=0){
    cin>>s;
    cout<<solve()<<endl;
  }
}
