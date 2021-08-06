#include<bits/stdc++.h>
using namespace std;
class meaning
{
	public :
	string data;
	meaning* next;
	public:
		meaning(string str)
		{	data=str;
			next=NULL;
		}
		
		
};

class word
{	public :
	string keyword;
	word *left,*right;
	meaning *mean;
	word(string str)
	{
		left=right=NULL;
		mean=NULL;
		keyword =str;
	}
	word* insert_meaning();
	;	
};
void inorder(word *p);

class node
{	private :
	word *root;
	public :
	node()
	{
		root=NULL;
	}
	public :
		
		void create();
		void insert_meaning();
		
		void display()
		{
			inorder(root);
		}
		
};
void inorder(word *p)
{
	//	word *p;
			if(p!=NULL)
			{
				inorder(p->left);
				cout<<p->keyword<<endl;
				cout<<"meaning are"<<endl;
				
				{	meaning *q;
					q=p->mean;
					while(q!=NULL)
					{
						cout<<q->data;
					}
				}
				
				inorder(p->right);
			}
}
word* node::insert(word*t,string str)
{		
			if(t==NULL)
			{
				t=new word (str);
				t->mean->insert_meaning();
				return t;		
					
				}
				
				
			
						
			
			else
			{
				if(str<t->keyword)
				{
					t->left=insert(t->left,str);
					return t;	
				}
				if(str>t->keyword)
				{
					t->right=insert(t->right,str);
					return t;
				}
				else{
					cout<<"data is duplicate";
				}
				}	
}
void node::create()
	{
			string str;
			
			cout<<"keep entering data or _stop to stop"<<endl;
			while(1)
			{
				getline(cin,str);
				if(str=="_stop");
				break;
				root=insert(root,str);
			}	
		}

word* word::insert_meaning() 
		{	int n,i;
			meaning *p;
			word *q;
			string s;
			cout<<"number of meaning"<<endl;
			cin>>n;
			cout<<"enter meaning"<<endl;
			getline(cin,s);
			if(q->mean==NULL)
			q->mean=new meaning(s);
			else
			{	p=q->mean;
				for(i=1;i<n;i++)
				{
					cout<<"enter meaning"<<endl;
					getline(cin,s);
					p->next=new meaning(s);
					
				}
			}
			return q;
			
		}
int main()
{	node dict;
dict.create();
dict.display();

}
