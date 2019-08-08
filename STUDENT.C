#include<stdio.h>
#include<conio.h>
struct student
{
	int id,age,marks;
};
struct student s;
void main()
{
	clrscr();
	printf("Enter id , age , marks of student\n");
	scanf("%d%d%d",&s.id,&s.age,&s.marks);
	if((s.age>20)&&(s.marks>=0)&&(s.marks<=100))
	{
		printf("Data is valid\n");
		if(s.marks>=65)
			printf("Student is Qualified for admission\n");
		else
			printf("Not Qualified\n");
	}
	else
		printf("Invalid Data\n");
	getch();
}