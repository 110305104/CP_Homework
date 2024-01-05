#include <stdio.h>
#pragma warning( disable : 4996 )

int main()
{
	int a, b;

	while (scanf("%d%d", &a, &b) != EOF)
	{
		long int arr1[1000][1000] = { 0 };

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				scanf("%li", &(arr1[i][j]));
			}
		}


		int  c, d;
		scanf("%d%d", &c, &d);


		long int arr2[1000][1000] = { 0 };

		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < d; j++)
			{
				scanf("%li", &(arr2[i][j]));
			}
		}


		if (b != c)
		{
			printf("Invalid calculation!!\n");
		}
		else
		{
			long int arr3[1000][1000] = { 0 };

			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < d; j++)
				{
					for (int k = 0; k < b; k++)
					{
						arr3[i][j] += arr1[i][k] * arr2[k][j];
					}
				}
			}


			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < d; j++)
				{
					if (j == 0)
					{
						printf("%li", arr3[i][j]);
					}
					else
					{
						printf(" %li", arr3[i][j]);
					}
					
				}
				printf("\n");
			}
			//printf("\n");

		}




	}
	return 0;
}