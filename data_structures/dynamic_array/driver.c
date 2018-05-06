#include <stdio.h>
#include "dynamic_array.h"

int main() {
	struct DynamicArray *da;
	add_item(&da, 21, 32);

	printf("%d\n", da->data[32]);
	
	delete_array(&da);
	return 0;
}
