#include <cmath>
#include <complex>
#include <vector>
#include <cfloat>
#include <algorithm>
#include <iostream>
using namespace std;


///////////////////////
//�񎟌��􉽃e���v���[�g
//�_�N���X point->x,y
//�����N���X line->s,v
//
class point;
class line;
point vec_add(point vec1,point vec2);//�x�N�g���̑����Z
point vec_sub(point vec1,point vec2);//�x�N�g���̈����Z
double inner_product(point a,point b);//����
double outer_product(point a,point b);//�O��
bool vec_parallel(point vec1,point vec2);//�x�N�g���̕��s����(��������false�Ƃ��Ă��g����)
bool vec_angle_right(point vec1,point vec2);//�x�N�g���̒��s����
bool cross_line_segment(line a,point p1,point p2);//�����Ɛ����̌�������
//
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
///////////////////////


int main(){
	point a[4];
	while(cin>>a[0].x>>a[0].y){
		for(int i=1;i<4;i++){
			cin>>a[i].x>>a[i].y;
		}
		bool f=vec_angle_right(vec_sub(a[0],a[1]),vec_sub(a[2],a[3]));
		if(f){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
//////////////////////////


//���p�`(���_��ێ�����)
typedef vector<point> polygon;

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


//�x�N�g���̕��s����
bool vec_parallel(point vec1,point vec2){
	if(outer_product(vec1,vec2)==0){
		return true;
	}else{
		return false;
	}
}
//�x�N�g���̒��𔻒�
bool vec_angle_right(point vec1,point vec2){
	if(inner_product(vec1,vec2)==0){
		return true;
	}else{
		return false;
	}
}

bool cross_line_segment(line l,point p1,point p2){
	p1=vec_sub(p1,l.s);
	p2=vec_sub(p2,l.s);
	if(outer_product(p1,l.v)*outer_product(p2,l.v)<0){
		return true;
	}else{
		return false;
	}
}



//
