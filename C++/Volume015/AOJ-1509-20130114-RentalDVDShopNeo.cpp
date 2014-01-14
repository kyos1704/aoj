#include<iostream>
using namespace std;


int main(){
  int a,b,c,d,e,na,nb,nc;
  while(cin>>a>>b>>c>>d>>e,a!=0){
    cin>>na>>nb>>nc;
    int ans = 0;
    int tmp_ans = 0;
    for(int i=0;i<nc+nb+na;i++){
      int tmp;
      if(i<nc)tmp=c;
      else if(i<nc+nb)tmp=b;
      else if(i<nc+nb+na)tmp=a;
      tmp_ans+=tmp;
      if(i<d-1){
      }else if(i==d-1){
        ans =min(tmp_ans,d*e);
        tmp_ans=0;
      }else if(i<nc){
        tmp_ans=0;
        ans += e;
      }
    }
    if(nc+nb+na < d){
      ans = min(tmp_ans,d*e);
      tmp_ans = 0;
    }
    cout<<ans+tmp_ans<<endl;
  }
}
