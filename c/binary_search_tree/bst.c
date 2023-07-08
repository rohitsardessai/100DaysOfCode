/**
 * @file bst.c
 * @author Rohit Sardessai
 * @brief Implementation of a binary search tree
 * @version 0.1
 * @date 2023-07-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "bst.h"
#include <assert.h>
#include <stdlib.h>

bst_node_t *create_node(int data)
{
    bst_node_t *new_node = malloc(sizeof(bst_node_t));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

bst_node_t *insert(bst_node_t *node, int data)
{

    if (node == NULL) {
        bst_node_t *new_node = create_node(data);

        return new_node;
    } else if (node->data > data) {
        node->left_node = insert(node->left_node, data);
    } else if (node->data < data) {
        node->right_node = insert(node->right_node, data);
    }

    return node;
}

int get_node_count(bst_node_t *root)
{

    if (root == NULL) {
        return 0;
    }

    int count = 1;

    count += get_node_count(root->left_node);
    count += get_node_count(root->right_node);

    return count;
}

bool is_in_tree(bst_node_t *node, int value)
{
    if (node == NULL) {
        return false;
    }

    if (node->data == value) {
        return true;
    } else if (node->data > value) {
        return is_in_tree(node->left_node, value);
    } else {
        return is_in_tree(node->right_node, value);
    }
}

int get_min(bst_node_t *node)
{
    if (node == NULL) {
        return 0;
    }

    bst_node_t *tmp = node;

    while (tmp->left_node != NULL) {
        tmp = tmp->left_node;
    }

    return tmp->data;
}

int get_max(bst_node_t *node)
{
    if (node == NULL) {
        return 0;
    }

    bst_node_t *tmp = node;

    while (tmp->right_node != NULL) {
        tmp = tmp->right_node;
    }

    return tmp->data;
}

void destroy_tree(bst_node_t *root)
{
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left_node);
    destroy_tree(root->right_node);
    free(root);
}