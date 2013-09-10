#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;
string s;
bool input(){
  if(getline(cin,s)){
    if(s==".")return false;
    return true;
  }
  return false;
}
bool solve(){
  stack<char> st;
  for(int i=0;i<s.size();i++){
    if(s[i]=='('||s[i]=='['){
      st.push(s[i]);
    }else if(s[i]==')'||s[i]==']'){
      if(st.empty())return false;
      char tmp = st.top();st.pop();
      if(s[i]==')'){
        if(tmp != '(')return false;
      }else{
        if(tmp != '[')return false;
      }
    }
  }
  if(st.empty()){
    return true;
  }else{
    return false;
  }
}

int main(){
  while(input()){
    if(solve()){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  }
}
