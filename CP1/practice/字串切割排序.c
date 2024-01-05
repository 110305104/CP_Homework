#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>


typedef struct str {
	char String[1000];
}Str;

int cmp(const Str* a, const Str* b)
{
	return strcmp(a->String, b->String);//
}


int main()
{
	Str arr[1000]; int i = 0;
	while (scanf("%s",&arr[i].String)!=EOF)
	{
		if (arr[i].String!= ' ' && arr[i].String != '\n')
		{
			i++;
		}
	}

	//for (int j = 0; j < i; j++)
	//{
	//	printf("%s\n", arr[j].String);
	//}

	qsort(arr, i, sizeof(arr[0]), cmp);

	for (int j = 0; j < i; j++)
	{
		printf("%s\n", arr[j].String);
	}


}