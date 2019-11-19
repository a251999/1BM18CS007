#include<stdio.h>
#include<stdlib.h>
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
NODE insert_front(NODE head,int item)
{
    NODE p;
    p=getnode();
    p->data=item;
    if(head == NULL)
    {
        p->next=NULL;
        head=p;
        //return head;
    }
    else
    {p->next=head;
    head=p;
    }
    return head;
}
NODE reverse(NODE head)
{
    NODE prev=NULL,nextn=NULL,curr=head;
     if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL)
        return head;
    else
    {
        while(curr!=NULL)
        {
            nextn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextn;
        }
        head=prev;
        return head;
    }
}
void sort(NODE head)
{
    NODE p=head,q=NULL;
    int temp;
    if(head==NULL)
        return ;
    while(p->next!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data>q->data)
            {
                temp=q->data;
                q->data=p->data;
                p->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}
void display(NODE head)
{
    NODE p;
    if(head==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
NODE concatenate(NODE head,NODE first)
{
    NODE p;
    if(head==NULL)
        return first;
    if(first==NULL)
        return head;
    p=first;
    while(p->next!=NULL)
        p=p->next;
    p->next=head;
    return first;
}
int main()
{
    NODE head=NULL,head2=NULL;
    int e,i,j,option;
    printf("1.Insert elements in 1\n2.Insert elements in 2\n3.Reverse 1\n4.Reverse 4\n5.Sort 1\n6.Sort 2\n7.Display 1\n8.Display 2\n9.Concatenate\n");
    printf("Enter option\n");
    scanf("%d",&option);
    while(option!=-1)
    {
        switch(option)
        {
            case 1:printf("Enter  element in 1\n");
                    scanf("%d",&e);
                    head=insert_front(head,e);
                    //printf("%d\n",head);
                    break;
            case 2: printf("Enter  element in 2\n");
                    scanf("%d",&e);
                    head2=insert_front(head2,e);
                    break;
            case 3:printf("List 1 after reversing\n");
                    head=reverse(head);
                    display(head);
                    break;
            case 4: printf("List 2 after reversing\n");
                    head2=reverse(head2);
                    display(head2);
                    break;
            case 5: printf("List 1 after sorting\n");
                    sort(head);
                    display(head);
                    break;
            case 6: printf("List 2 after sorting\n");
                    sort(head2);
                    display(head2);
                    break;
            case 7:printf("Elements in list 1\n");
                    display(head);
                    break;
            case 8: printf("Elements in list 2\n");
                    display(head2);
                    break;
            case 9: head2=concatenate(head,head2);
                    break;
            default:printf("Invalid option\n");
        }
        printf("Enter other option or -1 to exit\n");
        scanf("%d",&option);
    }
    return 0;
}
