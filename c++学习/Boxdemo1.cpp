#include<iostream>
using namespace std;

class Boxdemo1
{
public:
	double getVolume(void)
	{
		return length * breadth * height;
	}
	void setLength(double len)
	{
		length = len;
	}
	void setBreadth(double bre)
	{
		breadth = bre;
	}
	void setHeight(double hei)
	{
		height = hei;
	}
	//重载 + 运算符，用于把两个Boxdemo1对象相加
	Boxdemo1 operator+(const Boxdemo1& b)
	{
		Boxdemo1 box;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}
private:
	double length;//长度
	double breadth;//宽度
	double height;//高度
};
//程序的主函数
int main()
{
	Boxdemo1 box1;
	Boxdemo1 box2;
	Boxdemo1 box3;
	double volume = 0.0; //把体积存到该变量中

	//Box1详述
	box1.setLength(6.0);
	box1.setBreadth(7.0);
	box1.setHeight(5.0);

	//Box1详述
	box2.setLength(12.0);
	box2.setBreadth(13.0);
	box2.setHeight(10.0);

	//Box1的体积
	volume = box1.getVolume();
	cout << "Volume of Box1 :" << volume << endl;

	//Box2的体积
	volume = box2.getVolume();
	cout << "Volumen of Box2:" << volume << endl;

	//把两个对象相加，得到Box3
	box3 = box1 + box2;

	//box3的体积
	volume = box3.getVolume();
	cout << "Volume of Box3:" << volume << endl;

	return 0;
}
