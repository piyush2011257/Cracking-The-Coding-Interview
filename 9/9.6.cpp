/*
9.6
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

void func ( int n, string str, int open, int sum );

int main()
{	int n;
	cin>>n;
	string str;
	func(n,str,0,0);
	return 0;
}

void func ( int n, string str, int open, int sum )
{	if ( open == n && sum  == 0 )
	{	str += '\0';
		cout<<str<<endl;
		return;
	}
	if ( open < n )
		func(n,str+'(',open+1,sum+1);
	if ( sum > 0 )
		func(n,str+')',open,sum-1);
}
