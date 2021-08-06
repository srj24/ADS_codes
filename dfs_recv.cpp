#include<iostream>
using namespace std;
class graph
{	public :
	int **g;
	int n;
	int du,start;
	
	graph()
	{	int i;
		cout<<"enter  no. of vetices "<<endl;
		cin>>n;
		cout<<"enter strating vertex and du"<<endl;
		cin>>start>>du;
		g=new int *[n];
		for(i=0;i<n;i++)
		{
			g[i]= new int [n];
		}
	}
	void read()
	{	int i,j;
		cout<<"enter the adjacency matrix"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
	}
	void display()
	{	int source;
		int visited[n]={0};
		cout<<"enter the source value";
		
		cin>>source;
		dfs(source, visited);
		
	}
	void dfs(int i,int visited[])
	{
		cout<<i<<endl;
		visited[i]=1;
		for(int j=0;j<n;j++)
		{
			if(g[i][j]!=0 && visited[j]==0)
			{
				dfs(j,visited);
			}
		}
	}
};
int main()
{	
	graph a;
	a.read();
	a.display();
	
}
