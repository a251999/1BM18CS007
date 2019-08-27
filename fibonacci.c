#include<stdio.h>
int fib(int x);
int main()
{
	int n;
	printf("Enter the nth term \n");
	scanf("%d",&n);
	printf("Value of %dth term is %d",n,fib(n));
	return 0;
}
int fib(int x)
{
	if(x==1)
		return 0;
	else if(x==2)
		return 1;
	else
		return(fib(x-1)+fib(x-2));
}
