#include<iostream>
#include<string>
using namespace std;
const string HaabMonth[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
const string TzolkinDay[21]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int caculateday(char numofday[10],char month[10],int year);
void getchange(int day,int number);
int main()
{
	int i=0;
	int number;
	int totalday;
	char numofday[1000][10];
	char month[1000][10];
	int year[1000];
	cin>>number;
	while(i<number)
	{
		cin>>numofday[i];
		cin>>month[i];
		cin>>year[i];
		i++;
	}
	i=0;
	cout<<number<<endl;
	while(i<number)
	{
		totalday=caculateday(numofday[i],month[i],year[i]);
		getchange(totalday,number);
		i++;
	}
	return 0;
}
int caculateday(char numofday[10], char month[10], int year)
{
	int i=0;
	int theday = 0;
	int theyear = 0;
	int totalday = 0;
	while(numofday[i]!='.')
	{
		theday = theday*10 + int(numofday[i]-'0');
		i++;
	}
	//cout<<"The day "<<theday<<endl;
	string themonth = month;
	//cout<<"The month "<<themonth<<endl;
	theyear = year;
	//cout<<"The year "<<theyear<<endl;
	
	totalday = totalday + theyear*365;
	int m;
	for(m=0;m<19;m++)
	{
		if(HaabMonth[m]==themonth)
			break;
	}
	totalday = totalday + m*20;
	totalday = totalday + theday;	
	return totalday;	
}
void getchange(int day,int number)
{
	int year;
	int nameindex;
	char name[10]={'\0'};
	year = day/260;
	nameindex = day%20;
	cout<<(day%13+1)<<" "<<TzolkinDay[nameindex]<<" "<<year<<endl;
}
