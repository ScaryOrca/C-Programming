#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define DATA_TYPE int

struct DynamicArray {
	DATA_TYPE *data;
	int capacity;
	int size;
};

/* Description: Creates a new DynamicArray struct.
 * Parameters: n/a
 * Returns: Newly created DynamicArray struct.
 */
static struct DynamicArray *create_array();

/* Description: Resizes a DynamicArray struct to a specified size. Size is
 * expected to be greater. This should not be called by the user.
 * Parameters:
 *   a: Double pointer to a DynamicArray struct.
 *   s: New size of the DynamicArray.
 * Returns: n/a
 */
static void resize_array(struct DynamicArray **a, int s);

/* Description: Add an item to a DynamicArray.
 * Parameters:
 *   a: Double pointer to a DynamicArray struct.
 *   e: Item to be added to the DynamicArray.
 *   i: Index to insert parameter e.
 * Returns: n/a
 */
void add_item(struct DynamicArray **a, DATA_TYPE e, int i);

/* Description: Free DynamicArray struct from memory.
 * Parameters:
 *   a: Double pointer to DynamicArray struct.
 * Returns: n/a
 */
void delete_array(struct DynamicArray **a);

#endif
