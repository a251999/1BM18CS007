#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node
{
	int data;
	struct node *next;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("No memory allocation\n");
		exit(0);
	}
}
NODE insert(NODE head,int item,int *c)
{
	NODE p,q=head;
	p=getnode();
	if(*c==size-1)
		{printf("Overflow\n");
		return head;
		}
	else{	
	p->data=item;
	
	if(head==NULL)
	{
		p->next=NULL;
		head=p;
		(*c)++;
		return head;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
		(*c)++;
		return head;
	}
	}
}
NODE delete(NODE head)
{
	NODE p;
	int item;
	if(head==NULL)
	{
		printf("Undreflow\n");
		return head;
	}
	else
	{
		item=head->data;
		p=head;
		head=head->next;
		free(p);
		printf("Deleted element is %d\n",item);
		return head;
	}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("Empty\n");
	}
	else
	{p=head;
	printf("Elements in stack are\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	}
}
int main()
{
	NODE head=NULL;
	int option,ele,count=0;
	printf("1.Insert\n2.Delete\n3.Display\n");
	printf("Enter option\n");
	scanf("%d",&option);
	while(option!=-1)
	{
		switch(option)
		{
			case 1: printf("Enter element to be inserted\n");
				scanf("%d",&ele);
				head=insert(head,ele,&count);
				break;
			case 2: head=delete(head);
				break;
			case 3: 
				display(head);
				break;
			default: printf("Invalid\n");
		}
		printf("Enter next option or -1 to exit\n");
		scanf("%d",&option);
	}
	return 0;
}
		
