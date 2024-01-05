#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
#pragma warning( disable : 4996 )
/*
int Fib(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}
*/


int main() {
	
	int Fib_Chart[55];
	Fib_Chart[0] = 1, Fib_Chart[1] = 1;
	for (int i = 2; i < 55; i++)
	{
		Fib_Chart[i] = Fib_Chart[i - 1] + Fib_Chart[i - 2];
	}
	
	int count;
	scanf("%d", &count);
	int n[T];
	int index;
	for (index = 0; index < count; index++)
	{
		scanf("%d", &n[index]);
	}
	n[index] = -10;

	for (int i = 0; i < n && n[i] != -10; i++)
	{
		printf("%d\n", Fib_Chart[n[i]]);
	}

	return 0;
}
