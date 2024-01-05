#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NUM 1000000
#define NUM_OF_WORD 1000000
#define MAX_WORD_LEN 1000000

/*
int main()
{
	char input[MAX_NUM];
	scanf("%s", &input);
	char* token;

	token = strtok(input, " ,");

	while (token != NULL) {
		printf("%s\n", token);

		token = strtok(NULL, input);
	}
}
*/
/*
int main() {
    char str[MAX_NUM];
    //char wordList[NUM_OF_WORD][MAX_WORD_LEN];

    char wordList[NUM_OF_WORD];


    scanf("%s", &str);
    const char* d = "  ,";
    char* word;
    word = strtok(str, d);

    int i = 0;
    while (word != NULL) {
        wordList[i] = word;
        
        printf("%s\n", wordList[i]);

        i++;

        word = strtok(NULL, d);
    }
    return 0;
}
*/

int cmp(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    char str[MAX_NUM]; //要被分割的

    scanf("%s", &str);
    char* s = strtok(str, ","); //分割的判斷字元 ","
    char* WordList[NUM_OF_WORD]; //分割後放入新的字串陣列
    int s_count = 0; //分幾個了


    while (s != NULL) {
        WordList[s_count++] = s;  //把分出來的丟進去字典陣列
        s = strtok(NULL, ","); //繼續分割
    }

    /*
    for (int x = 0; x < s_count; x++) //驗收成果
        printf("%d %s\n", x, WordList[x]);

     printf("\n=====\n");
    */


    qsort(WordList, s_count, sizeof(char*), cmp);//字串排序

    /*
    for (int x = 0; x < s_count; x++) //驗收成果
        printf("%d %s\n", x, WordList[x]);
    */

    char search[MAX_WORD_LEN];
    char alpha;
    while (scanf("%s", &search) != EOF)
    {
        bool exist = false;
        int order = 0;
        for (int j = 0; j < s_count; j++)
        {
            //printf("search:%s\nWordList[%d]:%s\n", search, j, WordList[j]);
            if (!strcmp(search, WordList[j]))
            {
                exist = true;
                alpha = search[0];
                order = j;
                //printf("EXIST");
            }

        }



        if (!exist)
            printf("NOT FOUND\n");
        else
        {
            int first;
            for (int j = 0; j < s_count; j++)
            {

                if (WordList[j][0] == alpha)
                {
                    first = j;
                    break;
                }

            }

            //printf("FOUND\n");
            printf("%c %d\n", toupper(alpha), order - first + 1);
        }
    }

    return 0;
}