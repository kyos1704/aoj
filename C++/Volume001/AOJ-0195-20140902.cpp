#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> data;

bool input(){
  data.clear();
  data.resize(5);
  for(int i=0;i<5;i++){
    data[i].resize(2);
    cin>>data[i][0]>>data[i][1];
    if(data[i][0]==0&&data[i][1]==0)return false;
  }
  return true;
}

pair<char,int> solve(){
  char max_c;
  int max_n = 0;

  for(int i=0;i<data.size();i++){
    const int n = data[i][0] + data[i][1];
    if(max_n < n){
      max_c = 'A' + i;
      max_n = n;
    }
  }
  return make_pair(max_c,max_n);
}

int main(){
  while(input()){
    auto ans = solve();
    cout<<ans.first<<" "<<ans.second<<endl;
  }
}
