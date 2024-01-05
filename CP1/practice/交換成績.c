#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define Q 1000
#pragma warning( disable : 4996 )


void swap(int list[N], int a, int b)
{
	int temp = list[a - 1];
	list[a - 1] = list[b - 1];
	list[b - 1] = temp;
}

int main()
{
	int n;
	scanf("%d", &n);
	int grade_list[N];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &grade_list[i]);
	}

	int q;
	int how_to_change[Q][2];

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &how_to_change[i][0], &how_to_change[i][1]);
	}

	for (int i = 0; i < q; i++)
	{
		swap(grade_list, how_to_change[i][0], how_to_change[i][1]);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", grade_list[i]);
	}
	return 0;
}