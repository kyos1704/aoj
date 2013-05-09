#include <stdio.h>
int main(){
    double a,b,c,d,e,f;
    double x,y;
    while((scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f))!=EOF){
        y=(c*d-a*f)/(b*d-a*e);
        x=(c-b*y)/a;
        printf("%0.3lf %0.3lf\n",x,y);
    }
    return 0;
}