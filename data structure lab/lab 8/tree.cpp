#include <iostream>
using namespace std;

// Structure for a node in the binary tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for Binary Tree ADT
class BinaryTree {
private:
    TreeNode* root;

    
    void preorder(TreeNode* node);
    void inorder(TreeNode* node);
    void postorder(TreeNode* node);
    bool search(TreeNode* node, char key);
    TreeNode* findNode(TreeNode* node, char value);

public:
    BinaryTree();
    ~BinaryTree();
    
    
    void insert();
    void preorder();
    void inorder();
    void postorder();
    void search(char key);
};


BinaryTree::BinaryTree() : root(nullptr) {}


BinaryTree::~BinaryTree() {}


void BinaryTree::insert() {
    char value, parentValue, direction;
    
    cout << "Enter character to insert: ";
    cin >> value;

    
    if (root == nullptr) {
        root = new TreeNode(value);
        cout << "Inserted '" << value << "' as the root node.\n";
        return;
    }

    
    cout << "Enter the parent node value: ";
    cin >> parentValue;

    
    TreeNode* parent = findNode(root, parentValue);
    if (parent == nullptr) {
        cout << "Parent node '" << parentValue << "' not found!\n";
        return;
    }

    
    cout << "Insert as (l)eft or (r)ight child of '" << parentValue << "'? (l/r): ";
    cin >> direction;

    
    if (direction == 'l' || direction == 'L') {
        if (parent->left != nullptr) {
            cout << "Left child already exists for node '" << parentValue << "'!\n";
        } else {
            parent->left = new TreeNode(value);
            cout << "Inserted '" << value << "' as left child of '" << parentValue << "'.\n";
        }
    } else if (direction == 'r' || direction == 'R') {
        if (parent->right != nullptr) {
            cout << "Right child already exists for node '" << parentValue << "'!\n";
        } else {
            parent->right = new TreeNode(value);
            cout << "Inserted '" << value << "' as right child of '" << parentValue << "'.\n";
        }
    } else {
        cout << "Invalid direction! Use 'l' for left or 'r' for right.\n";
    }
}

// Function for preorder traversal
void BinaryTree::preorder(TreeNode* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Function to perform preorder traversal
void BinaryTree::preorder() {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
}

// Function for inorder traversal 
void BinaryTree::inorder(TreeNode* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Function to perform inorder traversal
void BinaryTree::inorder() {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
}

// Function for postorder traversal 
void BinaryTree::postorder(TreeNode* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

// Function to perform postorder traversal
void BinaryTree::postorder() {
    if (!root) {
        cout << "Tree is empty!\n";
        return;
    }
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
}

// Function to search for a character in the tree
bool BinaryTree::search(TreeNode* node, char key) {
    if (node == nullptr) return false;
    if (node->data == key) return true;
    return search(node->left, key) || search(node->right, key);
}

// Function to search for a character in the tree (public interface)
void BinaryTree::search(char key) {
    if (search(root, key)) {
        cout << "Character '" << key << "' is present in the tree.\n";
    } else {
        cout << "Character '" << key << "' is NOT found in the tree.\n";
    }
}

// Helper function to find a node with a given value
TreeNode* BinaryTree::findNode(TreeNode* node, char value) {
    if (node == nullptr) return nullptr;
    if (node->data == value) return node;
    TreeNode* leftResult = findNode(node->left, value);
    if (leftResult) return leftResult;
    return findNode(node->right, value);
}

int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        cout << "\nBinary Tree Operations:";
        cout << "\n1. Insert";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Search";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.insert();
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}