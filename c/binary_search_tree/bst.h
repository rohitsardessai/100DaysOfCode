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
 * @brief Deletes the tree and frees up all the alocated memory
 *
 * @param root Pointer to the root of the tree
 */
void destroy_tree(bst_node_t *root);

#endif