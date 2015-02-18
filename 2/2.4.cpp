/*
2.4
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

int getlength ( node *h)
{	int i=0;
	while ( h!=NULL )
	{	i++;
		h=h->next;
	}
	return i;
}

void print ( node *root )
{	while (root != NULL )
	{	printf("%d ", root->data);
		root=root->next;
	}
	printf("\n");
}

void quick_sort_partition_single_ll( node **root, int x );

int main()
{	int x;
	node *root=NULL;
	while ( scanf("%d",&x) != EOF )
		push(&root,x);
	scanf("%d",&x);
	//print(root);
	//printf("x: %d\n",x);
	quick_sort_partition_single_ll(&root,x);
	print(root);
	return 0;
}

void quick_sort_partition_single_ll(node **root, int x )
{	// Node here we have been given a value x explicitly. NOT any node in the linked list
	node *before_h, *before_t, *after_h, *after_t, *tmp;
	before_h=before_t=after_h=after_t=NULL;
	tmp=*root;
	while ( tmp != NULL )
	{	if ( tmp->data < x )
		{	if ( before_h == NULL )
				before_h=before_t=tmp;
			else
			{	before_t->next=tmp;
				before_t=tmp;
			}
		}
		else
		{       if ( after_h == NULL )
 	        	       after_h=after_t=tmp;
                        else
                        {       after_t->next=tmp;
				after_t=tmp;
			}
		}
		tmp=tmp->next;
	}
	/*
	if ( before_h != NULL )
		printf("before: %d %d\n", before_h->data, before_t->data);
	if ( after_h != NULL )
		printf("after: %d %d\n", after_h->data, after_t->data);
	*/
	if ( before_h == NULL )
	{	before_h=before_t=after_h;
		after_t->next=NULL;
	}
	else
	{	before_t->next=after_h;
		if ( after_h != NULL )
			after_t->next=NULL;
	}
	*root=before_h;
}
