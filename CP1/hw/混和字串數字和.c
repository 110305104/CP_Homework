#include <stdio.h>
#pragma warning( disable : 4996 )
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int charToInt(char k)
{
	switch (k)
	{
	case '0':
		return 0;
		break;

	case '1':
		return 1;
		break;

	case '2':
		return 2;
		break;

	case '3':
		return 3;
		break;

	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;

	case '6':
		return 6;
		break;

	case '7':
		return 7;
		break;

	case '8':
		return 8;
		break;

	case '9':
		return 9;
		break;

	default:
		break;
	}
}


int main()
{
	char string[1000];
	while (scanf("%s", string)!=EOF)
	{

		int sum = 0;

		for (int j = 0; string[j] != '\0'; j++)
		{

			if (string[j] == '\0')
				break;

			char numC[1000] = { '0' };
			int numI[1000] = { 0 };

			if (!isdigit(string[j]) && string[j] != '-')
				continue;
			else if (string[j] == '-')
			{
				int k = 0;
				j++;
				while (isdigit(string[j]))
				{
					//printf("%d ", string[j]);
					//printf("%c ", string[j]);
					numC[k] = string[j];
					numI[k] = charToInt(numC[k]);

					k++;
					j++;
				}

				int n = 0;
				for (k; k > 0; k--)
				{
					//printf("%d ", numI[n]);
					sum -= numI[n] * pow(10, k - 1);
					//printf("\n%d\n", sum);
					n++;
				}
				//printf("\n");
			}
			else
			{
				int k = 0;
				while (isdigit(string[j]))
				{
					//printf("%d ", string[j]);
					//printf("%c ", string[j]);
					numC[k] = string[j];
					numI[k] = charToInt(numC[k]);

					k++;
					j++;
				}

				int n = 0;
				for (k; k > 0; k--)
				{
					//printf("%d ", numI[n]);
					sum += numI[n] * pow(10, k - 1);
					//printf("\n%d\n", sum);
					n++;
				}
				//printf("\n");
			}
				
			


		}
		printf("%d\n", sum);


	}


	return 0;
}