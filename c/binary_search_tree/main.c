#include "bst.h"
#include <stdio.h>

void inorder_traversal(bst_node_t *root)
{
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left_node);
    printf("%i ", root->data);
    inorder_traversal(root->right_node);
}

int main()
{
    printf("START\n\n");

    bst_node_t *root = NULL;

    printf("1. Number of nodes in the tree: %i\n", get_node_count(root));

    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    printf("2. Number of nodes in the tree: %i\n", get_node_count(root));
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 16);

    printf("\nPrinting tree:\n");
    inorder_traversal(root);
    printf("\n\n");

    printf("3. Number of nodes in the tree: %i\n", get_node_count(root));
    printf("Min value in the tree: %i\n", get_min(root));
    printf("Max value in the tree: %i\n", get_max(root));

    printf("\nWhat value would you like to search for?\n");
    int val;
    scanf("%d", &val);
    printf("Is present: %i\n", is_in_tree(root, val));

    destroy_tree(root);

    printf("\nEND\n");
    return 0;
}