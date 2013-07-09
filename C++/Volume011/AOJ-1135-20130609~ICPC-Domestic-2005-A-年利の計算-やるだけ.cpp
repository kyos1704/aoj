#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

struct datum{
  datum(){};
  datum(bool type,double ratio,int charge){
    t=type;
    r=ratio;
    c=charge;
  }
  bool t;
  double r;
  int c;
};

int charge;
int years;
vector<datum> data;

void init(){
  charge=years=0;
  data.clear();
}

bool input(){
  int n=0;
  cin>>charge>>years;
  cin>>n;
  bool t;
  double r;
  int c;
  for(int i=0;i<n;i++){
    cin>>t>>r>>c;
    data.push_back(datum(t,r,c));
  }
  return true;
}



int cul_end(datum a,int c,int y){
  int res=c;
  if(a.t){
    for(int i=0;i<y;i++){
      int A,B;
      A=res;
      B=res*a.r;
      res=A+B-a.c;
    }
  }else{
    int add=0;
    for(int i=0;i<y;i++){
      int A,B;
      A=res;
      B=res*a.r;
      res=A-a.c;
      add+=B;
    }
    res+=add;
  }
  return res;
}


int solve(){
  int res=0;
  for(int i=0;i<data.size();i++){
    res=max(res,cul_end(data[i],charge,years));
  }
  return res;
}


int main(){
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    init(),input();
    cout<<solve()<<endl;
  }
}
