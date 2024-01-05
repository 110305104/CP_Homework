#include <stdio.h>
#include <stdlib.h>
#include<Math.h>

/*給定平面上四個點，它們彼此不共點，請判斷這個多邊形的形狀，有以下三種可能：

如果四邊長度相同以及角度為直角，它們即是正方形，如多邊形 (−1,0),(0,1),(1,0),(0,−1) 就是個正方形。
如果四邊長度相同但角度不是直角，它們即是菱形，如多邊形 (−2,0),(0,1),(2,0),(0,−1) 就是個菱形。
如果四邊長度不同且四個角均是直角，它們即是長方形，如 (0,0),(0,1),(2,1),(2,0) 就是個長方形。
不屬於上述三者，請回報 other*/


int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4, n;
	scanf("%d", &n);
	int vector[1000][4][2];
	double abcd_length[1000][4], abcd_right[1000][4];

	for (int index = 0; index < n; index++)
	{
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

		vector[index][0][0] = x1 - x2;
		vector[index][0][1] = y1 - y2;

		vector[index][1][0] = x2 - x3;
		vector[index][1][1] = y2 - y3;

		vector[index][2][0] = x3 - x4;
		vector[index][2][1] = y3 - y4;

		vector[index][3][0] = x1 - x4;
		vector[index][3][1] = y1 - y4;


		abcd_length[index][0] = sqrt(pow(x1 - x2, 2) + (y1 - y2, 2));
		abcd_length[index][1] = sqrt(pow(x2 - x3, 2) + (y2 - y3, 2));
		abcd_length[index][2] = sqrt(pow(x3 - x4, 2) + (y3 - y4, 2));
		abcd_length[index][3] = sqrt(pow(x1 - x4, 2) + (y1 - y4, 2));

		for (int i = 0, j = 1; i < 4 && j < 5; i++, j++)
		{
			abcd_right[index][i] = vector[index][i][0] * vector[index][j][0] + vector[index][i][1] * vector[index][j][1];
		}
		/*
		abcd_right[index][0] = vector[index][0][0]* vector[index][1][0]+ vector[index][0][1]* vector[index][1][1]
		abcd_right[index][1] = vector[index][1][0] * vector[index][2][0] + vector[index][1][1] * vector[index][2][1]
		abcd_right[index][2] =
		abcd_right[index][3] =
		*/
	}
	for (int index = 0; index < n; index++)
	{
		if (abcd_length[index][0] == abcd_length[index][1] && abcd_length[index][1] == abcd_length[index][2] && abcd_length[index][2] == abcd_length[index][3] && abcd_length[index][0] == abcd_length[index][3] && abcd_right[index][0] == 0 && abcd_right[index][1] == 0 && abcd_right[index][2] == 0 && abcd_right[index][3] == 0)
		{
			printf("square\n");
		}
		else if (abcd_length[index][0] == abcd_length[index][1] && abcd_length[index][1] == abcd_length[index][2] && abcd_length[index][2] == abcd_length[index][3] && abcd_length[index][0] == abcd_length[index][3] && !(abcd_right[index][0] == 0 && abcd_right[index][1] == 0 && abcd_right[index][2] == 0 && abcd_right[index][3] == 0))
		{
			printf("diamond\n");
		}
		else if (!(abcd_length[index][0] == abcd_length[index][1] && abcd_length[index][1] == abcd_length[index][2] && abcd_length[index][2] == abcd_length[index][3] && abcd_length[index][0] == abcd_length[index][3]) && abcd_right[index][0] == 0 && abcd_right[index][1] == 0 && abcd_right[index][2] == 0 && abcd_right[index][3] == 0)
		{
			printf("rectangle\n");
		}
		else { printf("other\n"); }
	
	}
	return 0;

}