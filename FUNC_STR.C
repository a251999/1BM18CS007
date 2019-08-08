#include<stdio.h>
#include<conio.h>
int validate(struct student s);
int qualify(struct student s);
struct student
{
	int id,age,marks;
};
struct student stu[100];
void main()
{
	int n,i;
	clrscr();
	printf("Enter no of Students\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter id,age,marks of student %d\n",i+1);
		scanf("%d%d%d",&stu[i].id,&stu[i].age,&stu[i].marks);
		if(qualify(stu[i]))
		printf("Student %d is eligible for admission\n",i+1);
		else
		printf("Student %d is not eligible\n",i+1);
	}
	getch();
}
int validate(struct student s)
{
	if((s.age>20)&&(s.marks>=0)&&(s.marks<=100))
	return 1;
	else
	return 0;
}
int qualify(struct student s)
{
	if(validate(s))
	{
		if(s.marks>=65)
		return 1;
		else
		return 0;
	}
	else
	{
		printf("Invalid Data\n");
		return 0;
	}
}