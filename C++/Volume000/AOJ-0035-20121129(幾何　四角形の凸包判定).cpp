#include <cmath>
#include <complex>
#include <vector>
#include <cfloat>
#include <algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
class point;
class line;
point vec_add(point vec1,point vec2);//�x�N�g���̑����Z
point vec_sub(point vec1,point vec2);//�x�N�g���̈����Z
double inner_product(point a,point b);//����
double outer_product(point a,point b);//�O��
bool vec_parallel(point vec1,point vec2);//�x�N�g���̕��s����(��������false�Ƃ��Ă��g����)
bool vec_angle_right(point vec1,point vec2);//�x�N�g���̒��s����
bool cross_line_segment(line a,point p1,point p2);//�����Ɛ����̌�������

class point{
public:
	double x,y;
	point(){
		x=0;
		y=0;
	}
	point(double a,double b){
		x=a;
		y=b;
	}
	void in(double a,double b){
		x=a;
		y=b;
		return ;
	}
};
//�����N���X
class line{
public:
	point s,v;
public:
	line(point a,point b){
		s=a;
		v=vec_sub(a,b);
	}
};
//�x�N�g���̑����Z
point vec_add(point vec1,point vec2){
	point res(vec1.x+vec2.x,vec1.y+vec2.y);
	return res;
}
//�x�N�g���̈����Z
point vec_sub(point vec1,point vec2){
	point res(vec1.x-vec2.x,vec1.y-vec2.y);
	return res;
}
//����
double inner_product(point a,point b){
	return a.x * b.x + a.y * b.y;
}
//�O��
double outer_product(point a,point b){
	return a.x * b.y - a.y * b.x;
}

point p[6];

bool solve(){
	bool judge;
	bool ans;
	if(outer_product(p[0],p[1])>0){
		judge=true;
	}else{
		judge =false;
	}
	for(int i=1;i<4;i++){
		if(outer_product(p[i],p[i+1])>0){
			if(judge!=true) return false;
		}else if(outer_product(p[i],p[i+1])==0){
			return false;
		}else{
			if(judge!=false) return false;
		}
	}
	return true;
}



int main(){
	
	
	while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y)!=EOF){
		p[4]=p[0];
		p[5]=p[1];
		for(int i=0;i<5;i++){
			p[i]=vec_sub(p[i],p[i+1]);
		}
		bool ans=solve();
		
		if(ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
}