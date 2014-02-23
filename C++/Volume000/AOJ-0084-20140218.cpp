#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main(){
  vector<string> list;
  string s;
  getline(cin,s);
  for(int i=0;i<s.size()&&s.size()!=0;i++){
    if(s[i]=='.' || s[i]==' ' || s[i]== ','){
      if(i!=0)list.push_back(s.substr(0,i));
      s = s.substr(i+1);
      i=-1;
    }
  }
  vector<string> ans ;
  for(int i=0;i<list.size();i++){
    if(2<list[i].size()&&list[i].size()<7){
      ans.push_back(list[i]);
    }
  }
  for(int i=0;i<ans.size()-1;i++){
    cout<<ans[i]<<" ";
  }cout<<ans[ans.size()-1]<<endl;
}
