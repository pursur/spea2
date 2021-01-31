#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <memory>
#include <string>
#include <random>
using namespace std;
#include"head.h"//参数头文件
#include"init_fun.h"//ZDT函数头文件
#include"init1.h"//ZDT函数头文件
#include"init2.h"//GA操作算子
#include"init3.h"//SPEA操作算子
#include"init4.h"//测试算子
void main()
{
	ABOUT();
	clock_t start=clock();		//程序开始计时
	srand(time(NULL));//启用随机种子
	DERTA=UPPER-LOWER;
	step=DERTA/(pow((double)2,LENGTH));
	/***/
	test();
	/**************/
	clock_t end=clock();		//程序结束用时
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"程序用时:"<<endtime<<"s"<<endl;		//s为单位
}