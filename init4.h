int cal_pare(double fit[],int size)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(fit[i]<1)
			count++;
	}
	return count;
}
void test()
{
	getPop(population,nPop);
	cur_pop=nPop;
	cost(population,popTriple,cur_pop);
	cout << "程序初始化完成，正在迭代*******" << endl;
	for(int gen=0;gen<GEN;gen++)
	{
		cout.width(6);
		cout << gen << " ";
		cout << "\b\b\b\b\b\b\b";
		calFitness(popTriple,popFit,cur_pop);
		truncation(popFit,arcFit,cur_pop);
		for(int opt=0;opt<nPop+nArchive;opt+=2)
		{
			int s1=selection(arcFit,nArchive);
			int s2=selection(arcFit,nArchive);
			GA(s1,s2,opt);
		}
		cur_pop=nArchive+nPop;
		cost(population,popTriple,cur_pop);
	}
	calFitness(popTriple,popFit,cur_pop);
	//truncation(popFit,tempFit,arcFit,cur_pop);
	//cost(archive,arcTriple,nArchive);
	int pareto=0;
	ofstream fout;
	fout.open("sunjcSPEA2.txt");
	for(int i=0;i<nArchive;i++)
	{
		if(arcFit[i]<1)
		{
			pareto++;
			for(int j=0;j<NUM;j++)
				fout<<arcTriple[i][j]<<"  ";
			fout<<endl;
		}
		
	}
	fout.close();
	cout<<endl;
	cout<<"程序迭代已完成，前沿面数据导入文件"<<endl;
	cout<<"唤醒截断程序的次数:"<<pp<<endl;
	cout<<"pareto前沿面的个数为:"<<pareto<<endl;
	cout<<"种群数量参数:"<<nPop<<endl;
	cout<<"档案种群数量参数:"<<nArchive<<endl;
	cout<<"迭代次数:"<<GEN<<endl;
	cout<<"精度:"<<step<<endl;
	cout<<"概率参数:交叉率"<<Pc<<"，变异率"<<Pm<<endl;
}