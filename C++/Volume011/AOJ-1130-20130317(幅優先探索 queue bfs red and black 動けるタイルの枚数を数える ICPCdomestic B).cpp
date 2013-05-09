#include<iostream>
#include<string>
#include<queue>
using namespace std;
int w,h;
string map[40];
int vec[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

struct s{
	s(int X,int Y){
		x=X,y=Y;
	}
	int x,y;
};

int solve(int x,int y){
	int ans=0;
	map[x][y]='#';
	queue<s> q;
	q.push(s(x,y));
	while(!q.empty()){
		s n=q.front();q.pop();
		x=n.x;
		y=n.y;
		
		ans++;
		for(int i=0;i<4;i++){
			if((x+vec[i][0]>=0)&&(y+vec[i][1]>=0)&&(x+vec[i][0]<h)&&(y+vec[i][1]<w)){
				if(map[x+vec[i][0]][y+vec[i][1]]=='.'){
					map[x+vec[i][0]][y+vec[i][1]]='#';
					q.push(s(x+vec[i][0],y+vec[i][1]));
				}
			}
		}
	}
	return ans;
}

int main(){
	while(cin>>w>>h,w){
		int fx,fy;
		for(int i=0;i<h;i++){
			cin>>map[i];
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(map[i][j]=='@'){
					fx=i;
					fy=j;
					break;
				}
			}
		}
		int ans=solve(fx,fy);
		cout<<ans<<endl;
		
	}
}