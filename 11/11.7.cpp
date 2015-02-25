/*
11.7
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{	int w,h;
};

bool cmp ( node a, node b )	// whenever sorting based on 2 parameters needed
{	if ( a.w >= b.w )	// sort on the basis of weight only, this will already help in finding collisions on the basis of height
		return 1;
	return 0;
}
	
int func ( node *a, int n );

int main()
{	int n;
	cin>>n;
	node a[n];
	for ( int i=0; i<n; i++ )
		cin>>a[i].w>>a[i].h;
	cout<<func(a,n);
	return 0;
}

int func ( node *a, int n )
{	sort(a,a+n,cmp);
        int max[n];
        memset(max,0,sizeof max);
        max[0]=1;
	for ( int i=0; i<n; i++ )
		cout<<a[i].w<<" "<<endl;
        for ( int i=1; i<n; i++ )
        {       for ( int j=i-1; j>=0; j-- )
                        if ( a[i].h < a[j].h && a[i].w < a[j].w )
                        {       if ( max[j]+1 > max[i] )
                                        max[i]=max[j]+1;
                        }
        }
        int mx=0;
        for (int i=0; i<n; i++ )
                if ( max[i] > mx )
                        mx=max[i];
        return mx;

}
