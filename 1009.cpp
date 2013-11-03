#include<iostream>
using namespace std;
#define FLAGNUM 10000
struct node
{
	int index;
	int value;
};
int getflagpoints(int width, int height, int input[10000][2], int count, node flagpoints[10000]);
int getoriginpixel(int position, int width, int input[10000][2]);
int getvalue(int position, int width, int height, int input[10000][2]);
void sort(node flagpoints[10000],int length);
void display(node flagpoints[10000], int length, int totalpixel);
int main()
{
	int width,tempindex,tempvalue;
	int input[10000][2];
	node flagpoints[FLAGNUM];
	int i=0;
	int j=0;
	int totalpixel=0;
	int pictures=0;
	while(true)
	{	
		cin>>width;
		if(width==0)
			break;
		i=0;
		totalpixel = 0;
		j=0;
		while(true)
		{	
			cin>>tempindex>>tempvalue;
			if(tempindex == 0 && tempvalue ==0)
				break;
			input[i][0] = tempindex;
			input[i][1] = tempvalue;
			totalpixel = totalpixel + input[i][1];
			i++;	
		}
		cout<<width<<endl;
		j=getflagpoints(width,totalpixel/width,input,i,flagpoints);
		sort(flagpoints,j);
		pictures++;
		display(flagpoints,j,totalpixel);
	}
	cout<<0<<endl;
	return 0;
}
void display(node flagpoints[10000], int length, int totalpixel)
{
	node temp = flagpoints[0];
	for(int i=0;i<length;i++)
	{
		if(temp.value!=flagpoints[i].value)
		{
			cout<<temp.value<<" "<<flagpoints[i].index-temp.index<<endl;
			temp = flagpoints[i];
		}
	}	
	cout<<temp.value<<" "<<totalpixel-temp.index+1<<endl;
	cout<<0<<" "<<0<<endl;
}
void sort(node flagpoints[10000], int length)
{
	node temp;
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-i-1;j++)
		{
			if(flagpoints[j].index>flagpoints[j+1].index)
			{
				temp = flagpoints[j];
				flagpoints[j] = flagpoints[j+1];
				flagpoints[j+1] = temp;
			}
		}
	}
}
int getflagpoints(int width, int height, int input[10000][2], int count, node flagpoints[10000])
{
	int originpos=1;
	int total=1;
	int outindex=0;
	for(int i=0;i<=count;i++)
	{
		originpos = total;
		int row = (originpos-1)/width;
		int col = (originpos-1)%width;
		for(int m=row-1;m<=row+1;m++)
		{
			for(int n=col-1;n<=col+1;n++)
			{
				if(m<0 || m>=height || n>=width || n<0)	
					continue;
				int nowpos = m*width+n+1;
			//	cout<<"T "<<nowpos<<" i "<<m<<" j "<<n<<" row "<<row<<" col "<<col<<endl;
				flagpoints[outindex].index = nowpos;
				flagpoints[outindex].value = getvalue(nowpos,width,height,input);
				outindex++;	
			}
		}
		if(col==width-1)
		{
			if(height-(row+1)>=2)
			{
				int nowpos = (row+2)*width+1;
				flagpoints[outindex].index = nowpos;
				flagpoints[outindex].value = getvalue(nowpos,width,height,input);
				outindex++;
			}
			if(row+2==height)
			{
				int nowpos = (row+1)*width+1;
				flagpoints[outindex].index = nowpos;
				flagpoints[outindex].value = getvalue(nowpos,width,height,input);
				outindex++;
			}
		}
		total = total+input[i][1];
	}	
	return outindex;
}
int getvalue(int position, int width, int height, int input[10000][2])
{
	int pixel = getoriginpixel(position,width,input);
	position = position - 1;
	int row = position/width;
	int col = position%width;
	int result = 0;
	for(int i=row-1;i<=row+1;i++)
	{
		for(int j=col-1;j<=col+1;j++)
		{
			if(i<0 || i>=height || j>=width || j<0)
				continue;
			int nowpos = i*width+j+1;
			/*
			cout<<"The position "<<nowpos<<endl;
			cout<<"The pexel "<<pixel<<endl;
			cout<<"The orign "<<abs(getoriginpixel(nowpos,width,input)-pixel)<<endl;
			*/
			if(abs(getoriginpixel(nowpos,width,input)-pixel)>result)
			{
				//cout<<"The fucking "<<abs(getoriginpixel(nowpos,width,input))<<endl;
				result = abs(getoriginpixel(nowpos,width,input)-pixel);
			}
		}
	}
	return result;
}
int getoriginpixel(int position, int width, int input[10000][2])
{
	int total = 0;
	int index = 0;
	while(position>total)	
	{
		total = total + input[index][1];
		index++;
	}
	index--;
	return input[index][0];
}
