#include<stdio.h>
#define size 10
void insert(int q[],int *r,int item)
{
    if(*r==size-1)
        printf("Queue is full\n");
    else
        {
            *r=*r+1;
            q[*r]=item;
        }
}
void display(int bt[],int f,int r)
{
    int i,sum=0;
    if(f>r)
        printf("Queue is empty\n");
    else
    {
        for(i=0;i<=r;i++)
        {
            printf("Starting time of proc %d is :  %d\n",(i+1),sum);
            sum=sum+bt[i];
            printf("Ending time of proc %d is : %d\n",(i+1),sum);
        }
    }
}
int main()
{
    int queue[10],front=0,rear= -1,n,i,e;
    printf("Enter no of processor\n");
    scanf("%d",&n);
     printf("Enter burst time of each processor\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        insert(queue,&rear,e);
    }
    display(queue,front,rear);
     return 0;

}
