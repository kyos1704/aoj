#include<iostream>
#include<vector>
using namespace std;


int main(){
	unsigned int c[110][110],t[110][110];	
	
	int n,v;
	
	int a,b;
	
	while(cin>>n>>v,n){
		for(int i=0;i<v+1;i++){
			for(int j=0;j<v+1;j++){
				int tmp;
				if(i==j){
					tmp=0;
				}else{
					tmp=2000000;
				}
				c[i][j]=tmp;
				t[i][j]=tmp;
			}
		}
		
		for(int i=0;i<n;i++){
			cin>>a>>b;
			cin>>c[a][b];
			c[b][a]=c[a][b];
			cin>>t[a][b];
			t[b][a]=t[a][b];
		}
		
		
		for(int k=1;k<v+1;k++){
			for(int i=1;i<v+1;i++){
				for(int j=1;j<v+1;j++){
					c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
					t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
				}
			}
		}
		
		
		cin>>n;
		bool r;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			cin>>r;
			if(r){
				cout<<t[a][b]<<endl;
			}else{
				cout<<c[a][b]<<endl;
			}
		}
		
		
	}
}