// Author:- Jatin Kumar
// we have given a max heap
// we shall increase the value of a node
// index of the array will start from zero
#include<stdio.h>
// given max heap
int array[7]={100,30,20,1,3,10,15};
int heapsize=7;
// increase function will take two arguments
// first will be the index of node
// second will be the increased value
void increase(int,int);
void display();
void swap();
int main()
{	
	increase(4,2);
	increase(4,300);
	display();
}
void increase(int i, int key)
{
	// check wheather you are increasing or not
	if(array[i]>key)
	{
		printf("invalid\n");
		return;
	}
	array[i]=key;
	while(i>0 && array[i]>array[(i-1)/2])
	{
		swap(i,((i-1)/2));
		i=(i-1)/2;
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