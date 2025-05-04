#include <iostream>
#include<cstdio>
using namespace std;

// Definition of a Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search for a value in the BST
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == key) {
        return true;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

// Menu-driven program
int main() {
    Node* root = nullptr;
    int choice, value;
    
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
                
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
                
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
                
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
                
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                
                if (search(root, value)) {
                    printf("Value found in the BST.\n");
                } 
                else {
                    printf("Value not found.\n");
                }
                
                break;
                
            case 6:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
