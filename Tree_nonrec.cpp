#include<iostream>
using namespace std;
class node
{	public :
	int data;
	node *left;
	node *right;
	node(int x)
	{
		data=x;
		left=right=NULL;
	}
};
class stacknode
{	public :
	stacknode*link;
	int flag;
	stcknode()
	{
		flag=0;
		link=NULL;
	}
};
class stack_
{	public:
	stacknode* data[30];
	int top;
	stack_()
	{
		top=-1;
	}
	int full()
	{
		if(top==29)
		return 1;
		else return 0;
		
	}
	int empty()
	{
		if(top==-1)
		return 1;
		else return 0;
	}
	void push(stacknode* p)
	{
		if(!full())
		top++;
		data[top]=p;
		
	}
	stacknode* pop()
	{	stacknode* p;
		if(!empty())
		{
			p = data[top];
			top--;
		}
		return p;
	 } 
	
};
class Tree
{
	node*root;
	public :
		Tree()
		{
			root=NULL;
		}
		void create();
		void preorder();
	/*	void inorder();
		void postorder();
		int count();
		int search();*/
};
void Tree::create()
{	int x;
	stack_ S;
	node *t;
	cout<<"enter data to add or -1 to stop"<<endl;
	cin>>x;
	if(x==-1)
	return;
	root=new node(x);
	t=root;
	while(1)
	{	S.push(t);
		cout<<"enter data or -1 to stop" <<endl;
		cout<<"left of :"<<x<<"   :";
		cin>>x;
		if(x==-1) break;
		t->left=new node(x);
		t=t->left;
		
	}
	while(!S.empty())
	{
		t=S.pop();
		cout<<"enter data or -1 to stop";
		cout<<"right of "<<x<<"  ";
		cin>>x;
		if(x!=-1)
		{
			S.push(t);
			cout<<"enter data or -1 to stop"<<endl;
			cout<<"left of :"<<x;
			cin>>x;
			if(x==-1) break;
			t=t->left=new node(x);
			t=t->left;
		
		}
	}
	
	
}
void Tree:: preorder()
{
	node*p=root;
	stack_ S;
	while(p!=NULL)
	{
		cout<<p->data;
		S.push(p);
		p=p->left;
	}
	while(!S.empty())
	{	p=S.pop();
		p=p->right;
	while(p!=NULL)
	{
		cout<<p->data;
		S.push(p);
		p=p->left;
	}
		
		
		
	}
	
}
int main()
{
	Tree obj;
	obj.create();
	obj.preorder();
	
}
