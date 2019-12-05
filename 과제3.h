#include<stdbool.h>
#include<math.h>
#include<stdio.h>

typedef struct{
	void** heapary;
	int last;
	int size;
	int (*compare)(void* argu1, void* argu2);
	int maxsize;
} HEAP;

HEAP* heapcreat(int maxsize, int(*compare)(void* argu1, void* argu2));
bool heapinsert(HEAP* heap, void* dataptr);
bool heapdelete(HEAP* heap, void** dataoutptr);


static void _reheapup(HEAP* heap, int childloc);
static void _reheapdown(HEAP* heap, int root);

HEAP* heapcreat(int maxsize, int(*compare)(void* argu1, void* argu2)){
	HEAP* heap;
	heap = (HEAP*)malloc(sizeof(HEAP));
	if (!heap)
		return NULL;;
	heap->last = -1;
	heap->compare = compare;
	heap->maxsize = (int)pow(2, ceil(log2(maxsize)))-1;
	heap->heapary = (void*)malloc(heap->maxsize, sizeof(void*));
	return heap;
}
//heap 생성

bool heapinsert(HEAP* heap, void* dataptr)//
{
	if (heap->size == 0) {
		heap->size = 1;
		heap->last = 0;
		heap->heapary[heap->last] = dataptr;
		return true;
	}
	if (heap->last == heap->maxsize-1)
		return false;
	++(heap->last);
	++(heap->size);
	heap->heapary[heap->last] = dataptr;
	_reheapup(heap, heap->last);
	return true;
}
//heap 삽입

void _reheapup(HEAP* heap, int childloc) {
	int parent;
	void** heapary;
	void* hold;
	if (childloc) {
		heapary = heap->heapary;
		parent = (childloc - 1) / 2;
		if (heap->compare(heapary[childloc], heapary[parent]) > 0) {
			hold = heapary[parent];
			heapary[parent] = heapary[childloc];
			heapary[childloc] = hold;
			_reheapup(heap, parent);
		}
	}
	return;
}

bool heapdelete(HEAP* heap, void** dataoutptr) {
	if (heap->size == 0)
		return false;
	*dataoutptr = heap->heapary[0];
	heap->heapary[0] = heap->heapary[heap->last];
	(heap->last)--;
	(heap->size)--;
	_reheapdown(heap, 0);
	return true;
}
//heap 삭제

void _reheapdown(HEAP* heap, int root) {
	void* hold;
	void* leftdata;
	void* rightdata;
	int largeloc;
	int last;

	last = heap->last;
	if ((root * 2 + 1) <= last) {
		leftdata = heap->heapary[root * 2 + 1];
		if ((root * 2 + 2) <= last)
			rightdata = heap->heapary[root * 2 + 2];
		else
			rightdata = NULL;
		if ((!rightdata) || heap->compare(leftdata, rightdata) > 0)
			largeloc = root * 2 + 1;
		else
			largeloc = root * 2 + 2;
		if (heap->compare(heap->heapary[root], heap->heapary[largeloc]) < 0) {
			hold = heap->heapary[root];
			heap->heapary[root] = heap->heapary[largeloc];
			heap->heapary[largeloc] = hold;
			_reheapdown(heap, largeloc);
		}
	}
	return;
}
