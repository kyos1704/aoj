#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<cmath>
#include<cstdlib>
using namespace std;

int solve(string tmp){
  set<string> ans;
  for(int i=1;i<tmp.size();i++){
    string a = tmp.substr(0,i);
    string b = tmp.substr(i);
    const string ra = string(a.rbegin(),a.rend());
    const string rb = string(b.rbegin(),b.rend());
    ans.insert(a+b);
    ans.insert(ra+b);
    ans.insert(a+rb);
    ans.insert(ra+rb);
    ans.insert(b+a);
    ans.insert(rb+a);
    ans.insert(rb+ra);
    ans.insert(b+ra);
  }
  return ans.size();
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string tmp;
    cin>>tmp;
    cout<<solve(tmp)<<endl;
  }
  return 0;
}
