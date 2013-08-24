#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cassert>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;

class Cake{
private:
  int x,y;
public:
  Cake(){};
  Cake(int xx,int yy){
    x=xx;
    y=yy;
  }
  int size(){
    return x*y;
  }
  pair<Cake,Cake> cut(int n){
    pair<Cake,Cake> res;
    Cake tmp[2];
    if((n%(x+y))<x){
      int len = (n%(x+y));
      tmp[0]=Cake(len,y);
      tmp[1]=Cake(x-len,y);
    }else{
      int len = (n%(x+y))-x;
      tmp[0]=Cake(x,y-len);
      tmp[1]=Cake(x,len);
    }
    if(tmp[0].size()>tmp[1].size()){
      res.first=tmp[1];
      res.second=tmp[0];
    }else{
      res.first=tmp[0];
      res.second=tmp[1];
    }
    return res;
  }
};

bool operator<(Cake a,Cake b){
  return a.size()<b.size();
}


int n;
Cake C;
bool init(){
  n=0;
  C=Cake();
}

bool input(){
  int w,h;
  cin>>n>>w>>h;
  if(n==0&&w==0&&h==0)return false;
  C=Cake(w,h);
}

vector<Cake> solve(){
  vector<Cake> res;
  res.push_back(C);
  for(int i=0;i<n;i++){
    int p,s;
    cin>>p>>s;
    p--;
    vector<Cake> tmp;
    pair<Cake,Cake> cut_cake;
    for(int j=0;j<res.size();j++){
      if(j==p){
        cut_cake=res[j].cut(s);
      }else{
        tmp.push_back(res[j]);
      }
    }
    tmp.push_back(cut_cake.first);
    tmp.push_back(cut_cake.second);
    res.clear();
    res=tmp;
    tmp.clear();
  }
  return res;
}

int main(){
  while(init(),input()){
    vector<Cake> ans=solve();
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
      cout<<ans[i].size();
      if(i!=ans.size()-1){
        cout<<" ";
      }else{
        cout<<endl;
      }
    }
  }
}
