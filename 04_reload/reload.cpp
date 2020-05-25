/*************************************************************************
    > File Name: reload.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月25日 星期一 10时06分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

class printData
{
	public:
		//三个名字一样的函数，调用的时候根据入参自动调用适配的函数,该功能叫做函数重载
		void print(int i){
			cout<<"int i = "<<i<<endl;
		};
		void print(float f){
			cout<<"float f = "<<f<<endl;
		};
		void print(char *c){
			cout<<"char c = "<<c<<endl;
		};
};

int main(void)
{
	printData pd;

	pd.print(10);
	//cpp中的小数默认是double的，因此需要强转一下
	pd.print((float)1.34);
	pd.print((char *)"hello cpp");

	return 0;
}
