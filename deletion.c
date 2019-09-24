#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE del_front(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	printf("Deleted element is %d \n",p->data);
	head=p->next;
	free(p);
	return head;
}
NODE del_end(NODE head)
{
	NODE p,q;
	p=head;
	q=head;
	if(head==NULL)
		{
			printf("List is empty\n");
			exit(0);
		}
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	printf("DEl element is %d \n",p->data);
	q->next=NULL;
	free(p);
	return head;
}
NODE del_pos(NODE head,int value)
{
	NODE prev=NULL,curr;
	curr=head;
	int flag=0;
	if(head==NULL)
		{
			printf("List is empty\n");
			return head;
		}
	
		while(curr!=NULL&&curr->data==value)
		{
			head=curr->next;
			
			free(curr);
			curr=head;
			return head;
		}
		
		while(curr->next!=NULL)
		{
			prev=curr;
			curr=curr->next;
			if(curr->data==value)
			{
				prev->next=curr->next;
				free(curr);
				flag=1;
				return head;
			}
		}
	if(flag==0)
	{
		printf("Value doesnt exxist\n");
		return head;
	}
}
NODE getnode()
{
	NODE p;
	
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("No memory allocatipon\n");
		exit(0);
	}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

int main()
{
	NODE p,q,r,head;
	int option,value;
head=getnode();
	p=getnode();
	q=getnode();
	r=getnode();
	head->data=4;
	head->next=p;
	p->data=5;
	p->next=q;
	q->data=7;
	q->next=r;
	r->data=9;
	
	r->next=NULL;
	printf("1.Front\n2.End\n3.Given value\n4.Display\n");
	printf("Enter choice\n");
	scanf("%d",&option);
	while(option!=-1)
	{
		switch(option)
		{
			case 1:head=del_front(head);
				break;
			case 2:head=del_end(head);
				break;
			case 3:printf("Enter value\n");
				scanf("%d",&value);
				head=del_pos(head,value);
				break;
			case 4:printf("Elements r\n");
				display(head);
				break;
			default:printf("Invalid\n");
		}
		printf("Enetr next option or -1 to exit\n");
		scanf("%d",&option);
	}
	return 0;
}
	
	
			
