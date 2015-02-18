/*
2.5
i/p
7 1 6
5 9 2
o/p-
2 1 9
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

int getlength ( node *h)
{	int i=0;
	while ( h!=NULL )
	{	i++;
		h=h->next;
	}
	return i;
}

node * add_number ( node *root1, node *root2 );

int main()
{	int d;
	node *root1=NULL, *root2=NULL;
	while ( scanf("%d",&d) != EOF )
		push(&root1,d);
	print(root1);	
        while ( scanf("%d",&d) != EOF )
                push(&root2,d);
        print(root2);
	print(add_number(root1, root2));
	return 0;
}

node * add_number ( node *root1, node *root2 )
{	node *root_h=NULL, *root_t=NULL;
	int sum,carry=0;
	while ( root1 != NULL && root2 != NULL )
	{	sum=root1->data+root2->data;
		sum +=carry;
		carry=sum/10;
		sum=sum%10;
		if ( root_h == NULL )
			root_h=root_t=new node(sum);
		else
		{	root_t->next=new node(sum);
			root_t=root_t->next;
		}
		root1=root1->next;
		root2=root2->next;
	}
	while ( root1 != NULL )
	{	sum= root1->data+carry;
		carry=sum/10;
		sum=sum%10;
		if ( root_h == NULL )
                        root_h=root_t=new node(sum);
                else
                {       root_t->next=new node(sum);
                        root_t=root_t->next;
                }
		root1=root1->next;
	}
        while ( root2 != NULL )
        {       sum= root2->data+carry;
                carry=sum/10;
                sum=sum%10;
                if ( root_h == NULL )
                        root_h=root_t=new node(sum);
                else
                {       root_t->next=new node(sum);
                        root_t=root_t->next;
                }
                root2=root2->next;
        }
	if ( carry != 0 )
	{	root_t->next = new node(carry);
		root_t=root_t->next;
		carry=0;
	}
	return root_h;
}
