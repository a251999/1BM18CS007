#include<stdio.h>
#include<conio.h>
struct mark
{
	int m1,m2,m3;
};
struct mark m[100];
void main()
{
	int n,i;
	clrscr();
	printf("enter no of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter marks of student %d\n",i+1);
		printf("enter marks in Math\n");
		scanf("%d",&m[i].m1);
		printf("enter marks in Data Structure\n");
		scanf("%d",&m[i].m2);
		printf("enter marks in Logic Design\n");
		scanf("%d",&m[i].m3);
	}
	printf("******Marks of Students are********\n");
	for(i=0;i<n;i++)
	{
		printf("Student %d\n",i+1);
		printf("MAth: %d\n",m[i].m1);
		printf("Data Structre: %d\n",m[i].m2);
		printf("Logic Design: %d\n",m[i].m3);
	}
	getch();
}