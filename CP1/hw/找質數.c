#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#pragma warning( disable : 4996 )
#define MAX_NUM 100000000

int main()
{
	
	bool* isPrime = (int*)malloc(sizeof(int) * MAX_NUM);
	for (int i = 0; i < MAX_NUM; i++)
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i <= sqrt(MAX_NUM); i++)
	{
		if (isPrime[i])
		{
			for (int k = (MAX_NUM - 1) / i, j = i * k; k >= i; k--, j -= i)
			{
				if (isPrime[k])
				{
					isPrime[j] = false;
				}
			}
		}
	}

	int* primeList = (int*)malloc(sizeof(int) * MAX_NUM);
	int count = 0;
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (isPrime[i])
		{
			primeList[count] = i;
			count++;
		}

	}


	int start, end;
	while (scanf("%d%d", &start, &end) != EOF)
	{
		bool flag = true;
		bool noPrime = true;
		for (int i = 0; primeList[i] < end && primeList[i]>0; i++)
		{

			if (primeList[i] >= start)
			{
				if (flag)
				{
					printf("%d", primeList[i]);
					flag = false;
					noPrime = false;
				}
				else
				{
					printf(" %d", primeList[i]);
				}
			}


		}

		if (noPrime)
		{
			printf("No\n");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}