/*
2.7

odd length

1 	2	 3	 2	 1
| 		 |
root	    second_half

1       2        3       2       1
	|        |
       root   second_half

1       2        3       2       1
                 ||
             root/second				<- Base Case. Now return from recursion
		  _half

1       2        3       2       1
        |		 |
      root	    second_half

1       2        3       2       1
|                		 |
root          		     second_half


even length

1       2        3       3	2       1
|                	 |
root        	     second_half

1       2        3       3	2       1
        |        	 |
       root   	     second_half

1       2        3       3	2       1
                 |	 |
                root  second_half			<- Base Case. Now return from recursion

1       2        3       3	2       1
        |                	|
      root          	   second_half

1       2        3       3	2       1
|                               	|
root                         	    second_half

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

int get_length ( node *h)
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

node * find_mid ( node *root )
{	node *fast=root, *slow=root;
	while ( fast->next != NULL && fast->next->next != NULL )
	{	slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

bool check_pallindrome ( node *root, node *mid, node **second_half, int len );

int main()
{	int x;
	node *root=NULL;
	while ( scanf("%d",&x) != EOF )
		push(&root,x);
	//print(root);
	int n= get_length(root);
	node *second_half=NULL, *mid;
	mid=find_mid(root); 
	if (  n % 2 == 0 )
		second_half=mid->next;
	else
		second_half=mid;
	printf("is_pallindrome: %d\n",check_pallindrome(root,mid,&second_half,n));
	return 0;
}

bool check_pallindrome ( node *root, node *mid, node **second_half, int len )	// inplace. O(1) space
{	if ( root == mid )
	{	if ( len % 2 == 0 )
			return mid->data == (*second_half)->data;
		else
			return 1;
	}
	if ( check_pallindrome(root->next,mid,second_half,len) == 0 )
		return 0;
	(*second_half)=(*second_half)->next;
	if ( root->data == (*second_half)->data )
		return 1;
	return 0;
}
