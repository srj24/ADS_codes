#include<iostream>
using namespace std;
void readgraph(int g[][20] ,int n)
{	int j;
	cout<<"enter adj matrix\n";	
	for(int i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}

}
void degree(int g[][20],int n ,int start)
{	int i,j,cnt;
	for(i=0;i<n;i++)
	{	cnt=0;
		for(j=0;j<n;j++)
		{ if(g[i][j]>0)
			cnt++;	
		}
		cout<<"degree of "<<i+start<<cnt<<endl;
	}

	
}
void indgree(int g[][20],int n ,int start)
{	
	int i,j,cnt;
	for(i=0;i<n;i++)
	{	cnt=0;
		for(j=0;j<n;j++)
		{ if(g[i][j]>0)
			cnt++;	
		}
		cout<<"indegree of "<<i+start<<cnt<<endl;
	}

	
	
}
void outdegree(int g[][20],int n ,int start)
{
	int i,j,cnt;
	for(i=0;i<n;i++)
	{	cnt=0;
		for(j=0;j<n;j++)
		{ if(g[j][i]>0)
			cnt++;	
		}
		cout<<"outdegree of "<<i+start<<cnt<<endl;
	}
	
}

int main()
{
	int g[20][20];
	int i,n,j,du,start;
	cout<<"enter number of vertices du and starting node\n";
	cin>>n>>du>>start;
	readgraph(g,n);
	if(du==1)
	{
		degree(g,n,start);
		}	
	else
	{
		indgree(g,n,start);
		outdegree(g,n,start);
	}
}
