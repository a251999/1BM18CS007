#include<stdio.h>
#include<conio.h>
struct student
{
	char id[200];
	int age;
	int marks;
};
struct student stu[100];
void main()
{
	int n,i;
	clrscr();
	printf("Enter no of students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of student %d\n",i+1);
		printf("Enter id\n");
		scanf("%s",stu[i].id);
		fflush(stdin);
		printf("Enter age\n");
		scanf("%d",&stu[i].age);
		fflush(stdin);
		printf("Enter Marks\n");
		scanf("%d",&stu[i].marks);
		fflush(stdin);
		if((stu[i].age>20)&&(stu[i].marks>=0)&&(stu[i].marks<=100))
		{
			printf("Data is valid\n");
			if(stu[i].marks>=65)
			{
				printf("Student is qualified for admission\n");
			}
			else
			{
				printf("Not Qualified\n");
			}
		}
		else
		{
			printf("Invalid Data\n");
		}
	}
	getch();
}
