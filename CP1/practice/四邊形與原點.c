/*給一個凸四邊形 Q 的四個頂點座標，請問原點 (0,0) 是否在四邊形內部，如果原點在四邊形內部，輸出 1，反之，請輸出 0。*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, d, e, f, g, h;
	scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
	if((-b+a*(h-b)/(g-a))* (-d + c * (f - d) / (e - c))<=0 && (-b + a * ( b - d ) / (a - c)) * (-f + e * (f - h) / (e - g)) <= 0)
		printf("%d",1 );
	else
		printf("%d", 0);
	return 0;

}