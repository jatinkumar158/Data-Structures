// author= jatin kumar
// program to convert infix expression to postfix expression
#include<stdio.h>
#include<stdlib.h>
char expression[20];
#define max 20
char stack[max];
void push(char);
int priority(char);
char pop();
int top=-1,i=0;
int main()
{	
	char p;
	printf("enter the expression=");
	scanf("%s",expression);
	while(expression[i])
	{
		if(isalnum(expression[i]))
		{
			printf("%c",expression[i]);
		}
		else if(expression[i]=='(')
		{
			push(expression[i]);
		}
		else if(expression[i]==')')
		{
			while(stack[top]!='(')
			{
				printf("%c",pop());
			}
			p=pop();
		}
		else
		{
			if(top==-1)
			{
				push(expression[i]);
			}
			else
			{
				while(priority(expression[i])<priority(stack[top]))
				{
					printf("%c",pop());
				}
				push(expression[i]);
			}
		}
		i++;
	}
	while(top!=-1)
	{
		printf("%c",pop());
	}
}
int priority(char x)
{
	if(x=='(')
	return 0;
	if(x=='+' || x=='-')
	return 1;
	if(x=='*' || x=='/')
	return 2;
}
void push(char ch)
{
	top=top+1;
	stack[top]=ch;
}
char pop()
{
	char s;
	s=stack[top];
	top=top-1;
	return s;
}
