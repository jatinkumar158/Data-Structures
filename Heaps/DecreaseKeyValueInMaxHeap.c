// Author:- Jatin Kumar
// we have given a heap
// we shall decrease the value of a node
#include<stdio.h>
// given max heap
int array[7]={100,30,20,10,15,1,5};
int heapsize=7;
// decrease function will take two arguments
// first one is the index where you want to decrease value
// second one is the decreased key value
void decrease(int,int);
void maxheapify(int);
void swap(int,int);
void display();
int main()
{
	decrease(0,200);
	decrease(0,8);
	display();
}
void decrease(int i,int key)
{
	// check whether you are decreasing or not
	if(array[i]<key)
	{
		printf("Invalid\n");
		return;
	}
	array[i]=key;
	maxheapify(i);
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