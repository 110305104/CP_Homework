#include <stdio.h>
#pragma warning( disable : 4996 )
int GCD(int num1, int num2) //2數最大公因數
{
	if (num2 == 0)
	{
		return num1;
	}

	return GCD(num2, num1 % num2);
}

int LCM(int num1, int num2) //2數最小公倍數
{
	return((num1 * num2) / GCD(num1, num2));
}

void calAndPrintAns()
{
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	printf("%d\n", GCD(num1, num2) * LCM(num1, num2));
	//return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		calAndPrintAns();
	}
	
	return 0;
}