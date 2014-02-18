#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<map>
#include<set>
using namespace std;

vector<int> chair = {1,2,1,2,1,4,1,4};
int l[8];

vector<int> solve(){
  map<int,set<vector<int>>> list;
  for(int i=0;i<chair.size();i++){
    int tmp=0;
    for(int j=0;j<8;j++){
      tmp += max(0,l[j]-chair[j]);
    }
    list[tmp].insert(chair);
    rotate(chair.begin(),chair.begin()+1,chair.end());
  }
  return *((*list.begin()).second).begin();
}

int main(){
  while(cin>>l[0]>>l[1]>>l[2]>>l[3]>>l[4]>>l[5]>>l[6]>>l[7]){
    vector<int> ans = solve();
    cout<<ans[0];
    for(int i=1;i<ans.size();i++){
      cout<<" "<<ans[i];
    }cout<<endl;
  }
}
