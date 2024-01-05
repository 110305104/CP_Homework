#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n,arr[2000];
		scanf("%d", &n);

		int j = 0;
		for (; j < n; j++)
		{
			scanf("%d", &arr[j]);
		}

		for (int k = j-1; k > 0; k--)
		{
			printf("%d ", arr[k]);
		}
		printf("%d\n", arr[0]);


	}

	return 0;

}