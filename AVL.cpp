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
class AVL
{
	node *root;
	public :
		AVL()
		{
			root=NULL;
		}
		node *check_node(node *t)
		{
			if(bal_fac(t)==2)
			{
				if(bal_fac(t->left)==1 || bal_fac(t->left)==0)
				{
					t=rotateright(t);
				}
				else
				{
					t=rotateLR(t);
				}
			}
			else if(bal_fac(t)==-2)
			{
				
				if(bal_fac(t->left)==-1 || bal_fac(t->left)==0)
				{
					t=rotateleft(t);
				}
				else
				{
					t=rotateRL(t);
				}
			}
			return t;
		}
		node *insert(node *t,int x)
		{
			if(t==NULL)
			{
			//	cout<<"a"<<endl;
				t=new node(x);
				return t;
			}
			if(x<t->data)
			{
				t->left=insert(t->left,x);
				if(bal_fac(t)==2)
				{
					if(x<t->left->data)
					{
						//cout<<"a"<<endl;
						t=rotateright(t);
					}
					else
					{
						t=rotateLR(t);
					}
				}
				return t;
			}
			if(x>t->data)
			{	
				t->right=insert(t->right,x);
				if(bal_fac(t)==-2)
				{
					if(x>t->right->data)
					{//	cout<<"a"<<endl;
						t=rotateleft(t);
					}
					else
					{
						t=rotateRL(t);
					}
				}
				return t;
			}
			else
				{
					return t;
				}
			
		}
		void  create()
		{	cout<<"enter data to add or -1 to stop"<<endl;
			int x;
			while(1)
			{	
				cin>>x;
				if(x==-1)
				{
					return;
				}
				root=insert(root,x);
				
			}
		}
		void inorder(node *t)
		{
			if(t!=NULL)
			{
				inorder(t->left);
				cout<<"data : "<<t->data<<" "<<"height : "<<height(t)<<"bal_fac  : "<<bal_fac(t)<<endl;
				inorder(t->right);
			}
		}
		void display()
		{
			inorder(root);
			
		}
		int height(node *t)
		{
			if(t==NULL)
			{
				return 0;
				
			}
			if(t->left==NULL && t->right==NULL)
			{
				return 0;
			}
			int hl=0,hr=0;
			hl=height(t->left);
			hr=height(t->right);
			if(hl>hr)
			{
				return hl+1;
				
			}
			else 
			{
				return hr+1;
			}
		}
		node *rotateleft(node *t)
		{	cout<<"a"<<endl;
			node *p=t->right;
			t->right=p->left;
			p->left=t;
			return p;
			
		}
		node *rotateright(node *t)
		{	cout<<"a"<<endl;
			node *p=t->left;
			t->left=p->right;
			p->right=t;
			return p;
		}
		node *rotateLR(node *t)
		{	cout<<"a"<<endl;
			t->left=rotateleft(t->left);
			t=rotateright(t);
			return t;
		}
		node *rotateRL(node *t)
		{	cout<<"a"<<endl;
			t->right=rotateright(t->right);
			t=rotateleft(t);
			return t;
			
			
		}
		int bal_fac(node *t)
		{	int hl=0,hr=0;
			if(t->left!=NULL)
			{
				
				hl=1+height(t->left);
				
			}
			if(t->right!=NULL)
			{
					hr=1+height(t->right);
				
			}
			//cout<<t->data<<" "<<hl<<"  "<<hr<<endl;
			return hl-hr;
	
		}
		void del()
		{	cout<<"enter data to delete"<<endl;
			int x;
			cin>>x;
			root=delete_rec(root,x);
		}
		node *find_min(node *t)
		{	while(t->left!=NULL)
			{
				t=t->left;
			}
			return t;
		}
		node *delete_rec(node *t,int x)
		{	node *p;
			if(t==NULL)
			{
				return NULL;
				
			}
			if(x<t->data)
			{
				t->left=delete_rec(t->left,x);
				t=check_node(t);
				return t;
			}
			if(x>t->data)
			{
				t->right=delete_rec(t->right,x);
				t=check_node(t);
				return t;
			}
			//leaf node
			if(t->left==NULL && t->right==NULL)
			{
				delete t;
				return NULL;
				
			}
			//one child;
			if(t->left==NULL)
			{
				p=t->right;
				delete t;
				return p;
			}
			if(t->right==NULL)
			{
				p=t->left;
				delete t;
				return p;
			}
			else
			{
				p=find_min(t->right);
				t->data=p->data;
				t->right=delete_rec(t->right,p->data);
				t=check_node(t);
				return t;
			}
			
		}
};
int main()
{
	AVL obj;
	obj.create();
	obj.display();
	obj.del();
	obj.display();
}













