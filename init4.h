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
	cout << "�����ʼ����ɣ����ڵ���*******" << endl;
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
	cout<<"�����������ɣ�ǰ�������ݵ����ļ�"<<endl;
	cout<<"���ѽضϳ���Ĵ���:"<<pp<<endl;
	cout<<"paretoǰ����ĸ���Ϊ:"<<pareto<<endl;
	cout<<"��Ⱥ��������:"<<nPop<<endl;
	cout<<"������Ⱥ��������:"<<nArchive<<endl;
	cout<<"��������:"<<GEN<<endl;
	cout<<"����:"<<step<<endl;
	cout<<"���ʲ���:������"<<Pc<<"��������"<<Pm<<endl;
}