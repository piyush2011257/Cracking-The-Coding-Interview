/*
9.3
*/
#include<cstdio>
#include<iostream>
using namespace std;

int func ( int *a, int s, int e );
int max ( int a, int b )
{	return a > b ? a : b;	}

int min ( int a, int b )
{	return a < b ? a : b;	}

int main()
{	int n;
	cin>>n;
	int a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	cout<<func(a,0,n-1)<<endl;
	return 0;
}

int func ( int *a, int s, int e )
{	cout<<s<<" "<<e<<endl;	
	if ( s > e )
		return -1;
	int m=(s+e)/2;
	if ( a[m] == m )
		return m;
	int v1;
	v1= func(a,s,min(m-1, a[m]));
	if (  v1 != -1 )
		return v1;
	return func(a,max(m+1,a[m]),e);
}

/*
Given- all sorted and repetition ALLOWED

CONSIDER
idx     0 1 2 3 4 5 6 7
val             6                       a[idx] > idx

NOw all values after idx=4 will be >= 6 and hence a[5] will never be = 5 and hence we need to start from idx=6 only for possible matches

val             2                       a[idx] < val
Using above reason
*/	
