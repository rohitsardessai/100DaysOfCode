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

    bst_node_t *root = NULL;

    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);

    inorder_traversal(root);

    destroy_tree(root);

    return 0;
}