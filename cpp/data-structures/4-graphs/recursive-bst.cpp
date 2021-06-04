#include <iostream>
using namespace std;

/* Recursive implementation of a BST.
    Worst case time complexity of search and insert operations is O(h) where h is the hieght of the BST. 
    In the worst case, we may have to travel from root to the deepest leaf node; however, the height of a 
    skewed tree may become n and the time complexity of search and insert operation may become O(n). */

struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;
};

// Utility function to create a new BST node
struct TreeNode* newNode(int data){
    struct TreeNode* temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
};

// Utility function to perform in-order traversal
void inorder(struct TreeNode* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

// Utility function to insert a new node in the BST
struct TreeNode* insert(struct TreeNode* node, int key){
    // If the tree is empty, return a new (root) node
    if(node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

int main(){
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct TreeNode *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    // print inoder traversal of the BST 
    inorder(root); 
    return 0;
}