#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int winning[7];
int myList[7];
long long int prize = 0;
int same = 0;
int count()
{
	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (myList[i] == winning[j])
			{
				sum++;
			}
		}
	}
	return sum;
}
int special()
{
	for (int i = 0; i < 6; i++)
	{
		if (myList[i] == winning[6])
			return true;
	}
	return false;
}

int main() {


	for (int i = 0; i < 6; i++)
	{
		scanf("%d ", &winning[i]);
	}
	scanf("%d\n", &winning[6]);

	//printf("\n----------------------------------\n");
	//for (int i = 0; i < 7; i++)
	//{
	//	printf("%d ", winning[i]);
	//}
	//printf("\n----------------------------------\n");

	while (scanf("%d",&myList[0])!=EOF)	//0
	{
		for (int i = 1; i < 5; i++)	//1,2,3,4
		{
			scanf(" %d", &myList[i]);
		}
		scanf(" %d", &myList[5]);	//5

		//printf("\n----------------------------------\n");
		//for (int i = 0; i < 6; i++)
		//{
		//	printf("%d ", myList[i]);
		//}
		//printf("\n----------------------------------\n");


		same = count();

		switch (same)
		{
		case 6:
			prize += 5000000;
			//printf("\n==%lld\n", prize);
			break;

		case 5:

			if (special())
				prize += 3000000;
			else
				prize += 1000000;

			//printf("\n==%lld\n", prize);
			break;

		case 4:
			prize += 200000;
			//printf("\n==%lld\n", prize);
			break;

		case 3:
			prize += 60000;
			//printf("\n==%lld\n", prize);
			break;
		default:
			break;
		}



	}

	printf("%lld", prize);
	return 0;


}


//%d讀入可以不用設空白和換行的format，但for迴圈次數要設對
//Code:
int test() {

	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &winning[i]);
	}


	while (scanf("%d",&myList[0])!=EOF)	//0
	{
		for (int i = 1; i < 6; i++)	//1,2,3,4,5
		{
			scanf("%d", &myList[i]);
		}

		same = count();

		switch (same)
		{
		case 6:
			prize += 5000000;
			break;

		case 5:

			if (special())
				prize += 3000000;
			else
				prize += 1000000;

			break;

		case 4:
			prize += 200000;
			break;

		case 3:
			prize += 60000;
			break;
		default:
			break;
		}
	}

	printf("%lld", prize);
	return 0;

}