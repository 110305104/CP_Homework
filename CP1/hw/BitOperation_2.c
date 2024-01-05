//color code

#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>


int main() {
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int color;
		scanf("%x", &color);

		int pos;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &pos);
			int mask = 1;
			mask <<= (pos);
			color &= (~mask);

		}

		printf("%06X\n", color);//字母大寫 保證6碼 有缺補0
	}
	

}