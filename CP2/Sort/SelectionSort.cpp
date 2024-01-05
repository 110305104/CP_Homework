#include <stdio.h> 

void selection_sort(int array[], int n) {
    for (int i=0; i<n-1; i++) {
        int min_idx = i;
        for (int j=i+1; j<n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        // swap
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

int main() {
    int array[] = {10,8,6,2,4};
    printf("排序前 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    selection_sort(array, 5);

    printf("排序後 = ");
    for (int i=0; i<5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}