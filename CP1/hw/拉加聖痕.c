#pragma warning( disable : 4996 )
#include <stdio.h>


char scars[30][30];
int n;
int counter = 0;

/*
scars[i + 1][j] = '.';
scars[i - 1][j] = '.';
scars[i][j + 1] = '.';
scars[i][j - 1] = '.';
*/

void ClearScar(int i, int j);

void ClearScar_NewDirection(int i, int j)
{
	scars[i][j] = '&';

	printf("\n==ND==\n");
	for (int j = 1; j <= n; j++)
	{

		for (int k = 1; k <= n; k++)
		{
			printf("%c", scars[j][k]);
		}
		printf("\n");

	}
	printf("=======\n");

	ClearScar(i, j);
}



void ClearScar(int i, int j)
{
	if (scars[i][j] == '#')
		scars[i][j] = '&';

	printf("\n===%d===\n", counter);
	for (int j = 1; j <= n; j++)
	{

		for (int k = 1; k <= n; k++)
		{
			printf("%c", scars[j][k]);
		}
		printf("\n");

	}
	printf("=======\n");


	if (scars[i + 1][j] != '#' && scars[i - 1][j] != '#' && scars[i][j + 1] != '#' && scars[i][j - 1] != '#')
	{
		printf("\nOne Way END\n");
		//counter++;

	}
	else
	{
		if (scars[i + 1][j] == '#')
		{
			int tmp = i + 1;
			ClearScar_NewDirection(tmp, j);
		}
		if (scars[i - 1][j] == '#')
		{
			int tmp = i - 1;
			ClearScar_NewDirection(tmp, j);
		}
		if (scars[i][j + 1] == '#')
		{
			int tmp = j + 1;
			ClearScar_NewDirection(i, tmp);
		}
		if (scars[i][j - 1] == '#')
		{
			int tmp = j - 1;
			ClearScar_NewDirection(i, tmp);
		}
	}


}



int main() {

	for (int j = 0; j < 30; j++)
	{
		for (int k = 0; k < 30; k++)
		{
			scars[j][k] = '.';
		}

	}


	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{


		scanf("%d\n", &n);


		char null;
		for (int j = 1; j <= n; j++)
		{

			for (int k = 1; k <= n; k++)
			{
				scanf("%c", &scars[j][k]);
			}
			scanf("%c", &null);

		}

		counter = 0;
		int limit = 1;
		for (int j = 1; j <= n; j++)
		{

			for (int k = 1; k <= n; k++)
			{
				if (scars[j][k] == '#')
				{
					counter++;
					ClearScar(j, k);
					printf("\nAll Cleared\n");
				}

			}

		}


		printf("%d\n", counter);

	}
	return 0;
}

