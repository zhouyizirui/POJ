#include<iostream>
#include<iomanip>
using namespace std;
void average(char *result, char *every);
int main()
{
	char every[12][20]={'\0'};
	double theevery[12]={0.0};
	double total = 0.0;
	char result[20]={'\0'};
	for(int i=0;i<12;i++)
	{
		cin>>theevery[i];
		total = total + (theevery[i]);
	}
	cout<<"$";
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<(total/12.0)<<endl;
	return 0;
}
void average(char *result, char **every)
{
	int penny = 0;
	int cent = 0;
	int length = 0;
	for(int i=0;i<12;i++)
	{
		length = strlen(every[i]);
		penny = penny + int(every[i][length-1]-'0');
	}
}
