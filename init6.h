
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
void truncation(const double fit_p[],double fit_a[],const int size)
{
	int Qnum=0;
	memset(tempSIGMA,0,sizeof(SIGMA));
	for(int q=0;q<size;q++)
    {
        if(fit_p[q]<1.0)//适应度小于1的，一定为非支配个体
		{
			memcpy(temp[Qnum],population[Qnum],sizeof(double)*NUMBER);
			tempFit[Qnum] = fit_p[Qnum];//临时种群
			tempTriple[Qnum]=popTriple[Qnum];
			memcpy(tempSIGMA[Qnum],SIGMA[Qnum],sizeof(double)*cur_pop);
			Qnum++;
		}
    }
    if(Qnum>nArchive)//修剪
	{
		pp++;
		int k=1;
        while (Qnum>nArchive)
		{
			while(isminmax(tempSIGMA,Qnum,cur_pop)&&k<cur_pop)
				k++;
			int p=min_index(tempSIGMA[k],Qnum);
            for(int z=p+1; z<Qnum; z++)
			{
				memcpy(temp[z-1],temp[z],sizeof(int)*NUMBER);
				tempFit[z-1] = tempFit[z];//临时种群
				tempTriple[z-1]=tempTriple[z];
				memcpy(tempSIGMA[z-1],tempSIGMA[z],sizeof(int)*NUMBER);
			}
			Qnum--;
		}
		for(int j=0;j<nArchive;j++)
		{
			memcpy(archive[j],temp[j],sizeof(int)*NUMBER);
			arcTriple[j]=tempTriple[j];
			fit_a[j]=tempFit[j];
		}
	}
	else
	{
		int j=0;
		int index[nPop+nArchive];
		for(j=0;j<size;j++)
			index[j]=j;
		sortIndex(fit_p,index,size);
		for(j=0;j<nArchive;j++)
		{
			memcpy(archive[j],population[index[j]],sizeof(int)*NUMBER);
			arcTriple[j]=popTriple[index[j]];
			fit_a[j]=fit_p[index[j]];
		}
	}
}