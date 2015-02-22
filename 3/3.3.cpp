/*
3.3
*/
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

struct node
{	node *next;
	stack <int> s;
	node()
	{	next=NULL;	}
};

void insert(node **root, int d, int cap );
void print ( node *root );


int main()
{	int cap;
	cin>>cap;			// >= 1
	int d;
	node *root=NULL;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d,cap);
	print(root);
	return 0;
}

void insert(node **root, int d, int cap )
{	if ( *root == NULL )
	{	*root=new node();
		(*root)->s.push(d);
	}
	else
	{	if ( (*root)->s.size() == cap )
		{	node *tmp=new node();
			tmp->s.push(d);
			tmp->next=*root;
			*root=tmp;
		}
		else
			(*root)->s.push(d);
	}
}

void print ( node *root )
{	while ( root != NULL )
	{	while ( root->s.empty() == 0 )
		{	cout<<root->s.top()<<" ";
			root->s.pop();
		}
		root=root->next;
		printf("\n");
	}
}
