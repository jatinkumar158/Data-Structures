// Author:- Jatin Kumar
// we have given a heap
// we want to insert the element into it
// the element will always be inserted at last index
// then we shall find its correct position depending upon its value
#include<stdio.h>
int array[10]={100,20,30,1,5,10,15};
int heapsize=7;
void display();
void insert(int);
void swap(int,int);
int main()
{
	printf("Initial:\n");
	display();
	insert(200);
	printf("final:");
	display();
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
void insert(int key)
{	
	int i=heapsize;
	array[i]=key;
	heapsize++;
	while(i>0 && array[i]>array[(i-1)/2])
	{
		swap(i,((i-1)/2));
		i=i/2;
	}
}
void swap(int x,int y)
{
	int temp=array[x];
	array[x]=array[y];
	array[y]=temp;
}