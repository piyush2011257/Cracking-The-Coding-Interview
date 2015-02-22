/*
4.4
*/

#include<cstdio>
#include<climits>
#include<list>
#include<vector>
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

void level_connect ( node *root, vector < vector<node *> > &l, int level );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	vector < vector<node *> > l;
	level_connect(root,l,0);
	for ( int i=0; i<l.size(); i++ )
	{	printf("level: %d\n",i);
		for ( int j=0; j<l[i].size(); j++ )
			printf("%d-> ", l[i][j]->data);
		printf("\n");
	}
		
	return 0;
}

void level_connect ( node *root, vector < vector<node *> > &l, int level )
{	if ( root == NULL )
		return;
	if ( l.size() == level )
	{	vector<node *> t;
		l.push_back(t);
	}
	l[level].push_back(root);
	level_connect(root->left,l,level+1);
	level_connect(root->right,l,level+1);
}
