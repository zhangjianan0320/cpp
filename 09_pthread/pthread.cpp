/*************************************************************************
    > File Name: pthread.cpp
    > Author: zjn
    > Mail:zjn 
    > Created Time: 2020年06月01日 星期一 11时23分39秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<thread>
using namespace std;

#define NUM_THREADS	5
#if 0
//编译的时候必须g++ -std=c++11
void *PrintHello(int id)
{
	printf("pthread %d start\n",id);
	sleep(id);
	printf("pthread %d end\n",id);
	//退出线程
	long long ack = id;	//64位系统 地址的长度是64，为了与返回值保持一致，因此定义成long long型
	// 此处两种退出方式都会把参数传出去，通过pthrea_join函数获取到
	pthread_exit((void*)(ack));
//	return (void*)ack;
}

int main(int argc, const char** argv) {

// 假设buy是一个可调用的函数对象，它即可能是函数指针，也可能是函数对象
//std::thread Annie(buy);
// Annie会去执行buy()
//std::thread Bob(buy, book, food);
// Bob会去执行buy(book, food)
 
// 假设buy是Consumer的一个可调用的成员函数
//Consumer Clara;
//std::thread action(buy, Clara, phone);
// Clara会去执行Consumer.buy(phone)

	std::thread thread0(PrintHello,0); 
	std::thread thread1(PrintHello,1); 
	std::thread thread2(PrintHello,2); 
	std::thread thread3(PrintHello,3); 
	std::thread thread4(PrintHello,4);
//剥离后执行子线程
	thread0.detach();
	thread1.detach();
	thread2.detach();
	thread3.detach();
	thread4.detach();
/*
//顺序执行子线程
	thread0.join();
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
*/
	pthread_exit(NULL);
}
#endif
#if 1
void *PrintHello(void *threadid)
{
	int id = *((int *)threadid);
	//cout<<"pthread id is "<<id<<endl;
	printf("pthread %d start\n",id);
	sleep(id);
	//cout<<"pthread id is "<<id <<"out"<<endl;
	printf("pthread %d end\n",id);
	//退出线程
	long long ack = id;	//64位系统 地址的长度是64，为了与返回值保持一致，因此定义成long long型
	// 此处两种退出方式都会把参数传出去，通过pthrea_join函数获取到
	pthread_exit((void*)(ack));
//	return (void*)ack;
}
int main()
{
	//使用c函数的方式实现
	pthread_t threads[NUM_THREADS];
	int index[NUM_THREADS];
	int rc,i;

	for(i=0;i<NUM_THREADS;i++)
	{
		index[i]=i;
		//创建线程
		rc = pthread_create(&threads[i],NULL,PrintHello,(void *)&index[i]);

		if(rc)
		{
			cout<<"error create pthread "<<i<<endl;
			exit(-1);
		}
#if 1
		//释放该块代码对顺序执行每一个子线程
		void *status=NULL;
		//可以保证每个子线程执行完之后再执行下一个子线程
		pthread_join(threads[i],&status);
		//if(status!=NULL)
		{
			int ack = (int)(long long)status;
			printf("ack is %d\n",ack);
		}
#endif
	}
	//pthread_exit 一般子线程调用，用于结束当前线程 pthread_joio 一般主线程调用，用来等待子线程退出，因为是等待，所以书阻塞的，一般主线程会一次joio所有他创建的子线程，pthread_exit可以传递一个返回值，而主线程可以通过pthread_join获取该返回值，从而判断子线程的退出是正常还是异常
	printf("pthread_exit is end\n");
	pthread_exit(NULL);
	//pthread_exit 为直接退出当前进程，return则为退出当前函数，不一定退出当前进程，g++编译器中main中的return会被自动优化为exit，所以主函数中调用return会退出所有线程的运行
	//pthread_exit只会使主线程自身退出，产生的子线程会继续执行，使用return则多有线程退出
	//为了保证子线程总能完整执行，1、主线程中调用pthread_join对齐等待；2、主线程中使用pthread_exit只退出主线程；3、通过逻辑保证子线程不会比子线程先退出；
	sleep(10);
	printf("main is end\n");
	return 0;
}
#endif
