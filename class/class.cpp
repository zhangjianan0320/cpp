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
	//private 外部不能直接访问，但是class内部的函数可以访问
	private:
		char name[512];
	//protected 外部不能直接访问，但是子孙类可以访问
	protected:
		int class_type;
};

int Box::setName(const char *str)
{
	//name 为class private变量，但是在class内的函数是可以直接调用的，但是其他地方则无法直接调用
	strcpy(name,str);
}

int Box::getName(char *str)
{
	strcpy(str,name);
	cout<<"name is"<<name<<endl;
}

int main()
{
	Box box1;
	Box box2;

	box1.height = 100;
	box2.height = 200;

	cout<<"box1 is "<<box1.height<<endl;
	cout<<"box2 is "<<box2.height<<endl;

	char name[512];
	box1.getName(name);
	box1.setName("sencond name");
	box1.getName(name);

	return 0;
}
