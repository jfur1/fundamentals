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

    Steps for AVL Insertion:
        * Let the newly inserted node be W
        1) Perform standard BST insertion for W.
        2) Starting from W, travel up and find the first unbalanced node. 
            - Let Z be the first unbalanced node.
            - Let Y be the child of Z that is found on the path from W to Z
            - Let X be the grandchild of Z that is found on the path from W to Z
        3) Rebalance the tree by rotating the subtree, rooted with Z.
           There are 4 possible arrangements for X, Y, and Z:
           (T1, T2, T3 and T4 are subtrees.)

               a) Z->left = Y ; Y->left = X ; ("Left Left Case")
               
                           z                                      y 
                          / \                                   /   \
                        y   T4      Right Rotate (z)          x      z
                       / \          - - - - - - - - ->      /  \    /  \ 
                      x   T3                               T1  T2  T3  T4
                     / \
                   T1   T2

               b) Z->left = Y ; Y->right = X ; ("Left Right Case")

                      z                               z                           x
                     / \                            /   \                        /  \ 
                    y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
                   / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
                  T1   x                          y    T3                    T1  T2 T3  T4
                      / \                        / \
                    T2   T3                    T1   T2

               c) Z->right = Y ; Y->right = X ; ("Right Right Case")

                     z                                y
                    /  \                            /   \ 
                   T1   y     Left Rotate(z)       z      x
                       /  \   - - - - - - - ->    / \    / \
                      T2   x                     T1  T2 T3  T4
                          / \
                         T3  T4

               d) Z->right = Y ; Y->left = X ; ("Right Left Case")

                    z                            z                            x
                   / \                          / \                          /  \ 
                 T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
                     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
                    x   T4                      T2   y                  T1  T2  T3  T4
                   / \                              /  \
                 T2   T3                           T3   T4
    
    ** IMPLEMENTATION: **
        1) Perform the normal BST insertion
        2) The current node must be an ancestor of the newly inserted node. Update the height of the current node
        3) Get the balance factor (left subtree height - right subtree height) of the current node
        4) If balanceFactor > 1, then current node is unbalanced and we either have Left-Left Case or Left-Right Case.
            - To check whether or not we have Left-Left Case, compare newly inserted key with the key in the left subtree's root
        5) If balanceFactor < -1, then the current node is unbalanced and we either have Right-Right Case or Right-Left Case
            - To check whether or not we have Right-Right Case, comare the newly inserted key with the key in the right subtree's root

    Time Complexity:
        - Left/Right Rotation opertations take O(1) time since only a few pointers are changed
        - Updating heights and balance factors is also O(1) time
        - So, time complexity of AVL insert is the same as BST insert --> O(h) time, where h is the height of the tree
        * Since AVL tree is balanced, however, we know the height will always be O(log N)
            ** Therefore, time complexity of AVL insertion is O(log N) time!
        
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

// Utility function to right-rotate subtree rooted with y. (See above diagram)
Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right) + 1);
    x->height = max(height(x->left), height(x->right) + 1);

    // Return the new root
    return x;
}

// Utility function to left-rotate subtree rooted with x. (See above diagram)
Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right) + 1);
    y->height = max(height(y->left), height(y->right) + 1);

    // Return new root
    return y;
}

// Returns the balance factor for a node n
int getBalance(Node* n){
    if(n == NULL) return 0;
    return height(n->left) - height(n->right);
}

// Recursive function to insert a key in the subtree rooted with node
// Returns the new root of the rebalanced subtree
Node* insert(Node* node, int key){
    // 1) Perform normal BST insertion:
    if(node == NULL) return (newNode(key));

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else    // Equal keys not valid in our BST
        return node;

    // 2) Update height of this ancestor node:
    node->height = 1 + max(height(node->left), height(node->right));

    // 3) Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // 4) If node becomes unbalanced, then we have 4 possible cases:
    
    // Left-Left Case
    if(balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right-Right Case
    if(balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right Case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right-Left Case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
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
    Node *root = NULL;
     
    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
     
    /* The constructed AVL Tree would be
             30
            /  \
           20   40
          /  \    \
        10   25    50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}




