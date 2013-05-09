#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class S{
public:
	S(int pos,int cost){
		p=pos;
		c=cost;
	}
	int p,c;
};
bool operator<(S a,S b){
	return a.c>b.c;
}
int m;
vector<S> edge[100][2];
void add_edge(int a,int b,int c,int t){
	edge[a][0].push_back(S(b,c));
	edge[a][1].push_back(S(b,t));
	edge[b][0].push_back(S(a,c));
	edge[b][1].push_back(S(a,t));
}


int solve(int p,int q,int r){
	int ans=0;
	bool use[100];
	for(int i=0;i<100;i++){
		use[i]=0;
	}
	
	priority_queue<S> que;
	que.push(S(p,0));
	
	while(!que.empty()){
		S n=que.top();que.pop();
		
		if(n.p==q){
			ans=n.c;
			break;
		}
		
		if(use[n.p]){
			continue;
		}
		use[n.p]=1;
		
		
		for(int i=0;i<edge[n.p][r].size();i++){
			if(!use[edge[n.p][r][i].p]){
				que.push(S(edge[n.p][r][i].p,n.c+edge[n.p][r][i].c));
			}
		}
	}
	return ans;
}



int main(){
	int n;
	while(cin>>n>>m,n!=0||m!=0){
		for(int i=0;i<100;i++){
			for(int j=0;j<2;j++){
				edge[i][j].clear();
			}
		}
		for(int i=0;i<n;i++){
			int a,b,c,t;
			cin>>a>>b>>c>>t;
			a--;b--;
			add_edge(a,b,c,t);
		}
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			int p,q,r;
			cin>>p>>q>>r;
			p--;q--;
			cout<<solve(p,q,r)<<endl;
		}
	}
}

