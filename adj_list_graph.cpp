#include<iostream>
using namespace std;
int main()
{	int x,y;
	int data[10]={-1};
	int chain[10]={-1};
	for(int i=0;i<10;i++)
	{
		cin>>x;
		if(data[x%10]==-1)
		{
			data[x%10]=x;
			
		}
		else{
			while(1)
			{
				y=x%10+1;
				if(y==10)
				{
					y=0;
				}
				if(data[y]==-1)
				{
					data[y]=x;
					chain[x%10]=y;
					break;
				}
				
			}
		}
		
	}
	for(int i=0;i<10;i++)
	{
		cout<<data[i]<<" -> "<<chain[i];
	}
	
}
