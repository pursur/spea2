/***测试函数参数**/
#define NUMBER 2//自变量的个数
#define NUM 2//目标个数
#define NO 1//函数测试例子
#define LOWER 0//目标目标个数
#define UPPER 1//目标目标个数
/**系统参数**/
#define nPop 100//种群数量参数
#define nArchive 100//档案种群数量参数
#define GEN  300//迭代次数
#define LENGTH 20//精度
#define Pc 0.8   //概率参数
#define Pm 0.1//概率参数
/**********************************/
/**********************************/
double population[nPop+nArchive][NUMBER] = { 0 };//初始种群
double archive[nArchive][NUMBER] = { 0 };//档案种群
double temp[nPop+nArchive][NUMBER] = { 0 };//临时种群
double popTriple[nPop+nArchive][NUM] = { 0 };//初始种群代价
double arcTriple[nArchive][NUM] = { 0 };//档案种群代价
double tempTriple[nPop+nArchive][NUM] = { 0 };//临时种群代价
double popFit[nPop+nArchive] = { 0 };//种群适应度值
double arcFit[nArchive] = { 0 };//档案种群适应度值
double tempFit[nPop+nArchive] = { 0 };//临时种群适应度值
int cur_pop=0;//当前个体个数
double SIGMA[nPop+nArchive][nPop+nArchive]={0};//距离矩阵
double tempSIGMA[nPop+nArchive][nPop+nArchive]={0};//临时距离矩阵
int pp=0;//唤醒截断程序的次数
double step =0;//精度对应的步长
double DERTA =0;//自变量宽度
#define EPS 1e-8//无穷小量
#define INF 9999999999//无穷小量