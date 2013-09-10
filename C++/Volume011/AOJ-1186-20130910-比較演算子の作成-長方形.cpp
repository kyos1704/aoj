#include<iostream>
using namespace std;

struct S{
  S(){};
  S(int xx,int yy){
    x=xx;
    y=yy;
  }
  int x,y;
};
bool operator<(S a,S b){
  int aa = a.x*a.x+a.y*a.y;
  int bb = b.x*b.x+b.y*b.y;
  if(aa!=bb){
    return aa<bb;
  }else{
    return a.x<b.x;
  }
}
int x,y;
S a;
bool input(){
  a = S(150,150);
  cin>>x>>y;
  if(y==0&&x==0){
    return false;
  }else{
    return true;
  }
}

void solve(){
  S in(x,y);
  for(int i=1;i<150;i++){
    for(int j=i+1;j<150;j++){
      S comp(i,j);
      if(in<comp&&comp<a){
        a=comp;
      }
    }
  }
}

int main(){
  while(input()){
    solve();
    cout<<a.x<<" "<<a.y<<endl;
  }
}


