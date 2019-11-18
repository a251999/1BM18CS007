#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    if(p!=NULL)
        return p;
    else
        exit(0);
}
NODE insert(NODE head,int n,int item)
{
    NODE p,q,temp;
    p=getnode();
    p->data=item;
    if(head==NULL)
    {
        printf("Value cant be inserted \n");
        return head;

    }
    if(head->data==n)
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;
        return p;

    }

        q=head;
            while(q->next!=NULL)
        {
            temp=q;
            q=q->next;
            if(q->data==n)
            {
                temp->next=p;
                 p->prev=temp;
                p->next=q;
               q->prev=p;
               return head;
            }

        }

   if(q->next==NULL)
    {
        printf("Given node value doesnt exist\n");
        return head;
    }
}
NODE delete(NODE head,int item)
{
    NODE p=head,q;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;

    }
    if(head->next==NULL)
    {

        if(head->data==item)
        {
            head=head->next;
            free(p);
            head->prev=NULL;
            return head;
        }
        else
        {
            printf("Value doesnt exist\n");
            return head;
        }
    }
        q=head;
        if(head->data==item)
        {
            head=head->next;
            free(p);
            head->prev=NULL;
            return head;
        }
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
            if(q->data==item)
            {
                p->next=q->next;
                q->next->prev=q->prev;
                free(q);
                return head;
            }

        }

    if(q->next==NULL)
    {
        printf("Value doesnt exist\n");
        return head;
    }
}
void display(NODE head)
{
    NODE p=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        printf("Elements in list are\n");
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            p=p->next;

        }
    }
}
NODE insert_front(NODE head,int item)
{
    NODE p;
    p=getnode();
    p->data=item;
    if(head==NULL)
    {
        p->next=NULL;
        p->prev=NULL;
        head=p;
        return p;
    }
    p->next=head;
    head->prev=p;
    p->prev=NULL;
    head=p;
    return head;
}
int main()
{
    int option,e,n;
    NODE head=NULL;
    printf("1.Insert front\n2.Insert left\n3.Delete value\n4.Display\n");
    printf("Enter option\n");
    while(option!=-1)
    {
        switch(option)
        {
            case 1:printf("Enter element\n");
                    scanf("%d",&e);
                    head=insert_front(head,e);
                    break;
            case 2: printf("Enter the value to whose left u wish to insert\n");
                    scanf("%d",&n);
                    printf("Enter the no\n");
                    scanf("%d",&e);
                    head=insert(head,n,e);
                    break;
            case 3:printf("Enter value to be deleted\n");
                    scanf("%d",&e);
                    head=delete(head,e);
                    break;
            case 4: display(head);
                    break;
        }
        printf("Enter choice or -1 to exit\n");
        scanf("%d",&option);
    }
    return 0;
}
