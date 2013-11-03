#include<iostream>
using namespace std;
int getunsortedness(char *input);
void sort(int unsorts[200],int m);
int main()
{
	int n,m;
	char dna[200][100];
	int unsorts[200];
	cin>>n>>m;
	int i=0;
	while(i<m)
	{
		cin>>dna[i];
		unsorts[i] = getunsortedness(dna[i])*1000+i;
		i++;
	}
	sort(unsorts,m);
	i = 0;
	while(i<m)
	{
		cout<<dna[unsorts[i]%1000]<<endl;
		i++;
	}
	return 0;
}
int getunsortedness(char *input)
{
	int length = strlen(input);
	int count = 0;
	for (int i=0;i<length;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(int(input[i])>int(input[j]))
				count++;
		}
	}	
	return count;
}
void sort(int unsorts[200],int m)
{
	int temp;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-1-i;j++)
		{
			if(unsorts[j]>unsorts[j+1])
			{
				temp = unsorts[j];
				unsorts[j] = unsorts[j+1];
				unsorts[j+1] = temp;
			}
		}	
	}
}
