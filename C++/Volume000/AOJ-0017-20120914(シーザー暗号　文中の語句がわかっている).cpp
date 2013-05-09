#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main(){
	
	char s[1000];
	while(cin.getline(s,1000)){
		for(int i=0;s[i]!='\0';i++){
			if(((s[i]-s[i+1]+26)%26=='t'-'h')&&(((s[i+1]-s[i+2]+26)%26==('h'-'e'+26)%26)||(((s[i+1]-s[i+2]+26)%26==('h'-'i'+26)%26)&&((s[i+2]-s[i+3]+26)%26==('i'-'s'+26)%26))||(((s[i+1]-s[i+2]+26)%26==('h'-'a'+26)%26)&&((s[i+2]-s[i+3]+26)%26==('a'-'t'+26)%26)))){
				for(int j=0;s[j]!='\0';j++){
					if((s[j]!=' ')&&(s[j]!='.')&&(s[j]!='\n')){
						putchar((s[j]+'t'-s[i]-'a'+26)%26+'a');
					}else{
						putchar(s[j]);
					}
				}cout<<endl;
				break;
			}
		}
	}
	return 0;
}