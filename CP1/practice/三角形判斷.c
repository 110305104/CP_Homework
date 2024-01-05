#include <stdio.h>
#include <stdlib.h>
 
 
int main() {
    int n=1;
    scanf("%d", &n);
    int x1, y1, x2, y2, x3, y3;
    int abc[100][3];
    //printf("testing");
    // char answer[n][10];
    for (int index = 0; index < n; index++)
    {
 
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        abc[index][0] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        abc[index][1] = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
        abc[index][2] = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
 
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (abc[i][0] <= abc[i][j])
            {
                int ram = abc[i][0];
                abc[i][0] = abc[i][j];
                abc[i][j] = ram;
            }
        }
        //printf(" %d %d %d\n", abc[i][0], abc[i][1], abc[i][2]);
        if (abc[i][1] == abc[i][2] || abc[i][1] == abc[i][0])
        {
            printf("isosceles\n");
        }
        else
        {
            if (abc[i][0] == (abc[i][1] + abc[i][2]))
            {
                printf("right\n");
            }
            else if (abc[i][0] > (abc[i][1] + abc[i][2]))
            {
                printf("obtuse\n");
            }
            else if (abc[i][0] < (abc[i][1] + abc[i][2]))
            {
                printf("acute\n");
            }
        }
    }
 
 
    return 0;
}