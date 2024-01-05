#pragma warning( disable : 4996 )
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_NUM 2500


//Queue is LIFO

int main()
{
    int n,arr[MAX_NUM];
    for(int i=0;i<MAX_NUM;i++)
    {
        arr[i]=-1;
    }

    int push_idx=0;
    int pop_idx=-1;

    char cmd[10];

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",cmd);
        if(cmd[1]=='u')//push
        {
            scanf(" %d\n",&arr[push_idx]);
            push_idx++;
            pop_idx++;
        }
        else if(cmd[1]=='o')//pop
        {
            if(pop_idx==-1)
            {
                printf("empty\n");
            }
            else
            {
                printf("%d\n",arr[pop_idx]);
                push_idx--;
                pop_idx--;
            }

        }

    

    }

    return 0;

}