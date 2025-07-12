//this approach will work for binary tree 
//but not for binary search tree as it does not consider the properties of BST better opt i mean 

class Solution {
    Node* target;
    bool found = false;
    int result = -1;

    void inorder(Node* root) {
        if (!root || result != -1) return;

        inorder(root->left);

        if (found && result == -1) {
            result = root->data;
            return;
        }

        if (root == target) found = true;

        inorder(root->right);
    }

public:
    int inOrderSuccessor(Node *root, Node *x) {
        target = x;
        inorder(root);
        return result;
    }
};



//binary search tree approach
/*
    Structure of Node:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = right = nullptr;
        }
    };
*/

class Solution {
    // Helper to find the leftmost node in a subtree
    Node* leftmost(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

public:
    int inOrderSuccessor(Node* root, Node* x) {
        // ✅ Case 1: If x has a right child, successor is the leftmost node in right subtree
        if (x->right != nullptr) {
            Node* succ = leftmost(x->right);
            return succ ? succ->data : -1;
        }

        // ✅ Case 2: No right child — find the lowest ancestor whose left child is also ancestor of x
        Node* succ = nullptr;
        while (root != nullptr) {
            if (x->data < root->data) {
                // x lies in left subtree, so root could be successor
                succ = root;
                root = root->left;
            } else if (x->data > root->data) {
                // x lies in right subtree, move right
                root = root->right;
            } else {
                // Found the node x
                break;
            }
        }

        // If succ is still null, x is the rightmost node — no successor
        return succ ? succ->data : -1;
    }
};
