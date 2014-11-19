#include<bits/stdc++.h>
using namespace std;

pair<double,string> ds(string s){
  stringstream ss(s);
  double res1 = 0;
  string res2 = "";
  ss>>res1;
  ss.ignore(100,' ');
  getline(ss,res2);
  return make_pair(res1,res2);
}

pair<char,string> cs(string s){
  stringstream ss(s);
  char res1 = 0;
  string res2 = "";
  ss>>res1;
  ss.ignore(100,' ');
  getline(ss,res2);
  return make_pair(res1,res2);
}

double solve(string s){
  stack<double> st;
  double res = 0;
  while(s.size()!=0){
    while(s[0]==' ')s = s.substr(1);
    if((s[0] == '+' || s[0] == '-' || s[0]=='/' || s[0]=='*') && (s.size()==1 || s[1]==' ')){
      auto tmp = cs(s);
      char c = tmp.first;
      s = tmp.second;
      double b = st.top();st.pop();
      double a = st.top();st.pop();
      switch(c){
        case '+':
          a += b;
          break;
        case '/':
          a /= b;
          break;
        case '*':
          a *= b;
          break;
        case '-':
          a -= b;
          break;
      }
      st.push(a);
    }else{
      auto tmp = ds(s);
      st.push(tmp.first);
      s = tmp.second;
    }
  }
  return st.top();
}
 
int main(){
  string s;
  while(!cin.eof()){
    getline(cin,s);
    if(s.size()==0)return 0;
    cout<<setprecision(100)<<solve(s)<<endl;
  }
}
