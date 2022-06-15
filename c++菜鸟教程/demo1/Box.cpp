#include<iostream>

using namespace std;

class Box{
 public:
    double length;//长度
    double breadth;//宽度
    double height;//高度
    //成员函数声明
    double get(void);
    void set(double len,double bre,double hei);
};
//成员函数定义
double Box::get(void)
{
    return length * breadth * height;
}
void Box::set(double len,double bre,double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

int main()
{
    Box Box1;//声明Box1,类型Box
    Box Box2;//声明Box2,类型Box
    Box Box3;//声明Box3,类型Box
    double volume = 0.0;//用于存储体积


    //box1详情
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    //box2 详述
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    //box1 的体积
    volume = Box1.height * Box1.length * Box1.breadth;
    cout<<"Box1的体积："<<volume<<endl;
}