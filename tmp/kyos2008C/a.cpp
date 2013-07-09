#include<iostream>
#include<cmath>
#include<string>
using namespace std;

char CtoN[3];
string in;
string cp;

bool input(){
  cin>>in;
  if(in==".")return false;
  return true;
}

char Not(char c){
  switch(c){
    case '0':
      return '2';
    case '1':
      return '1';
    case '2':
      return '0';
  }
}
char Lpro(char a,char b){
  return min(a,b);
}

char Lsum(char a,char b){
  return max(a,b);
}

char Clac(string str){
  if(str[0]=='('){
    int count=1;
    for(int i=1;i<str.size();i++){
      if(str[i]=='('){
        count++;
      }else if(str[i]==')'){
        count--;
      }else if(count==1&&(str[i]=='+' || str[i]=='*')){
        string str1 = str.substr(1,i-1);
        string str2 = str.substr(i+1,str.size()-(i+1)-1);
        if(str[i]=='+'){
          return Lsum(Clac(str1),Clac(str2));
        }else{
          return Lpro(Clac(str1),Clac(str2));
        }
      }
    }
  }else if(str[0]=='-'){
    return Not(Clac(str.substr(1)));
  }else{
    return str[0];
  }
}

char conv(char c){
  switch(c){
    case 'P':
      return CtoN[0];
    case 'Q':
      return CtoN[1];
    case 'R':
      return CtoN[2];
    default:
      return c;
  }
}

void mkcp(){
  cp="";
  for(int i=0;i<in.size();i++){
    cp+=conv(in[i]);
  }
}


int solve(){
  int ans=0;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        CtoN[0]=CtoN[1]=CtoN[2]='0';
        CtoN[0]+=i;
        CtoN[1]+=j;
        CtoN[2]+=k;
        mkcp();
        if(Clac(cp)=='2'){
          ans++;
        }
      }
    }
  }
  return ans;
}


int main(){
  while(input()){
    cout<<solve()<<endl;
  } 
}
