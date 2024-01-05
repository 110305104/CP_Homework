#include <stdio.h>
#include <stdlib.h>
#include<Math.h>

int gcd(int i, int j) {
	if (i % j == 0)
	{
		return j;
	}
	else
	{
		return gcd(j, i % j);
	}
}


int main() {
	int x, y, g;
	scanf("%d%d", &x, &y);
	g = gcd(x, y);
	printf("%d", g);
}