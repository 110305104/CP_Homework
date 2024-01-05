#include <stdio.h>
//#pragma warning( disable : 4996 )
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>

float BMI(int weight, float height)
{
	float result;
	result =10000* weight / (height * height);
	return result;
}

int main()
{
	int weight;
	float height;

	scanf("%f%d", &height, &weight);
	printf("%.2f",BMI(weight, height));
	return 0;
}