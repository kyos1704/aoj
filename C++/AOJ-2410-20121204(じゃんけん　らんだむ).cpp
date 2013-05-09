#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	srand(unsigned(time(NULL)));
	char judge[20][20];
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>judge[i];
	}
	int n;
	for(int i=0;i<1000;i++){
		cout<<rand()%N+1<<endl;
		fflush(stdout);
		cin>>n;
	}
}

