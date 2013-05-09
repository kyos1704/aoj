#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

#define MAX_M 110

struct edge{int to,cost;};
typedef pair<int,int> P;

vector<edge> c[2][MAX_M];

int dijkstra(int s,int e,bool r){
	int d[MAX_M];
	for(int i=0;i<MAX_M;i++){
		d[i]=INT_MAX;
	}
	priority_queue<P,vector<P>,greater< P > > que;
	
	d[s]=0;
	
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(int i=0;i<c[r][v].size();i++){
			edge e=c[r][v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	
	return d[e];
}

int main(){
	int n,m;
	while(cin>>n>>m,n!=0||m!=0){
		for(int r=0;r<2;r++){
			for(int i=0;i<MAX_M;i++){
				c[r][i].clear();
			}
		}
		for(int i=0;i<n;i++){
			int a,b,cos,tim;
			cin>>a>>b>>cos>>tim;
			edge co,t;
			co.to=b;co.cost=cos;
			t.to=b;t.cost=tim;
			c[0][a].push_back(co);
			c[1][a].push_back(t);
			co.to=a;t.to=a;
			c[0][b].push_back(co);
			c[1][b].push_back(t);
		}
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			int s,e;
			bool r;
			cin>>s>>e>>r;
			int ans=dijkstra(s,e,r);
			cout<<ans<<endl;
		}
	}
}