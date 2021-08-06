#include<iostream>
using namespace std;
	int fibo_rec(int n)
	{
		if(n==1)
		return 1;
		if(n==0)
		return 0;
		else return n-1+fibo_rec(n-2);
	}

int main()
{
	int n;
	cout<<"enter no.of term find fibo";
	cin>>n;
	cout<<fibo_rec(n);

}
