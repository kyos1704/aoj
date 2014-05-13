#include<bits/stdc++.h>
using namespace std;

struct D{
  int t,s;
};

vector<vector<D>> data;
void init(){
  data.clear();
}
int q;
void print(){
  for(int i=0;i<data.size();i++){
    //cerr<<"m="<<i<<":";
    for(int j=0;j+1<data[i].size();j+=2){
      //cerr<<"("<<data[i][j].t<<"-"<<data[i][j+1].t<<")";
    }//cerr<<endl;
  }
}
bool input(){
  int n,m;
  cin>>n>>m;
  if(n==0&&m==0)return false;
  //cerr<<"input"<<endl;
  int r;
  cin>>r;
  data.resize(m+10);
  vector<int> login(m+10,0);
  for(int i=0;i<r;i++){
    int t,n,m,s;
    cin>>t>>n>>m>>s;
    if(s==1){
      login[m]++;
    }else{
      login[m]--;
    }
    //cerr<<login[m]<<" "<<s<<endl;
    if(login[m]==s){
      data[m].push_back(D{t,s});
    }else if(data[m].size()>0&&data[m][data[m].size()-1].s==0){
      int pre_t = data[m][data[m].size()-1].t;
      data[m][data[m].size()-1].t = max(pre_t,t);
    }
  }
  cin>>q;
  return true;
}
int solve(){
  int s,e,m;
  cin>>s>>e>>m;
  //cerr<<"solve::"<<s<<" "<<e<<" "<<m<<endl;
  const vector<D> l = data[m];
  int ans = 0;
  for(int i=0;i<(int)l.size()-1;i++){
    if(l[i].s==1&&(s<l[i+1].t)&&l[i].t<=e){
      ans += l[i+1].t - max(s,l[i].t);
      if(e<=l[i+1].t){
        ans -= l[i+1].t - e;
      }
    }
  }
  return ans;
}

int main(){
  while(init(),input()){
    print();
    for(int i=0;i<q;i++){
      int ans = solve();
      //cerr<<"ans::"<<ans<<endl;
      cout<<ans<<endl;
    }
  }
}
