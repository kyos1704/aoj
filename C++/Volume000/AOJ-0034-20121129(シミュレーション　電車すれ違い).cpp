#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;



int main(){
	int l[10];
	int v[2];
	double m;
	double pos;
	int ans;
	while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&l[0],&l[1],&l[2],&l[3],&l[4],&l[5],&l[6],&l[7],&l[8],&l[9],&v[0],&v[1])!=EOF){
		m=0;
		for(int i=0;i<10;i++){
			m+=l[i];
		}
		pos=(m*v[0])/double(v[0]+v[1]);
		for(int i=0;i<10;i++){
			pos-=l[i];
			if(!(pos>0)){
				ans=i+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}