/*
5.2
*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string to_binary ( double n );
double to_decimal ( string str );

int main()
{	double n;		// n E (0,1)
	cin>>n;
	string str= to_binary(n);
	cout<<str<<endl;
	cout<<to_decimal(str)<<endl;
	return 0;
}

string to_binary ( double n )
{	string str;
	while ( str.length() < 32 && n > 0 )
	{	n=n*2.0;		// no bitwise and % on float / double
		if ( n >= 1 )
		{	str += '1';
			n-=1;
		}
		else
			str += '0';
	}
	return str;
}

double to_decimal ( string str )
{	int div=2;
	double sum=0;
	for ( int i=0; i<str.length(); i++, div *=2 )
		if ( str[i] == '1' )
		{	sum  += (double)( 1.0 / div );
			cout<<sum<<" ";
		}
	return sum;
}
