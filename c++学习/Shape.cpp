#include<iostream>
using namespace std;

//基类
class Shape
{
	public:
		void setWidth(int w)
		{
			width = w;
		}
		void setHeight(int h)
		{
			height = h;
		}
protected:
	int width;
	int height;
};

//基类	PaintCost
class PaintCost
{
public:
	int getCost(int area)
	{
		return area * 70;
		}
};

//派生类
//派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。

//我们可以根据访问权限总结出不同的访问类型
class Rectangle :public Shape,public PaintCost
{
public:
	int getArea()
	{
		return (width * height);
	}
};
int main(void)
{
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(7);

	area = Rect.getArea();

	//输出对象的面积
	cout << "Total area:" << Rect.getArea() << endl;

	//输出总费用
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;
	return 0;
}
