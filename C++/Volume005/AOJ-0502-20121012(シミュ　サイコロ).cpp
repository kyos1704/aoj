#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int north;
int west;
int east;
int south;
int up;
int down;


void turn(string s){
	if(s=="North"){
		swap(up,south);
		swap(south,down);
		swap(down,north);
	}else if(s=="East"){
		swap(up,west);
		swap(west,down);
		swap(down,east);
	}else if(s=="West"){
		swap(up,east);
		swap(east,down);
		swap(down,west);
	}else if(s=="South"){
		swap(up,north);
		swap(north,down);
		swap(down,south);
	}else if(s=="Right"){
		swap(north,west);
		swap(west,south);
		swap(south,east);
	}else{
		swap(north,east);
		swap(east,south);
		swap(south,west);
	}
}


int main(){
	int n;
	while(cin>>n,n){
		int ans=1;
		north=5;
		west=4;
		east=3;
		south=2;
		up=1;
		down=6;
		while(n--){
			string s;
			cin>>s;
			turn(s);
			ans+=up;
		}
		cout<<ans<<endl;
	}
	return 0;
}


