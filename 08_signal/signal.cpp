/*************************************************************************
    > File Name: signal.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年06月01日 星期一 10时58分58秒
 ************************************************************************/

#include<iostream>
#include<csignal>
#include<unistd.h>
#include<stdlib.h>

using namespace std;
//中断信号处理函数
void signalHandler(int signum)
{
	cout<<"Interrupt signal ("<<signum<<")recived.\n";

	exit(signum);
}

int main()
{
	//注册信号
	signal(SIGINT,signalHandler);

	int i = 0;
	while(++i)
	{
		if(i>=3)
		{
			//生成一个 SIGINT 信号
			raise(SIGINT);
		}
		cout << " Going to sleeep..."<<endl;
		sleep(1);
	}

	return 0;
}
