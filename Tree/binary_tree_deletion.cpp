#include <iostream>
using namespace std;

// Structure for a BST Node
struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper: Find the minimum value node (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Function to insert a value
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
        
    return root;
}

// Function to delete a value
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1 & 2: One child or Leaf
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print tree (Inorder: Left, Root, Right)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // 1. Building the tree
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : values) root = insert(root, x);

    cout << "Original Tree: ";
    inorder(root); 
    cout << endl;

    // 2. Deleting a leaf node
    cout << "Deleting 20 (Leaf)..." << endl;
    root = deleteNode(root, 20);
    inorder(root);
    cout << endl;

    // 3. Deleting a node with one child
    cout << "Deleting 30 (One child)..." << endl;
    root = deleteNode(root, 30);
    inorder(root);
    cout << endl;

    // 4. Deleting a node with two children
    cout << "Deleting 50 (Root/Two children)..." << endl;
    root = deleteNode(root, 50);
    inorder(root);
    cout << endl;

    return 0;
}