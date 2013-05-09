#include<iostream>
#include<vector>
using namespace std;

const int MAX_in=300010;
vector<int> list;

void make_list(){
  bool prime[MAX_in];
  prime[0]=prime[1]=0;
  for(int i=2;i<MAX_in;i++){
    prime[i]=1;
  }
  for(int i=2;i<MAX_in;i++){
    if(prime[i]==1)
    switch(i%7){
    case 1:
    case 6:
      list.push_back(i);
      for(int j=i+i;j<MAX_in;j+=i){
        prime[j]=0;
      }
      break;
    default:
      prime[i]=0;
    }
  }
}


void solve(int n){
  for(int i=0;i<list.size();i++){
    if(n%list[i]==0){
     cout<<" "<<list[i];
    }
  }
}


int main(){
  make_list();
  long long n;
  while(cin>>n,n!=1){
    cout<<n<<":";
    solve(n);
    cout<<endl;
  }
}

