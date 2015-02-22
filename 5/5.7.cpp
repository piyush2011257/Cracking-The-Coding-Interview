/*
5.7
*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int func ( vector<int> v, int c );

int main()
{	int n,d;
	cin>>n;
	vector<int> v;
	for ( int i=0; i<n; i++ )
	{	cin>>d;
		v.push_back(d);
	}
	cout<<func(v,0)<<endl;
}

int func ( vector<int> v, int c )
{	if ( v.size() == 0 )
		return 0;
	vector<int>zero;
	vector<int>one;
	int ct_0=0, ct_1=0;
	for ( int i=0; i<v.size(); i++ )
	{	if ( ( v[i] & (1<<c) ) != 0 )
		{	one.push_back(v[i]);
			ct_1++;
		}
		else
		{	zero.push_back(v[i]);
			ct_0++;
		}
	}
	/*
	cout<<"Zero"<<endl;
	for ( int i=0; i<zero.size(); i++ )
		cout<<zero[i]<<" ";
	cout<<endl;
	cout<<"One"<<endl;
	for ( int i=0; i<one.size(); i++ )
		cout<<one[i]<<" ";
	cout<<endl;
	*/
	if ( (v.size()+1)%2 == 0 )
	{	if ( ct_0 < ct_1 )
		{	int v=func(zero,c+1);
			v = (v<<1) | 0;
			//cout<<v<<endl;
			return v;
		}
		else
		{       int v=func(one,c+1);
                        v = (v<<1) | 1;
                        //cout<<v<<endl;
			return v;
		}
	}
	else
        {       if ( ct_0 == ct_1 )
                {       int v=func(zero,c+1);
                        v = (v<<1) | 0;
                        //cout<<v<<endl;
                        return v;
                }
                else 
                {       int v=func(one,c+1);
                        v = (v<<1) | 1;
                        //cout<<v<<endl;
                        return v;
                }
        }
}

/*

N=5+1
000
001 ---
010
011
100
101


N=2+1
001 ---
011
101

N=1+1
001 ---
101

N=0+1
001 ---
*/


