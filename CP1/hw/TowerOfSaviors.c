#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

bool Mark();
void Now();
void Copy();
char runeType(char rune);
void Count();
void Drop();
char CurrentBoard[2000][6], TmpBoard[2000][6];
char CopyBoard[2000][6];
int count = 0;


// Fire Water Earth Leight Dark Heart

struct Monster {

	char Name[100];
	char CType[100];
	int Type;
	int Atk;
	int Recovery;
	int Damage;
	int Heal;
};
typedef struct Monster Monster;

int cmp(const Monster* p1, const Monster* p2)
{
	return(p2->Damage - p1->Damage);
}


bool isNormal(char rune) {
	return islower(rune);
}



void PrintCurrent()
{

	printf("-------------------------------------------\n");
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", CurrentBoard[i][j]);
		}
		printf("%c\n", CurrentBoard[i][5]);
	}
	printf("-------------------------------------------\n");

}

void PrintMark()
{

	printf("-------------------------------------------\n");
	for (int i = count-5; i < count; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", TmpBoard[i][j]);
		}
		printf("%c\n", TmpBoard[i][5]);
	}
	printf("-------------------------------------------\n");

}

void PrintC5()
{

	printf("-------------------------------------------\n");
	for (int i = count - 5; i < count ; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", CurrentBoard[i][j]);
		}
		printf("%c\n", CurrentBoard[i][5]);
	}
	printf("-------------------------------------------\n");

}

void ITB()
{
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			TmpBoard[i][j] = ' ';
		}
	}
}


Monster Team[6];


int main() {


	char tmp[2000];
	for (int i = 0; i < 6; i++)
	{
		gets(tmp);
		scanf("%s %c  ", &tmp,&tmp[0]);
		gets(Team[i].Name);
		scanf("TYPE : %s\n", &Team[i].CType);
		scanf("ATTACK : %d\n", &Team[i].Atk);
		scanf("RECOVERY : %d\n", &Team[i].Recovery);
		Team[i].Damage = 0;
		Team[i].Heal = 0;
	}
	gets(tmp);




	/*printf("-------------------------------------------\n");
	for (int i = 0; i < 6; i++) {

		printf("| %-40s|\n",Team[i].Name);

		printf("| Damage : %-10d| Recovery : %-8d|\n",Team[i].Damage,Team[i].Heal);

		//printf("|%-41s|\n", Team[i].CType);
		printf("-------------------------------------------\n");
	}*/




	
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			CurrentBoard[i][j] = '&';
		}
	}

	ITB();

	char try;
	
	while (scanf("%c", &try) != EOF)
	{
		CurrentBoard[count][0] = try;
		for (int j = 1; j < 5; j++)
		{
			scanf("%c", &CurrentBoard[count][j]);
		}
		scanf("%c\n", &CurrentBoard[count][5]);
		if (CurrentBoard[count][5] == '-')
			count--;
		count++;
	}

	//PrintCurrent();

	while (Mark())
	{
		//PrintMark();
		Count();
		Copy();
		Drop();
		ITB();
		//PrintCurrent();
	}

	//PrintCurrent();
	qsort(Team, 6, sizeof(Team[0]), cmp);
	Now();



}

void Now()
{
	printf("-------------------------------------------\n");
	for (int i = 0; i < 6; i++) {

		printf("| %-40s|\n", Team[i].Name);

		printf("| Damage : %-10d| Recovery : %-8d|\n", Team[i].Damage, Team[i].Heal);

		//printf("|%-41s|\n", Team[i].CType);
		printf("-------------------------------------------\n");
	}
}


