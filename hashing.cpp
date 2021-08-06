#include<iostream>
using namespace std;
class Num
{
	int data[10];
	int chain[10];
	public :
	Num()
	{
		for(i=0;i<10;i++)
		{
			data[i]=-1;
			chain[i]=-1;
		}
	}
	void read()
	{
		
		int x,k,j;
		for(i=0;i<10;i++)
		{
			cin>>x;
			k=x%10
			if(data[k]==-1)
			{
				data[k]=x;
				}
				else
				{	if(chain[k]!=-1)
					{
						j=chain[k];
					}
					else
					{
						j=k+1;
					}
					while(1)
					{
						if(data[j]==-1)
						{
							data[j]=x;
							j++;
						}
						
					}
				}	
		}
		
	}
	
}
int main()
{
	NUM obj;
}
