#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n,tmp,ans=0;
vector<int> list;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		list.push_back(tmp);
	}
	sort(list.begin(),list.end());
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		ans+=binary_search(list.begin(),list.end(),tmp);
	}
	printf("%d\n",ans);
	return 0;
}