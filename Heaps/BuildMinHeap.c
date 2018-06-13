// Author:- Jatin Kumar
// C program to implement a min heap
// See my build max heap program for complete logic
// in this I will start array index from 0


#include<stdio.h>
int heapsize;
int array[100];
void buildheap();
void minheapify(int);
void swap(int,int);
void display();
int main()
{
	int i,n;
	printf("enter the no. of elements=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	heapsize=n;
	buildheap();
	display();
}
void buildheap()
{
	int i;
	for(i=(heapsize/2)-1;i>=0;i--)
	{
		minheapify(i);
	}
}

void minheapify(int i)
{
	int left,right,smallest;
	left=2*i+1;
	right=2*i+2;
	if(left<=(heapsize-1))
	{
		if(array[left]>array[i])
		{
			smallest=i;
		}
		else
		{
			smallest=left;
		}
	}
	else
	{
		return;
	}
	if(right<=(heapsize-1))
	{
		if(array[smallest]>array[right])
		{
			smallest=right;
		}
	}
	if(smallest!=i)
	{
		swap(smallest,i);
		minheapify(smallest);
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
	for(i=0;i<heapsize;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}
