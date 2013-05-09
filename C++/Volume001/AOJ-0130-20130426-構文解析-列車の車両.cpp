#include<iostream>
#include<string>
using namespace std;


string solve(string in){
  string ans="";
  ans+=in[0];
  int pos=0;
  string op;
  char c;
  for(int i=1;i<in.size();){
    op=in.substr(i,2);
    c=in[i+2];
    i+=3;
    if(op=="->"){
      if(pos==ans.size()-1){
        ans=ans+c;
	pos++;
      }else{
        pos++;
      }
    }else{
      if(pos==0){
        ans=c+ans;
      }else{
        pos--;
      }
    }
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    cout<<solve(s)<<endl;
  }
}
