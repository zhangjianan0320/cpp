/*************************************************************************
    > File Name: mul_form.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月25日 星期一 14时07分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Shape{
	protected:
		int width,height;
	public:
		Shape(int w,int h)
		{
			width = w;
			height = h;
		}
//虚函数，派生类继承时可以不重写该函数
/*		virtual int area()
		{
			cout<<"Parent class area:"<<endl;
			return 0;
		}
*/
//纯虚函数，派生类中必须重写，否则派生类也是个虚基类，而虚基类不能定义对象
		virtual int area() =0;
};

class Rectange:public Shape
{
	public:
		Rectange(int w=0,int h=0):Shape(w,h){};
		int area()
		{
			cout<<"rectange area is "<<width*height<<endl;
			return width*height;
		}
};

class Triangle:public Shape
{
	public:
		Triangle(int w,int h):Shape(w,h){};
		int area()
		{
			cout<<"Triangle area is "<<width*height/2<<endl;
			return width*height/2;
		}
};

int main()
{
	Rectange rec(2,2);
	Triangle tri(2,2);

	rec.area();
	tri.area();
//	如果要使如下的调用方式，需要设置 20行为虚函数  virtual int area()  纯虚函数不可以这么使用
/*
	Shape *shape;
	shape = &rec;
	shape->area();

	Shape temp(5,5);
	temp.area();
*/
}