bool Mark()
{
	bool flag = false;
	//直消
	for (int i = 0; i < 6; i++)
	{
		if ((runeType(CurrentBoard[count - 3][i]) == runeType(CurrentBoard[count - 4][i])) && (runeType(CurrentBoard[count - 4][i]) == runeType(CurrentBoard[count - 5][i])))
		{
			TmpBoard[count - 3][i] = '&';
			TmpBoard[count - 4][i] = '&';
			TmpBoard[count - 5][i] = '&';
			//PrintC5();
			//printf("%c\n", CurrentBoard[count - 3][i]);
			//PrintMark();
			flag = true;
		}
		if ((runeType(CurrentBoard[count - 3][i]) == runeType(CurrentBoard[count - 2][i])) && (runeType(CurrentBoard[count - 2][i]) == runeType(CurrentBoard[count - 1][i])))
		{
			TmpBoard[count - 2][i] = '&';
			TmpBoard[count - 1][i] = '&';
			TmpBoard[count - 3][i] = '&';
			//PrintC5();
			//printf("%c\n", CurrentBoard[count - 3][i]);
			//PrintMark();
			flag = true;
		}
		if ((runeType(CurrentBoard[count - 3][i]) == runeType(CurrentBoard[count - 2][i])) && (runeType(CurrentBoard[count - 2][i]) == runeType(CurrentBoard[count - 4][i])))
		{
			TmpBoard[count - 2][i] = '&';
			TmpBoard[count - 4][i] = '&';
			TmpBoard[count - 3][i] = '&';
			//PrintC5();
			//printf("%c\n", CurrentBoard[count - 3][i]);
			//PrintMark();
			flag = true;
		}

	}
	//橫消
	for (int i = count - 5; i < count; i++)
	{
		if (runeType(CurrentBoard[i][2]) == runeType(CurrentBoard[i][3]))
		{
			if (runeType(CurrentBoard[i][3]) == runeType(CurrentBoard[i][4]))
			{
				TmpBoard[i][2] = '&';
				TmpBoard[i][3] = '&';
				TmpBoard[i][4] = '&';
				flag = true;
				if (runeType(CurrentBoard[i][4]) == runeType(CurrentBoard[i][5]))
					TmpBoard[i][5] = '&';
			}
			if (runeType(CurrentBoard[i][2]) == runeType(CurrentBoard[i][1]))
			{
				TmpBoard[i][2] = '&';
				TmpBoard[i][3] = '&';
				TmpBoard[i][1] = '&';
				flag = true;
				if (runeType(CurrentBoard[i][1]) == runeType(CurrentBoard[i][0]))
					TmpBoard[i][0] = '&';
			}

			//PrintC5();
			//printf("%c\n", CurrentBoard[i][3]);
			//PrintMark();
		}
		else
		{
			if ((runeType(CurrentBoard[i][2]) == runeType(CurrentBoard[i][1])) && (runeType(CurrentBoard[i][1]) == runeType(CurrentBoard[i][0])))
			{
				TmpBoard[i][2] = '&';
				TmpBoard[i][1] = '&';
				TmpBoard[i][0] = '&';
				flag = true;
				//PrintC5();
				//printf("%c\n", CurrentBoard[i][2]);
				//PrintMark();
			}

			if ((runeType(CurrentBoard[i][3]) == runeType(CurrentBoard[i][4])) && (runeType(CurrentBoard[i][4]) == runeType(CurrentBoard[i][5])))
			{
				TmpBoard[i][3] = '&';
				TmpBoard[i][4] = '&';
				TmpBoard[i][5] = '&';
				flag = true;
				//PrintC5();
				//printf("%c\n", CurrentBoard[i][3]);
				//PrintMark();
			}
		}

	}
	return flag;
}

void Count()
{

	for (int i = count - 5; i < count; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (TmpBoard[i][j] == '&')
			{
				for (int k = 0; k < 6; k++)
				{
					if (runeType(CurrentBoard[i][j]) == Team[k].CType[0])
					{
						if (isNormal(CurrentBoard[i][j]))
							Team[k].Damage += Team[k].Atk;
						else
							Team[k].Damage += 2 * Team[k].Atk;
					}
					else if (runeType(CurrentBoard[i][j]) == 'H')
					{
						if (isNormal(CurrentBoard[i][j]))
							Team[k].Heal += Team[k].Recovery;
						else
							Team[k].Heal += 2 * Team[k].Recovery;
					}
				}
				//Now();
			}
			

		}

	}
}


void Copy()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			CopyBoard[i][j] = ' ';
		}
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			CopyBoard[i][j] = CurrentBoard[i][j];
		}
	}
}

void Drop()
{
	for (int j = count - 5; j < count; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (TmpBoard[j][i] == '&')
			{
				int k = j;
				int t = i;


				for (; k > 0; k--)
				{
					CurrentBoard[k][t] = CopyBoard[k - 1][t];
				}
				CurrentBoard[0][t] = '-';
				Copy();
				//PrintCurrent();
			}
		}
	}
}

char runeType(char rune) {
	switch (rune)
	{
	case'F': case'f':
		return 'F';
		break;

	case'W': case'w':
		return 'W';
		break;

	case'E': case'e':
		return 'E';
		break;


	case'L': case'l':
		return 'L';
		break;

	case'D': case'd':
		return 'D';
		break;

	case'H': case'h':
		return 'H';
		break;

	default:
		break;
	}




}