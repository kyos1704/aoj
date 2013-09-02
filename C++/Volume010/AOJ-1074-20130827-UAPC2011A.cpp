#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
#include<set>
#include<string>
using namespace std;

struct C{
  C(){};
  C(string ss,vector<int> tt){
    s = ss;
    t = tt;
  }
  string s;
  vector<int> t;
};

struct A{
  A(){};
  A(string ss,int pp){
    s= ss;
    p = pp;
  }
  string s;
  int p;
};

bool operator<(A a,A b){
  if(a.p!=b.p){
    return a.p<b.p;
  }else{
    return a.s<b.s;
  }
}

int N;
vector<int> num;
vector<C> c;
void init(){
  num.clear();
  num.resize(40);
  c.clear();
}

bool input(){
  int n;
  cin>>n;
  if(n==0)return false;
  N=n;
  for(int i=0;i<n;i++){
    string ts;
    cin>>ts;
    int tn;
    cin>>tn;
    vector<int> tv;
    for(int i=0;i<tn;i++){
      int tmp;
      cin>>tmp;
      num[tmp]++;
      tv.push_back(tmp);
    }
    c.push_back(C(ts,tv));
  }
  return true;
}

int cal(vector<int> t){
  int res=0;
  for(int i=0;i<t.size();i++){
    res += max(0,N-num[t[i]]+1);
  }
  return res;
}

void solve(){
  vector<A> ans;
  for(int i=0;i<c.size();i++){
    ans.push_back(A(c[i].s,cal(c[i].t)));
  }
  sort(ans.begin(),ans.end());
  cout<<ans[0].p<<" "<<ans[0].s<<endl;
}


int main(){
  while(init(),input()){
    solve();
  }
}
