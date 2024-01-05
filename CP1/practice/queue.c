#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Queue is FIFO
#define MAX_NUM 520000
int main()
{

    int n, arr[MAX_NUM] = { -1 };
    char cmd[8];
    scanf("%d", &n);

    int enqidx = 0;
    int popidx = 0;
    int flag = 1;

    for (int i = 0; i < MAX_NUM; i++)
    {
        arr[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (flag != 1)
            break;

        scanf("%s", &cmd);
        //printf("==%s==", cmd);

        if (cmd[0] == 'e') {
            //printf("==%s==", cmd);
            scanf(" %d\n", &arr[enqidx]);
            //printf("Hi %d\n", arr[enqidx]);
            enqidx++;
        }
        else {
            //printf("hi%d\n", arr[popidx]);
            if (arr[popidx] != (-1))
            {
                //printf("Hi\n");
                printf("%d\n", arr[popidx]);
                arr[popidx] = -1;
                popidx++;
            }
            else
            {
                printf("empty\n");
                //flag = 0;
            }

        }

    }

    return 0;
}