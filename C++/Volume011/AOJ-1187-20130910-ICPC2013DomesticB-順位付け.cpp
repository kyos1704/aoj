#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct T{
  T(){ac=0;t=0;}
  int n,ac,t;
  vector<int> p;
};
bool operator<(T a,T b){
  if(a.ac!=b.ac){
    return a.ac>b.ac;
  }else if(a.t!=b.t){
    return a.t<b.t;
  }else{
    return a.n>b.n;
  }
}
bool operator==(T a,T b){
  return a.ac==b.ac && a.t==b.t;
}

vector<T> team;
int M,T,P,R;


bool input(){
  cin>>M>>T>>P>>R;
  if(M==0&&T==0&&P==0&&R==0)return false;
  team.clear();team.resize(T);
  for(int i=0;i<T;i++){
    team[i].n=i+1;
    team[i].p.resize(P+1);
  }
  return true;
}

void que(){
  for(int i=0;i<R;i++){
    int m,t,p,j;
    cin>>m>>t>>p>>j;
    t--;p--;
    if(j==0){
      team[t].t += team[t].p[p] + m;
      team[t].ac++;
    }else{
      team[t].p[p]+=20;
    }
  }
}

void solve(){
  sort(team.begin(),team.end());
}

void print(){
  for(int i=0;i<team.size()-1;i++){
    cout<<team[i].n;
    if(team[i]==team[i+1]){
      cout<<"=";
    }else{
      cout<<",";
    }
  }
  cout<<team[team.size()-1].n<<endl;
}

int main(){
  while(input()){
    que();
    solve();
    print();
  }
}
