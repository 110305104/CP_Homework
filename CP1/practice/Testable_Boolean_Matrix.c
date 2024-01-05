#include <stdio.h>
#pragma warning( disable : 4996 )
#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>



int main()
{
	while (true)
	{
		bool isTestable = true;
		int n;
		scanf("%d ", &n);
		if (n == 0)
		{
			break;
		}
		else
		{
			int nums[100][100];

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					scanf("%d", &nums[i][j]);
				}
			}

			int wrongRow = 1000;
			for (int i = 0; i < n; i++)
			{
				int rowSum = 0;
				for (int j = 0; j < n; j++)
				{
					rowSum += nums[i][j];
				}
				if (rowSum % 2 != 0 && wrongRow==1000)
				{
					wrongRow = i+1;
				}		
				else if (rowSum % 2 != 0 && wrongRow != 1000)
				{
					isTestable = false;
				}
			}

			int wrongCol = 1000;
			for (int i = 0; i < n; i++)
			{
				int colSum = 0;
				for (int j = 0; j < n; j++)
				{
					colSum += nums[j][i];
				}
				if (colSum % 2 != 0 && wrongCol == 1000)
				{
					wrongCol = i + 1;
				}
				else if (colSum % 2 != 0 && wrongCol != 1000)
				{
					isTestable = false;
				}
			}

			if (isTestable == false)
			{
				printf("Corrupt\n");
			}
			else if(wrongCol*wrongRow==1000000)
			{
				printf("OK\n");
			}
			else if( wrongRow != 1000 && wrongCol != 1000)
			{
				printf("Change bit (%d,%d)\n", wrongRow, wrongCol);
			}
			else
			{
				printf("Corrupt\n");
			}

		}
	}
	return 0;
}