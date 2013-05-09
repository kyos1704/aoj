#include<stdio.h>
#include<bitset>
int n,tmp,ans=0;
int main(){
	std::bitset<32000000> list;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		list[tmp]=1;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		ans+=list[tmp];
	}
	printf("%d\n",ans);
	return 0;
}