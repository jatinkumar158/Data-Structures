// implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *pre;
	struct node *next;
}*head;
void create();
void display();
void insertbeg();
void insertend();
void insertaftervalue();
void insertbeforevalue();
void deleteaftervalue();
void deletebeforevalue();
void deletenode();
struct node* reverse(struct node*);
int main()
{	
	int choice;
	start:
	printf("\n**************************************MENU*************************************\n");
	printf("1.)create the doubly linked list\n");
	printf("2.)display the doubly linked list\n");
	printf("3.)insert a node in the beginning\n");
	printf("4.)insert a node in the end\n");
	printf("5.)insert a node after a particular value\n");
	printf("6.)insert a node before a particular value\n");
	printf("7.)delete a node after a particular value\n");
	printf("8.)delete a node before a particular value\n");
	printf("9.)delete a particular node\n");
	printf("10.)reverse the linked list\n");
	printf("enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:create();
				break;
		case 2:display();
				break;
		case 3:insertbeg();
				break;
		case 4:insertend();
				break;
		case 5:insertaftervalue();
				break;
		case 6:insertbeforevalue();
				break;
		case 7:deleteaftervalue();
				break;
		case 8:deletebeforevalue();
				break;
		case 9:deletenode();
				break;
		case 10:head=reverse(head);
				break;
		default:
				printf("\nplease enter the correct option\n");
	}
	goto start;
}
void create()
{	
	int choice;
	struct node *ptr,*temp;
	ptr=malloc(sizeof(struct node));
	ptr->pre=NULL;
	ptr->next=NULL;
	printf("enter the data=");
	scanf("%d",&ptr->data);
	head=ptr;
	label:
	printf("do you want to enter more nodes(0/1):");
	scanf("%d",&choice);
	if(choice)
	{
		temp=malloc(sizeof(struct node));
		temp->pre=NULL;
		temp->next=NULL;
		printf("enter the data=");
		scanf("%d",&temp->data);
		ptr->next=temp;
		temp->pre=ptr;
		ptr=temp;
		goto label;
	}
}
void display()
{
	struct node *ptr=head;
	while(ptr->next)
	{
		printf("|%d|<->",ptr->data);
		ptr=ptr->next;
	}
	printf("|%d|",ptr->data);
}
void insertbeg()
{
	struct node *ptr;
	ptr=malloc(sizeof(struct node));
	printf("enter the data=");
	scanf("%d",&ptr->data);
	ptr->pre=NULL;
	ptr->next=head;
	head=ptr;
}
void insertend()
{
	struct node *ptr=head,*temp;
	temp=malloc(sizeof(struct node));
	printf("enter the data=");
	scanf("%d",&temp->data);
	while(ptr->next)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->pre=ptr;
	temp->next=NULL;
}
void insertaftervalue()
{
	int value;
	struct node *ptr=head,*temp;
	temp=malloc(sizeof(struct node));
	printf("enter the value after which you want to insert the node=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	printf("enter the data=");
	scanf("%d",&temp->data);
	temp->pre=ptr;
	temp->next=ptr->next;
	ptr->next->pre=temp;
	ptr->next=temp;
}
void insertbeforevalue()
{
	int value;
	struct node *ptr=head,*temp;
	temp=malloc(sizeof(struct node));
	printf("enter the value before which you want to insert the element=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	temp->data=ptr->data;
	printf("enter the data=");
	scanf("%d",&ptr->data);
	temp->next=ptr->next;
	temp->pre=ptr;
	ptr->next->pre=temp;
	ptr->next=temp;
}
void deleteaftervalue()
{
	int value;
	struct node *ptr=head,*temp;
	printf("enter the value after which you want to delete the node=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->pre=ptr;
	free(temp);
}
void deletebeforevalue()
{
	int value;
	struct node *ptr=head,*temp;
	printf("enter the value before which you want to delete the node=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	temp=ptr->pre;
	temp->pre->next=ptr;
	ptr->pre=temp->pre;
	free(temp);
}
void deletenode()
{
	int value;
	struct node *ptr=head,*temp;
	printf("enter the value that you want to delete=");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;	
	}
	temp=ptr->pre;
	temp->next=ptr->next;
	ptr->next->pre=temp->next;
	free(ptr);
}
struct node* reverse(struct node *cur)
{
	struct node *temp,*nextnode=NULL,*prev=NULL;
	while(cur)
	{	
		prev=cur;
		nextnode=cur->next;
		temp=cur->next;
		cur->next=cur->pre;
		cur->pre=temp;
		cur=nextnode;
	}
	return prev;
}
