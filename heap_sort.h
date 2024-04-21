#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdbool.h>

#include "element.h"

void printArray(Element *array, int size);
void heapSort(Element *array, int n, bool withTrace);

#endif