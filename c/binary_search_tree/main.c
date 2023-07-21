#include "bst.h"
#include <stdio.h>

void print_result(bool result);
void test_bst_validity();
void inorder_traversal(bst_node_t *root);
void preorder_traversal(bst_node_t *root);
void postorder_traversal(bst_node_t *root);

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

    printf("Deleting %i\n", val);
    delete_value(root, val);

    printf("\nPrinting tree:\n");
    inorder_traversal(root);
    printf("\n\n");

    printf("\nPre-order traversal:\n");
    preorder_traversal(root);
    printf("\n\n");

    printf("\nPost-order traversal:\n");
    postorder_traversal(root);
    printf("\n\n");

    printf("Is BST: %i\n", is_binary_search_tree(root));

    test_bst_validity();

    destroy_tree(root);

    printf("\nEND\n");
    return 0;
}

void inorder_traversal(bst_node_t *root)
{
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left_node);
    printf("%i ", root->data);
    inorder_traversal(root->right_node);
}

void preorder_traversal(bst_node_t *root)
{
    if (root == NULL) {
        return;
    }

    printf("%i ", root->data);
    preorder_traversal(root->left_node);
    preorder_traversal(root->right_node);
}

void postorder_traversal(bst_node_t *root)
{
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left_node);
    postorder_traversal(root->right_node);
    printf("%i ", root->data);
}

void print_result(bool result)
{
    printf(result ? "Valid Binary Search Tree\n" : "Invalid Binary Search Tree\n");
}

// Test cases written by chatGPT
void test_bst_validity()
{
    // Valid Binary Search Tree
    bst_node_t *root1 = create_node(4);
    root1->left_node = create_node(2);
    root1->right_node = create_node(6);
    root1->left_node->left_node = create_node(1);
    root1->left_node->right_node = create_node(3);
    root1->right_node->left_node = create_node(5);
    root1->right_node->right_node = create_node(7);
    printf("Tree 1: ");
    print_result(is_binary_search_tree(root1));

    // Invalid Binary Search Tree
    bst_node_t *root2 = create_node(4);
    root2->left_node = create_node(6);
    root2->right_node = create_node(2);
    root2->left_node->left_node = create_node(1);
    root2->left_node->right_node = create_node(5);
    root2->right_node->left_node = create_node(3);
    root2->right_node->right_node = create_node(7);
    printf("Tree 2: ");
    print_result(is_binary_search_tree(root2));

    // Invalid Binary Search Tree
    bst_node_t *root3 = create_node(4);
    root3->left_node = create_node(2);
    root3->right_node = create_node(6);
    root3->left_node->left_node = create_node(1);
    root3->left_node->right_node = create_node(3);
    root3->right_node->left_node = create_node(7);
    root3->right_node->right_node = create_node(5);
    printf("Tree 3: ");
    print_result(is_binary_search_tree(root3));

    // Valid Binary Search Tree
    bst_node_t *root4 = create_node(50);
    root4->left_node = create_node(30);
    root4->right_node = create_node(70);
    root4->left_node->left_node = create_node(20);
    root4->left_node->right_node = create_node(40);
    root4->right_node->left_node = create_node(60);
    root4->right_node->right_node = create_node(80);
    printf("Tree 4: ");
    print_result(is_binary_search_tree(root4));

    // Invalid Binary Search Tree
    bst_node_t *root5 = create_node(50);
    root5->left_node = create_node(30);
    root5->right_node = create_node(70);
    root5->left_node->left_node = create_node(20);
    root5->left_node->right_node = create_node(40);
    root5->right_node->left_node = create_node(80);
    root5->right_node->right_node = create_node(60);
    printf("Tree 5: ");
    print_result(is_binary_search_tree(root5));

    // Clean up memory
    destroy_tree(root1);
    destroy_tree(root2);
    destroy_tree(root3);
    destroy_tree(root4);
    destroy_tree(root5);
}