#include<utility>
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

int n,m,h,d;
vector<string> F;


bool judge(vector<string> f){
  int now = m;
  for(int i=0;i<f.size();i++){
    assert(now!=0);
    if(f[i][now-1]=='1'){
      now = now-1;
    }else if(f[i][now]=='1'){
      now = now+1;
    }
    //cout<<F[i]<<" "<<f[i]<<" "<<now<<endl;
  }
  return now == h;
}

pair<int,int> solve(){
  if(judge(F))return make_pair(0,0);
  for(int i=0;i<F.size();i++){
    for(int j=1;j<F[i].size()-1;j++){
      vector<string> tmp = F;
      if(tmp[i][j-1]!='1'&&tmp[i][j+1]!='1'){
        tmp[i][j]='1';
        if(judge(tmp)){
          return make_pair(i+1,j);
        }
      }
    }
  }
  return make_pair(-1,0);
}


int main(){
  while(cin>>n,n!=0){
    cin>>m>>h>>d;
    F.clear();
    for(int i=0;i<d;i++){
      string s;
      cin>>s;
      s = "*"+s+"*";
      F.push_back(s);
    }
    pair<int,int> ans = solve();
    if(ans.first==0){
      cout<<0<<endl;
    }else if(ans.first==-1){
      cout<<1<<endl;
    }else{
      cout<<ans.first<<" "<<ans.second<<endl; 
    }
  }
}
