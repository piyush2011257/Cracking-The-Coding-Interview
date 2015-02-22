/*
9.10
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{	int l,b,h;
};
/*
bool cmp ( node a, node b )
{	if ( a.l > b.l && a.b > b.b && a.h > b.h )
		return 1;
	return 0;
}
*/

int lis ( node *a, int n );

int main()
{	int n;
	cin>>n;
	node a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i].l>>a[i].b>>a[i].h;
	// Assume sorted i/p. Sorting can be done using merge / quick sort-O(NlogN)
	/*
	sort(a,a+n,cmp);
	cout<<"sorted"<<endl;
	for ( int i=0; i<n; i++ )
		cout<<a[i].l<<" "<<a[i].b<<" "<<a[i].h<<endl;
	*/
	cout<<lis(a,n)<<endl;
	return 0;
}

int lis ( node *a, int n )		// Box stacking problem
{	int max[n];
	memset(max,0,sizeof max);
	max[0]=a[0].h;
	for ( int i=1; i<n; i++ )
	{	for ( int j=i-1; j>=0; j-- )
			if ( a[i].l < a[j].l && a[i].b < a[j].b && a[i].h < a[j].h )
			{	if ( max[j]+a[i].h > max[i] )
					max[i]=max[j]+a[i].h;
			}
	}
	int mx=0;
	for (int i=0; i<n; i++ )
		if ( max[i] > mx )
			mx=max[i];
	return mx;
}
