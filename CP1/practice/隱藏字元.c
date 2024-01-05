#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 10000
#define STRINGLENGTH 1000
#pragma warning( disable : 4996 )

void hide_and_print(char string[STRINGLENGTH], char to_be_hide[1])
{
	size_t length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		if (string[i] != to_be_hide)
		{
			printf("%c", string[i]);
		}
	}
	printf("\n");
}


int main() {
	int n;
	char string[T][STRINGLENGTH];
	char to_be_hide[T];
	char alphabet;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", &string[i]);
		scanf(" %c", &to_be_hide[i]);
	}



	for (int i = 0; i < n; i++)
	{
		hide_and_print(string[i], to_be_hide[i]);
	}
	
	return 0;
}
