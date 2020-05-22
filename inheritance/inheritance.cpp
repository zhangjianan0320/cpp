/*************************************************************************
    > File Name: inheritance.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月22日 星期五 17时46分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Shape
{
	public:
		void setWidth(int w)
		{
			width = w;
		};
		void setHeight(int h)
		{
			height = h;
		};
	protected:
		int width;
		int height;
};

class Rectangle:public Shape
{
	public:
		int getArea()
		{
			return width*height;
		}
};

int main(void)
{
	Rectangle rect;

	rect.setWidth(3);
	rect.setHeight(5);

	cout<<"area is "<<rect.getArea()<<endl;

	return 0;
}
