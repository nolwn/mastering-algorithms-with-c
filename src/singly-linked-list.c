#include <stdio.h>
#include "./singly-linked-list.h"

void list_init(List *list, void (*destroy)(void *data))
{
	list->head = NULL;
	list->destroy = destroy;
	list->tail = NULL;
}
