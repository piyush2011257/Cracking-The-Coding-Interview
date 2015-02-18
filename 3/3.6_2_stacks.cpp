#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void sort ( stack<int> &s1, stack<int> &s2 );

int main()
{	stack<int> s1;
	stack<int> s2;
	int d;
	while ( scanf("%d",&d) != EOF )
		s1.push(d);
	sort(s1,s2);
	while ( s2.empty() == 0 )
	{	cout<<s2.top()<<" ";
		s2.pop();
	}
	cout<<endl;
	return 0;
}

void sort ( stack<int> &s1, stack<int> &s2 )		// Use insertion sort logic.
{	while ( s1.empty() == 0 )
	{	int ele=s1.top(), ct=0;
		s1.pop();
		while ( s2.empty() == 0 && s2.top() < ele )
		{	s1.push(s2.top());
			s2.pop();
			ct++;
		}
		s2.push(ele);
		while ( ct-- > 0 )
		{	s2.push(s1.top());
			s1.pop();
		}
	}
}

/*
For 3 stacks
we found smallest at each step and pushed it into the o/p stack at each step and used 2nd buffer as intermediate for finding smallest element ( Selection Sort )

For 2 stacks
We do not find smallest but keep on sorting, the top k elements ( Insertion Sort ) and use the first stack itself for storing intermediate popped elements
*/
