#include <stdio.h>

void bubble_sort(int array[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (array[j] > array[j+1]) {//小到大
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[] = {6,4,8,10,2};
    printf("排序前 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    bubble_sort(array, 5);

    printf("排序後 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}