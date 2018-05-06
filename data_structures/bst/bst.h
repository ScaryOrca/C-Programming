#ifndef BST_H_
#define BST_H_

#define DATA_TYPE int

struct BST {
	DATA_TYPE data;
	struct BST *left;
	struct BST *right;
};

/* Description: Create a new BST struct.
 * Paramaters: n/a
 * Returns: Newly created BST struct.
 */
static struct BST *new_bst();

/* Description: Add a node to a specified BST struct.
 * Parameters:
 *   b: Double pointer to BST struct.
 *   d: Value to add BST struct.
 * Returns: n/a
 */
void add_node(struct BST **b, DATA_TYPE d);

/* Description: Frees specified BST struct from memory.
 * Parameters:
 *   b: Double pointer to BST struct.
 * Returns: n/a
 */
void delete_tree(struct BST **b);
int search_tree(struct BST *b, DATA_TYPE k);
int delete_node(struct BST **b, DATA_TYPE k);
static DATA_TYPE minimum_node(struct BST *n);

#endif
