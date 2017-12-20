// author= jatin kumar
// implementation of queue using two stacks
#include<stdio.h>
#define max 6
int stack1[max];
int stack2[max];
int top1=-1,top2=-1;
void enqueue();
void dequeue();
void display();
int main()
{	
	int choice,flag=0;
	start:
	printf("\n**************************MENU******************************\n");
	printf("1.)enqueue\n");
	printf("2.)dequeue\n");
	printf("3.)display\n");
	printf("4.)exit\n");
	printf("please enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:enqueue();
				break;
		case 2:dequeue();
				break;
		case 3:display();
				break;
		case 4:flag=1;
				break;
		default:printf("please enter the correct choice\n");
	}
	if(flag==0)
	{
		goto start;
	}
}
void enqueue()
{	
	if(top1==max-1)
	{
		printf("\nqueue is full\n");
		return;
	}
	printf("enter the element that you want to insert=");
	top1=top1+1;
	scanf("%d",&stack1[top1]);
}
void dequeue()    // understand this function carefully this is really interesting
{
	if(top2==-1)
	{
		if(top1==-1)
		{
			printf("\nqueue is empty\n");
			return;
		}
		else
		{
			while(top1!=-1)
			{
				top2++;
				stack2[top2]=stack1[top1];
				top1--;
			}
		}
	}
	top2--;
}
void display()
{
	if(top1==-1 && top2==-1)
	{
		printf("\n|empty|\n");
		return;
	}
	int i;
	for(i=top2;i>=0;i--)
	{
		printf(" |%d| ",stack2[i]);
	}
	for(i=0;i<=top1;i++)
	{
		printf(" |%d| ",stack1[i]);
	}
}
