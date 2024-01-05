#include <stdio.h>
#include <stdlib.h>

int main() {

	int s, f, t, chicken = 0, rabbit = 0, crab = 0;

	scanf("%d %d %d", &s, &f, &t);
	crab = s - t;
	if (crab < 0)
		printf("%d", 0);
	else
	{
		chicken = -(f - 8 * crab - 4 * t);
		rabbit = -(-f + 8 * crab + 2 * t);
		if (chicken >= 0 && rabbit >= 0 && chicken % 2 == 0 && rabbit % 2 == 0)
		{
			printf("%d\n%d\n%d", chicken / 2, rabbit / 2, crab);

		}
		else
			printf("%d", 0);

	}



	return 0;
}