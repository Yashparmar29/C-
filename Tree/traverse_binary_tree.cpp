#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int key) {
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    
    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        if (node->val == key) return true;

        if (key < node->val)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    
    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);

        if (key < node->val)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        return node;
    }

    
    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->val << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) {
        if (node) {
            cout << node->val << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->val << " ";
        }
    }
};

int main() {
    BST tree;
    
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    
    cout << "Search for 40: " << (tree.search(tree.root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search for 99: " << (tree.search(tree.root, 99) ? "Found" : "Not Found") << endl;

    
    cout << "\nIn-Order (Sorted): ";
    tree.inOrder(tree.root);

    cout << "\nPre-Order: ";
    tree.preOrder(tree.root);

    cout << "\nPost-Order: ";
    tree.postOrder(tree.root);

    return 0;
}