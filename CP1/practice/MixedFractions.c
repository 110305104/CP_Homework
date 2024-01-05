#include <stdio.h>
#include <stdlib.h>

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
void cal(int top, int bottom) {
	int Gcd;
	Gcd = gcd(top, bottom);
	top /= Gcd;
	bottom /= Gcd;

	int h, i, j;
	h = top / bottom;
	i = abs(top % bottom);
	j = abs(bottom);
	printf("%d\n%d\n%d", h, i, j);
	//return top,bottom;
	

}

int main() {
	int a, b, c, d, e, f, g;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

	int top_A, bottom_A, top_B, bottom_B;
	bottom_A = c;
	bottom_B = g;
	top_A = (a > 0 ? a * c + b : -(abs(a) * c + b));
	top_B = (e > 0 ? e * g + f : -(abs(e) * g + f));

	/*
		if (a > 0)
	{
		top_A = a * c + b;
	}
	else
	{
		top_A = -(abs(a) * c + b);
	}
	*/

	int top_C = 0, bottom_C = 0;
	switch (d)
	{
	case 0:
		top_C = top_A * bottom_B + top_B * bottom_A;
		bottom_C = bottom_A * bottom_B;
		break;
	case 1:
		top_C = top_A * bottom_B - top_B * bottom_A;
		bottom_C = bottom_A * bottom_B;
		break;
	case 2:
		top_C = top_A * top_B;
		bottom_C = bottom_A * bottom_B;
		break;
	case 3:
		top_C = top_A * bottom_B;
		bottom_C = bottom_A * top_B;
		break;
	default:
		printf("error");
	}


	cal(top_C, bottom_C);

}

	/*
	int h, i, j;
	h = top_C / bottom_C;
	i = abs(top_C % bottom_C);
	j = bottom_C;
	printf("%d\n%d\n%d", h, i, j);
	(放到cal裡，或攤開cal也可以)
	*/

	

	/*
	printf("\n%d/%d\n", top_C, bottom_C);

	int top_F=0, bottom_F=0;
	top_F, bottom_F = cal(top_C, bottom_C); C不能這樣一次接兩個

	printf("\n%d/%d\n\n", top_F, bottom_F);
	int h, i, j;
	h = top_F / bottom_F;
	i = abs(top_F % bottom_F);
	j = bottom_F;
	printf("%d\n%d\n%d", h, i, j);
	*/



