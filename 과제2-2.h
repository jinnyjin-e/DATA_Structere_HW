#include<stdio.h>
#include <stdlib.h>
#include <cType.h>
#include <stdbool.h>

typedef struct node {
	void* dataP;
	struct node* link;
}Node;

typedef struct {
	int count;
	Node* pos;
	Node* head;
	Node* rear;
	int(*compare)(void* argu1, void* argu2);
}List;

List* createlist(int(*compare)(void* argu1, void* argu2));
int addnode(List* plist, void* datainP);

bool removenode(List* plist, void* keyP, void** dataoutP);
bool searchlist(List* plist, void* pargu, void** pdataout);
bool retrievenode(List* pist, void* pargu, void** dataoutP);
bool traverse(List* plist, int fromwhere, void** dataoutp);
bool emptylist(List* plist);

List* createlist(int(*compare)(void* argu1, void* argu2)) {
	List* list;
	list = (List*)malloc(sizeof(List));
	if (list) {
		list->head = NULL;
		list->pos = NULL;
		list->rear = NULL;
		list->count = 0;
		list->compare = compare;
	}
	return list;
}//리스트 생성

void _delete(List* plist, Node* pPre, Node*pLoc, void**dataoutP) {
	*dataoutP = pLoc->dataP;
	if (pPre == NULL)
		plist->head = pLoc->link;
	else
		pPre->link = pLoc->link;
	if (pLoc->link == NULL)
		plist->rear = pPre;
	(plist->count)--;
	free(pLoc);
	return;
}
bool _search(List* plist, Node** pPre, Node**pLoc, void* pargu) {
#define COMPARE \
	(((*plist->compare)(pargu,(*pLoc)->dataP)))
#define COMPARE_LAST \
	((*plist->compare)(pargu,plist->rear->dataP))

	int result;
	*pPre = NULL;
	*pLoc = plist->head;
	if (plist->count == 0)
		return false;
	if (COMPARE_LAST > 0) {
		*pPre = plist->rear;
		*pLoc = NULL;
		return false;
	}
	while ((result = COMPARE) > 0) {
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}
	if (result == 0)
		return true;
	else
		return false;
}
static bool _insert(List* plist, Node* pPre, void* datainP) {
	Node* pNew;
	if (!(pNew = (Node*)malloc(sizeof(Node))))
		return false;
	pNew->dataP = datainP;
	pNew->link = NULL;
	if (pPre == NULL) {
		pNew->link = plist->head;
		plist->head = pNew;
		if (plist->count == 0)
			plist->rear = pNew;
	}
	else {
		pNew->link = pPre->link;
		pPre->link = pNew;
		if (pNew->link == NULL)
			plist->rear = pNew;
	}
	(plist->count)++;
	return true;
}

int addnode(List* plist, void* datainP) {
	bool found;
	bool success;
	Node* pPre;
	Node* pLoc;
	found = _search(plist, &pPre, &pLoc, datainP);
	if (found)
		return (+1);
	success = _insert(plist, pPre, datainP);
	if (!success)
		return (-1);
	return (0);
}// addnode

bool removenode(List* plist, void* keyP, void** dataoutP) {
	bool found;
	Node* pPre;
	Node* pLoc;
	found = _search(plist, &pPre, &pLoc, keyP);
	if (found)
		_delete(plist, pPre, pLoc, dataoutP);
	return found;
}

bool searchlist(List* plist, void* pargu, void** pdataout) {
	bool found;
	Node* pPre;
	Node* pLoc;
	found = _search(plist, &pPre, &pLoc, pargu);
	if (found)
		*pdataout = pLoc->dataP;
	else
		*pdataout = NULL;
	return found;
}//searchlist

static bool retrievenode(List* plist, void* pargu, void** dataoutP) {
	bool found;
	Node* pPre;
	Node* pLoc;
	found = _search(plist, &pPre, &pLoc, pargu);
	if (found) {
		*dataoutP = pLoc->dataP;
		return true;
	}
	*dataoutP = NULL;
	return false;
}//retrievenode

bool traverse(List* plist, int fromwhere, void** dataoutp) {
	if (plist->count == 0)
		return false;
	if (fromwhere == 0) {
		plist->pos = plist->head;
		*dataoutp = plist->pos->dataP;
		return true;
	}
	else {
		if (plist->pos->link == NULL)
			return true;
		else {
			plist->pos = plist->pos->link;
			*dataoutp = plist->pos->dataP;
			return true;

		}
	}
}

bool emptylist(List* plist) {
	return(plist->count == 0);
}