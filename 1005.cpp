#include<iostream>
#include<math.h>
using namespace std;
double getradius(double area);
int judge(double x,double y);
const double PI = 3.141592653;
int main()
{
	int i=0;
	int number;
	double x[1000],y[1000];
	cin>>number;
	while(i<number)
	{
		cin>>x[i]>>y[i];	
		i++;
	}	
	i=0;
	while(i<number)
	{
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<judge(x[i],y[i])<<"."<<endl;
		i++;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}
double getradius(double area)
{
	return sqrt((area*2)/PI);
}
int judge(double x,double y)
{
	double distance = sqrt(x*x+y*y);	
	double area = 0.0;
	int i=1;
	area = 50.0;
	while(true)
	{
		if(distance<=getradius(area))
		{
			break;	
		}
		else
		{
			i++;
			area+=50.0;
		}
	}
	return i;
}
