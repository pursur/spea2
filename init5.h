double min_din_col(double sigma[nPop+nArchive][nPop+nArchive],int col,int size)
{
	double r=sigma[0][col];
	for(int i=1;i<size;i++)
	{
		if(sigma[i][col]<r)
		{
			r=sigma[i][col];
		}
	}
	return r;
}
double min_din(double sigma[],int size)
{
	double r=sigma[0];
	for(int i=1;i<size;i++)
	{
		if(sigma[i]<r)
		{
			r=sigma[i];
		}
	}
	return r;
}
double max_din_col(double sigma[nPop+nArchive][nPop+nArchive],int col,int size)
{
	double r=sigma[0][col];
	for(int i=1;i<size;i++)
	{
		if(sigma[i][col]>r)
		{
			r=sigma[i][col];
		}
	}
	return r;
}
double max_din(double sigma[],int size)
{
	double r=sigma[0];
	for(int i=1;i<size;i++)
	{
		if(sigma[i]>r)
		{
			r=sigma[i];
		}
	}
	return r;
}
int min_index(double sigma[],int size)
{
	double r=sigma[0];
	int index=0;
	for(int i=1;i<size;i++)
	{
		if(sigma[i]<r)
		{
			r=sigma[i];
			index=i;
		}
	}
	return index;
}
int min_index_col(double sigma[nPop+nArchive][nPop+nArchive],int col,int size)
{
	double r=sigma[0][col];
	int index=0;
	for(int i=1;i<size;i++)
	{
		if(sigma[i][col]<r)
		{
			r=sigma[i][col];
			index=i;
		}
	}
	return index;
}
void convert(double a[nPop+nArchive][nPop+nArchive])
{
	for(int i=0;i<nPop+nArchive;i++)
		for(int j=i+1;j<nPop+nArchive;j++)
		{
			double t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
}
void truncation(double fit_p[],double fit_a[],int size)
{
	int j=0;
	int index[nPop+nArchive];
	for(j=0;j<size;j++)
		index[j]=j;
	sortIndex(fit_p,index,size);
	if(fit_p[index[nArchive-1]]>=1)
	{
		for(j=0;j<nArchive;j++)
		{
			memcpy(archive[j],population[index[j]],sizeof(double)*NUMBER);
			fit_a[j]=fit_p[index[j]];
			//¾«Ó¢²âÊÔ
			if(fit_p[index[j]]<1)
			{
				memcpy(ECS[ECS_num++],population[index[j]],sizeof(double)*NUMBER);
			}
		}
	}
	else
	{
		pp++;//»½ÐÑ½Ø¶Ï³ÌÐòµÄ´ÎÊý
		int tNum=0;
		for(tNum=0;tNum<size&&(fit_p[index[tNum]]<1);tNum++)
		{
			memcpy(temp[tNum],population[index[tNum]],sizeof(double)*NUMBER);
			memcpy(tempSIGMA[tNum],SIGMA[index[tNum]],sizeof(double)*size);
			tempFit[tNum]=fit_p[index[tNum]];
		}
		//convert(tempSIGMA);
		int k=1;
        while (tNum>nArchive)
		{
            while( min_din_col(tempSIGMA,k,tNum)==max_din_col(tempSIGMA,k,tNum) && k<size)
                k=k+1;
            
            int min_i=min_index_col(tempSIGMA,k,tNum);
            for(int j=min_i;j<tNum-1;j++)
			{
				memcpy(temp[j],temp[j+1],sizeof(double)*NUMBER);
				//convert(tempSIGMA);
				memcpy(tempSIGMA[j],tempSIGMA[j+1],sizeof(double)*(nPop+nArchive));
				//convert(tempSIGMA);
				tempFit[j]=tempFit[j+1];
			}
			tNum--;
		}
		for(j=0;j<nArchive;j++)
		{
			memcpy(archive[j],temp[j],sizeof(double)*NUMBER);
			fit_a[j]=tempFit[j];
		}
	}
}