#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM 1000



//回傳的值大於0會交換
int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);//把void指標轉成int指標後再取值(反參考)
}

int main()
{
	int n;
	scanf("%d", &n);

	int arr[MAX_NUM];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(arr[0]), cmp);


	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}



	return 0;
}
