#include<iostream>
using namespace std;
int muti(char a[],char b[],int *result);
void reset(int *intresult);
void reset(char *finalresult);
void deletedot(char *a);
void reverse(char *a);
int deletezero(char *a);
void transfer(int *intresult,char *charresult,int length);
void adddot(char *charresult,char * finalresult,int dotnum,int length);
void copy(char *from , char *to);
int countdot(char *a, int b);
int get(int *temp,int length);
int main()
{
    char a[100];
	int intresult[1000]={0};
	char finalresult[1000]={'\0'};
	char charresult[1000]={'\0'};
	int b;
    int dotnum;
	int resultcount;
	int zeroflag = 1;
	while(cin>>a>>b)
	{
		reset(charresult);
		zeroflag = deletezero(a);
		if(b==0 && zeroflag!=0)
		{
			cout<<1<<endl;
		}
		else
		{
			if(zeroflag == 0)
			{
				cout<<0<<endl;
			}
			else
			{
				if(b>=1)
				{
					dotnum = countdot(a,b);	
//					cout<<dotnum<<endl;
					deletedot(a);
					copy(a,charresult);
					resultcount = strlen(charresult)-1;
					while(b-1>0)
					{
						reset(intresult);
						resultcount=muti(charresult,a,intresult);
						transfer(intresult,charresult,resultcount);
						b--;
					}
					adddot(charresult,finalresult,dotnum,resultcount);
					cout<<finalresult<<endl;
					reset(finalresult);
				}
				if(b==1)
				{
				}
			}	
			//cout<<a<<endl;
		}
	}
	return 0;
}
void adddot(char *charresult,char * finalresult,int dotnum,int length)
{
	int fuck=dotnum;
	if(dotnum==0)
	{
		for(int i=0;i<=length;i++)
		{
			finalresult[i] = charresult[i];
		}
	}
	else
	{if(dotnum>=length+1)
	{
		finalresult[0]='.';	
		int k=0;
		for(int j=1;j<=fuck;j++)
		{
			if(j<=fuck-length-1)
				finalresult[j]='0';
			else
			{
				finalresult[j]=charresult[k];
				k++;
			}
		}
	}
	else
	{
		int k=0;
		for(int j=0;j<=length+1;j++)	
		{
			if(j==length+1-dotnum)
			{	
				finalresult[j]='.';
				k--;
			}	
			else
				finalresult[j]=charresult[k];
			k++;
		}	
	}
}
}
void transfer(int *intresult,char *charresult,int length)
{
	for(int i=0;i<=length;i++)
	{
		charresult[i]=char(intresult[i]+'0');
	}
}
void copy(char *from , char *to)
{
	int i=0;
	int l=0;
	while(from[i]!='\0')
	{
		to[l]=from[i];
		l++;
		i++;
	}
}
void reverse(char *a)
{
	int i=0;
	int temp;
	while(a[i]!='\0')
	{
		i++;
	}
	for(int j=0;j<=(i-1)/2;j++)
	{
		temp = a[j];
		a[j] = a[i-1-j];
		a[i-1-j] = temp;
	}
}
int muti(char a[],char b[],int *result)
{
	char tempa[1000]={'\0'};
	char tempb[1000]={'\0'};
	int alength = strlen(a);
	int blength = strlen(b);
	for(int i=0;i<alength;i++)
	{
		tempa[i]= a[i];
	}
	for(int j=0;j<blength;j++)
	{
		tempb[j]= b[j];
	}
	reverse(tempa);
 	reverse(tempb);
	//cout<<"The reversed a "<<tempa<<" with length "<<alength<<endl;
	//cout<<"The reversed b "<<tempb<<" with length "<<blength<<endl;
	for(int i=0;i<alength;i++)
	{
		for(int j=0;j<blength;j++)
		{
	//		cout<<int(tempa[i]-'0')*int(tempb[j]-'0');
			result[i+j]+=int(tempa[i]-'0')*int(tempb[j]-'0');
		}
	}	
	//cout<<endl;
	return get(result,alength*blength);
}
int get(int *temp,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		temp[i+1] += temp[i]/10;
		temp[i] = temp[i]%10;
	}		
	i=length;
	while(temp[i]==0)
		i--;

	int te;
	for(int j=0;j<=i/2;j++)
	{
		te = temp[j];
		temp[j] = temp[i-j];
		temp[i-j] = te;
	}
	return i;
}
void deletedot(char *a)
{
	int i=0;
	if(a[0]=='.')
	{
		a[0]='0';
		while(a[0]=='0')
		{
			int l=0;
			while(a[l]!='\0')
			{
				a[l]=a[l+1];
				l++;
			}
		}
	//	cout<<"FUCKING "<<a<<endl;
	}
	else
	{
		while(a[i]!='.')	
		{
			i++;
		}
		while(a[i]!='\0')
		{
			a[i]=a[i+1];
			i++;
		}
	//	cout<<"MAKING "<<a<<endl;
	}
}
void reset(int *intresult)
{
	for(int i=0;i<1000;i++)
	{
		intresult[i]=0;
	}
}
void reset(char *finalresult)
{
	for(int i=0;i<1000;i++)
	{
		finalresult[i]='\0';
	}
}
int countdot(char *a, int b)
{
    int i,j;
	bool flag=false;
	i = 0;
	j = -1;
	while(a[i]!='\0')
	{
		if(a[i]=='.')
		{
	    	flag = true;
		}
		if(flag == true)
		{
			j++;
		}
		i++;
	}
//	cout<<"The j "<<j<<endl;
	return j*b;
}
int deletezero(char *a)
{
	int i=0;
	int k,m;
	while(a[i]!='\0')
	{
		i++;
	}
	i--;
	for(k=i;k>=0;k--)
	{
		if(a[k]=='0')
			a[k]='\0';
		else
			break;
	}
	while(a[0]=='0')
	{
		int l=0;
		while(a[l]!='\0')
		{
			a[l]=a[l+1];
			l++;
		}
	}
	if(a[0]=='\0' || (a[0]=='.' && a[1]=='\0'))
		return 0;
	else
		return 1;
}
