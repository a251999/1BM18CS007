#include<stdio.h>
#include<conio.h>
int stack[100];
int top=-1;
void push(int ele);
int pop();
void display();
void main()
{
	int e;
	clrscr();
	push(1);
	push(2);
	push(3);
	display();
	e=pop();
	printf("Popped element is %d\n",e);
	display();
	getch();
}
void push(int ele)
{
	if(top==99)
	{
		printf("Stack is overflow\n");
		return ;
	}
	stack[++top]=ele;
}
int pop()
{
	if(top== -1)
	{
		printf("Stack is underflow\n");
		return -9999;
	}
	return stack[top--];
}
void display()
{
	int i;
	if(top== -1)
	{
		printf("Stack is empty\n");
		return ;
	}
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}
