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

bool is_binary_search_tree(bst_node_t *node)
{
    if (node == NULL) {
        return true;
    }

    if (node->left_node != NULL) {
        if (node->left_node->data > node->data) {
            return false;
        }
    }

    if (node->right_node != NULL) {
        if (node->right_node->data < node->data) {
            return false;
        }
    }

    if (is_binary_search_tree(node->left_node) == false) {
        return false;
    }

    if (is_binary_search_tree(node->right_node) == false) {
        return false;
    }

    return true;
}

bst_node_t *delete_value(bst_node_t *node, int value)
{
    if (node == NULL) {
        return NULL;
    }

    if (value < node->data) {
        node->left_node = delete_value(node->left_node, value);
    } else if (value > node->data) {
        node->right_node = delete_value(node->right_node, value);
    } else {
        if (node->left_node == NULL && node->right_node == NULL) {
            free(node);
            return NULL;
        } else if (node->left_node == NULL) {
            bst_node_t *tmp = node->right_node;
            free(node);
            return tmp;
        } else if (node->right_node == NULL) {
            bst_node_t *tmp = node->left_node;
            free(node);
            return tmp;
        } else {
            int right_min = get_min(node->right_node);

            node->data = right_min;
            node->right_node = delete_value(node->right_node, right_min);
        }
    }
    return node;
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