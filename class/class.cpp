/*************************************************************************
    > File Name: cass.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月21日 星期四 10时51分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

/*
*1、c的struct与class的区别：struct只是作为一种复杂数据类型的定义，struct只能定义数据成员，不能定义成员函数（但是可以通过函数指针实现），不能面向对象编程
*2、c++中的struct与class的区别
*	a：默认的继承权限 struct默认public的，class默认时private的
*	b：struct作为数据结构的实现体，默认的数据访问控制时public的，而class作为对象的实现体，他的默认成员变量访问控制时private
*	c：class这个关键字还用于定义模板参数，就像typename，但关键字不用于定义模板参数
*/

/*
 * 作用域		当前类	同一package	子孙类	其他package  
 * public		  是		是		 是			是
 * protected	  是		是		 是			否
 * friendly		  是		是		 否			否		//如果没有定义类型，则默认为friendly
 * private		  是		否		 否			否
 * */

class Box
{
	//public 外部可以直接访问的变量或函数
	public:
		double length;
		double breadth;
		double height;
		int setName(const char *str);
		int getName(char *str);
		int printAll(void)
		{
			//对象创建的时候会创建一个特殊的指针  this ，指向对象本身
			printf("length is %f\n",this->length);
			printf("breadth is %f\n",this->breadth);
			printf("height is %f\n",this->height);
		};
		//构造函数 名字与class一样  创建class的时候默认调用，主要初始化变量 构造的时候也可以不带参数
		Box(double a,double b,double c);
		//析构函数 名字与class一样，但是要在前边加波浪号
		~Box(void);
	//private 外部不能直接访问，但是class内部的函数可以访问
	private:
		char name[512];
	//protected 外部不能直接访问，但是子孙类可以访问
	protected:
		int class_type;
};
//构造函数 冒号后边的类似于直接定义名字与以下的注释效果一致
// 使用的时候要注意顺序，初始化的时候是按照声明的顺序初始化的，而不是按照初始化列表中的顺序
//Box::Box(double a,double b,double c)
//{
//	length = a;
//	breadth = b;
//	height = c;
//}
Box::Box(double a,double b,double c):length(a),breadth(b),height(c)
{
	printf("Box::Box\n");
}
//析构函数 没有入参和返回值
Box::~Box(void)
{
	printf("Box::~Box\n");
}
int Box::setName(const char *str)
{
	//name 为class private变量，但是在class内的函数是可以直接调用的，但是其他地方则无法直接调用
	strcpy(name,str);
}

int Box::getName(char *str)
{
	strcpy(str,name);
//	cout<<"name is"<<name<<endl;
}

int main()
{
	Box box1(1,2,3);
	Box box2(4,5,6);

	box1.printAll();
	box2.printAll();

	box1.height = 100;
	box2.height = 200;

	char name[512];
	box1.getName(name);
	box1.setName("sencond name");
	box1.getName(name);

	return 0;
}
