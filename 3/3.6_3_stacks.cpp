#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void sort ( stack<int> &s1, stack<int> &s2, stack<int> &s3 );

int main()
{	stack<int> s1;
	stack<int> s2;
	stack<int> s3;
	int d;
	while ( scanf("%d",&d) != EOF )
		s1.push(d);
	sort(s1,s2,s3);
	while ( s3.empty() == 0 )
	{	cout<<s3.top()<<" ";
		s3.pop();
	}
	cout<<endl;
	return 0;
}

void sort ( stack<int> &s1, stack<int> &s2, stack<int> &s3 )
{	while ( s1.empty() == 0 )
	{	int max=s1.top();
		while ( s1.empty() == 0 )
		{	int t=s1.top();
			if ( t > max )
				max=t;
			s2.push(s1.top());
			s1.pop();
		}
		while ( s2.empty() == 0 )
		{	if ( s2.top() == max )
			{	s3.push(s2.top());
				s2.pop();
			}
			else
			{	s1.push(s2.top());
				s2.pop();
			}
		}
	}
}
