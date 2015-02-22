/*
3.3
*/
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

struct node
{	node *next, *prev;			// DLL
	stack <int> s;
	node()
	{	next=prev=NULL;		}
};

void insert(node **root, int d, int cap );
void print ( node *root );
void pop ( node ** root, int idx );

int main()
{	int cap;
	cin>>cap;			// >= 1
	int d;
	node *root=NULL;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d,cap);
	//print(root);
	while ( scanf("%d",&d) != EOF )
		pop(&root,d);
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
			(*root)->prev=tmp;
			*root=tmp;
		}
		else
			(*root)->s.push(d);
	}
}

void print ( node *root )
{	while ( root != NULL )
	{	cout<<root<<" "<<root->s.size()<<endl;
		while ( root->s.empty() == 0 )
		{	cout<<root->s.top()<<" ";
			root->s.pop();
		}
		root=root->next;
		printf("\n");
	}
}

void pop ( node ** root, int idx )
{	node *tmp=*root;
	idx--;
	while ( tmp != NULL && idx-- > 0 )
		tmp=tmp->next;
	if ( tmp == NULL )
	{	printf("Invalid index\n");
		return;
	}
	cout<<tmp<<" "<<tmp->s.size()<<endl;
	printf("pop: %d\n", tmp->s.top());
	tmp->s.pop();					// Maintain individual stack. Delete stack if cap = 0
	cout<<tmp->s.size()<<" "<<tmp->s.empty()<<endl;
	if ( tmp->s.empty() == 1 )
	{	if ( tmp->prev != NULL )
		{	tmp->prev->next=tmp->next;
			if ( tmp->next != NULL )
				tmp->next->prev=tmp->prev;
		}
		else
		{	cout<<"Yes"<<endl;
			(*root)=tmp->next;
			if ( *root != NULL )
				(*root)->prev=NULL;
		}
			
	}
}
