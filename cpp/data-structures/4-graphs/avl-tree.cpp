#include <iostream>
using namespace std;

/*
    An AVL Tree is a self-balancing binary search tree where the difference between heights of the left and right subtrees cannot be greater than 1 for all nodes.

    Why AVL Trees?
        Most BST operations (e.g., search, max, min, insert, delete, ... etc) take O(h) time where h is the height of the BST. 
        The cost of these operations may become O(N) for a skewed binary tree. Therefore, if we ensure that the height of the BST remains O(log N) after each insertion/deletion,
        then we can guarantee an upper bound of O(log N) for all of these operations. The height of an AVL tree is always O(log N) where N is the number of nodes in the tree.

    Insertion:
        To ensure that the binary tree retains AVL after each insertion, we must augment the standard BST insertion to handle rebalancing. 
        The following are 2 basic operations that can be performed to rebalance a BST without violating the constraints of a BST.
            1) Left Rotation
            2) Right Rotation

            T1, T2 and T3 are subtrees of the tree 
            rooted with y (on the left side) or x (on 
            the right side)
                 y                               x
                / \     Right Rotation          /  \
              x   T3    - - - - - - - >        T1   y 
             / \        < - - - - - - -            / \
            T1  T2       Left Rotation            T2  T3

            Keys in both of the above trees follow the 
            following order:
                keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
            So BST property is not violated anywhere.
            */


// An AVL tree node
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// Utility Function that returns the max of 2 integers
int max(int a, int b){
    return (a > b) ? a : b;
}

// Utility function that returns the height of the tree
int height(Node* n){
    if(n == NULL) return 0;
    return n->height;
}

// Helper function that allocates a new node with
// given key and NULL left and right pointers
Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node initially added at leaf

    return node;
}


void preOrder(Node* root){
    if(root != NULL){
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){

    return 0;
}