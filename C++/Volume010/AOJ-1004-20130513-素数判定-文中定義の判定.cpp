#include<iostream>
#include<bitset>
using namespace std;
#define L_SIZE 10010
bitset<L_SIZE> list;

void make_list(){
  for(int i=2;i<list.size();i++){
    list[i]=1;
  }
  list[0]=list[1]=0;

  for(int i=2;i*i<list.size();i++){
    if(list[i]==1){
      for(int j=i*2;j<list.size();j+=i){
        list[j]=0;
      }
    }
  }
}

int main(){
  make_list();
  int n;
  while(cin>>n){
    n++;
    int ans=0;
    for(int i=1;i<n;i++){
      if(list[i]&&list[n-i]){
	ans++;
      }
    }
    cout<<ans<<endl;
  }
}
