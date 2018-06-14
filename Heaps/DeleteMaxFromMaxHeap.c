// Author:- Jatin Kumar
// we have given a max heap
// we shall display max element and then delete it
// I have started array index from zero
#include<stdio.h>
// given max heap
int array[7]={100,50,20,1,3,10,5};
int heapsize=7;
int deletemax();
void maxheapify(int);
void swap(int,int);
void display();
int main()
{
	int a=deletemax();
	printf("deleted element=%d\n",a);
	printf("after deletion heap is:\n");
	display();
}
int deletemax()
{
	if(heapsize<=0)
	{
		printf("Heap underflow\n");
	}
	int max=array[0];
	array[0]=array[heapsize-1];
	heapsize--;
	maxheapify(0);
	return max;
}
void maxheapify(int i)
{
	int left,right,largest;
	left=2*i+1;
	right=2*i+2;
	if(left<=heapsize-1)
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
		return;
	}
	if(right<=heapsize-1)
	{
		if(array[largest]<array[right])
		{
			largest=right;
		}
	}
	if(largest!=i)
	{
		swap(largest,i);
		maxheapify(largest);
	}
}
void swap(int x,int y)
{
	int temp=array[x];
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