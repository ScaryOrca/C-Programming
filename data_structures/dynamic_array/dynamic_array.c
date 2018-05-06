#include "dynamic_array.h"
#include <stdlib.h>

static struct DynamicArray *create_array() {
	struct DynamicArray *a = malloc(sizeof(struct DynamicArray));
	a->data = malloc(sizeof(DATA_TYPE) * 2);
	a->capacity = 2;
	a->size = 0;

	return a;
}

void add_item(struct DynamicArray **a, DATA_TYPE e, int i) {
	/* empty array */
	if (*a == NULL)
		*a = create_array();

	/* index greater than capacity, resize */
	if (i > ((*a)->capacity) - 1)
		resize_array(a, i);

	(*a)->data[i] = e;
	(*a)->size++;
}

static void resize_array(struct DynamicArray **a, int s) {
	(*a)->data = realloc((*a)->data, s);
	(*a)->capacity = s;
}

void delete_array(struct DynamicArray **a) {
	free((*a)->data);
	free(*a);
}
