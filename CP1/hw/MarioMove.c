#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#pragma warning( disable : 4996 )

int main(void) {

	int mario[2];
	scanf("%d%d", &mario[0], &mario[1]);

	char comment;
	int num1, num2;
	int ignore = 0;
	while (scanf("%c %d", &comment, &num1) != EOF)
	{
		switch (comment)
		{
		case'U':
			if (ignore == 0)
			{
				mario[1]+=num1;
				break;
			}
			else if (ignore != 0)
			{
				ignore--;
				break;
			}

		case'D':
			if (ignore == 0)
			{
				mario[1]-=num1;
				break;
			}
			else if (ignore != 0)
			{
				ignore--;
				break;
			}

		case'L':
			if (ignore == 0)
			{
				mario[0]-=num1;
				break;
			}
			else if (ignore != 0)
			{
				ignore--;
				break;
			}


		case'R':
			if (ignore == 0)
			{
				mario[0]+=num1;
				break;
			}
			else if (ignore != 0)
			{
				ignore--;
				break;
			}

		case'S':
			ignore = num1;
			//printf("%d", ignore);
			break;

		case'T':
			if (ignore == 0)
			{
				scanf("%d", &num2);
				mario[0] = num1;
				mario[1] = num2;
				break;
			}
			else if (ignore != 0)
			{
				ignore--;
				break;
			}
			

		default:
			break;
		}
	}
	printf("(%d , %d)", mario[0], mario[1]);

	return 0;
}