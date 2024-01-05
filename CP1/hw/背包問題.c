#pragma warning( disable : 4996 )
#include <stdio.h>
//#include <math.h>
//#include <stdbool.h>
#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
#define MAX_NUM 50


// A utility function that returns
// maximum of two integers
//int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be
// put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than
    // Knapsack capacity W, then this item cannot
    // be included in the optimal solution
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max( val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Driver program to test above function
int main()
{

    int num, max;
    scanf("%d%d ", &num, &max);

    int* val = (int*)malloc(sizeof(int) * MAX_NUM);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &val[i]);
    }

    printf("%d", knapSack(max, val, val, num));
    return 0;
}