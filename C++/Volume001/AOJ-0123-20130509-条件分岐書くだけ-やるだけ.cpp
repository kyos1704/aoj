#include<iostream>
using namespace std;
/*

男子   500M  1000M
AAA級  35秒50  1分11秒00
AA級   37秒50  1分17秒00
A級  40秒00  1分23秒00
B級  43秒00  1分29秒00
C級  50秒00  1分45秒00
D級  55秒00  1分56秒00
E級 1分10秒00 2分28秒00

*/

int main(){
  double a,b;
  while(cin>>a>>b){
    if(a<35.5 && b<71){
      cout<<"AAA"<<endl;
    }else if(a<37.5 && b<77){
      cout<<"AA"<<endl;
    }else if(a<40 && b<83){
      cout<<"A"<<endl;
    }else if(a<43 && b<89){
      cout<<"B"<<endl;
    }else if(a<50 && b<105){
      cout<<"C"<<endl;
    }else if(a<55 && b<116){
      cout<<"D"<<endl;
    }else if(a<70 && b<148){
      cout<<"E"<<endl;
    }else{
      cout<<"NA"<<endl;
    }
  }
}
