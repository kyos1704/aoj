#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

#define X first
#define Y second

const double eps =  1e-9;
typedef long double ld;
int main(){
  ld x[4];
  ld y[4];
  while(cin >>x[0]>>y[0]>>x[1]>>y[1] >>x[2]>>y[2]>>x[3]>>y[3]){
    if(min(x[1],x[3])<max(x[0],x[2]) || min(y[1],y[3])< max(y[0],y[2]))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
}
