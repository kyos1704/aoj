#include<string> 
#include<vector>
#include<iostream>
using namespace std;
bool map[20][20][4];
vector< string > maphor,mapver;
int xsize,ysize;
void init(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			for(int k=0;k<4;k++){
				map[i][j][k]=0;
			}
		}
	}
}
void setmap(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(-1<i&&i<maphor.size()&&-1<j&&j<maphor[0].size()){
				if(maphor[i][j]=='1'){
					map[i][j][0]=1;
				}
			}
			if(-1<i&&i<maphor.size()&&-1<j-1&&j-1<maphor[0].size()){
				if(maphor[i][j-1]=='1'){
					map[i][j][2]=1;
				}
			}
			if(-1<i&&i<mapver.size()&&-1<j&&j<mapver[0].size()){
				if(mapver[i][j]=='1'){
					map[i][j][3]=1;
				}
			}
			if(-1<i-1&&i-1<mapver.size()&&-1<j&&j<mapver[0].size()){
				if(mapver[i-1][j]=='1'){
					map[i][j][1]=1;
				}
			}
		}
	}
}

int solve(){
	int x=0,y=0;
	int v=0;
	string vec="RULD";
	int loop[4]={1,0,3,2};
	int vx[4]={1,0,-1,0};
	int vy[4]={0,-1,0,1};
	int count=0;
	while(1){
		count++;
		if(count>100)return -1;
		for(int i=0;i<5;i++){
			if(i==4)return -1;
			if(x==0
				&& y==0
				&&(((v+loop[i])%4)==2)){
				return 0;
			}
			if(map[y][x][(v+loop[i])%4]==1){
				v+=loop[i];
				v=v%4;
				x+=vx[v];
				y+=vy[v];
				cout<<vec[v];
				break;
			}
		}
	}
}

int main(){
	string tmp;
	for(int i=0;cin>>tmp;i++){
		if(i%2==0){
			maphor.push_back(tmp);
		}else{
			mapver.push_back(tmp);
		}
	}
	xsize=maphor[0].size()+1;
	ysize=mapver.size()+1;
	init();setmap();
	
	/*
	for(int i=0;i<xsize;i++){
		for(int j=0;j<ysize;j++){
			for(int k=0;k<4;k++){
				cout<<map[i][j][k];
			}
			cout<<" ";
		}
		cout<<endl;
	}
	*/
	if(solve()==-1)return -1;
	cout<<endl;
	
	return 0;
	
}