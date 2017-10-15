// author= jatin kumar
//stack implementation using an array
#include<stdio.h>
#define max 5
int stack[max],top=-1;
void display();
void push();
void pop();
int main()
{	
	int choice,flag=0;
	start:
	printf("\n*****************************menu*******************************\n");
	printf("1.)display the stack\n");
	printf("2.)push the element into the stack\n");
	printf("3.)pop the element from the stack\n");
	printf("4.)exit\n");
	printf("\n\nenter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:display();
				break;
		case 2:push();
				break;
		case 3:pop();
				break;
		case 4: flag=1;
				break;
		default:printf("\n\nplease enter the correct choice\n\n");
	}
	if(flag==0)
	{
		goto start;
	}
}
void push()
{
	if(top==max-1)
	{
		printf("\nstack overflow is occured\n");
		return;
	}
	else
	{
		top=top+1;
		printf("enter the element that you want to push into stack=");
		scanf("%d",&stack[top]);
		return;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\nstack underflow is occured\n");
		return;
	}
	else
	{
		top=top-1;
		return;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\n|EMPTY|\n");
		return;
	}
	for(i=top;i>=0;i--)
	{	
		printf("----\n");
		printf("|%d|\n",stack[i]);
		printf("----\n");
	}
}
