#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
bool check(char c){
  for(int i=0;i<9;i+=3){
    if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i]==c){
      return true;
    }
  }
  for(int i=0;i<3;i++){
    if(s[i]==c&&s[i+3]==c&&s[i+6]==c){
      return true;
    }
  }
  if(s[0]==s[4]&&s[4]==s[8]&&s[0]==c){
    return true;
  }
  if(s[2]==s[4]&&s[4]==s[6]&&s[2]==c){
    return true;
  }
  return false;
}


int main(){
  while(cin>>s){
    bool o = check('o');
    bool x = check('x');
    if(o){
      cout<<"o"<<endl;
    }
    if(x){
      cout<<"x"<<endl;
    }
    if(!o&&!x){
      cout<<"d"<<endl;
    }
  }
}
