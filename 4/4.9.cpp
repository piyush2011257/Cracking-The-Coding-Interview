/*
4.9
*/

#include<cstdio>
#include<climits>
#include<vector>
#include<cstring>
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

int func ( node *root, vector<int> &v );

int main()
{	node *root=NULL;
	int d;
	while ( scanf("%d",&d) != EOF )
		insert(&root,d);
	/*
	root=new node(10);
        root->left=new node(3);
        root->right=new node(15);
        root->left->right=new node(4);
        root->right->left= new node(12);
	*/
	vector<int> v;
	printf("max_path: %d\n",func(root,v));
	return 0;
}

int func ( node *root, vector<int> &v )
{	if ( root == NULL )
	{	//largest contiguous subarray
         	int n=v.size();
		int old_sum=v[0], max_sum=v[0];
        	for ( int i=1; i<n; i++ )
        	{       if ( old_sum + v[i] >= 0 )
	                {       old_sum=old_sum+v[i];
        	                if ( old_sum > max_sum )
                	                max_sum=old_sum;
                	}
                	else
                	{       old_sum=0;
                	        if ( v[i] > max_sum )
                	                max_sum=v[i];
                	}
        	}
        	return max_sum;
	}
	v.push_back(root->data);
	int l=func(root->left,v);
	int r=func(root->right,v);
	v.pop_back();
	return l > r ? l : r;
}
