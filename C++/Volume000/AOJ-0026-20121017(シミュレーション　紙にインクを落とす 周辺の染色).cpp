#include<iostream>
#include<cstdio>
using namespace std;


int main(){
	int vx[]={ 0, 1,-1, 0, 0,-1,-1, 1, 1, 2,-2, 0, 0};
	int vy[]={ 0, 0, 0, 1,-1,-1, 1,-1, 1, 0, 0, 2,-2};
	int x,y,size;
	int map[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			map[i][j]=0;
		}
	}
	
	int nm_ans=0,max_ans=0;
	
	while(scanf("%d,%d,%d",&x,&y,&size)!=EOF){
		switch(size){
		case 1:
			for(int i=0;i<5;i++){
				if((min(x+vx[i],y+vy[i])>=0)&&max(x+vx[i],y+vy[i])<10){
					map[x+vx[i]][y+vy[i]]++;
				}
			}
			break;
		case 2:
			for(int i=0;i<9;i++){
				if((min(x+vx[i],y+vy[i])>=0)&&max(x+vx[i],y+vy[i])<10){
					map[x+vx[i]][y+vy[i]]++;
				}
			}
			break;
		case 3:
			for(int i=0;i<13;i++){
				if((min(x+vx[i],y+vy[i])>=0)&&max(x+vx[i],y+vy[i])<10){
					map[x+vx[i]][y+vy[i]]++;
				}
			}
			break;
		}
	}
	
	
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(map[i][j]>max_ans){
				max_ans=map[i][j];
			}
			if(map[i][j]==0){
				nm_ans++;
			}
		}
	}
	cout<<nm_ans<<endl;
	cout<<max_ans<<endl;
	return 0;
}
