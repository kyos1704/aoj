#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef pair<int,int> pii;
vector<vector<pii>> line;
int dist(pii a,pii b){
  return max(abs(a.first-b.first),abs(a.second-b.second));
}
pii operator-(pii a,pii b){
  return pii(a.first-b.first,a.second-b.second);
}
int out(pii a,pii b){
  return a.first*b.second - a.second*b.first;
}

bool judge(vector<pii> a,vector<pii> b){
  if(a.size()!=b.size())return false;
  for(int i=1;i<a.size();i++){
    if(dist(a[i],a[i-1])!=dist(b[i],b[i-1]))return false;
  }
  for(int i=2;i<a.size();i++){
    bool tmpa = (0<out(a[i]-a[i-1],a[i-1]-a[i-2]));
    bool tmpb = (0<out(b[i]-b[i-1],b[i-1]-b[i-2]));
    if(tmpa!=tmpb)return false;
  }
  return true;
}

void solve(){
  for(int i=1;i<line.size();i++){
    if(judge(line[0],line[i])||judge(line[0],vector<pii>(line[i].rbegin(),line[i].rend()))){
      cout<<i<<endl;
    }
  }
}


int main(){
  int n;
  while(cin>>n,n!=0){
    line.clear();
    for(int i=0;i<=n;i++){
      int m;
      cin>>m;
      vector<pii> ttmp;
      for(int j=0;j<m;j++){
        pii tmp;
        cin>>tmp.first>>tmp.second;
        ttmp.push_back(tmp);
      }
      line.push_back(ttmp);
    }
    solve();
    cout<<"+++++"<<endl;
  };
  return 0;
}
