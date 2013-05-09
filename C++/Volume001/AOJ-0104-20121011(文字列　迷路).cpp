#include<iostream>
#include <stdlib.h>
#include<string>
using namespace std;

string map[200];
int j_map[200][200];

int* ans(int* x){
	if(j_map[x[0]][x[1]]==1){
		x[0]=x[1]=-1;
		return x;
	}else{
		j_map[x[0]][x[1]]=1;
		
		if(map[x[0]][x[1]]=='v'){
			x[0]++;
			return ans(x);
		}else if(map[x[0]][x[1]]=='<'){
			x[1]--;
			return ans(x);
		}else if(map[x[0]][x[1]]=='>'){
			x[1]++;
			return ans(x);
		}else if(map[x[0]][x[1]]=='^'){
			x[0]--;
			return ans(x);
		}else{
			return x;
		}
	}
}



int main(){
	int w,h;
	while(cin>>w,cin>>h,(w!=0)&&(h!=0)){
		for(int i=0;i<w;i++){
			cin>>map[i];
		}
		for(int i=0;i<w;i++){
			for(int j=0;j<h;j++){
				j_map[i][j]=0;
			}
		}
		
		int* x=(int *)malloc(sizeof(int)*3);
		x[0]=x[1]=0;
		x = ans(x);
		if(x[0]==-1){
			cout<<"LOOP"<<endl;
		}else{
			cout<<x[1]<<" "<<x[0]<<endl;
		}
	}
	
}