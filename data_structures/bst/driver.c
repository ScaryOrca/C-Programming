#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void print_tree_sorted(struct BST *t) {
	if (t != NULL) {
		print_tree_sorted(t->left);
		printf("%d\n", t->data);
		print_tree_sorted(t->right);
	}
}

int main(int argc, char **argv) {
	struct BST *my_tree;

	add_node(&my_tree, 21);
	add_node(&my_tree, 18);
	add_node(&my_tree, 50);
	add_node(&my_tree, 47);
	add_node(&my_tree, 30);
	add_node(&my_tree, 64);
	add_node(&my_tree, 15);
	add_node(&my_tree, 17);
	add_node(&my_tree, 19);

	print_tree_sorted(my_tree);
	delete_node(&my_tree, 21);
	printf("------\n");
	print_tree_sorted(my_tree);
	//printf("%d\n", search_tree(my_tree, 19));
	/* call free() on every node */
	delete_tree(&my_tree);
	return 0;
}
