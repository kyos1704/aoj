#include<string>
#include<iostream>
#include<vector>
using namespace std;

vector<string> m;


void draw(int a,int b){
  if(m[a][b]=='1'){
    m[a][b]='0';
    draw(a-1,b);
    draw(a+1,b);
    draw(a,b-1);
    draw(a,b+1);
  }
}

int solve(){
  int ans= 0;
  for(int i=0;i<m.size();i++){
    for(int j=0;j<m[i].size();j++){
      if(m[i][j]=='1'){
        draw(i,j);
        ans++;
      }
    }
  }
  return ans;
}

int main(){
  while(!cin.eof()){
    string s;
    m.clear();
    m.push_back("00000000000000");
    for(int i=0;i<12;i++){
      cin>>s;
      s = "0"+s+"0";
      m.push_back(s);
    }
    m.push_back("00000000000000");
    cin.ignore(100,'\n');
    cin.ignore();
    cout<<solve()<<endl;
  }
}
