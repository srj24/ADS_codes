#include<iostream>
using namespace std;
int prime_rec(int x,int y)
{
	if(y==x/2)
	return 0;
	else
	if(x%y==0)
	return 1;
	else prime_rec(x,y+1);
}
int main()
{
	int n;
	cout<<"enter no:";
	cin>>n;
	if(prime_rec(n,2)) cout<<"not prime!!"<<endl;
	else cout<<" prime";
	
}
