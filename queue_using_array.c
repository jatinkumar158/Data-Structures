// author= jatin kumar
// implementing a queue with the help of an array
// the queue implemented is circular queue as it is most widely used
// there are several disadvantages of simple queue like the space can't be used again
#include<stdio.h>
void enqueue();
void dequeue();
void display();
#define n 6
int queue[n],front=0,rear=0;
int main()
{	
	int choice,flag=0;
	start:
	printf("\n**********************Menu************************\n");
	printf("1.)enqueue\n");
	printf("2.)dequeue\n");
	printf("3.)display the queue\n");
	printf("4.)exit\n");
	printf("enter your choice=");
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
		default:printf("\nplease enter a valid choice\n");
	}
	if(flag==0)
	{
		goto start;
	}
}
void enqueue()
{
	rear=(rear+1)%n;
	if(rear==front)
	{
		printf("\n the queue is full\n");
		if(rear==0)
		{
			rear=n-1;
		}
		else
		{
			rear--;
		}
		return;
	}
	else
	{
		printf("enter the value that you want to insert into the queue=");
		scanf("%d",&queue[rear]);
	}
}
void dequeue()
{
	if(front==rear)
	{
		printf("\nthe queue is empty and there is nothing to delete\n");
		return;
	}
	else
	{
		front=(front+1)%n;
	}
}
void display()
{
	int i;
	if(front==rear)
	{
		printf("|empty|\n");
		return;
	}
	i=front+1;
	while(i!=(rear+1)%n)  // understand the while loop carefully.......
	{
		printf(" |%d| ",queue[i]);
		i=(i+1)%n;
	}
}
