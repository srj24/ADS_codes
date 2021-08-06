#include<iostream>
using namespace std;


class node
{
	public:
		int data;
		node *left,*right;
		int lbit,rbit;
		int child;
	node(int x)
	{
		data=x;
		lbit=rbit=1;
		left=right=NULL;
	}
	
		
};
void create_rec(node *father,int child)
{	int x;
node *t;
	cout<<"\n enter data ";
	cin>>x;
	if(x==-1)
		{
			return;
		
		}
		t=new node(x);
		if(child==0)
		{
			t->child =child;
			t->right = father;
			father->left=t;
			father->lbit=0;
			t->left=father->left;
			
		}
		else
		{
			t->child=child;
			t->right=father->right;
			t->left=father;
			father->rbit=0;
			father->right=t;
		}
		cout<<"\n enter data to left of"<<t->data;
				create_rec(t,0);
				cout<<"\n enter data to right of "<<t->data;
				create_rec(t,0);
}

class tbt
{
	node *root;
	public :
		tbt()
		{
			root=new node(-1);
			root->left=root->right=root;
		}
		void create()
		{
			create_rec(root,0);
		}
		void preorder()
		{
			node *t=root->left;
			while(t!=root)
			{
				cout<<t->data;
				t=pre_succ(t);
			}
		}
		node*pre_succ(node *t)
		{
			if(t->lbit==0)
		{
			return t->left;
		}
		while(t->rbit==1&&t!=root)
		{
			t=t->right;
		}
		return t;
		}
		void inorder()
		{
			node *t=root->left;
			while(t->lbit==0)
			{
				t=t->left;
			}
			while(t!=NULL)
			{
				cout<<t->data;
				t=inorder_secc(t);
			}
		}
		node* inorder_secc(node*t)
		{
			if(t->rbit==1)
			{
				return t->right;
				
			}
			t=t->right;
			while(t->lbit==0)
			{
				t=t->left;
			}
			return t;
		}
		
};
int main()
{	tbt obj;
		obj.create();
		cout<<"\npreorder:";
		obj.preorder();
		cout<<"\n inorder :";
	
}
