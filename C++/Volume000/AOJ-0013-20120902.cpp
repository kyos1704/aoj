#include<stdio.h>
#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int main(){
	stack<int> s;
	int n;
	while((scanf("%d",&n))!=EOF){
		if(n!=0){
			s.push(n);
		}else{
			printf("%d\n",s.top());
			s.pop();
		}
	}
	return 0;
}


