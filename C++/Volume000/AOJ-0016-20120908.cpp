#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	double x,y,s;
	int n,k;
	x=y=s=0;
	while((scanf("%d,%d",&n,&k)),n!=0){
		x=x+n*cos(M_PI*s/180);
		y=y+n*sin(M_PI*s/180);
		s=s+k;
	}
	printf("%d\n%d\n",int(y),int(x));
}