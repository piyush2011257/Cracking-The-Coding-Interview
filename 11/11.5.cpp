/*
11.5
*/

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int binary_search( string *a, int n, string ele );

const int n=15;
int main()
{	string a[n]={"a","","","","b","","bc","bcd","","c","d","","","","f"};
	string ele="ab";
	cout<<binary_search(a,n,ele)<<endl;
	return 0;
}

int binary_search( string *a, int n, string ele )
{	int s=0, e=n-1;
	while ( s <= e )
	{	int m=(s+e)/2;
		cout<<s<<" "<<e<<" "<<m<<endl;
		if ( a[m].compare(ele) == 0 )
			return m;
		if ( a[m].size() == 0 )		// empty_string
		{	cout<<"empty_string mid"<<endl;
			int l=m-1;
			int r=m+1;
			while ( l >= s && a[l].size() == 0 && r <= e && a[r].size() == 0 )	// look for first non-empty string in left and right
				l--,r++;
			if ( l < s )			// if l < s, no non-empty string on left side of mid
				s=r;
			else if ( r > e )		// if r > e, no non-empty string on right side of mid
				e=l;	
			else
			{	if ( a[l].size() > 0 )	// if l found the first non-empty, then binary search according to left
				{	if ( a[l].compare(ele) == 0 )
						return l;
					else if ( a[l].compare(ele) < 0 )
						s=l+1;
					else
						e=l-1;
				}
				else			// if r found first non-empty, then binary search according to right
				{	cout<<a[r].compare(ele)<<" "<<a[r]<<" "<<ele<<endl;
					if ( a[r].compare(ele) == 0 )
						return r;
					else if ( a[r].compare(ele) < 0 )
						s=r+1;
					else
						e=r-1;
				}
			}
		}
		else if ( a[m].compare(ele) < 0 )	// m was non-empty cases
			s=m+1;
		else
			e=m-1;
	}
	return -1;
}
