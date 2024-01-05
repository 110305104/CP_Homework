#include <stdio.h>
#pragma warning( disable : 4996 )
//#include <math.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>

int Letter2int(char c) {
	int list[26] = { 1, 0, 9, 8, 7, 6, 5, 4, 9, 3, 2, 2, 1, 0, 8, 9, 8, 7, 6, 5, 4, 3, 1, 3, 2, 0 };
	return(list[c - 'A']);
}

void check()
{
	char Letter;
	scanf(" %c ", &Letter);

	int checksum = 0;
	checksum += Letter2int(Letter);

	long long int number;
	scanf("%lli", &number);
	int seperateNum[9];
	for (int j = 0; j < 9; j++)
	{
		seperateNum[j] = number % 10;
		number /= 10;
	}
	/*

	for (int j = 0; j < 9; j++)
	{
		printf("%d ", seperateNum[j]);
	}
	*/
	if (seperateNum[8] == 1 || seperateNum[8] == 2)
	{
		checksum += seperateNum[0];
		for (int k = 1; k < 9; k++)
		{
			checksum += seperateNum[k] * k;
		}

		if (checksum % 10 == 0)
		{
			printf("Valid\n");
		}
		else
		{
			printf("Invalid\n");
		}

	}
	else
	{
		printf("Invalid\n");
	}


	return 0;
}



int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		check();
	}


	return 0;

}



/*

char Letter;
scanf("%c", &Letter);

int checksum = 0;
checksum += Letter2int(Letter);

int add = 0;
scanf("%d", &add);


if (add != 1 && add != 2)
{
	//printf("%d",add);
	printf("Invalid");
}
else
{
	checksum += add;
	for (int j = 1; j < 9; j++)
	{
		scanf("%d", &add);
		checksum += add;
	}

	if (checksum % 10 == 0)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}

}
*/