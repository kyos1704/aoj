#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> in;
vector<string> list = {"+","-","*"};
vector<pair<int,int>> ll;
void gen(int,int,int);
void init(){
  ll.push_back(make_pair(0,3));
  ll.push_back(make_pair(1,4));
  ll.push_back(make_pair(0,2));
  ll.push_back(make_pair(1,3));
  ll.push_back(make_pair(2,4));
  for(int i=0;i<list.size();i++){
    for(int j=0;j<list.size();j++){
      for(int k=0;k<list.size();k++){
        gen(i,j,k);
      }
    }
  }
}
vector<string> cal_list;
void gen(int ii,int jj,int kk){
  for(long long i=0;i<(1<<ll.size());i++){
    int l[5]={},e[5]={};
    for(int j=0;j<(int)ll.size();j++){
      if(i&(1<<j)){
        l[ll[j].first]++;
        e[ll[j].second]++;
      }
    }
    string tmp = "";
    string abc[] = {"a","b","c","d"};
    for(int i=0;i<5;i++){
      for(int j=0;j<e[i];j++){
        tmp += ")";
      }
      if(i==1)tmp+=list[ii];
      if(i==2)tmp+=list[jj];
      if(i==3)tmp+=list[kk];
      for(int j=0;j<l[i];j++){
        tmp += "(";
      }
      if(i!=4){
        tmp += abc[i];
      }
    }
    cal_list.push_back(tmp);
  }
}
 
string conv(string s){
  stack<char> st;
  s = "(("+s+"))";
  string res;
  for(int i=0;i<s.size();i++){
    switch(s[i]){
      case '(':
        st.push(s[i]);
        break;
      case ')':
        while(1){
          char tmp = st.top(); st.pop();
          if(tmp=='(')break;
          res += tmp;
        }
        break;
      case '+':
      case '-':
        while(1){
          char tmp = st.top();st.pop();
          if(tmp=='*'||tmp=='+'||tmp=='-'){
            res+= tmp;
          }else{
            st.push(tmp);
            break;
          }
        }
        st.push(s[i]);
        break;
      case '*':
        while(1){
          char tmp = st.top();st.pop();
          if(tmp=='*'){
            res+= tmp;
          }else{
            st.push(tmp);
            break;
          }
        }
        st.push(s[i]);
        break;
      default:
        res += s[i];
    }
  }
  return res;
}
 
int cal_t(char a,int x,int y){
  switch(a){
    case '+':return x+y;
    case '-':return x-y;
    case '*':return x*y;
  }
  return 0;
}
 
int cal(string s,vector<int>& in){
  stack<int> st;
  for(int i=0;i<s.size();i++){
    switch(s[i]){
      case 'a':st.push(in[0]);break;
      case 'b':st.push(in[1]);break;
      case 'c':st.push(in[2]);break;
      case 'd':st.push(in[3]);break;
      default:
        int b = st.top();st.pop();
        int a = st.top();st.pop();
        int c = cal_t(s[i],a,b);
        st.push(c);
    }
  }
  return st.top(); 
}
 
string convert(string s,vector<int>& in){
  string res="";
  for(int i=0;i<s.size();i++){
    if(s[i]=='a'){
      res += to_string(in[0]);
    }else if(s[i]=='b'){
      res += to_string(in[1]);
    }else if(s[i]=='c'){
      res += to_string(in[2]);
    }else if(s[i]=='d'){
      res += to_string(in[3]);
    }else{
      res += s[i];
    } 
  }
  return res;
}
 
string solve(){
  //cout<<cal_list.size()<<endl;
  for(int i=0;i<cal_list.size();i++){
    sort(in.begin(),in.end());
    string tmp = conv(cal_list[i]);
    do{
      int tt = cal(tmp,in);
      //cout<<tt<<" "<<convert(cal_list[i],in)<<" "<<tmp<<endl;
      if(tt==10){
        //cout<<cal_list[i]<<" "<<conv(cal_list[i])<<endl;
        return convert(cal_list[i],in);
      }
    }while(next_permutation(in.begin(),in.end()));
  }
  return "0";
}
 
int main(){
  init();
  bool j;
  while(1){
    j=false;
    in.clear();
    for(int i=0;i<4;i++){
      int tmp;
      cin>>tmp;
      if(tmp!=0)j=true;
      in.push_back(tmp);
    }
    if(!j)break;
    cout<<solve()<<endl;
  }
}
