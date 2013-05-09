#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
using namespace std;

class union_find{
private:
	vector<int> parents;
	vector<int> rank;
	vector<int> weight;
public:
	union_find(int n){
		for(int i=0;i<n;i++){
			parents.push_back(i);
			rank.push_back(0);
			weight.push_back(0);
		}
	}
	int find(int x){
		if(parents[x]==x){
			return x;
		}else{
			int tmp=find(parents[x]);
			weight[x]=weight[x]+weight[parents[x]];
			return parents[x]=tmp;
		}
	}
	void unite(int x,int y,int w){
		int tmpx=find(x);
		int tmpy=find(y);
		if(tmpx==tmpy)return;
		if(rank[tmpx]<rank[tmpy]){
			weight[tmpx]=w-weight[x]+weight[y];
			parents[tmpx]=tmpy;
		}else{
			weight[tmpy]=-w-weight[y]+weight[x];
			parents[tmpy]=tmpx;
			if(rank[tmpx]==rank[tmpy])rank[tmpx]++;
		}
	}
	int get_weight(int x,int y){
		if(find(x)==find(y)){
			return weight[x]-weight[y];
		}else{
			return -2000000;
		}
	}
};
int main(){
	char c;
	int a,b,w;
	int n,m;
	while(cin>>n>>m,n!=0||m!=0){
		union_find uf(n+1);
		for(int i=0;i<m;i++){
			cin>>c;
			if(c=='!'){
				cin>>a>>b>>w;
				uf.unite(a,b,w);
			}else if(c=='?'){
				cin>>a>>b;
				int tmp=uf.get_weight(a,b);
				if(tmp!=-2000000){
					cout<<tmp<<endl;
				}else{
					cout<<"UNKNOWN"<<endl;
				}
			}
		}
	}
}