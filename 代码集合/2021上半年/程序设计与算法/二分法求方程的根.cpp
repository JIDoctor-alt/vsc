#include <iostream>
#include<iomanip>
#include<math.h>
#define EPS 1e-6  //注意阈值的设置精确到浮点数
using namespace std;
double a3,a2,a1,a0;
double a,b;
double f(double x){
	return a3*pow(x,3)+a2*pow(x,2)+a1*pow(x,1)+a0;
}
int main(){	
	cin>>a3>>a2>>a1>>a0;
	cin>>a>>b;
	double mid;
    //在给定区间内查找
	while(b - a > EPS){
		 mid = (b + a)/2;//区间正中的元素
		if(f(mid)*f(a) > EPS)//如果mid 和 左端点a同号 区间取右半边
			 a = mid;
		else if(f(mid) == EPS) //函数值为0
			break;
        else   //如果mid 和右端点同号  区间取左半边
			b = mid;
	}
	cout<<fixed<<setprecision(2)<<mid;
	return 0;
}