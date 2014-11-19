#include<bits/stdc++.h>
using namespace std;


int h,m,s;

bool input(){
  cin>>h>>m>>s;
  if(h==-1)return false;
  return true;
}

char ans[2][100];
void solve(){
  const int  time = 60 * 120;
  int tmp = 60 * 60 * h + 60 * m + s;
  int now = time - tmp;
  
  tmp = now;
  int a_s = tmp % 60;
  tmp /= 60;
  int a_m = tmp % 60;
  tmp /= 60;
  int a_h = tmp;
  sprintf(ans[0],"%02d:%02d:%02d",a_h,a_m,a_s);

  tmp = now * 3;
  a_s = tmp % 60;
  tmp /= 60;
  a_m = tmp % 60;
  tmp /= 60;
  a_h = tmp;
  sprintf(ans[1],"%02d:%02d:%02d",a_h,a_m,a_s);
}

int main(){
  while(input()){
    solve();
    cout<<ans[0]<<endl<<ans[1]<<endl;
  }
}
