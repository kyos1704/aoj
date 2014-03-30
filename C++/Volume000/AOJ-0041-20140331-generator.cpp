#include<algorithm>
#include<set>
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
set<string> cal_list;
void gen(int ii,int jj,int kk){
  for(long long i=0;i<(1<<ll.size());i++){
    int l[5]={},e[5]={};
    for(int j=0;j<(int)ll.size();j++){
      if(i&(1<<j)){
        l[ll[j].first]++;
        e[ll[j].second]++;
      }
    }
    if(list[ii]=="*"){
      int tmp = min(l[0],e[0+2]);
      l[0]-=tmp;
      e[0+2]-=tmp;
    }
    if(list[jj]=="*"){
      int tmp = min(l[1],e[1+2]);
      l[1]-=tmp;
      e[1+2]-=tmp;
    }
    if(list[kk]=="*"){
      int tmp = min(l[2],e[2+2]);
      l[2] -= tmp;
      e[2+2] -=tmp;
    }

    for(int i=0;i<4;i++){
      for(int j=1;i+j<5;j++){
        int tmp = max(0,min(l[i],e[i+j])-1);
        l[i]-=tmp;
        e[i+j]-=tmp;
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
    cal_list.insert(tmp);
  }
}

int main(){
  init();
  for(auto i:cal_list){
    cout<<("if("+(i)+"==10)return \""+(i)+"\";")<<endl;
  }
}
