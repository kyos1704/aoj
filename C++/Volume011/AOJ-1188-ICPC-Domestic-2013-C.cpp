#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int solve(string s){
  if(s[1]!='['){
    string tmp = s.substr(1,s.size()-2);
    int res = atoi(tmp.c_str()) ;
    return res/2 + res%2;
  }
  int c=0;
  int pre = 1;
  vector<int> list;
  for(int i=1;i<s.size()-1;i++){
    if(s[i]=='['){
      c++;
    }else if(s[i]==']'){
      c--;
    }
    if(c==0&&s[i]==']'){
      list.push_back(solve(s.substr(pre,(i-pre+1))));
      pre=i+1;
    }
  }
  sort(list.begin(),list.end());
  int ans = 0;
  for(int i=0;i<list.size()/2;i++){
    ans += list[i];
  }
  if(list.size()%2==1){
    ans+=list[list.size()/2];
  }
  return ans;
}


int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
  }
}
