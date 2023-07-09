/**
 * @file bst.h
 * @author Rohit Sardessai
 * @brief Header file for the implementation of a binary search tree
 * @version 0.1
 * @date 2023-07-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef struct bst_node {
    int data;
    struct bst_node *left_node;
    struct bst_node *right_node;
} bst_node_t;

/**
 * @brief Create a node in the binary search tree
 *
 * @param data Value at that node
 * @return Returns a pointer to the newly created node
 */
bst_node_t *create_node(int data);

/**
 * @brief Inserts a new node in an existing tree. If no tree exists, this node is set as root
 *
 * @param root Root of the binary tree
 * @param data Value at that node
 * @return Returns a pointer to the root of the tree
 */
bst_node_t *insert(bst_node_t *root, int data);

/**
 * @brief Count the  umber of nodes in the tree
 *
 * @param root Pointer to the root of the tree
 * @return Returns the number of nodes in the tree
 */
int get_node_count(bst_node_t *root);

/**
 * @brief Check if the given value is present in the tree
 *
 * @param node Pointer to the root of the tree
 * @param value Value to find
 * @return true Returns true if the value is present in the tree
 * @return false Returns false if the value is not present in the tree
 */
bool is_in_tree(bst_node_t *node, int value);

/**
 * @brief Get the minimum value present in the tree
 *
 * @param node Pointer to the root of the tree
 * @return Returns the minimum value present in the tree
 */
int get_min(bst_node_t *node);

/**
 * @brief Get the maximum value present in the tree
 *
 * @param node Pointer to the root of the tree
 * @return Returns the maximum value present in the tree
 */
int get_max(bst_node_t *node);

/**
 * @brief Checks if the given tree is a valid binary search tree. The node that is passes is considered the root of the tree.
 *
 * @param node Pointer to the root of the tree
 * @return true Returns true if the given tree is a valid binary search tree
 * @return false Returns false if the given tree is not a valid binary search tree
 */
bool is_binary_search_tree(bst_node_t *node);

/**
 * @brief Deletes the tree and frees up all the alocated memory
 *
 * @param root Pointer to the root of the tree
 */
void destroy_tree(bst_node_t *root);

#endif