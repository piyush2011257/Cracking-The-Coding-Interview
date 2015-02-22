/*
5.5
*/
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{	int a,b,ct=0;
	cin>>a>>b;
	int diff=a^b;
	//cout<<diff<<endl;
	while ( diff != 0 )
	{	ct++;
		diff= diff & (diff-1);
		//cout<<diff<<endl;
	}
	cout<<ct<<endl;
	return 0;
}
