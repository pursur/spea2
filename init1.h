void getPop(double pop[][NUMBER],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<NUMBER;j++)
		{
			pop[i][j]=rand() / (double)(RAND_MAX);//�������0-1��С��;BU+(BD-BU)*
			pop[i][j]=pop[i][j]*DERTA+LOWER;
		}
	}
}
void cost(double pop[][NUMBER],double triple[][NUM],int size)
{
	for(int i=0;i<size;i++)
	{
		OVcom(pop[i],triple[i]);
	}
}
