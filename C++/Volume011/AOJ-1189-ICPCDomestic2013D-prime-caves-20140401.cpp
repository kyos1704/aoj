#include<vector>
#include<iomanip>
#include<iostream>
#include<map>
using namespace std;

typedef pair<int,int> pii;
#define X first
#define Y second
const int mem_max = 1100;
const int mm_max = mem_max*mem_max+100;
struct F{
  int prime[mm_max];
  pii mem2[mm_max];
  int mem[mem_max][mem_max];
  public:
  void init(){
    make_prime();
    for(int i=0;i<mem_max;i++){
      for(int j=0;j<mem_max;j++){
        mem[i][j]=-1;
      }
    } 
    int x=0,y=0;
    int c=1;
    int dx=1,dy=1;
    int vx=1,vy=-1;
    w(x,y,c);
    while(1){
      for(int i=0;i<dx;i++){
        x+=vx;c++;if(!(c<=mem_max*mem_max))break;
        w(x,y,c);
      }
      if(!(c<=mem_max*mem_max))break;
      vx*=-1;
      dx++;
      for(int i=0;i<dy;i++){
        y+=vy;c++;if(!(c<mem_max*mem_max))break;
        w(x,y,c);
      }
      if(!(c<=mem_max*mem_max))break;
      vy*=-1;
      dy++;
    }
    for(int i=0;i<mem_max;i++){
      for(int j=0;j<mem_max;j++){
        mem2[mem[i][j]] = pii(i-mem_max/2,j-mem_max/2); 
      }
    }
  }
  private:
  void make_prime(){
    for(int i=2;i<mm_max;i++){
      prime[i]=1;
    }
    for(int i=0;i*i<=mm_max;i++){
      if(prime[i])for(int j=i*2;j<mm_max;j+=i){
        prime[j]=0;
      }
    }
  }
  int res(int x){
    x+=mem_max/2;
    if(x<0||mem_max<=x)return -1;
    return x;
  }
  int w(int x,int y,int m){
    if(-1==(x = res(x))) return -1;
    if(-1==(y = res(y))) return -1;
    mem[x][y]=m;
    return mem[x][y];
  }
  public:
  int g(int x,int y){
    if(-1==(x = res(x))) return -1;
    if(-1==(y = res(y))) return -1;
    return mem[x][y];
  }
  int num(int x,int y){return g(x,y);}
  pii pos(int n){
    return mem2[n];
  }
  bool is_prime(int x,int y){
    int tmp = g(x,y);
    return prime[tmp];
  }
};
F f;

#define DEBUG 0
void print(){
  if(!DEBUG)return ;
  for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
      cout<<setw(4)<<f.g(j-10,i-10);
    }cout<<endl;
  }cout<<endl;

  for(int i=0;i<20;i++){
    cout<<f.pos(i+1).X<<" "<<f.pos(i+1).second<<endl;
  }
}
int m;
vector<pii> dp;
pii req(int x,int y){
  if(f.num(x,y)<0 || f.num(x,y)>=(int)dp.size())return pii();
  if(dp[f.num(x,y)].X!=-1)return dp[f.num(x,y)];
  if(f.num(x,y)>m)return pii();
  pii res = pii(0,0);
  for(int i=-1;i<=1;i++){
    pii tmp = req(x+i,y+1);
    res = max(tmp,res);
  }
  if(f.is_prime(x,y)){
    if(res.first == 0){
      res.second = f.num(x,y);
    }
    res.first++;
  }
  return dp[f.num(x,y)]=res;
}


pii solve(int n){
  dp.clear();dp.resize(m+100);
  for(int i=0;i<(int)dp.size();i++){
    dp[i] = pii(-1,-1);
  }
  return req(f.pos(n).X,f.pos(n).Y);
}

int main(){
  print();
  f.init();
  int n;
  while(1){
    cin>>m>>n;
    if(n==0&&m==0)break;
    pii ans = solve(n);
    cout<<ans.first<<" "<<ans.second<<endl;
  }
  return 0;
}
