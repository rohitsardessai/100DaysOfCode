# Binary Search Tree (BST)

A binary search tree (BST) is a hierarchical data structure that organizes data in a manner that facilitates efficient searching.<br>
Each node in a binary search tree (BST) points to at most two other child nodes. Hence the term binary.<br>
The other important characteristic of a BST is that the value of the left node should always be less than the value of the parent node and the value of the right node should always be greater than the value of the parent node. This rule apples to each node in the tree. Hence, any subtree of a BST is also a valid BST.

Here is an example of a binary search tree:
```
        8  <---- Root
      /   \
    3      10
   / \    /  \
  1   6  9   14
     / \    /
    4   7  13
``````

The root of the tree is the topmost element in the tree. In this cae it is 8. All elements to the left of 8 are less than 8 and all elements to the right are greater than 8.


## Tree Traversal

Binary trees can be traversed in various ways. The most common methods are:

### Depth first search

In depth first search, the depth if the tree is traversed before the breadth. There are 3 commonly used strategies for DFS:

* In-order traversal
    The left subtree is traversed first, followed by the current node and then the right subtree. For the BST shown above, that would output:<br>
    ```1 3 4 6 7 8 9 10 13 14```
* Pre-order traversal
    The current node is visited first, followed by the left subtree and then the right subtree. Pre-order traversal output for the tree shown above:<br>
    ```8 3 1 6 4 7 10 9 14 13```
* Post-order traversal
    The left subtree is visited first, followed by the right subtree and then the current node. Post-order traversal output for the tree shown:<br>
    ```1 4 7 6 3 9 13 14 10 8```


### Breadth first search

In breadth first search the breadth of the tree is traversed before the depth.


## Common Operations

| Operation    | Description                                                                                                 | Time complexity (Average Case/Worse Case (unbalanced tree)) |
| ------------ | ----------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------- |
| Insertion    | Adds a new value to the binary search tree at the appropriate location                                      | O(log n) / O(n)                                             |
| Searching    | Finds a particular value in the BST. The ordering of the BST allows for efficient searching (binary search) | O(log n) / O(n)                                             |
| Deletion     | Deletes a node from the BST while maintaining the order property and reorganizing the tree as necessary     | O(log n) / O(n)                                             |
| Find min/max | Finds the min or max value in the BST. This can be achieved by traversing the left or right side            | O(log n) / O(n)                                             |


### Caveats

The advantages offered by binary search trees are only fully realized when the tree is balanced. A balanced tree ensures that the heights of the left and right subtrees are similar. If one subtree has a significantly greater height than the other, the efficiency of searching or insertion operations can be greatly affected.

