/*************************************************************************
    > File Name: file.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年05月25日 星期一 16时40分38秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main()
{
	const char *filename = "out.dat";
	char data[512];

	ofstream outfile;
	//第一个参数为文件名字，第二个参数为打开模式 ios::app追加模式  ios::ate文件打开后定位到文件末尾 ios::in 读模式打开文件 iso::out写模式打开文件 ios::trunc如果文件已存在，则设置文件长度为0
	outfile.open(filename);

	cout<<"write to file"<<endl;
	cout<<"enter your name:"<<endl;
	//cin.getline(字符指针char*，字符个数int，结束符char) 默认回车为结束符
	cin.getline(data,sizeof(data));

	outfile<<data<<endl;

	cout<<"enter your age:"<<endl;
	cin>>data;
	cin.ignore();

	outfile<<data<<endl;
	outfile.close();

	ifstream infile;
	infile.open(filename);

	cout<<"reading from "<<filename<<endl;
	infile>>data;
	cout<<data<<endl;
	infile>>data;
	cout<<data<<endl;

	infile.close();

//	system("cat out.dat");
	return 0;
}
