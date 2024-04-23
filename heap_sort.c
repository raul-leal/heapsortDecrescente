#include <stdio.h>
#include <stdbool.h>

#include "heap_sort.h"

int left(int index) {
    return index * 2 + 1;
}

int right(int index) {
    return index * 2 + 2;
}

int parent(int index) {
    return (index - 1) / 2;
}

int last(int size) {
    return size - 1;
}

bool hasLeft(int size, int index) {
    return left(index) < size;
}

bool hasRight(int size, int index) {
    return right(index) < size;
}

bool hasParent(int index) {
    return index > 0;
}

Element get(Element* data, int size, int index) {
    if (index >= size) {
        return ELEMENT_MAX;
    }

    return data[index];
}

void swapAt(Element* data, int i, int j) {
    Element temp = data[i];

    data[i] = data[j];
    data[j] = temp;
}

void printArray(Element *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        element_print(array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int minimum(Element* array, int size, int a, int b){
    if(get(array, size, a) > get(array, size, b))
        return b;
    return a;
}

void siftDownAt(Element* data, int size, int i){
    int cur = i;
    while((hasLeft(size, cur))){
        int minChild = minimum(data, size, left(cur), right(cur));

        if(get(data, size, cur) < get(data, size, minChild)){
            break;
        }

        swapAt(data, cur, minChild);
        cur = minChild;
    }
}

void heapify(Element* data, int size){
    for(int i=parent(size-1); i>=0; i--){
        siftDownAt(data, size, i);
    }
}

void heapSort(Element *array, int n, bool withTrace){
    int heapSize = n;
    heapify(array, heapSize);
    for(int i=0; i<n-1; i++){
        swapAt(array, 0, heapSize-1);
        heapSize--;
        siftDownAt(array, heapSize, 0);
        if(withTrace == true){
            printArray(array, n);
        }
    }
}
