// Author :- Jatin Kumar
// C program to implement a max heap
// heap is a complete or almost complete binary tree
// max heap is a heap in which root value is maximum as compared to its children
// all the subtrees should also be a max heap
// to represent a heap we use left child right sibling representation that uses an array
// index of the array starts with 1
// heaps are used because we want some operations like find min/max or delete min/max should be optimal 

#include<stdio.h>
int n,heapsize;
int array[100];
void buildheap();
void maxheapify(int);
void swap(int,int);
void display();
int main()
{
	printf("enter the no. of elements=");
	scanf("%d",&n);
	heapsize=n;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&array[i]);
	}
	buildheap();
	display();
}
void buildheap()
{	
	int i;
	// we go from last non-leaf node to the root of the tree
	for(i=heapsize/2;i>=1;i--)
	{	
		// at each non-leaf node we call max heapify algorithm
		maxheapify(i);
	}
}
void maxheapify(int i)
{
	int left,right,largest;
	left=2*i;
	right=2*i+1;
	// we should check whether left child exists or not
	if(left<=heapsize)
	{
		if(array[left]>array[i])
		{
			largest=left;
		}
		else
		{
			largest=i;
		}
	}
	else
	{	
		// if left child doesn't exists then definitely there will be no right child also
		// so it means we are at leaf and leaf is always a heap so simply return
		// and we don't need to do anything
		return;
	}
	if(right<=heapsize)
	{	
		if(array[largest]<array[right])
		{
			largest=right;
		}
	}
	if(largest!=i)
	{	
		// largest element should be at index i
		// so simply swap largest and i
		swap(largest,i);
		// call again it at largest because tree is changed
		maxheapify(largest);
	}
}
void swap(int x,int y)
{
	int temp;
	temp=array[x];
	array[x]=array[y];
	array[y]=temp;
}
void display()
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}
