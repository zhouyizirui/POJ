#include<iostream>
using namespace std;
int cmp(char *first, char *second);
int caculate(char *input);
double getlength(int n);
int main()
{
	char end[4]={'0','.','0','0'};
	char a[1000][4];
	int result[1000];
	int i=0;
	while(cin>>a[i])
	{	if(cmp(a[i],end)!=0)
		{
			//cout<<a[i]<<endl;
			result[i]=caculate(a[i]);
			//cout<<caculate(a[i])<<endl;
			i++;
		}
		else
		{		
			break;
		}
	}
	for(int l=0;l<i;l++)
	{
		cout<<result[l]<<" card(s)"<<endl;	
	}
	return 0;
}
int cmp(char *first, char *second)
{
	if(first[0]==second[0] && first[1]==second[1] && first[2]==second[2] && first[3]==second[3])
		return 0;
	else
		return 1;
}
int caculate(char *input)
{
	double result = (input[0]-'0')*100+(input[2]-'0')*10+(input[3]-'0')*1;
	result = result/100.0;
	int i=1;
	while(getlength(i)<result)
	{
		i++;
	}
	return i;
}
double getlength(int n)
{
	double length=0.0;
	for(int i=2;i<=n+1;i++)
	{
		length=length+1.0/i;
	}
	return length;
}
