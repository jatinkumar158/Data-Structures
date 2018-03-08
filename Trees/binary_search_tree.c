// author:- Jatin Kumar
// program to construct a binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;
int find=0;
void menu();
void construct();
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
int search(struct node*,int);
int countnodes(struct node*);
int countleaves(struct node*);
int countnonleaves(struct node*);
int countfullnodes(struct node*);
int heightoftree(struct node*);
int max(struct node*);
int min(struct node*);
struct node* deletenode(struct node*,int);

int main()
{
	menu();
}
void menu()
{	
	int flag=1,choice,c1,c2,c3,c4,h1,mx,mn,res,sea,del;
	start:
	printf("\n******************menu******************\n\n");
	printf("1.)enter the element\n");
	printf("2.)preorder traversal of the tree\n");
	printf("3.)inorder traversal of the tree\n");
	printf("4.)postorder traversal of the tree\n");
	printf("5.)search the element\n");
	printf("6.)count no. of nodes\n");
	printf("7.)count no. of leaves\n");
	printf("8.)count no. of non leaves\n");
	printf("9.)count no. of full nodes\n");
	printf("10.)find height of tree\n");
	printf("11.)print max. element of tree\n");
	printf("12.)print min. element of tree\n");
	printf("13.)delete node from the tree\n");
	printf("14.)exit the program\n");
	printf("enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: construct();
				break;
		case 2: preorder(root);
				break;
		case 3: inorder(root);
				break;
		case 4: postorder(root);
				break;
		case 5: printf("enter the element to be searched=");
				scanf("%d",&sea);
				res=search(root,sea);
				if(res)
					printf("element present\n");
				else
					printf("not present\n");
				break;
		case 6: c1=countnodes(root);
				printf("total nodes=%d\n",c1);
				break;
		case 7: c2=countleaves(root);
				printf("total leaves=%d\n",c2);
				break;
		case 8: c3=countnonleaves(root);
				printf("total non-leaves=%d\n",c3);
				break;
		case 9: c4=countfullnodes(root);
				printf("total full nodes=%d\n",c4);
				break;
		case 10: h1=heightoftree(root);
				 printf("height of tree is %d\n",h1);
				 break; 
		case 11: mx=max(root);
				 printf("max element=%d\n",mx);
				 break;
		case 12: mn=min(root);
				 printf("min. element=%d\n",mn);
				 break;
		case 13: printf("enter value to be deleted=");
				 scanf("%d",&del);
				 res=search(root,del);
				 if(!res)
				 	printf("deletion not possible\n");
				 else
				    root=deletenode(root,del);
				 break;
		case 14: flag=0;
				 break;
		default: printf("please enter correct value\n");
	}
	if(flag!=0)
	{
		goto start;
	}
	printf("\n-------Good Bye---------\n\n");
}
void construct()
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	printf("enter the value=");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *parent,*t;
		t=root;
		parent==root;
		while(t!=NULL)
		{	
			parent=t;
			if(temp->data<t->data)
			{
				t=t->left;
			}
			else
			{
				t=t->right;
			}
		}
		if(temp->data<parent->data)
		{
			parent->left=temp;
		}
		else
		{
			parent->right=temp;
		}
	}
}
void preorder(struct node *temp)
{
	if(temp)
	{
		printf("%d\t",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(struct node *temp)
{
	if(temp)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void postorder(struct node *temp)
{
	if(temp)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
int search(struct node *t,int value)
{
	if(t==NULL)
	{
		return 0;
	}
	if(t->data==value)
	{
		return 1;
	}
	else
	{
		if(t->data<value)
		{
			search(t->right,value);
		}
		else
		{
			search(t->left,value);
		}
	}
}
int countnodes(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		return (1+countnodes(t->left)+countnodes(t->right));
	}
}
int countleaves(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	if(t->left==NULL && t->right==NULL)
	{
		return 1;
	}
	else
	{
		return (countleaves(t->left)+countleaves(t->right));
	}
}
int countnonleaves(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	if(t->left==NULL && t->right==NULL)
	{
		return 0;
	}
	else
	{
		return (1+countnonleaves(t->left)+countnonleaves(t->right));
	}
}
int countfullnodes(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	if(t->left==NULL && t->right==NULL)
	{
		return 0;
	}
	else
	{
		return (countfullnodes(t->left)+countfullnodes(t->right)+
			   ((t->left!=NULL && t->right!=NULL)?1:0));
	}
}
int heightoftree(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	if(t->left==NULL && t->right==NULL)
	{
		return 0;
	}
	int l,r;
	l=heightoftree(t->left);
	r=heightoftree(t->right);
	return (1+((l>r)?l:r));
}
int min(struct node *t)
{	
	struct node *parent;
	while(t)
	{	
		parent=t;
		t=t->left;
	}
	return parent->data;
}
int max(struct node *t)
{
	while(t->right)
	{
		t=t->right;
	}
	return t->data;
}
struct node* deletenode(struct node *t,int value)
{
	if(t==NULL)
		return t;
	if(t->data>value)
		t->left=deletenode(t->left,value);
	if(t->data<value)
		t->right=deletenode(t->right,value);
	else
	{
		// if t is a leaf node
		if(t->left==NULL && t->right==NULL)
		{
			struct node *temp=t;
			t=NULL;
			free(temp);
			return t;
		}
		// node having only right child
		else if(t->left==NULL)
		{
			struct node *sample=t;
			t=t->right;
			free(sample);
			return t;
		}
		// node having only left child
		else if(t->right==NULL)
		{
			struct node *sample=t;
			t=t->left;
			free(sample);
			return t;
		}
		// node having two children
		else
		{
			int var=min(t->right);
			t->data=var;
			t->right=deletenode(t->right,var);
			return t;
		}
	}
}
