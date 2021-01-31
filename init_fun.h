void OVcom(double pop[NUMBER],double triple[NUM])
{
	double x,y,z,B1,B2;
	switch(NO)
	{
	case 1://bu=[1,1];bd=[0,0];���Ժ���='DEB';
		triple[0]=pop[0];
		triple[1]=(1+10*pop[1])*(1-(pop[0]/(1+10*pop[1]))*(pop[0]/(1+10*pop[1]))-(pop[0]/(1+10*pop[1]))*sin(2*3.1415926*4*pop[0]));
		break;
	case 2://[10 10];bd=[-5 -5];���Ժ���='Binh1';
		x=pop[0];
		y=pop[1];;
        triple[0]=x*x+y*y;
        triple[1]=(x-5)*(x-5)+(y-5)*(y-5);
		break;
	case 3://bu=[10^6 10^6];bd=[10^(-6) 10^(-6)];���Ժ���='Binh3';
		x=pop[0];
		y=pop[1];
        triple[0]=x-1000000;
        triple[1]=y-2*0.000001;
        triple[2]=x*y-2;
		break;
	case 4://bu=[10 10];bd=[-10 -10];���Ժ���='Fonseca';
		x=pop[0];
		y=pop[1];
        triple[0]=1-exp(-(x-1)*(x-1)-(y+1)*(y+1));
        triple[1]=1-exp(-(x+1)*(x+1)-(y-1)*(y-1));
		break;
	case 5://bu=[2 2];bd=[-2 -2];���Ժ���='Laumanns';
		x=pop[0];
		y=pop[1];
        triple[0]=x*x+y*y;
        triple[1]=(x+2)*(x+2)+y*y;
		break;
	case 6:// bu=[pi pi];bd=[-pi -pi];���Ժ���='Poloni';
		x=pop[0];
		y=pop[1];
		triple[0]=0.5*sin(1.0)-2*cos(1.0)+sin(2.0)-1.5*cos(2.0);
        triple[1]=1.5*sin(1.0)-cos(1.0)+2*sin(2.0)-0.5*cos(2.0);
        B1=0.5*sin(x)-2*cos(x)+sin(y)-1.5*cos(y);
        B2=1.5*sin(x)-cos(x)+2*sin(y)-0.5*cos(y);
        triple[0]=(1+(triple[0]-B1)*(triple[0]-B1)+(triple[1]-B2)*(triple[1]-B2));
        triple[1]=x*(1-y)+5;
		break;
	case 7://bu=[5.12 5.12 5.12];bd=[-5.12 -5.12 -5.12];���Ժ���='Quagliarella';
		x=pop[0];
		y=pop[1];
		z=pop[2];
		triple[0]=(x*x-10*cos(2*3.1415926*y)+10)+(y*y-10*cos(2*3.1415926*y)+10)+(z*z-10*cos(2*3.1415926*z)+10);
        triple[1]=((x-1.5)*(x-1.5)-10*cos(2*3.14159*(x-1.5))+10)+((y-1.5)*(y-1.5)*10*cos(2*3.14159*(y-1.5))+10)+((z-1.5)*(z-1.5)-10*cos(2*3.1415926*(z-1.5))+10);
        triple[0]=sqrt(triple[0]/3);
        triple[1]=sqrt(triple[1]/3);
		break;
	case 8://bu=[3 3];bd=[-3 -3];���Ժ���='Rendon';
		x=pop[0];
		y=pop[1];
		triple[0]=1/(x*x+y*y+1);
        triple[1]=x*x+y*y+1;
		break;
	case 9:// bu=[3 3];bd=[-3 -3];���Ժ���='Rendon2';
		x=pop[0];
		y=pop[1];
		triple[0]=x+y+1;
        triple[1]=x*x+2*y-1;
		break;
	case 10://   bu=[5];bd=[-5];���Ժ���='Schaffer';
		x=pop[0];
		triple[0]=x*x;
        triple[1]=(x-2)*(x-2);
		break;
	case 11:// bu=[2 2];bd=[-2 -2];���Ժ���='Viennet';
		x=pop[0];
		y=pop[1];
		triple[0]=x*x+(y-1)*(y-1);
        triple[1]=x*x+(y+1)*(y+1)+1;
        triple[2]=(x-1)*(x-1)+y*y+2;
		break;
	case 12:// bu=[4 4];bd=[-4 -4];���Ժ���='Viennet2';
		x=pop[0];
		y=pop[1];
		triple[0]=(x-2)*(x-2)/2+(y+1)*(y+1)/13+3;
        triple[1]=(x+y-3)*(x+y-3)/36+(-x+y+2)*(-x+y+2)/8-17;
        triple[2]=(x+2*y-1)*(x+2*y-1)/175+(-x+2*y)*(-x+2*y)/17-13;
		break;
	case 13://bu=[3 3];bd=[-3 -3];���Ժ���='Viennet3';
		x=pop[0];
		y=pop[1];
		triple[0]=(x*x+y*y)/2+sin(x*x+y*y);
        triple[1]=(3*x-2*y+4)*(3*x-2*y+4)/8+(x-y+1)*(x-y+1)/27+15;
        triple[2]=1/(x*x+y*y+1)-1.1*exp(-x*x-y*y);
		break;
	case 14: //bd=zeros(1,30);bu=ones(1,30);  ���Ժ���='ZDT1';
		triple[0]=pop[0];
		triple[1]=0.0;
		for(int j=1;j<NUMBER;j++)
		{
			triple[1]+=pop[j];
		}
		triple[1]=1+9.0/(NUMBER-1)*triple[1];
		z=1-sqrt(triple[0]/triple[1]);
		triple[1]=z*triple[1];
		break;
	case 15: //bd=zeros(1,30);bu=ones(1,30);  ���Ժ���='ZDT2';
		triple[0]=pop[0];
		triple[1]=0.0;
		for(int j=1;j<NUMBER;j++)
		{
			triple[1]+=pop[j];
		}
		triple[1]=1+9.0/(NUMBER-1)*triple[1];
		triple[1]=triple[1]*(1-(pop[0]/triple[1])*(pop[0]/triple[1]));
		break;
	case 16: //bd=zeros(1,30);bu=ones(1,30);  ���Ժ���='ZDT3';
		triple[0]=pop[0];
		triple[1]=0.0;
		for(int j=1;j<NUMBER;j++)
		{
			triple[1]+=pop[j];
		}
		triple[1]=1+9.0/(NUMBER-1)*triple[1];
		triple[1]=triple[1]*(1-sqrt(pop[0]/triple[1])-(pop[0]/triple[1])*sin(10*3.1415926*pop[0]));
		break;
	default:
		exit(0);
		break;
	}
}
void ABOUT()
{
	cout<<"*******************SPEA2��Ŀ����Գ���*********"<<endl;
	cout<<"1-------���Ժ���='DEB';***********NUMBER=2��NUM=2��BD=0��BU=1��"<<endl;
	cout<<"2-------���Ժ���='Binh1';*********NUMBER=2��NUM=2��BD=-5��BU=10��"<<endl;
	cout<<"3-------���Ժ���='Binh3';*********NUMBER=2��NUM=3��BD=0.000001��BU=1000000��"<<endl;
	cout<<"4-------���Ժ���='Fonseca';*******NUMBER=2��NUM=2��BD=-10��BU=10��"<<endl;
	cout<<"5-------���Ժ���='Laumanns';******NUMBER=2��NUM=2��BD=-2��BU=2��"<<endl;
	cout<<"6-------���Ժ���='Poloni';********NUMBER=2��NUM=2��BD=-3.1415926��BU=3.1415926��"<<endl;
	cout<<"7-------���Ժ���='Quagliarella';**NUMBER=3��NUM=2��BD=-5.12��BU=5.12��"<<endl;
	cout<<"8-------���Ժ���='Rendon';********NUMBER=2��NUM=2��BD=-3��BU=3��"<<endl;
	cout<<"9-------���Ժ���='Rendon2';*******NUMBER=2��NUM=2��BD=-3��BU=3��"<<endl;
	cout<<"10------���Ժ���='Schaffer';******NUMBER=1��NUM=2��BD=-5��BU=5��"<<endl;       
	cout<<"11------���Ժ���='Viennet';*******NUMBER=2��NUM=3��BD=-2��BU=2��"<<endl;
	cout<<"12------���Ժ���='Viennet2';******NUMBER=2��NUM=3��BD=-4��BU=4��"<<endl;
	cout<<"13------���Ժ���='Viennet3';******NUMBER=2��NUM=3��BD=-3��BU=3��"<<endl;
	cout<<"14------���Ժ���='ZDT1';**********NUMBER=30��NUM=2��BD=��BU=1��"<<endl;
	cout<<"15------���Ժ���='ZDT2';**********NUMBER=30��NUM=2��BD=0��BU=1��"<<endl;
	cout<<"16------���Ժ���='ZDT3';**********NUMBER=30��NUM=2��BD=0��BU=1��"<<endl;
	cout<<"*******************sunjc0306---2020.3.29********"<<endl;
	
}
