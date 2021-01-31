bool judge(const double p)
{
	double se = rand() / (double)(RAND_MAX);//随机产生0-1的小数
	if (p>se)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void double2bin(const double x,int y[LENGTH])
{
	int p=(x-LOWER)/step;//BU
	for (int i=0;i<LENGTH;i++) 
	{ 
		y[LENGTH-1-i]=0;
		y[LENGTH-1-i]=(p&1);
		p>>=1;
	}
}
double bin2double(int y[])
{
	int p=0;
	for (int i=0;i<LENGTH;i++) 
	{ 
		p=(p<<=1)+y[i]; 
	}
	return LOWER+p*step;
}
int selection(const double fit[],const int size)
{
	int p1=rand() % (size);
	int p2=rand() % (size);
	return p1?p2:fit[p1]<fit[p2];
}
void matution(const int y[LENGTH],int o[LENGTH])
{
	memcpy(o,y,sizeof(int)*LENGTH);
	if(judge(Pm))
	{
		int p=rand() % (LENGTH);
		if(y[p]==0)
		{
			o[p]=1;
		}
		else{
			o[p]=0;
		}
	}
	
}

void cross(const int y1[LENGTH],int o1[LENGTH],const int y2[LENGTH],int o2[LENGTH])
{
	memcpy(o1,y1,sizeof(int)*LENGTH);
	memcpy(o2,y2,sizeof(int)*LENGTH);
	if(judge(Pc))
	{
		int p=rand() % (LENGTH);
		for(int i=p;i<LENGTH;i++)
		{
			o1[i]=y2[i];
			o2[i]=y1[i];
		}
		
	}
}
void GA(int s1,int s2,int opt)
{
	for(int i=0;i<NUMBER;i++)
	{
		int y1[LENGTH];
		int y2[LENGTH];
		double2bin(archive[s1][i],y1);
		double2bin(archive[s2][i],y2);
		int o1[LENGTH];
		int o2[LENGTH];
		cross(y1,o1,y2,o2);
		int o3[LENGTH];
		int o4[LENGTH];
		matution(o1,o3);
		matution(o2,o4);
		population[opt][i]=bin2double(o3);
		population[opt+1][i]=bin2double(o4);
	}
}
