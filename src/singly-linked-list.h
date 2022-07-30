typedef struct _ListElmt
{
	int data;
	int isHead;
	struct _ListElmt *next;
} ListElmt;

typedef struct _List
{
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

/**
 * @brief Macro that evaluates to the number of elements in the linked list
 * specified by list.
 *
 */
#define list_size(list) ((list)->size)

/**
 * @brief Macro that evaluates to the element at the had of the linked list
 * specified by list.
 *
 */
#define list_head(list) ((list)->head)

/**
 * @brief Macro that evaluates to the elemnt at the tail of the linked list
 * specified by list.
 *
 */
#define list_tail(list) ((list)->tail)

/**
 * @brief Macro that determines whether the element specified as element is at
 * the head of a linked list.
 *
 */
#define list_is_head(element) ((element)->isHead)

/**
 * @brief Macro that determines whether the element specified as element is at
 * the end of a linked list.
 *
 */
#define list_is_tail(element) ((element)->next == NULL)

/**
 * @brief Macro that evaluates to the data stored in the element of a linked
 * list specified by element.
 *
 */
#define list_data(element) ((element)->data)

/**
 * @brief Macro that evaluates to the element of a linked list folowing the
 * element specified by element.
 *
 */
#define list_next(element) ((element)->next)

/**
 * @brief Initializes the linked list specified by list. This operation must be
 * called for a linked list before the lsit can be used with any other
 * operation. The destroy argument provides a way to free dynamically allocated
 * data when list_destroy is called. For example, if the list contains data
 * dynamically allocated using malloc, destroy should be set to free to free the
 * data as the linked list is destroyed. For structured data containing several
 * dynamically allocated members, destroy should be set to a user-defined
 * function that calls free for each dynamically allocated member as well as for
 * the structure itself. For a linked list containing data that should not be
 * freed, destroy should be set to NULL.
 *
 * @param list List to use for initialization
 * @param destroy function used to free allocated memory
 */
void list_init(List *list, void (*destroy)(void *data));

/**
 * @brief Destroys the linked list specified by the list. No other oprations are
 * permitted after calling list_destroy unless list_init is called again. The
 * list_destroy operation removes all elements from a linked list and calls the
 * function passed as destroy to list_init once for each element as it is
 * removed, provided destroy was not set to NULL.
 *
 * @param list List to be destroyed
 */
void list_destroy(List *list);

/**
 * @brief Inserts an element just after element in the linked list specified by
 * list. If element is NULL, the new element is inserted at the head of the
 * list. The new element contains a pointer to data, so the memory referenced by
 * data should remain valid as long as the element remains in the list. It is
 * the responsibility of the caller to manage the storage associated with data.
 *
 * @param list List to add the element to
 * @param element ListElmt to be added to the given list
 * @param data data that will be contained by the ListElmt
 * @return int which is 0 if insertion was successful, -1 otherwise
 */
int list_ins_next(List *list, ListElmt *element, const void *data);

/**
 * @brief Removes the element just after given element from the linked list
 * specified by list. If element is NULL, the element at the head of the list is
 * removed. Upon return, data points to the data stored in the element that was
 * removed. It is the responsibility of the caller to manage to storage
 * associated  with the data.
 *
 * @param list List to remove from
 * @param element ListElmt after which one item will be removed
 * @param data
 * @return int
 */
int list_rem_next(List *list, ListElmt *element, void **data);
