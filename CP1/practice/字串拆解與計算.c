#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char word[10000];
	while (scanf("%s", word)!=EOF)
	{
		int sum = 0;
		for (int i = 0; i < strlen(word); i++)
		{
			sum += ((tolower(word[i]) - 'a') + 1);
		}

		int ans = sum % 100;
		if (ans == 0)
			ans+=100;

		printf("%d\n", ans);
	}
	
	return 0;

}