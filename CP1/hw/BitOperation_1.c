//找2的冪次；找落單數字

#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#define MAX_NUM 1000


//how many numbers are the integer power of 2
void level_1() {

    int num;
    int count = 0;

    while (scanf("%d", &num)!=EOF)
    {
        if ((num & (num - 1)) == 0)
        {
            count++;
            //printf("\nhi:%d\n", count);
        }
            
    }
    printf("%d", count);
}

// tell which number only appear once
void level_2() {
    int num;
    int ans=0;

    while (scanf("%d", &num) != EOF)
    {
        ans ^= num;
    }
    printf("%d", ans);

}

int main() {
    int level;
    scanf("%d", &level);
    switch (level) {
    case 1:
        level_1();
        break;
    case 2:
        level_2();
        break;
    default:
        printf("Wrong level number!");
        break;
    }
    return 0;
}