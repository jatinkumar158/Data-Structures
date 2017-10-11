// program to evaluate a postfix expression
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 20
char expression[20];
int stack[max];
void push(int);
void evaluate(int,int,char);
int pop();
int top=-1;
int op1,op2;
int main()
{	
	int i=0;
	printf("enter the expression=");
	scanf("%s",expression);
	while(expression[i])
	{
		if(isalnum(expression[i]))
		{
			push(expression[i]-48);
		}
		else
		{
			op2=pop();
			op1=pop();
			evaluate(op1,op2,expression[i]);
		}
		i++;
	}
	printf("the result of the expression is %d\n",stack[top]);
}
void push(int x)
{
	top=top+1;
	stack[top]=x;
	return;
}
int pop()
{
	int temp;
	temp=stack[top];
	top--;
	return temp;
}
void evaluate(int a,int b,char c)
{	
	if(c=='+')
	{
		push(b+a);
	}
	else if(c=='-')
	{
		push(b-a);
	}
	else if(c=='*')
	{
		push(b*a);
	}
	else if(c=='/')
	{
		push(b/a);
	}
}
