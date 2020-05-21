/*************************************************************************
    > File Name: cass.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月21日 星期四 10时51分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Box
{
	public:
		double length;
		double breadth;
		double height;
};

int main()
{
	Box box1;
	Box box2;

	box1.height = 100;
	box2.height = 200;

	cout<<"box1 is "<<box1.height<<endl;
	cout<<"box2 is "<<box2.height<<endl;

	return 0;
}
