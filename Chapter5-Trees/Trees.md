# 5. Trees
## 5.1 Introduction
### 5.1.1 Terminology
- Trees are useful for __hierarchically__ ordered data.
- The element at the top of the hierarchy is the __root__.
- Elements next in the hierarchy are the __children__ of the root.
- Elements next in the hierarchy are the __grandchildren__ of the root, and so on.
- Elements that have no children are __leaves__.
- A tree __t__ is a __finite nonempty__ set of elements.
- One of these elements is called the root.
- The remaining elements, if any, are partitioned into trees, which are called the __subtrees of t__.
- Root is at __level 1__. (Some texts start level numbers at 0 rather at 1.)
- height = depth = __number of levels__
- Node Degree = __Number of children__
- Tree Degree = __Max Node Degree__
### 5.1.2 Representation Of Trees
- List Representation
    - It is often easier to work with nodes of a __fixed size.__
- Left Child-Right Sibling Representation
    - Every node has only one leftmost child and one closet right sibling.
## 5.2 Binary Tree
- Finite (__possibly empty__) collection of elements.
- A __nonempty__ binary tree has a __root__ element.
- The remaining elements (if any) are partitioned into __two__ binary trees.
- These are called the __left__ and __right__ subtrees of the binary trees.
- Special Types of binary trees
    - Skewed tree
    - Complete binary tree
### 5.2.1 Differences between a Tree & a Binary Tree
- No node in a binary tree may have a degree more than __2__, whereas there is no limit on the degree of a node in a tree.
- __A binary tree may be empty__; a tree cannot be empty.
- The subtrees of a binary tree are __ordered__; those of a tree are not ordered.
### 5.2.2 Properties of Binary Trees
- The maximum number of nodes on __levl i__ of a binary tree is __2^(i-1), i >= 1__.
- The maximum number of nodes in a binary tree of __depth k__ is __2^k - 1, k >= 1__. (A full binary tree)
- Complete Binary Tree with n Nodes
    - Start with a full binary tree that has at least __n__ nodes.
    - The binary tree defined by the nodes numbered 1 through n is the unique n node complete binary tree.
### 5.2.3 Binary Tree Representation
- Linked Representation
- Node structure:
    ```c
    typedef struct node *tree_pointer;
    typedef struct node{
        int data;
        tree_pointer left_child, right_child;
    };
    ```
## 5.3 Binary Tree Traversal
- Preorder
- Inorder
- Postorder
- Level order
- [Tree traversal 실습]( "")
## 5.4 Additional Binary Tree Operations
- Copying Binary Trees
- Testing Equality
- The Satisfiability Problem
## 5.5 Threaded Binary Trees
- A binary tree T with n nodes has 2n links and among them, (n+1) are NULL links.
- Null links mean memory waste.
- Replace the null links by pointers, called __threads__, to other nodes in the tree by using the following rules.
    - Rule 1: Keep the leftmost and the rightmost NULL pointers as NULL.
    - Rule 2: Change all other NULL pointer as
        - Left pointer = Inorder predecessor
        - Right pointer = Inorder Successor
- Problem: We can't tell if the left and right pointers on each node point to a parent node or a child node.
    - flag
- [Threaded Binary Tree 실습]( "")
## 5.6 Heaps
### Min Tree Definition
- Each tree node has a value.
- Value in any node is the minimum value in the subtree for which that node is the root.
- Equivalently, no descendent has a smaller value.
### Min Heap Definition
- complete binary tree
- min tree
### Max Heap Definition
- complete binary tree
- max tree
### Basic operations on a max heap
- Creation of an empty heap
- Insertion of a new element into the heap
- Deletion of the largest element from the heap
### 5.6.2 Priority Queues
- Heaps are frequenlty used to implement priority queues.
- Unlike the queues, FIFO lists, a priority queue deletes the element with the highest (or the lowest) priority.
- At any time, an element with arbitrary priority can be inserted into a priority queue.
## 5.7 Binary Search Trees
- A binary search tree has a better performance than any of the data structures studied so far for operations, insertion, deletion, and searching of arbitrary element.
### Definition of Binary Search Tree
- A binary tree.
- Each node has a __(key, value)__ pair.
- For every node x, all keys in the left subtree of x are smaller than that in x.
- For every node x, all keys in the right subtree of x are greater than that in x.
- The left and right subtrees are also binary search trees.
- [Binary Search Tree 실습]( "")
## 5.8 Selection Trees
### Winner Trees
- Complete binary tree with n external nodes and n - 1 internal nodes.
- External nodes represent tournament players.
- Each internal node represents a match played between its two children; the winner of the match is stored at the internal node.
- Root has overall winner.
### Loser Trees
## 5.9 Forests
- Definition: A forest is a set of n >= disjoint trees.
    - Removing the root of any binary tree produces a forest of two trees.
## 5.10 Representation of Disjoint Sets
- Find(i)
- Union Operation
    - Height Rule
    - Weight Rule
