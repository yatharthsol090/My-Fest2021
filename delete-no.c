#include<stdio.h>
int main()
{
	int i,n,pos;
	printf("\nEnter the length of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("\nEnter the position from which the number has to be deleted:");
	scanf("%d",&pos);
	if(pos<0||pos>n-1)
	{
		printf("Invalid position!Please enter position between 1 to %d",n-1);
	}
	else
	{
		for(i=pos;i<n-1;i++)
		{
			arr[i]=arr[i+1];
		}
		n--;
		printf("\nThe array after deletion of the number from the given position:");
		for (i=0;i<n;i++)
		{
			printf("\t %d",arr[i]);
		}
		
	}
	return 0;
}
