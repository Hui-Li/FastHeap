#include <stdio.h>
#include <stdlib.h>
#include "FastHeap.h"

int main() {
    int k = 10;
    int heapCount = 0;
    helem_t *heap;
    heap = (helem_t *) malloc(k * sizeof(helem_t));

    heap_enqueue(2.1, 1, heap, &heapCount);
    heap_enqueue(13, 2, heap, &heapCount);
    heap_enqueue(2.54, 3, heap, &heapCount);
    heap_enqueue(4.3, 4, heap, &heapCount);
    heap_enqueue(9.1, 5, heap, &heapCount);
    heap_enqueue(22.1, 6, heap, &heapCount);
    heap_enqueue(0.1, 7, heap, &heapCount);
    heap_enqueue(-2.1, 8, heap, &heapCount);
    heap_enqueue(-27.1, 9, heap, &heapCount);
    heap_enqueue(2.112, 10, heap, &heapCount);

    heap_print(heap, heapCount);

    if(heap[0].value>-100){
        helem_t dequeueElement;
        heap_dequeue(&dequeueElement, heap, &heapCount);
        heap_enqueue(-100, 11, heap, &heapCount);

        heap_print(heap, heapCount);
    }

    free(heap);

    return 0;
}