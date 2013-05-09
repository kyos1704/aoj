#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int w,h;
int s[35][35];
int cost[4];
int vx[4][4]={{1,0,-1,0},{0,1,0,-1},{-1,0,1,0},{0,-1,0,1}};
int vy[4][4]={{0,1,0,-1},{-1,0,1,0},{0,-1,0,1},{1,0,-1,0}};
int vv[4][4]={{0,3,2,1},{1,0,3,2},{2,1,0,3},{3,2,1,0}};

struct S{
	S(int ix,int iy,int iv,int ic){
		x=ix;y=iy;v=iv;c=ic;
	}
	int x,y,v,c;
};

bool operator<(S a,S b){
	return a.c>b.c;
}


S next(S a,int o){
	int c;
	//cout<<(s[a.y][a.x]==o)<<endl;
	if(o!=s[a.y][a.x]){
		c=a.c+cost[o];
	}else{
		c=a.c;
	}
	int x = a.x+vx[a.v][o];
	int y=a.y+vy[a.v][o];
	int v=vv[a.v][o];
	if(x<0||y<0||x>=w||y>=h)c=-1;
	return S(x,y,v,c);
}


int solve(){
	priority_queue<S> q;
	int use[35][35][4];
	for(int i=0;i<35;i++){
		for(int j=0;j<35;j++){
			for(int k=0;k<4;k++){
				use[i][j][k]=0;
			}
		}
	}
	
	q.push(S(0,0,0,0));
	while(!q.empty()){
		S now=q.top();q.pop();
		
		if(use[now.x][now.y][now.v])continue;
		use[now.x][now.y][now.v]=true;
		
		if(now.x==w-1&&now.y==h-1){
			return now.c;
		}
		
		for(int i=0;i<4;i++){
			S npos= next(now,i);
			if(npos.c!=-1){
				//cout<<npos.x<<" "<<npos.y<<" "<<npos.c<<endl;
				q.push(npos);
			}
		}
		
	}
	return 0;
}


bool input(){
	cin>>w>>h;
	if(!(w||h))return 0;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>s[i][j];
		}
	}
	for(int i=0;i<4;i++){
		cin>>cost[i];
	}
	return 1;
}



int main(){
	while(input()){
		cout<<solve()<<endl;
	}
}