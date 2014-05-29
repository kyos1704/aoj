#include<bits/stdc++.h>
using namespace std;

int n,m,l;
vector<int> a,b,c;
bool input(){
  a=b=c=vector<int>(20,0);
  cin>>n>>m>>l;
  if(n==0&&m==0&&l==0)return false;
  for(int i=0;i<l;i++){
    string tmp;
    cin>>tmp;
    switch(tmp[0]){
      case 'a':
        a[tmp.size()-1]++;
        break;
      case 'b':
        b[tmp.size()-1]++;
        break;
      case 'c':
        c[tmp.size()-1]++;
        break;
    }
  }
  return true;
}
typedef long long ll;
ll nCk(int n,int k){
  if(n<k){
    return 0;
  }
  ll res = 1;
  for(int i=n-k+1;i<=n;i++)res*=i;
  for(int i=1;i<=k;i++)res/=i;
  return res;
}


bool check_sub(vector<int> h,int ai,int bi,int ci){
  vector<int> need(20,0);
  for(int i=0;i<a.size();i++){
    need[h[ai]+i] += a[i];
    need[h[bi]+i] += b[i];
    need[h[ci]+i] += c[i];
  }
  vector<int> now(20,0);
  for(int i=0;i<h.size();i++){
    now[h[i]]++;
  }
  for(int i=0;i<need.size();i++){
    if(need[i]>now[i])return false;
    if(now[i]>n)return false;
  }
  return true;
}

bool check(vector<int> h){
  for(int i=0;i<h.size();i++){
    for(int j=0;j<h.size();j++){
      for(int k=0;k<h.size();k++){
        if(check_sub(h,i,j,k))return true;;
      }
    }
  }
  return false;
}

ll count(vector<int> h,int b){
  vector<int> now(20,0);
  for(int i=0;i<h.size();i++){
    now[h[i]]++;
  }
  ll res = 1;
  for(int i=0;i<now.size();i++){
    res*=nCk(n,now[i]);
  }
  const int arr = m - (h[h.size()-1]-b+1) + 1;
  res *= nCk(arr,b+1);
  return res;
}

vector<int> hands;
ll req(int n,int b){
  if(!(hands[n]<m))return 0;
  if(n==hands.size()-1){
    if(check(hands)){
      return count(hands,b);
    }else{
      return 0;
    }
  }
  ll res = 0;
  hands[n+1] = hands[n];
  res += req(n+1,b);
  hands[n+1] = hands[n]+1;
  res += req(n+1,b);
  hands[n+1] = hands[n]+2;
  res += req(n+1,b+1);
  return res;
}
ll solve(){
  hands = vector<int>(l);
  hands[0]=0;
  return req(0,0);
}


int main(){
  while(input()){
    long long ans = solve();
    cout<<fixed<<setprecision(10)<<((double)ans)/nCk(n*m,l)<<endl;
  }
}
