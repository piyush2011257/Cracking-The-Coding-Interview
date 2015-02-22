/*
9.3
*/
#include<cstdio>
#include<iostream>
using namespace std;

int func ( int *a, int n );

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<func(a,n)<<endl;
	return 0;
}

int func ( int *a, int n )
{	int s=0, e=n-1;
	int m;
	while ( s <= e )
	{	m=(s+e)/2;
		if ( a[m] == m )
			return m;
		if ( a[m] > m )
			e=m-1;
		else
			s=m+1;
	}
	return -1;
}

/*
idx	0 1 2 3 4 5 6 7
val		5			a[idx] > idx

Consider this case where a[idx] > idx
Now since all sorted and no duplicate, for [m+1,e] we cannot have any solution since a[idx] > idx 

val	 	3			a[idx] < val
Using above reason if a[idx] < idx

Given- all sorted and NO repetition
*/	
