#include<iostream>
using namespace std;
int main()
{	int i,p,x,y;
	int data[10]={-1};
	int chain[10]={-1};
	for(i=0;i<10;i++)
	{	cout<<"enteer ele"<<endl;
		cin>>x;
		if(data[x%10]==-1)
		{
			data[x%10]=x;
		}
		else if(data[x%10]%10!=x%10)
		{
			z=data[x%10];
			data[x%10]=x;
			p=y=x%10;
			while(1)
			{	if(y==10)
				{
					y=0;
					
				}
					if(p==data[y]%10)
					{
						p=y;
					}
					if(data[y]==-1)
					{
						data[y]=x;
						chain[p]=y;
						break;
				
					}
					y++;
				
			}
		}
		else
		{
			p=y=x%10;
			while(1)
			{	if(y==10)
				{
					y=0;
					
				}
					if(p==data[y]%10)
					{
						p=y;
					}
					if(data[y]==-1)
					{
						data[y]=x;
						chain[p]=y;
						break;
				
					}
					y++;
				
			}
		}
	}
	
}
