#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int n;
int size;
vector<int> list;
void init(){
  n=0;
  list.clear();
}

bool input(){
  cin>>n;
  size=0;
  list.resize(n);
  if(n==0)return false;
  return true;
}


void rec(int n){
  if(n==0){
    for(int i=0;i<size-1;i++){
      cout<<list[i]<<" ";
    } cout<<list[size-1]<<endl;
  }else{
    for(int i=n;i>0;i--){
      if(size!=0&&(list[size-1]<i))continue;
      list[size]=i;
      size++;
      rec(n-i);
      size--;
    }
  }
}

void solve(){
  rec(n);
}

int main(){
  while(init(),input()){
    solve();
  }
}
