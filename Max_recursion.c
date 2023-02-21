#include <stdio.h>

int Max(int* arr, int size);
int main()
{
	int a[4] = { 7,5,1,8 };
	printf("%d", Max(a, 3));
	return 0;
}
int Max(int* arr, int size)
{

	if (size ==0) 
	{
		printf("size = %d\n\n\n", size);
		return arr[size];
	}
		
	int max = Max(arr, size - 1);
	printf("size = %d\n", size);
	printf("max = %d\n", max);
	
	arr[size] = arr[size] > max ? arr[size] : max;
	printf("arr[size] = % d\n", arr[size]);
	printf("\n\n");
	return arr[size];
}