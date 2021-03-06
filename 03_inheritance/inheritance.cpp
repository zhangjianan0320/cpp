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

class PaintCost
{
	public:
		int getCost(int area)
		{
			return area*70;
		}
};
/*
 *	类			public	protected	private
 * 同一类		yes		yes			yes
 * 派生类		yes		yes			no
 * 外部的类		yes		no			no
 *
 *
 * 基类的构造函数，析构函数，拷贝函数、基类的重载运算符、友元函数等不会被继承
 *
 *继承类型：public 公有成员还是公有的，保护的还是保护的，私有不继承
 *保护类型：protected 共有的 保护的全部转化为保护的
 *私有类型：private 所有的都变为私有
 *
*/
class Rectangle:public Shape,public PaintCost
{
	public:
		int getArea()
		{
			return width*height;
		}
};
/*
 *虚继承 virtual 
 *是为了处理多继承（环状继承问题的）
 *class D{};
 *class B:public D{};
 *class A:public D{};
 *class C:public A,public B{};
 *此时C包含了两份D的内容
 *
 *class D{};
 *class B:virtual public D{};
 *class A:virtual public D{};
 *class C:public A,public B{};
 *使用虚继承可以避免C包含两份D内容，但是实际使用的时候要避免出现多继承或环状继承的问题
 * */

int main(void)
{
	Rectangle rect;

	rect.setWidth(3);
	rect.setHeight(5);

	cout<<"area is "<<rect.getArea()<<endl;
	cout<<"areaCost is "<<rect.getCost(10)<<endl;

	return 0;
}
