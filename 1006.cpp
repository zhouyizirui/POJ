#include<iostream>
using namespace std;
int judge(int p, int e, int i, int d);
int main()
{
	int p[1000],e[1000],i[1000],d[1000];
	int j=0;
	while(true)
	{
		cin>>p[j]>>e[j]>>i[j]>>d[j];
		if(p[j]==-1 && e[j]==-1 && i[j]==-1 && d[j]==-1)
			break;
		j++;
	}
	for(int k=0;k<j;k++)
	{
		cout<<"Case "<<k+1<<": the next triple peak occurs in "<<judge(p[k],e[k],i[k],d[k])<<" days."<<endl;
	}
	return 0;
}
int judge(int p, int e, int i, int d)
{
	p = p%23;
	e = e%28;
	i = i%33;
	int m;
	for(m=d;;m++)
	{
		if(m%23==p && m%28==e && m%33==i && m!=d)
			break;
	}	
	return m-d;
}
