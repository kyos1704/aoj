#include<iostream>
#include<string>
using namespace std;
int ans;
int w,h;
string map[40];
int vec[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
void move(int x,int y){
	ans++;
	map[x][y]='#';
	for(int i=0;i<4;i++){
		if((x+vec[i][0]>=0)&&(y+vec[i][1]>=0)&&(x+vec[i][0]<h)&&(y+vec[i][1]<w)){
			if(map[x+vec[i][0]][y+vec[i][1]]=='.'){
				move(x+vec[i][0],y+vec[i][1]);
			}
		}
	}
	return;
}

int main(){
	while(cin>>w>>h,w){
		ans=0;
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
		move(fx,fy);
		cout<<ans<<endl;
		
	}
}