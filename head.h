/***���Ժ�������**/
#define NUMBER 2//�Ա����ĸ���
#define NUM 2//Ŀ�����
#define NO 1//������������
#define LOWER 0//Ŀ��Ŀ�����
#define UPPER 1//Ŀ��Ŀ�����
/**ϵͳ����**/
#define nPop 100//��Ⱥ��������
#define nArchive 100//������Ⱥ��������
#define GEN  300//��������
#define LENGTH 20//����
#define Pc 0.8   //���ʲ���
#define Pm 0.1//���ʲ���
/**********************************/
/**********************************/
double population[nPop+nArchive][NUMBER] = { 0 };//��ʼ��Ⱥ
double archive[nArchive][NUMBER] = { 0 };//������Ⱥ
double temp[nPop+nArchive][NUMBER] = { 0 };//��ʱ��Ⱥ
double popTriple[nPop+nArchive][NUM] = { 0 };//��ʼ��Ⱥ����
double arcTriple[nArchive][NUM] = { 0 };//������Ⱥ����
double tempTriple[nPop+nArchive][NUM] = { 0 };//��ʱ��Ⱥ����
double popFit[nPop+nArchive] = { 0 };//��Ⱥ��Ӧ��ֵ
double arcFit[nArchive] = { 0 };//������Ⱥ��Ӧ��ֵ
double tempFit[nPop+nArchive] = { 0 };//��ʱ��Ⱥ��Ӧ��ֵ
int cur_pop=0;//��ǰ�������
double SIGMA[nPop+nArchive][nPop+nArchive]={0};//�������
double tempSIGMA[nPop+nArchive][nPop+nArchive]={0};//��ʱ�������
int pp=0;//���ѽضϳ���Ĵ���
double step =0;//���ȶ�Ӧ�Ĳ���
double DERTA =0;//�Ա������
#define EPS 1e-8//����С��
#define INF 9999999999//����С��