#include<iostream>
#include<algorithm>
using namespace std;
void fomulate(char phone[50],int index, long *result);
void display(long oneresult,int times);
int themap(char input);
void thesort(long *result,int length);
int main()
{
	int number;
	int i=0;
	char phone[50]={'\0'};
	long result[100000];
	cin>>number;
	while(i<number)
	{
		cin>>phone;	
		fomulate(phone,i,result);	
		memset(phone,0,50);
		i++;
	}
	sort(result,result+number);
	/*for(int i=0;i<number;i++)
	{
		cout<<result[i]<<endl;
	}*/
	
	int count = 0;
	int flag = 0;	
	int temp = result[0];
	for(int i=0;i<number;)
	{
		count=0;
		while(result[i]==temp)
		{
			i++;	
			count++;
			if(i==number)
				break;		
		}
		if(count>1)
		{
			flag=1;
			display(temp,count);
		}
		temp=result[i];
	}
	if(flag==0)
	{
		cout<<"No duplicates."<<endl;
	}
	return 0;
}
void display(long oneresult,int times)
{
	int i=0;
	long first = oneresult/10000;
	long second = (oneresult-first*10000);
	int before[3];
	int after[4];
	for(int j=0;j<3;j++)
	{
		before[j] = first%10;
		first = first/10;
	}
	for(int k=0;k<4;k++)
	{
		after[k] = second%10;
		second = second/10;
	}
	for(int j=2;j>=0;j--)
	{
		cout<<before[j];
	}
	cout<<"-";
	for(int k=3;k>=0;k--)
	{
		cout<<after[k];
	}
	cout<<" "<<times<<endl;
}
void thesort(long *result,int length)
{
	long temp;
	for (int i=0;i<length;i++)
	{
		for(int j=0;j<length-i-1;j++)
		{
			if(result[j]>result[j+1])
			{
				temp = result[j];
				result[j] = result[j+1];
				result[j+1] = temp;
			}
		}
	}
}
void fomulate(char phone[50], int index, long *result)
{
	int length = strlen(phone);
	long total = 0;
	char temp[50]={'\0'};
	for(int i=0;i<length;i++)
	{
		temp[i]=phone[i];
	}	
	int j=0;
	while(temp[j]!='\0')
	{
		int mapresult;
		mapresult = themap(temp[j]);
		if(mapresult!=-1)	
		{
			total = total*10+mapresult;
		}
		j++;
	}
	result[index]=total;
}
int themap(char input)
{
	int value = int(input);
	if(value<= 57 && value >=48)
	{
		return value-48;
	}
	else if((value>=65 && value<=90) || (value>=97 && value<=122))
	{
		if(value<=90)
			value = value-65;
		else 
			value = value-97;

		if(value==16 || value == 25)
		{
			return -1;
		}
		else if(value<=2)
		{
			return 2;
		}
		else if(value<=5)
		{
			return 3;
		}
		else if(value<=8)
		{
			return 4;
		}
		else if(value <=11)
		{
			return 5;
		}
		else if(value <=14)
		{
			return 6;
		}
		else if(value <=18)
		{
			return 7;
		}
		else if(value <=21)
		{
			return 8;
		}
		else if(value <=24)
		{
			return 9;
		}
	}
	else
	{
		return -1;
	}
}
