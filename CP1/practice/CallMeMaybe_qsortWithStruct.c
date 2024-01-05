#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM 1000

struct Phone
{
	char PhoneNum[30];//字串版
	int PhoneNumber;//數字版
	int LuckyNum;
};

int charToInt(char string[30])
{
	int sum = 0;
	int k = strlen(string);
	int powerNumber = k;
	for (int j = 0; j < k; j++)
	{
		sum += (string[j] - '0') * pow(10, powerNumber - 1);
		powerNumber--;
	}
	return sum;

}

//qsort的compare方式
//LuckyNum由大到小排，LuckyNum相同時照PhoneNumber由小到大排
//ASK 怎麼運作的
int cmp(const void* a, const void* b)
{
	struct Phone* c = (struct Phone*)a;
	struct Phone* d = (struct Phone*)b;
	if (c->LuckyNum != d->LuckyNum)
		return d->LuckyNum - c->LuckyNum;
	else
		return c->PhoneNumber - d->PhoneNumber;
}

int main()
{
	int n;
	scanf("%d", &n);

	struct Phone phoneList[MAX_NUM];


	for (int i = 0; i < n; i++)
	{
		scanf("%s", &phoneList[i].PhoneNum);
	
		phoneList[i].PhoneNumber = charToInt(phoneList[i].PhoneNum);
	}



	for (int i = 0; i < n; i++)
	{
		phoneList[i].LuckyNum = 0;


		if (((phoneList[i].PhoneNum[strlen(phoneList[i].PhoneNum) - 1]) - '0') % 2 == 0)
		{
			phoneList[i].LuckyNum += 20;
		}


		for (int j = 0; j < strlen(phoneList[i].PhoneNum); j++)
		{
			if (phoneList[i].PhoneNum[j] == '1' || phoneList[i].PhoneNum[j] == '8')
			{
				phoneList[i].LuckyNum -= 3;
			}

			if (phoneList[i].PhoneNum[j] % 2 == 0)
			{
				phoneList[i].LuckyNum += 1;
			}
			phoneList[i].LuckyNum += (phoneList[i].PhoneNum[j]-'0');
		}

	}

	qsort(phoneList, n, sizeof(phoneList[1]), cmp);//要記得qsort在struct的用法

	for (int i = 0; i < n; i++)
	{
		printf("%s ", phoneList[i].PhoneNum);
	}



	return 0;
}
