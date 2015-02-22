/*
4.5
*/

#include<cstdio>
#include<climits>
using namespace std;

struct node
{	int data;
	node *left, *right;
	node()
	{	left=NULL, right=NULL;
		data=-1;
	}
	node (int d )
	{	left=NULL, right=NULL;
		data=d;
	}
};

void insert ( node **root, int d )
{	if ( *root == NULL )
	{	*root=new node();
		(*root)->data=d;
		return;
	}
	node *p, *q;
	p=NULL;
	q=*root;
	while ( q != NULL )
	{	if ( d < q->data )
		{	p=q;
			q=q->left;
		}
		else
		{	p=q;
			q=q->right;
		}
	}
	node *t=new node();
	t->data=d;
	if ( d < p->data )
		p->left=t;
	else
		p->right=t;
}

void print ( node *root )
{	while ( root != NULL )
	{	printf("%d %p %p %p\n", root->data, root->left, root, root->right);
		root=root->right;
	}
	printf("\n");
}

bool check_for_bst ( node *root, int start, int end );

int main()
{	node *root=NULL;
	int d;
	/*
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
        */
	root=new node(10);
        root->left=new node(3);
        root->right=new node(15);
        root->left->right=new node(4);
        root->right->left= new node(12);
	int start=INT_MIN , end=INT_MAX;
	printf("is bst: %d\n",check_for_bst(root,start,end));
	return 0;
}

bool check_for_bst ( node *root, int start, int end )			// top down approach
{	if ( root == NULL )
		return 1;
	if ( root->data >= start && root->data <= end )
		return check_for_bst(root->left,start,root->data-1) && check_for_bst(root->right,root->data, end);
	return 0;
}

/*
		node
	< node		>= node
*/
