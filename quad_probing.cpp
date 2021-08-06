#include<iostream>
using namespace std;
//quadratic probing
int main()
{
	int data[10]={-1};
	int i,p,x;
	int chain[10]={-1};
	
	for(i=0;i<10;i++)
	{	cout<<"enter data"<<endl;
		cin>>x;
		p=(i*i)%10;
		if(data[p]==-1)
		{
			data[p]=x;
		}	
		
		
	}
	for(i=0;i<10;i++)
	{
		cout<<data[i]<<endl;
	}
}
