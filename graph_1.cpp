
#include<iostream>
using namespace std;
class graph
{
	int **g;
	int n;
	int du;
	int start;
	public :
	graph()
	{
		cout<<"enter nuber of vertices\n";
		cin>>n;
		cout<<"enter starting node and 0.directed 1.undirected\n";
		cin>>start>>du;
		g=new int*[n];
		
		for(int i=0;i<n;i++)
		{
			g[i]=new int [n];
		}
				
	}
	void read()
	{	int i,j;
		cout<<"\n enter adj matrix";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>g[i][j];
		}
	}
		
	}
	void printgraph()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<g[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	void degree()
	{
		int i,j,cnt;
		for(i=0;i<n;i++)
		{	cnt=0;
			for(j=0;j<n;j++)
			{
				if(g[i][j]>0) cnt++;
			}
			cout<<"degree of "<<i+start <<"is :"<<cnt<<endl;
		}
	}
	void indgree()
	{
		int i,j,cnt;
		for(i=0;i<n;i++)
		{	cnt=0;
			for(j=0;j<n;j++)
			{
				if(g[j][i]>0) cnt++;
			}
			cout<<"indegree of "<<i+start <<"is :"<<cnt<<endl;
		}
	}
	void outdegree()
	{
		int i,j,cnt;
		for(i=0;i<n;i++)
		{	cnt=0;
			for(j=0;j<n;j++)
			{
				if(g[i][j]>0) cnt++;
			}
			cout<<"outdegree of "<<i+start <<"is :"<<cnt<<endl;
		}
	}
	void check()
	{
		if(du==1)
		{
		//	cout<<"\n degree";
			degree();
		}
		else
		{
			//cout<<"\nindegree";
			indgree();
		//	cout<<"\n outdegree";
			outdegree();
		
	
			
		}
	}
};
int main()
{	graph obj;
	obj.read();
	obj.printgraph();
	obj.check();
	
//	obj.degree();

	
}
