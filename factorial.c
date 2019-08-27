#include<stdio.h>
int fact(int x);
int main()
{
	int n;
	printf("Enter no\n");
	scanf("%d",&n);
	printf("Factorial of no is : %d",fact(n));
	return 0;
}
int fact(int x)
{
	if(x==0)
		return 1;
	else
		return(x*fact(x-1));
}
