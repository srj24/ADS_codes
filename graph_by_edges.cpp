#include<iostream>
using namespace std;
class graph
{
	int **g;
	int n,du,start;
	public :
	graph()
	{
		cout<<"enter no of vertices\n";
		cin>>n;
		cout<<"enter strating vertex and du value 0 for directed 1 for undirected \n";
		
		cin>>start>>du;
		g=new int*[n];
		for(int i=0;i<n;i++)
		{
			g[i]=new int[n];
		}
	}
	void readby_edges()
	{
		int i,j,u,v,w;
		//cout<<"\n enter edge and wight if any \n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				g[i][j]=0;
			}
		}
		
	
		while(1)
		{	
		cout<<"\n entter the edges and -1 to stop";
		cin>>u>>v>>w;
			if(u==-1)
			{
				break;
			}
			
			if(du==0)
			{
				g[u-start][v-start]=w;
				
			}
			else
			{
				g[u-start][v-start]=w;
				g[v-start][u-start]=w;
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
{
	graph obj;
	obj.readby_edges();
	obj.printgraph();
	obj.check();
}
