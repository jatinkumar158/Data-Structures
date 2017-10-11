// implementation of the circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*head;
void create();
void display();
void display2();
void display3();
void insertafter();
void insertbefore();
void deleteafter();
void deletebefore();
struct node* reverse(struct node*);
int main()
{	
	int choice;
	printf("first of all you have to create the linked list\n");
	create();	
    //display();
	//display2();
	//display3();
	start:
	printf("\n*************************************MENU***************************************\n");
	printf("1.)insert after a node\n");
	printf("2.)insert before a node\n");
	printf("3.)delete after a node\n");
	printf("4.)delete before a node\n");
	printf("5.)display the linked list\n");
	printf("6.)check whether the linked list is circular or not\n");
	printf("7.)reverse the list\n");
	printf("enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:insertafter();
				break;
		case 2:insertbefore();
				break;
		case 3:deleteafter();
				break;
		case 4:deletebefore();
				break;
		case 5:display();
				break;
		case 6:display2();
				break;
		case 7:head=reverse(head);
				break;
	}
	goto start;
}
void create()
{
	struct node *ptr,*temp;
	int choice;
	ptr=malloc(sizeof(struct node));
	head=ptr;
	printf("enter first node=");
	scanf("%d",&ptr->data);
	start:
	printf("do you want to enter more nodes(0/1:)");
	scanf("%d",&choice);
	if(choice==1)
	{
		temp=malloc(sizeof(struct node));
		printf("enter the node=");
		scanf("%d",&temp->data);
		ptr->link=temp;
		ptr=temp;
		goto start;
	}
	else
	{
		ptr->link=head;
	}
}
void display()
{
	struct node *temp=head;
	while(temp->link!=head)
	{
		printf("|%d|->",temp->data);
		temp=temp->link;
	}
	printf("|%d|",temp->data);
}
void display2()
{
	int value,i;
	printf("\nhow many step do want to move the head pointer=");
	scanf("%d",&value);
	for(i=0;i<value;i++)
	head=head->link;
	struct node *temp=head;
	while(temp->link!=head)
	{
		printf("|%d|->",temp->data);
		temp=temp->link;
	}
	printf("|%d|",temp->data);
	printf("\nHence you can see that the linked list is circular in nature");
}
void display3()
{	
	int position,i;
	struct node *temp=head,*pre=NULL;
	printf("\nenter the no. of the node to which you want to point=");
	scanf("%d",&position);
	for(i=0;i<position-1;i++)
	{	
		pre=temp;
		temp=temp->link;
	}
    printf("\nThe linked list from that node is given by\n");
	while(temp->link!=pre->link)
	{
		printf("|%d|->",temp->data);
		temp=temp->link;
	}
	printf("|%d|",temp->data);
	printf("\nHence you can see that the linked list is circular in nature");
} 
void insertafter()
{	
	int value;
	struct node *ptr=head,*temp;
	temp=malloc(sizeof(struct node));
	printf("enter the node after which you want to insert the node=");
	scanf("%d",&value);
	printf("enter the value that you want to insert=");
	scanf("%d",&temp->data);
	while(ptr->data!=value)
	{
		ptr=ptr->link;
	}
	temp->link=ptr->link;
	ptr->link=temp;
}
void insertbefore() // we have used the trick here so see the program carefully
{
	int value;
	struct node *ptr=head,*temp;
	temp=malloc(sizeof(struct node));
	printf("enter the value before which you want to insert the node=");
	scanf("%d",&value);
	printf("enter the data=");
	while(ptr->data!=value)
	{
		ptr=ptr->link;
	}
	temp->data=value;
	temp->link=ptr->link;
	ptr->link=temp;
	scanf("%d",&ptr->data);
}
void deleteafter()
{	
	int value;
	struct node *ptr=head,*temp;
	printf("enter the node after which you want to delete=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->link;
	}
	temp=ptr->link;
	ptr->link=temp->link;
	free(temp);
}
void deletebefore()
{	
	int value;
	struct node *ptr=head,*temp;
	printf("enter the node before which you want to delete=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->link;
	}
	temp=ptr->link;
	while(temp->link!=ptr)
	{
		temp=temp->link;
	}
	temp->data=ptr->data;
	temp->link=ptr->link;
	free(ptr);
}
struct node* reverse(struct node *cur)
{
	struct node *pre,*nextnode=NULL;
	while(cur->link!=head)
	{
		cur=cur->link;
	}
	pre=cur;
	cur=head;
	while(cur->link!=head)
	{
		nextnode=cur->link;
		cur->link=pre;
		pre=cur;
		cur=nextnode;
	}
	cur->link=pre;
	return cur;
}
