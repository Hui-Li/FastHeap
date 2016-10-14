#ifndef FASTHEAP_H
#define FASTHEAP_H

typedef double datatype;

/* heap element */
typedef struct {
    datatype value;
    int idx;
} helem_t;

/*returns the parent of a heap position*/
static int parent(int posel) {
    if (posel % 2) /*odd*/
        return posel / 2;
    else
        return (posel - 1) / 2;
}

/*enqueues element*/
/*heap[0] is the element with the smallest value*/
/*every element is greater than or equal to its parent*/
static void heap_enqueue(datatype el, int idx, helem_t *heap, int *num_elems) {
    datatype tmp;
    int tmpidx;
    int p;
    int posel;

    posel = *num_elems; //last position
    heap[(*num_elems)].value = el;
    heap[(*num_elems)++].idx = idx;

    while (posel > 0) {
        p = parent(posel);
        if (el < heap[p].value) {
            /* swap element with its parent */
            tmp = heap[p].value;
            heap[p].value = el;
            heap[posel].value = tmp;

            tmpidx = heap[p].idx;
            heap[p].idx = idx;
            heap[posel].idx = tmpidx;

            posel = parent(posel);
        }
        else break;
    }
}

/* moves down the root element */
/* used by dequeue (see below) */
static void heap_movedown(helem_t *heap, int *num_elems) {
    datatype tmp;
    int tmpidx;
    int posel = 0; //root
    int swap;
    /*while posel is not a leaf and heap[posel].value > any of childen*/
    while (posel * 2 + 1 < *num_elems) /*there exists a left son*/
    {
        if (posel * 2 + 2 < *num_elems) /*there exists a right son*/
        {
            if (heap[posel * 2 + 1].value < heap[posel * 2 + 2].value)
                swap = posel * 2 + 1;
            else
                swap = posel * 2 + 2;
        }
        else
            swap = posel * 2 + 1;

        if (heap[posel].value > heap[swap].value) /*larger than smallest son*/
        {
            /*swap elements*/
            tmp = heap[swap].value;
            heap[swap].value = heap[posel].value;
            heap[posel].value = tmp;

            tmpidx = heap[swap].idx;
            heap[swap].idx = heap[posel].idx;
            heap[posel].idx = tmpidx;

            posel = swap;
        }
        else break;
    }
}

/* returns the root element, puts the last element as root and moves it down */
static int heap_dequeue(helem_t *el, helem_t *heap, int *num_elems) {
    if ((*num_elems) == 0) /* empty queue */
        return 0;

    el->value = heap[0].value;
    el->idx = heap[0].idx;
    heap[0].value = heap[(*num_elems) - 1].value;
    heap[0].idx = heap[(*num_elems) - 1].idx;
    (*num_elems)--;
    heap_movedown(heap, num_elems);
    return 1;
}

/* prints the elements in the heap (starting from the top element)*/
void heap_print(helem_t *heap, int num_elems) {
    int i;

    for (i = 0; i < num_elems; i++)
        printf("%.2f(%d) ", heap[i].value, heap[i].idx);
    printf("\n");
}

#endif //FASTHEAP_H
