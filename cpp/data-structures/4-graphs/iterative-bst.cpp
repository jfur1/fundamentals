#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

class BST{
    private:
        TreeNode* root;
        
        void printNode(TreeNode* n){
            if(n->left != NULL)
                printNode(n->left);
            
            cout << n->data << " ";

            if(n->right != NULL)
                printNode(n->right);
        }

    public:
        // Default Constructor
        BST(int value){
            root = new TreeNode;
            root->data = value;
            root->parent = NULL; // Root's parent always set to NULL
            root->left = NULL;
            root->right = NULL;
        }

        // Default Destructor
        ~BST(){
            delete root;
        }

        int insert(int value){
            // Initialize a new node
            TreeNode* newNode = new TreeNode;
            newNode->data = value;
            newNode->parent = NULL;
            newNode->left = NULL;
            newNode->right = NULL;

            // Determine where to insert new node
            TreeNode* tmp = root;
            while(tmp != NULL){
                // Go left
                if(value < tmp->data){
                    if(tmp->left == NULL){
                        tmp->left = newNode;
                        newNode->parent = tmp;
                        return 0;
                    }
                    tmp = tmp->left;
                }
                // Go right
                else if(value > tmp->data){
                    if(tmp->right == NULL){
                        tmp->right = newNode;
                        newNode->parent = tmp;
                        return 0;
                    }
                    tmp = tmp->right;
                }
                // If we have duplicate values, each of the duplicate is just as good as the last
				// Adding duplicate values just makes our tree imbalanced and ugly with no benefit.
				// Therefore, we can just ignore duplicate values.
                else{
                    delete newNode;
                    return -1;
                }
            }
            return -1;
        }

        void inOrderPrint(){ // Helper function to call printNode and root, since they are private
			printNode(root);
		}

        TreeNode* minNode(TreeNode* n){
            TreeNode* tmp = n;
            while(tmp && tmp->left != NULL)
                tmp = tmp->left;
            return tmp;
        }

        TreeNode* deleteNode(TreeNode* tmp, int value){
            // Base Case
            if(tmp == NULL) return tmp;

            // If the key (data) to be deleted is less than the root, then it lies in the left subtree.
            if(value < tmp->data)
                tmp->left = deleteNode(tmp->left, value);
            
            // Similarly, if the key (data) to be deleted is greater than the root, then it lies in the right subtree
            if(value > tmp->data)
                tmp->right = deleteNode(tmp->right, value);

            // If the key (data) to be deleted is the same as the root's key, then this is the node to be deleted.
            else{
                if(tmp->left == NULL){
                    struct TreeNode* tmp2 = tmp->right;
                    free(tmp);
                    return tmp2;
                }
                else if(tmp->right == NULL){
                    struct TreeNode* tmp2 = tmp->left;
                    free(tmp);
                    return tmp2;
                }

                // Node with 2 children: Get the inorder successor (smallest in the right sub-tree)
                struct TreeNode* tmp2 = minNode(tmp->right);

                // Copy the in order successor's content to this node
                tmp->data = tmp2->data;

                tmp->right = deleteNode(tmp->right, tmp2->data);
            }
            return tmp;
        }
};

int main(){
	BST bst(4);

/* Let us create following BST 
            4 
         /     \ 
        2       6 
      /  \       \ 
     1    3       9 
 */

	bst.insert(6);
	bst.insert(2);
	bst.insert(3);
	bst.insert(9);
	bst.insert(1);
	bst.insert(2);

	//bst.deleteNode(, 3);
	bst.inOrderPrint();
    cout << endl;
    return 0;
}