#include "bst.h"
#include <stdlib.h>

static struct BST *new_bst() {
	struct BST *n = malloc(sizeof(struct BST));

	/* error allocating memory */
	if (n == NULL)
		return NULL;

	n->left = NULL;
	n->right = NULL;

	return n;
}

void add_node(struct BST **n, DATA_TYPE d) {
	if (*n == NULL) {
		*n = new_bst();

		/* error allocating memory */
		if (*n == NULL)
			return;
 
		(*n)->data = d;
		return;
	}

	if (d < (*n)->data)
		add_node(&(*n)->left, d);

	else if (d > (*n)->data)
		add_node(&(*n)->right, d);

	/* no duplicates allowed in a bst */
	else return;

}

void delete_tree(struct BST **n) {
	if (*n != NULL) {
		delete_tree(&(*n)->left);
		delete_tree(&(*n)->right);
		free(*n);
	}
}

int search_tree(struct BST *n, DATA_TYPE k) {
	/* key not found */
	if (n == NULL)
		return 0;

	if (k < n->data)
		return search_tree(n->left, k);

	else if (k > n->data)
		return search_tree(n->right, k);

	/* key found */
	else return 1;
}


int delete_node(struct BST **n, DATA_TYPE k) {
	DATA_TYPE min;

	/* key not found */
	if (*n == NULL)
		return 0;

	if (k < (*n)->data)
		return delete_node(&(*n)->left, k);

	else if (k > (*n)->data)
		return delete_node(&(*n)->right, k);

	/* key found */
	else {
		/* no children */
		if ((*n)->left == NULL && (*n)->right == NULL) {
			free(*n);
			*n = NULL;
		}

		/* one child, left */
		else if ((*n)->right == NULL) {
			free(*n);
			*n = (*n)->left;
		}

		/* one child, right */
		else if ((*n)->left == NULL) {
			free(*n);
			*n = (*n)->right;
		}

		/* two children */
		else {
			min = minimum_node((*n)->right);
			delete_node(n, min);
			(*n)->data = min;
		}

		return 1;
	}
}

static DATA_TYPE minimum_node(struct BST *n) {
	if (n->left != NULL)
		return minimum_node(n->left);

	return n->data;
}
