#include<stdio.h>
#include<math.h>
int main(){
    long long int x,y;
    long long int i,j;
    while(scanf("%lld%lld",&i,&j),i){
        x=i,y=j;
        while((i!=0)&&(j!=0)){
            if(i>j){
                i=i%j;
            }else{
                j=j%i;
            }
        }
        if(i==0){
            y=x*y/j;
            x=j;
        }else{
            y=x*y/i;
            x=i;
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}