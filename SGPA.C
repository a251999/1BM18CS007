#include<stdio.h>
#include<conio.h>
struct mark
{
	int m[5];
};
struct mark s;
void main()
{
	int i,points,credit[5],sum=0;
	int total=0;
	float sgpa;
	clrscr();
	for(i=0;i<5;i++)
       {
		printf("enter marks in sub %d\n",i+1);
		scanf("%d",&s.m[i]);
       }
       for(i=0;i<5;i++)
       {
		printf("enter credits of sub %d\n",i+1);
		scanf("%d",&credit[i]);
       }
	for(i=0;i<5;i++)
	{
		if((s.m[i]>=90)&&(s.m[i]<=100))
		       {
				printf("Grade in Sub %d is S\n",i+1);
				points=10;
		       }
		else if((s.m[i]>=75)&&(s.m[i]<=89))
		       {
				printf("Grade in Sub %d is A\n",i+1);
				points=9;
		       }
		else if((s.m[i]>=60)&&(s.m[i]<=74))
			{
				printf("Grade in Sub %d is B\n",i+1);
				points=8;
			}
		else if((s.m[i]>=40)&&(s.m[i]<=59))
			{
				printf("Grade in Sub %d is C\n",i+1);
				points=7;
			}
		else
		       {
				printf("Grade in Sub %d is D\n",i+1);
				points=5;
		       }
		       sum=sum+(points*credit[i]);
		}
		for(i=0;i<5;i++)
		{
			total=total+credit[i];
		}
		sgpa=(float)sum/total;
		printf("SGPA is : %f",sgpa);
		getch();
}