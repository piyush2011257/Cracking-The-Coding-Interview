/*
4.6
*/

#include<cstdio>
#include<climits>
using namespace std;

struct node
{	int data;
	node *left, *right, *parent;
	node()
	{	left=NULL, right=NULL, parent=NULL;
		data=-1;
	}
	node (int d )
	{	left=NULL, right=NULL, parent=NULL;
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
	t->parent-p;
}

void print ( node *root )
{	while ( root != NULL )
	{	printf("%d %p %p %p\n", root->data, root->left, root, root->right);
		root=root->right;
	}
	printf("\n");
}

node * inorder_successor( node *root );
void in_order ( node *root, int d, node **t );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	scanf("%d",&d);
	node *t=NULL;
	in_order(root,d,&t);
        t=inorder_successor(t);
	if ( t == NULL )
		printf("No inorder successor\n");
	else
		printf("inorder_successor: %d\n", t->data);
	return 0;
}

void in_order ( node *root, int d, node **t )
{	if ( root == NULL )
		return;
	if ( root->data == d )
	{	*t=root;			// find the node whose in_order successor is to be found
		return;
	}
	in_order(root->left,d,t);
	in_order(root->right,d,t);
}

node * inorder_successor( node *root )
{	if ( root == NULL )
		return NULL;
	if ( root->right != NULL )
	{	root=root->right;
		while ( root->left != NULL )
			root=root->left;
		return root;
	}
	node *p=root->parent;
	node *q=p;
	while ( p != NULL && p->right == q )
	{	q=p;
		p=p->parent;
	}
	return p;
}
