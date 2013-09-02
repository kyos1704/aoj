#include<iostream>
#include<vector>
using namespace std;

vector<int> list;

bool input(){
  int n;
  cin>>n;
  if(n==0)return false;
  list.resize(n);
  for(int i=0;i<n;i++){
    cin>>list[i];
  }
  return true;
}

void print(){
  for(int i=0;i<list.size();i++){
    cout<<list[i];
    i++;
    if(i<list.size()&&list[i-1]==list[i]-1){
      while(list[i-1]==list[i]-1)i++;
      i--;
      cout<<"-"<<list[i];
    }else{
      i--;
    }
    if(i!=list.size()-1)cout<<" ";
  }
  cout<<endl;
}

int main(){
  while(input())print();
}


