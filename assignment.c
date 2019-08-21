#include<stdio.h>
#include<string.h>
#include<ctype.h>
void push(char ele,char s[100],int *t);
char pop(char s[100],int *t);
int is_operator(char e);
int precedence(char e);
int main()
{
	char stack[100],infix[100],postfix[100],x;
	int i=0,j=0,top=-1;
	printf("enter infix exp\n");
	scanf("%s",infix);
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		{
			push(infix[i],stack,&top);
		}
		else if(infix[i]==')')
		{
			x=pop(stack,&top);
			while(x!='(')
			{
				postfix[j]=x;
				j++;
				x=pop(stack,&top);
			}

		}
		else if(isdigit(infix[i])||isalpha(infix[i]))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(is_operator(infix[i]==1))
		{

		    while(is_operator(x)==1&&precedence(x)>=precedence(infix[i]))
				{
					postfix[j]=x;
					j++;
					x=pop(stack,&top);
                }
				push(infix[i],stack,&top);

		}
		else
		{
			printf("Invalid input\n");
		}
		i++;
    }

		while(top!=-1)
		{
				x=pop(stack,&top);
				postfix[j]=x;
				j++;
        }

		postfix[j]='\0';
		printf("enter postfix exp\n");
		puts(postfix);
		return 0;
}
void push(char ele,char s[100],int *t)
{
	if(*t<99)
	{
	    *t=*t+1;
		s[*t]=ele;
	}

}
char pop(char s[100],int *t)
{
	char item;
	if(*t>-1)
	{
		item=s[*t];
		*t=*t-1;
		return item;
	}
}
int is_operator(char e)
{
	if(e=='*'||e=='/'||e=='+'||e=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int precedence(char e)
{
	if(e=='^')
		return 3;
	else if(e=='*'||e=='/')
		return 2;
	else if(e=='+'||e=='-')
		return 1;
	else
		return 0;
}


