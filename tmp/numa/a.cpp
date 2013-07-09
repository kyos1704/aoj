#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
#include<bitset>
#include<climits>
#include<cstdio>
#include<cassert>
using namespace std;

#define X first
#define Y second
typedef pair<int,int> Dim6;
vector<Dim6> M;
int Num;


Dim6 move(Dim6 a,int v){
  switch(v){
    case 0:
      a.Y--;
      return a;
    case 1:
      a.X++;
      a.Y--;
      return a;
    case 2:
      a.X++;
      return a;
    case 3:
      a.Y++;
      return a;
    case 4:
      a.X--;
      a.Y++;
      return a;
    case 5:
      a.X--;
      return a;
    default:
      return a;
  }
}

bool adjoin(Dim6 a,Dim6 b){
  for(int i=0;i<6;i++){
    if(move(a,i)==b){
      return true;
    }
  }
  return false;
}

class snake{
public:
  vector<Dim6> pos;
  vector<snake> Next;
  snake(){}
  snake(vector<Dim6> a){
    pos=a;
  };
  
  bool judge(vector<Dim6> n){
    int j=n.size()-1;
    for(int i=0;i<M.size();i++){
      if(n[j]==M[i]){
        return false;
      }
    }
    for(int i=0;i<n.size()-1;i++){
      if(i!=j-1){
        if(adjoin(n[i],n[j])){
          return false;
        }
      }else{
        if(!adjoin(n[i],n[j])){
          return false;
        }
      }
    }
    if(j+1<pos.size()&&!adjoin(n[j],pos[j+1])){
      return false;
    }
    return true;
  }

  void rec_next(vector<Dim6> n,int v){
    Dim6 tmp = move(pos[n.size()],v);
    n.push_back(move(pos[n.size()],v));
    if(judge(n)){
      if(n.size()==pos.size()){
        Next.push_back(snake(n));
      }else{
        if(v==6){
          for(int i=0;i<7;i++){
            rec_next(n,i);
          }
        }else{
          rec_next(n,6);
        }
      }
    }
  }

  vector<snake> next(){
    for(int i=0;i<7;i++){
      rec_next(vector<Dim6>(),i);
    }
    return Next;
  }
};
snake first_snake=snake(vector<Dim6>());


void init(){
  M.clear();
}
int self_x,self_y;
bool input(){
  cin>>Num;
  if(Num==0)return false;
  vector<Dim6> tmp;
  for(int i=0;i<Num;i++){
    int a,b;
    cin>>a>>b;
    tmp.push_back(Dim6(a,b));
  }
  first_snake=snake(tmp);

  int k;
  cin>>k;
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    M.push_back(Dim6(a,b));
  }
  cin>>self_x>>self_y;
  return true;
}

struct SS{
  SS(){};
  SS(int cost,snake a){
    c=cost;
    s=a;
  }
  int c;
  snake s;
};
bool operator<(SS a,SS b){
  if(a.c!=b.c){
    return a.c>b.c;
  }else{
    return a.s.pos>b.s.pos;
  }
}

bool comp_snake(SS a,SS b){
  if(a.s.pos!=b.s.pos){
    return a.s.pos<b.s.pos;
  }
}
int HOGE;
void print(SS a){
  cout<<"case:"<<HOGE<<":"<<a.c<<endl;
  for(int i=0;i<a.s.pos.size();i++){
    cout<<"case"<<HOGE<<":"<<a.s.pos[i].X<<" "<<a.s.pos[i].Y<<endl;
  }
  cout<<endl;
}
int solve(){
  queue<SS> q;
  q.push(SS(0,first_snake));
  set<vector<Dim6> > list;
  list.insert(first_snake.pos);
  int CCCC=0;
  int tmpc=0;
  while(!q.empty()){
    SS now=q.front();q.pop();
    if(now.s.pos[0].X == self_x && now.s.pos[0].Y == self_y){
      print(now);
      cout<<q.size()<<endl;
      return now.c;
    }
    vector<snake> next= now.s.next();
    for(int i=0;i<next.size();i++){
      set<vector<Dim6> >::iterator itr = list.find(next[i].pos);
      if(itr==list.end()){
        list.insert(next[i].pos);
        q.push(SS(now.c+1,next[i]));
      }
    }
    if(now.c>20)return now.c;
  }
  return -111111;
}

int main(){
  HOGE=0;
  while(init(),input()){
    HOGE++;
    cout<<solve()<<endl;
  }
}
