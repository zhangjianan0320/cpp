/*************************************************************************
    > File Name: new.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月25日 星期一 18时09分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(void)
{
	//使用new 创建的是一个对象，删除内存的时候需要使用delete函数调用析构函数处理，malloc函数只是申请了空间
	int *array=new int [5];
	for(int i=0;i<5;i++)
	{
		*(array+i) = i;
		cout<<"array["<<i<<"]="<<*(array+i)<<endl;
	}
	delete [] array;
	return 0;
}
