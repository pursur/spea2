bool dominates(double x[NUM],double y[NUM])
{
	for(int i=0;i<NUM;i++)
	{
		if(x[i]>y[i])
		{
			return false;
		}
	}
	for(int i=0;i<NUM;i++)
	{
		if(x[i]<y[i])
		{
			return true;
		}
	}
	return false;
}
void calFitness(double triple[][NUM],double fit[],int size)
{
	memset(SIGMA,0,sizeof(SIGMA));
	bool dom[nPop+nArchive][nPop+nArchive]={false};
	int S[nPop+nArchive]={0};
    for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(dominates(triple[i],triple[j]))
			{
				S[i]++;
				dom[i][j]=true;
			}
			else if(dominates(triple[j],triple[i]))
			{
				S[j]++;
				dom[j][i]=true;
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		fit[i]=0;
		for(int j=0;j<size;j++)
		{
			if(dom[j][i])
			{
				fit[i]+=S[j];
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		SIGMA[i][i]=0;
		for(int j=i+1;j<size;j++)
		{
			for(int k=0;k<NUM;k++)
			{
				SIGMA[i][j]+=((triple[i][k]-triple[j][k])*(triple[i][k]-triple[j][k]));
			}
			SIGMA[i][j]=sqrt(SIGMA[i][j]);
			SIGMA[j][i]=SIGMA[i][j];
		}
	}
	for(int i=0;i<size;i++)
	{
		sort(SIGMA[i],SIGMA[i]+size,greater<double>());
		fit[i]+=1/(SIGMA[i][size-(int)sqrt((double)(size))]+2);
	}
}
void sortIndex(const double fit[], int b[], int length)
{
	int i,j, t1;
	for(j=0; j<length; j++)
		for(i=0; i<length-1-j; i++)
			if(fit[b[i]]>fit[b[i+1]])
			{
				t1=b[i];
				b[i]=b[i+1];
				b[i+1]=t1;
			}
}
int min_index(double sigma[],int size)//计算群体Q中最小的距离
{
    //找出最小的距离
    int p=0;
    double min_d=INF;
    for(int i=0;i<size;i++)
    {
        if(sigma[i]<min_d)
        {
             min_d=sigma[i];
             p=i;
        }

    }
    // E_d_k[p]=INF;//把当前最小距离移除，使得后面不会再选
    return p;
}
bool isminmax(const double input[nPop+nArchive][nPop+nArchive],int row,int col)
{
	double min=EPS;
	double max=INF;
    int i;
    for(i=0;i<row;i++)
    {
		if(input[i][col]>max)
			max=input[i][col];
        if(input[i][col]<min)
			min=input[i][col];
    }
	if(abs(max-min)<EPS)
		return true;
	return false;
}
void truncation1(double fit_p[],double fit_a[],int size)
{
	int Qnum=0;
	memset(tempSIGMA,0,sizeof(tempSIGMA));
	int j=0;
	int index[nPop+nArchive];
	for(j=0;j<size;j++)
		index[j]=j;
	sortIndex(fit_p,index,size);
	if(fit_p[index[nArchive-1]]<1)//.3 .6 .5 9 9
	{
		pp++;
		for(int q=0;q<size&&fit_p[index[q]]<1;q++)
		{
			memcpy(temp[Qnum],population[index[q]],sizeof(double)*NUMBER);
			tempFit[Qnum] = fit_p[index[q]];//临时种群
			memcpy(tempTriple[Qnum],popTriple[index[q]],sizeof(double)*NUM);
			memcpy(tempSIGMA[Qnum],SIGMA[index[q]],sizeof(double)*cur_pop);
			Qnum++;
		}
		int k=1;
        while (Qnum>nArchive)
		{
			while(isminmax(tempSIGMA,Qnum,cur_pop)&&k<cur_pop)
				k++;
			int p=min_index(tempSIGMA[k],Qnum);
            for(int z=p+1; z<Qnum; z++)
			{
				memcpy(temp[z-1],temp[z],sizeof(double)*NUMBER);
				tempFit[z-1] = tempFit[z];//临时种群
				memcpy(tempTriple[z-1],tempTriple[z],sizeof(double)*NUM);
				memcpy(tempSIGMA[z-1],tempSIGMA[z],sizeof(int)*NUMBER);
			}
			Qnum--;
		}
		for(int j=0;j<nArchive;j++)
		{
			memcpy(archive[j],temp[j],sizeof(double)*NUMBER);
			memcpy(arcTriple[j],tempTriple[j],sizeof(double)*NUM);
			fit_a[j]=tempFit[j];
		}
	}
	else
	{
		for(j=0;j<nArchive;j++)
		{
			memcpy(archive[j],population[index[j]],sizeof(double)*NUMBER);
			memcpy(arcTriple[j],popTriple[index[j]],sizeof(double)*NUM);
			fit_a[j]=fit_p[index[j]];
		}
	}
}
void printPareto(double triple[][NUM])
{
	bool dom[nArchive][nArchive]={false};
	int S[nArchive]={0};
	double fit[nArchive]={0};
    for(int i=0;i<nArchive;i++)
	{
		for(int j=i+1;j<nArchive;j++)
		{
			if(dominates(triple[i],triple[j]))
			{
				S[i]++;
				dom[i][j]=true;
			}
			else if(dominates(triple[j],triple[i]))
			{
				S[j]++;
				dom[j][i]=true;
			}
		}
	}
	for(int i=0;i<nArchive;i++)
	{
		fit[i]=0;
		for(int j=0;j<nArchive;j++)
		{
			if(dom[j][i])
			{
				fit[i]+=S[j];
			}
		}
		
	}
	
	for(int i=0;i<nArchive;i++)
	{
		SIGMA[i][i]=0;
		for(int j=i+1;j<nArchive;j++)
		{
			for(int k=0;k<NUM;k++)
			{
				SIGMA[i][j]+=((triple[i][k]-triple[j][k])*(triple[i][k]-triple[j][k]));
			}
			SIGMA[i][j]=sqrt(SIGMA[i][j]);
			SIGMA[j][i]=SIGMA[i][j];
		}
		sort(SIGMA[i],SIGMA[i]+nArchive+1,greater<double>());
		fit[i]+=1/(SIGMA[i][nArchive-(int)sqrt((double)(nPop+nArchive))]+2);
	}
}
void truncation(const double fit_p[], double fit_a[], const int size)
{
	int Qnum = 0;
	memset(tempSIGMA, 0, sizeof(tempSIGMA));
	for (int q = 0; q < size; q++)
	{
		if (fit_p[q] < 1.0)//适应度小于1的，一定为非支配个体
		{
			memcpy(temp[Qnum], population[q], sizeof(int)*NUMBER);
			tempFit[Qnum] = fit_p[q];//临时种群
			//tempTriple[Qnum] = popTriple[q];
			memcpy(tempTriple[Qnum], popTriple[q], sizeof(double)*NUM);
			memcpy(tempSIGMA[Qnum], SIGMA[q], sizeof(double)*cur_pop);
			Qnum++;
		}
	}
	if (Qnum > nArchive)//修剪
	{
		pp++;
		int k = 1;
		while (Qnum > nArchive)
		{
			while (isminmax(tempSIGMA, Qnum, cur_pop) && k < cur_pop)
				k++;
			int p = min_index(tempSIGMA[k], Qnum);
			for (int z = p + 1; z < Qnum; z++)
			{
				memcpy(temp[z - 1], temp[z], sizeof(int)*NUMBER);
				tempFit[z - 1] = tempFit[z];//临时种群
				//tempTriple[z - 1] = tempTriple[z];
				memcpy(tempTriple[z - 1], popTriple[z ], sizeof(double)*NUM);
				memcpy(tempSIGMA[z - 1], tempSIGMA[z], sizeof(int)*NUMBER);
			}
			Qnum--;
		}
		for (int j = 0; j < nArchive; j++)
		{
			memcpy(archive[j], temp[j], sizeof(int)*NUMBER);
			///arcTriple[j] = tempTriple[j];
			memcpy(arcTriple[j], tempTriple[j], sizeof(double)*NUM);
			fit_a[j] = tempFit[j];
		}
	}
	else
	{
		int j = 0;
		int index[nPop + nArchive];
		for (j = 0; j < size; j++)
			index[j] = j;
		sortIndex(fit_p, index, size);
		for (j = 0; j < nArchive; j++)
		{
			memcpy(archive[j], population[index[j]], sizeof(int)*NUMBER);
			//arcTriple[j] = popTriple[index[j]];
			memcpy(arcTriple[j], popTriple[index[j]], sizeof(double)*NUM);
			fit_a[j] = fit_p[index[j]];
		}
	}
}