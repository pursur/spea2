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
#include"head.h"//����ͷ�ļ�
#include"init_fun.h"//ZDT����ͷ�ļ�
#include"init1.h"//ZDT����ͷ�ļ�
#include"init2.h"//GA��������
#include"init3.h"//SPEA��������
#include"init4.h"//��������
void main()
{
	ABOUT();
	clock_t start=clock();		//����ʼ��ʱ
	srand(time(NULL));//�����������
	DERTA=UPPER-LOWER;
	step=DERTA/(pow((double)2,LENGTH));
	/***/
	test();
	/**************/
	clock_t end=clock();		//���������ʱ
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"������ʱ:"<<endtime<<"s"<<endl;		//sΪ��λ
}