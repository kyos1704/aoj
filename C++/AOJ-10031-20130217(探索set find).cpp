#include<stdio.h>
#include<set>
using namespace std;

int n,tmp,ans=0;
set<int> list;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		list.insert(tmp);
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(list.find(tmp)!=list.end()){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}