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

class Box
{
	public:
		void setLength(int l){
			length = l;
		};
		int getLength(void){
			return length;
		};
		void print(){
			cout<<"length "<<length<<endl;
		}
		Box(int l){
			length = l;
			num = ++count;
			cout<<"creat "<<num<<endl;
		}
		Box(){num=++count;};
		~Box(){
			cout<<"delete "<<num<<endl;
		}
		Box operator+ (const Box& b){
			//测试发现，在该地方申请的box，在计算完成后便被销毁了，同时参数会全部覆盖返回值，达到将计算结果传递出去的目的，这样操作的内部逻辑不是很清除？
			Box box;
			box.setLength( this->length + b.length);

			return box;
		};
		static int count;
	private:
		int num;
		int length;
};
int Box::count=0;
void test()
{
	Box temp;
	return ;
}
int main(void)
{
	printData pd;
/*
	// 函数重载
	pd.print(10);
	//cpp中的小数默认是double的，因此需要强转一下
	pd.print((float)1.34);
	pd.print((char *)"hello cpp");
*/
//符号重载
	Box box1(10);
	Box box2(5);
	Box box3;
	box3.print();
	box3 = box1+box2;
	cout<<"calc end"<<endl;
	box3.print();

	return 0;
}
