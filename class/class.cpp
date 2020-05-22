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
		Box(void){};//不带参数的构造函数
		//拷贝构造函数
		Box(const Box &obj);
		//析构函数 名字与class一样，但是要在前边加波浪号
		~Box(void);
	//private 外部不能直接访问，但是class内部的函数可以访问
	private:
		char name[512];
	//protected 外部不能直接访问，但是子孙类可以访问
	protected:
		int class_type;
	//友元函数
	friend void printName(Box &box);
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
//	printf("Box::Box\n");
}
//使用现有对象创建对象的时候会调用拷贝构造函数
//1、可以读取出相同类对象的私有成员数据
//2、实质：把对象的数据复制到新的对象中
//3、构造函数的一种重载
//4、在用户没有定义拷贝函数的时候，系统会默认自动生成拷贝函数，默认的拷贝函数能够满足大多数的需求，所以，一般不需要用户自定义
//5、使用默认拷贝构造函数的时候，则会得到的对象存储空间地址会与原对象一致，在编写深拷贝构造函数时，为新的对象也申请堆，内存空间，并把原对象的数据复制过来
Box::Box(const Box &obj)
{
//	cout<<"调用拷贝构造函数"<<endl;
	this->length = obj.length;
	this->breadth = obj.breadth;
	this->height = obj.height;
}
//析构函数 没有入参和返回值
Box::~Box(void)
{
//	printf("Box::~Box\n");
}
int Box::setName(const char *str)
{
	//name 为class private变量，但是在class内的函数是可以直接调用的，但是其他地方则无法直接调用
	strcpy(name,str);
}

int Box::getName(char *str)
{
	strcpy(str,name);
	cout<<"name is "<<str<<endl;
}
/*
*友元函数是定义在类外部，但是有权访问类的所有私有 保护成员，尽管友元函数的原型在类的定义中出现过，但是友原函数并不是成员函数
* 友元函数也可以是一个类，该类被称为友元类，整个类及所有成员都是友元
* 定义友元类 使用关键字 friend
*/
void printName(Box &box)
{
	printf("frined name is %s\n",box.name);		//直接使用参数，不需要考虑变量的属性,都可以直接访问
	//printf("friend breadth is %f\n",box.breadth);
	
}

/*
 *内联函数：通常与类一起使用，引入内联函数的目的就是为了解决程序中函数调用的效率问题，程序在编译器编译的时候，编译器将程序中出现的内联函数的调用表达式用内联函数的函数体进行替换
 *，而对于其他函数，都是在运行的时候才被替代，这其实就是个空间代替时间的节省，所以内联函数一般都是1-10行的小函数，在使用内联函数的时候需要注意一下几点：
 *	1、在内联函数内不允许使用循环语句和开关语句；
 *	2、内联函数的定义必须出现在内联函数第一次调用之前；
 *	3、类结构中所在的类说明内部定义的函数是内联函数；
 */
inline int Max(int a,int b) 
{
	return (a>b) ? a : b;
}

int main()
{
	Box box1(1,2,3);
	Box box2;

	box1.printAll();
	box2.printAll();

	box1.height = 100;
	box2.height = 200;

	char name[512];
	box1.getName(name);
	box1.setName("sencond name");
	box1.getName(name);

	printName(box1);
	box2.getName(name);
	printName(box2);

	Box box3 = box1;
	box3.printAll();

	return 0;
}
