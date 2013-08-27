#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;

int l;
typedef pair<int,int> pii;
vector<pii> data;
void init(){
  data.clear();
}


bool input(){
  if(!(cin>>l))return false;
  if(l==0)return false;
  for(int i=0;i<12;i++){
    int m,n;
    cin>>m>>n;
    data.push_back(pii(m,n));
  }
  return true;
}

int  solve(){
  int m=0;
  for(int i=0;i<data.size();i++){
    m+=data[i].first-data[i].second;
    if(!(m<l)){
      return i+1;
    }
  }
  return -1;
}

int main(){
  while(init(),input()){
    int ans= solve();
    if(ans==-1){
      cout<<"NA"<<endl;
    }else{
      cout<<ans<<endl;
    }
  }
}
