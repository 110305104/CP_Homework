#include <stdio.h>
#pragma warning( disable : 4996 )
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_N 501

typedef struct vector {
	int x;
	int y;
	int z;
}Vector;


int main()
{
	int N;
	scanf("%d\n", &N);
	Vector VL[MAX_N];
	for (int i = 1; i <= N; i++)
	{
		scanf("<%d, %d, %d>\n", &VL[i].x, &VL[i].y, &VL[i].z);			
	}

	//ASK How to use enum here?

	int V1, V2;
	char operator;

	while (scanf("%d %c %d", &V1, &operator,&V2) != EOF)
	{
		Vector Answer = { 0,0,0 };

		if (operator=='+')
		{
			Answer.x = VL[V1].x + VL[V2].x;
			Answer.y = VL[V1].y + VL[V2].y;
			Answer.z = VL[V1].z + VL[V2].z;

			printf("<%d, %d, %d>\n", Answer.x, Answer.y, Answer.z);
		}
		else if (operator=='-')
		{
			Answer.x = VL[V1].x - VL[V2].x;
			Answer.y = VL[V1].y - VL[V2].y;
			Answer.z = VL[V1].z - VL[V2].z;

			printf("<%d, %d, %d>\n", Answer.x, Answer.y, Answer.z);
		}
		else if (operator=='.')
		{
			printf("%+d\n", (VL[V1].x * VL[V2].x) + (VL[V1].y * VL[V2].y) + (VL[V1].z * VL[V2].z));
		}
		else if (operator=='x')
		{
			Answer.x = (VL[V1].y * VL[V2].z) - (VL[V1].z * VL[V2].y);//y1 * z2 - z1 * y2
			Answer.y = (VL[V1].z * VL[V2].x) - (VL[V1].x * VL[V2].z);//z1 * x2 - x1 * z2
			Answer.z = (VL[V1].x * VL[V2].y) - (VL[V1].y * VL[V2].x);//x1 * y2 - y1 * x2

			printf("<%d, %d, %d>\n", Answer.x, Answer.y, Answer.z);
		}
	}
	return 0;



}