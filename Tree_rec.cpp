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
node* create_rec();
void preorder(node *t);
void inorder(node *t);
void postorder(node *t);
int count_rec(node *t);
int search_rec(node*t,int x);
class Tree
{
	node*root;
	public :
		Tree()
		{
			root=NULL;
		}
		void create();
		void show();
		int count();
		int search(int x);
		int leafnodes();
};



void Tree::create()
{
	root=create_rec();
}
node* create_rec()
{	int x;
	node*p;
	cout<<"enter data to add or -1 to stop"<<endl;
	cin>>x;
	if(x==-1) return NULL;
	else
	{	p=new node(x);
		cout<<"enter data to left of:"<<x<<endl;
		p->left=create_rec();
		cout<<"enter data to add rigt of :"<<x<<endl;
		p->right=create_rec();
		return p;	
		}	
		
	
}
void Tree::show()
{	cout<<"preorder:"<<endl;
	preorder(root);
	cout<<"inorder:"<<endl;
	inorder(root);
	cout<<"post order:"<<endl;
	postorder(root);
}
void preorder(node *t)
{	
	if(t!=NULL)
	{
		cout<<t->data;
		preorder(t->left);
		preorder(t->right);
		
	}
}
void inorder(node *t)
{
	if(t!=NULL)
	{
		
		inorder(t->left);
		cout<<t->data<<endl;
		inorder(t->right);
		
	}
}
void postorder(node *t)
{
	if(t!=NULL)
	{
		//cout<<t->data;
		preorder(t->left);
		preorder(t->right);
		cout<<t->data<<endl;
		
	}
}
int Tree::count()
{
	return(count_rec(root));
}
int count_rec(node *t)
{
	if(t==NULL)
	{
		return 0;
		
	}
	else return(1+count_rec(t->left)+count_rec(t->right));
}
int Tree::search(int x)
{
	return search_rec(root,x);
}
int search_rec(node*t,int x)
{	int z,y;
	if(t==NULL)
	return 0;
	else 
	if(t->data==x)
	{
		return 1;
	}
	else 
	{	z=search_rec(t->left,x);
		y=search_rec(t->right,x);
		return z+y;
	}
	
}
int leafnodes()
{
	return leafnodes_rec(root)

}
int leafnodes_rec(node *t)
{
	
}


int main()
{	int x;
	Tree obj;
	obj.create();
	obj.show();
	cout<<"number of nodes is "<<obj.count();
	cout<<"enter node to searech:"<<endl;
	cin>>x;
	if(obj.search(x)) cout<<"found !!";
	else cout<<"not found";	
	obj.leafnodes();
}
