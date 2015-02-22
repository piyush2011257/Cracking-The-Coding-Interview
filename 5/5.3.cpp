/*
5.3
https://martinm2w.wordpress.com/2012/06/03/5-3-bits-next-smallest-and-largest-have-the-same-no-of-1s/
http://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/
*/

#include<cstdio>
#include<iostream>
using namespace std;

void to_binary( int n, string &str )
{	if ( n == 0 )
		return;
	if ( n == 1 )
	{	str += '1';
		return;
	}
	char mod= (n%2 == 0) ? '0' : '1';
	to_binary(n/2,str);
	str+=mod;
}

void get_next(int n );
void get_prev(int n );

int main()
{	int n;
	cin>>n;
	string str;
	to_binary(n,str);
	cout<<str<<endl;
	str.clear();
	get_next(n);
	get_prev(n);
	return 0;
}

void get_next(int n )
{	int c1=0, c0=0, c=n;
	while ( c != 0 && (c & 1) == 0 )
	{	c0++;
		c>>=1;
	}
	while ( c != 0 && (c & 1) == 1 )
	{	c1++;
		c>>=1;
	}
	if ( c0+c1 == 32 || c0+c1 == 0 )
	{	cout<<"No next with same 1 bits"<<endl;
		return;
	}
	c=n;
	// c=1011000 
	c = c | ( 1 << (c0+c1));
	// c=1111000
	//cout<<c<<" ";
	c &= ~((1 << (c0+c1))-1);
	// c=1100000
	//cout<<c<<" ";
	c |= (1<<(c1-1))-1;
	// c=1100011
	cout<<c<<endl;
	string str;
	to_binary(c,str);
	cout<<str<<endl;
}

void get_prev ( int n )
{	int c1=0, c0=0, c=n;
        while ( c != 0 && (c & 1) == 1 )
        {       c1++;
                c>>=1;
        }
        while ( c != 0 && (c & 1) == 0 )
        {       c0++;
                c>>=1;
        }
        if ( c0+c1 == 32 || c0+c1 == 0 )
        {       cout<<"No next with same 1 bits"<<endl;
                return;
        }
        c=n;
	// c = 10100111
	c= c & (~(1<<(c0+c1)));
	// c = 10000111
	// cout<<c<<" ";
	c= c & (~( (1<<(c0+c1))-1) );
	// c = 10000000
	// cout<<c<<" ";
	int tmp= (1<<(c1+1))-1;
	// tmp = 00001111
	tmp <<= (c0-1);
	// tmp = 00011110
	c = c | tmp;
	// c = 10011110
	cout<<c<<endl;
        string str;
        to_binary(c,str);
	cout<<str<<endl;
}
