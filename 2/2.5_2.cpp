/*
2.5
i/p
6 1 7 
2 9 5
o/p-
9 1 2
*/

#include<cstdio>
using namespace std;

struct node
{	node *next;
	int data;
	node(int d=-1, node *n=NULL)
	{	data=d;
		next=n;
	}
	
};

void push(node **h, int d )
{	if ( *h == NULL )
	{	*h= new node(d);
		return;
	}
	node *t=*h;
	while ( t->next != NULL )
		t=t->next;
	node *tmp=new node(d);
	t->next=tmp;
}

void print(node *h)
{	while(h != NULL )
	{	printf("%d -> ", h->data);
		h=h->next;
	}
	printf("\n");
}

int get_length ( node *h)
{	int i=0;
	while ( h!=NULL )
	{	i++;
		h=h->next;
	}
	return i;
}

node * add_number ( node *root1, node *root2 );
void add_zero( node **root2, int n );
node * add_number_recursive ( node *root1, node *root2, int &carry );

int main()
{	int d;
	node *root1=NULL, *root2=NULL;
	while ( scanf("%d",&d) != EOF )
		push(&root1,d);
        while ( scanf("%d",&d) != EOF )
                push(&root2,d);
	int l1=get_length(root1);
	int l2=get_length(root2);
	if ( l1 > l2 )
		add_zero(&root2,l1-l2);
	else if ( l2 > l1 )
		add_zero(&root1,l2-l1);
	print(root1);
	print(root2);
	print(add_number(root1, root2));
	return 0;
}

void add_zero ( node **root, int n )
{	while ( n-- > 0 )
	{	node *tmp= new node(0);
		tmp->next=*root;
		*root=tmp;
	}
}

node * add_number ( node *root1, node *root2 )
{	int carry=0;
	node * root= add_number_recursive( root1, root2, carry);
	if ( carry != 0 )
	{	node * tmp= new node(carry);
		tmp->next=root;
		root=tmp;
	}
	return root;
}

node * add_number_recursive ( node *root1, node *root2, int &carry )
{	if ( root1 == root2 && root1 == NULL )
	{	carry=0;
		return NULL;
	}
	node *next=add_number_recursive(root1->next, root2->next, carry);
	int sum= root1->data+root2->data;
	sum +=carry;
	carry=sum/10;
	sum=sum%10;
	node *tmp= new node(sum);
	tmp->next=next;
	return tmp;
}
