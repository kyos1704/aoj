#include<iostream>
#include<map>
#include<sstream>
using namespace std;


int main(){
  int num,day;
  char c;
  string s;
  int j = 0;
  map<int,int> data[2];
  while(getline(cin,s),!cin.eof()){
    if(s.size()==0){
      j++;
      continue;
    }
    stringstream ss(s);
    ss>>num>>c>>day;
    data[j][num]++;
  }
  for(auto i:data[0]){
    if(data[1][i.first]>0){
      cout<<i.first<<" "<<i.second+data[1][i.first]<<endl;
    }
  }
  return 0;

}
