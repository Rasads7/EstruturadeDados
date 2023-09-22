#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int size) {
    int i, j;
    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int size = argc - 1;
    int *array = malloc(size * sizeof(int));
    int i;

    for(i = 1; i <= size; i++) {
        array[i-1] = atoi(argv[i]);
        }

    bubbleSort(array, size);

    for(i = 0; i < size; i++) {
        printf("%d ", array[i]);
        }

    free(array);
    
    return 0;
}