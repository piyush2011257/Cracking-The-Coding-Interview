/*
3.5
Implement queue using 2 stacks
*/

#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void reshuffle ( stack<int> &s1, stack<int> &s2 )
{	while ( s1.empty() == 0 )
	{	s2.push(s1.top());
		s1.pop();
	}
}

void pop ( stack<int> &s1, stack<int> &s2 )
{	if ( s2.empty() == 1 )
	{	if ( s1.empty() == 1 )
		{	printf("Underflow\n");
			return;
		}
		reshuffle(s1,s2);
		printf("pop: %d\n", s2.top());
		s2.pop();
	}
	else
	{	printf("pop: %d\n", s2.top());
		s2.pop();
	}
}

// size of queue = s1.size() + s2.size()

int main()
{	stack<int> s1;
	stack<int> s2;
	int d;
	while ( scanf("%d",&d) != EOF )
	{	cout<<d<<endl;
		if ( d == 1 )
		{	scanf("%d",&d);
			s1.push(d);
		}
		else if ( d == 0 )
			pop(s1,s2);
	}
	return 0;
}

/* Earlier
stack1
1 2 3 4 5
	|
       TOP

stack2 - empty

POP()
stack2 
5 4 3 2 1
	|
       top	<- remove this top element

stack1 - empty

Push back all on stack1

stack1
2 3 4 5
      |
     top

stack2 - empty

FOr subsequent pop() again pop from stack1 -> stack2 all elements in stack1 and remove top element of stack2 and push back again in stack1
ABOVE METHOD OPTIMIZES THIS APPROACH
*/

