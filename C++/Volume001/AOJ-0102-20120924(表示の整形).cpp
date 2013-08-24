#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n;
	int data[20][20];
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				data[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>data[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				data[i][n]=data[i][n]+data[i][j];
				data[n][j]=data[n][j]+data[i][j];
			}
		}
		for(int i=0;i<n;i++){
			data[n][n]=data[n][n]+data[i][n];
		}
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				printf("%5d",data[i][j]);
			}printf("\n");
		}
	}
}
