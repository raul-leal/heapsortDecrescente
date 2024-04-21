#include "heap_sort.h"

#include <stdio.h>
#include <stdbool.h>

int main() {
    Element array[] = {61, 73, 82, 28, 33, 57, 4, 15};

    printf("Original array: ");
    printArray(array, 8);
    heapSort(array, 8, false);
    printf("Sorted array: ");
    printArray(array, 8);

    return 0;
}