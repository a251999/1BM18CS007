#include<stdio.h>
#include<math.h>
void push(float e,float s[100],int *t);
float pop(float s[100],int *t);
float operation(float op1,float op2,char e);
int main()
{
	float stack[100],result,operand1,operand2;
	int i=0,top=-1;
	char p[100];
	printf("Enter exp\n");
	scanf("%s",p);
	while(p[i]!='\0')
	{
		if(p[i]>='0'&&p[i]<='9')
			push((p[i]-'0'),stack,&top);
		else
		{
			operand2=pop(stack,&top);
			operand1=pop(stack,&top);
			result=operation(operand1,operand2,p[i]);
			push(result,stack,&top);
		}
		i++;
	}
	printf("ans is %f",pop(stack,&top));
	return 0;
}
void push(float e,float s[100],int *t)
{
	if(*t==99)
		printf("Stack overflow\n");
	else
	{
		*t=*t+1;
		s[*t]=e;
	}
}
float pop(float s[100],int *t)
{
	if(*t==-1)
		printf("Stack underflow\n");
	else
	{
		return s[(*t)--];
	}
}
float operation(float op1,float op2,char e)
{
	if(e=='+')
		return (op1+op2);
	else if(e=='-')
		return (op1-op2);
	else if(e=='*')
		return (op1*op2);
	else if(e=='/')
		return (op1/op2);
	else if(e=='^')
		return(pow(op1,op2));
	else
		return 0;
}
