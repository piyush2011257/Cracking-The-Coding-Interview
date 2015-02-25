/*
11.2
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{	string str;
	string ana;
};

bool cmp ( node a, node b )
{	if ( a.ana.compare(b.ana) <= 0 )
		return 1;
	return 0;
}

int main()
{	int n;
	cin>>n;
	node a[n];
	for ( int i=0; i<n; i++ )
	{	cin>>a[i].str;
		a[i].ana=a[i].str;
		sort(a[i].ana.begin(), a[i].ana.end());	// O(L)
	}
	sort(a,a+n,cmp);				// NlogN*L
	for ( int i=0; i<n; i++ )
		cout<<a[i].str<<" "<<a[i].ana<<endl;
	return 0;
}
