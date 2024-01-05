#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

struct Pokemon {

	int Id;
	char Name[100];
	int Atk;
	int Def;
	int Blood;

};

typedef struct Pokemon Pokemon;

int comp(const void* p1, const void* p2) {
	struct Pokemon* c = (Pokemon*)p2;
	struct Pokemon* d = (Pokemon*)p1;
	if (c->Atk == d->Atk)
	{
		if (c->Def == d->Def)
		{
			if (strlen(c->Name) == strlen(d->Name))
			{
				return(strcmp(d->Name, c->Name));
			}
			else
			{
				return(strlen(c->Name) - strlen(d->Name));
			}
		}
		else
		{
			return(c->Def - d->Def);
		}
	}
	else
	{
		return(c->Atk - d->Atk);
	}

}


int main()
{
	Pokemon Pokemons[1000];

	int id,atk,def,blood;
	char name[100];

	int i = 0;
	while (scanf("%d %s %d %d %d",&id,&name,&atk,&def,&blood) != EOF)
	{
		Pokemons[i].Atk = atk;
		Pokemons[i].Blood = blood;
		Pokemons[i].Def = def;
		Pokemons[i].Id = id;
		strcpy(Pokemons[i].Name, name);
		i++;
	}


	qsort(Pokemons, i, sizeof(Pokemons[0]), comp);

	//printf("%03d %-10s %-3d %-3d %d", Pokemons[0].Id, Pokemons[0].Name, Pokemons[0].Atk, Pokemons[0].Def, Pokemons[0].Blood);
	for (int j = 0; j < i; j++)
	{
		printf("%03d %-10s %-3d %-3d %d\n",Pokemons[j].Id,Pokemons[j].Name,Pokemons[j].Atk,Pokemons[j].Def,Pokemons[j].Blood);
	}


	return 0;
}