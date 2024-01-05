#include <stdio.h>
int main()
{
	long int x1,y1,x2,y2;
	scanf("%li%li%li%li",&x1,&y1,&x2,&y2);
	long int area;
	area=(x2-x1)*(y1-y2);
	printf("%li",area);
	return 0;
}