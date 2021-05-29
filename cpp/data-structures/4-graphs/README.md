# [Data Structures](../)

## Trees and Graphs (C++)

### Types of Trees
A tree is a data structure composed of nodes.
  - Each tree has a root node. (Actually, this isn't strictly necessary in graph theory, but is typically how we use trees in programming).
  - The root node has zero or more child nodes.
  - Each child node has zero or mode child nodes, and so on.

The tree cannot contain cycles. The nodes may or may not be in a particular order, they could have any data types as values, and they may or may not have links back to their parent nodes.

A simple class definition for a Node:
  > ```
  > class Node{
  >   public:
  >     string name;
  >     Node[] children;
  > }

### Trees vs. Binary Trees:
A binary tree is a tree in which each node has up to two children. Not all trees are binary trees. For example, this tree is not a binary tree. You could call it a ternary tree:

![ternary-tree](../img/ternary-tree.png)

There are occasions where you might have a tree that is not a bianry tree. For example, suppose you were using a tree to represent a bunch of phone numbers. In this case, you might use a 10-ary tree, with each node having up to 10 children (1 for each digit).

A node is called a `leaf` if it has no children.

### Binary Tree vs. Binary Search Tree:
A binary search tree is a binary tree in which every node follows a specific ordering: 
  - `all left descendants <= n <= all right descendants`
  - This must be true for every node `n`

<p float="left">
  <p> Not a binary search tree</p>
  <img style="width: 100;" src="../img/binary-tree.png">
  <p> A binary search tree</p>
  <img style="width: 100;" src="../img/bst.png">
</p>
