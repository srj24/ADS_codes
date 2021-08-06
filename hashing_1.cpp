#include<iostream>
using namespace std;
int main()
{	int x,y,p,i;
	int data[10];
	int chain[10];
	for(i=0;i<10;i++)
	{
		data[i]=chain[i]=-1;
	}
	for(i=0;i<10;i++)
	{
		cout<<"enter element \n";
		cin>>x;
		if(data[x%10]==-1)
		{
			data[x%10]=x;
			
		}
		else
		{	
			p=y=x%10;
			while(1)
			{		if(y==10)
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
		
	for(i=0;i<10;i++)
	{
		cout<<data[i]<<" -> "<<chain[i]<<endl;
	}
	
}
