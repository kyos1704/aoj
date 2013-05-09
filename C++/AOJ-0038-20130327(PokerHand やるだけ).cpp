#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define same2(a,b) (c[a]==c[b])
#define same3(a,b,c) (same2(a,b)&&same2(b,c))
#define same4(a,b,c,d) (same3(a,b,c)&&same2(c,d))
int c[5];

bool four_card(){
	if(same4(0,1,2,3)||same4(1,2,3,4)){
		return 1;
	}
	return 0;
}

bool full_house(){
	if((same3(0,1,2)&&same2(3,4)) || (same2(0,1)&&same3(2,3,4))){
		return 1;
	}else{
		return 0;
	}
}

bool straight(){
	bool res=1;
	for(int i=0;i<4;i++){
		if((c[i]+1)!=c[i+1])res=0;
	}
	if((res==0) && (c[0]==1) && (c[1]==10)){
		res=1;
		for(int i=1;i<4;i++){
			if((c[i]+1)!=c[i+1])res=0;
		}
	}
	return res;
}

bool three_card(){
	if(same3(0,1,2)||same3(1,2,3)||same3(2,3,4)){
		return 1;
	}else{
		return 0;
	}
}

bool two_pair(){
	int p=0;
	for(int i=0;i<4;i++){
		if(same2(i,i+1)){
			p++;
		}
	}
	if(p==2){
		return 1;
	}else{
		return 0;
	}
}

bool one_pair(){
	if(same2(0,1)||same2(1,2)||same2(2,3)||same2(3,4)){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	while(scanf("%d,%d,%d,%d,%d",&c[0],&c[1],&c[2],&c[3],&c[4])!=EOF){
		sort(c,c+5);
		if(four_card()){
			cout<<"four card"<<endl;
		}else if(full_house()){
			cout<<"full house"<<endl;
		}else if(straight()){
			cout<<"straight"<<endl;
		}else if(three_card()){
			cout<<"three card"<<endl;
		}else if(two_pair()){
			cout<<"two pair"<<endl;
		}else if(one_pair()){
			cout<<"one pair"<<endl;
		}else{
			cout<<"null"<<endl;
		}
	}
}