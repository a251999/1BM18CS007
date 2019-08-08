#include<stdio.h>
#include<conio.h>
void swap(int *p1,int *p2);
void main()
{
	int a,b,*p1,*p2;
	p1=&a;
	p2=&b;
	clrscr();
	printf("Enter value of a & b\n");
	scanf("%d%d",p1,p2);
	printf("Befor swapping\n");
	printf("a=%d b=%d\n",*p1,*p2);
	printf("Values after swapping are \n");
	swap(p1,p2);
	printf("a=%d\nb=%d",*p1,*p2);
	getch();
}
void swap(int *p1,int *p2)
{
	*p1=*p1+ *p2;
	*p2=*p1- *p2;
	*p1=*p1- *p2;
}