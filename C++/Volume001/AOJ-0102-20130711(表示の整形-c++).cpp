#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

vector<vector<int> > data;

void init(){
  data.clear();
}

bool input(){
  int n;
  cin>>n;
  if(n==0)return false;

  for(int i=0;i<n;i++){
    vector<int> vtmp;
    for(int j=0;j<n;j++){
      int tmp;
      cin>>tmp;
      vtmp.push_back(tmp);
    }
    data.push_back(vtmp);
  }
  return true;
}

void solve(){
  vector<int> last;
  last.resize(data[0].size()+1);
  for(int i=0;i<data.size();i++){
    int tmp=0;
    for(int j=0;j<data[i].size();j++){
      tmp+=data[i][j];
      last[j]+=data[i][j];
      last[last.size()-1]+=data[i][j];
    }
    data[i].push_back(tmp);
  }
  data.push_back(last);
}


int main(){
  while(init(),input()){
    solve();
    for(int i=0;i<data.size();i++){
      for(int j=0;j<data[i].size();j++){
        cout<<setw(5)<<data[i][j];
      }cout<<endl;
    }
  }
}
