#include<iostream>
using namespace std;
class node 
{	public :
	int data;
	node*next;
	node(int x)
	{
		data=x;
	}
	
};


node* create_rec();
void show_rec(node*p);
node* del_rec(node*head,int x);
class Sll
{
	node *head;
	public :
		Sll()
		{
			head=NULL;
		}
		void create();
		void show();
		void del(int );
		int count();
		int search(int );
};
void Sll:: create()
{
	head=create_rec();
}
node* create_rec()
{	node *p;
	int x;
	cout<<"enter data to add or -1 to stop"<<endl;
	cin>>x;
	if(x==-1)
	return NULL;
	else
	p=new node(x);
	p->next=create_rec();
	return p;
	
	
}
void Sll::show()
{
	show_rec(head);	
}
void show_rec(node*p)
{
	if(p==NULL)
	{
		return;
		
	}
	else {
		cout<<p->data;
		show_rec(p->next);
	}
}
node*del_rec(node*p,int x)
{	if(p!=NULL)
	{
		if(p->data == x)
		{
			node *q= p->next;
			delete p;
			return q;
		}
		else
		{
			p->next = del_rec(p->next,x);
			return p;
		}
	}
	else
	{
		return NULL;
	}
}
void Sll::del(int x)
{
	head=del_rec(head,x);	
}
int main()
{
	Sll obj;
	obj.create();
	obj.show();
	int x;
	cout<<"Enter the data to delete: ";
	cin>>x;
	obj.del(x);
}
