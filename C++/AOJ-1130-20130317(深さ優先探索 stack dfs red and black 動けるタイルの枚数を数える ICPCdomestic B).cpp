#include<iostream>
#include<string>
#include<stack>
using namespace std;
int w,h;
string map[40];
int vec[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

struct pos{
	pos(int X,int Y){
		x=X,y=Y;
	}
	int x,y;
};

int move(int x,int y){
	int ans=0;
	map[x][y]='#';
	stack<pos> dfs;
	bfs.push(pos(x,y));
	while(!bfs.empty()){
		pos n=dfs.top();dfs.pop();
		x=n.x;
		y=n.y;
		////
		ans++;
		for(int i=0;i<4;i++){
			if((x+vec[i][0]>=0)&&(y+vec[i][1]>=0)&&(x+vec[i][0]<h)&&(y+vec[i][1]<w)){
				if(map[x+vec[i][0]][y+vec[i][1]]=='.'){
					map[x+vec[i][0]][y+vec[i][1]]='#';
					dfs.push(pos(x+vec[i][0],y+vec[i][1]));
				}
			}
		}
		/////
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
		int ans=move(fx,fy);
		cout<<ans<<endl;
		
	}
}