#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


struct P{
  P(int a,double b){
    num=a;
    time=b;
  }
  int num;
  double time;
};

bool operator<(P a,P b){
  if(a.time!=b.time){
    return a.time<b.time;
  }else{
    return a.num<b.num;
  }
}

vector<P> g[3];
vector<P> all;
void solve(){
  for(int i=0;i<3;i++){
    for(int j=0;j<8;j++){
      int t1;
      double t2;
      cin>>t1>>t2;
      g[i].push_back(P(t1,t2));
    }
    sort(g[i].begin(),g[i].end());
  }
  for(int i=2;i<8;i++){
    for(int j=0;j<3;j++){
      all.push_back(g[j][i]);
    }
  }
  sort(all.begin(),all.end());

  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      cout<<g[i][j].num<<" "<<fixed<<setprecision(2)<<g[i][j].time<<endl;
    }
  }
  cout<<all[0].num<<" "<<fixed<<setprecision(2)<<all[0].time<<endl;
  cout<<all[1].num<<" "<<fixed<<setprecision(2)<<all[1].time<<endl;
}

int main(){
  solve();
}
