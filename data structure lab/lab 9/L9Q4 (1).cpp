#include <iostream>
#include <cstdio>
#include <cstring>

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

class ExpressionTree {
private:
    Node* nodes[100]; // Array-based stack
    int top;

public:
    ExpressionTree() {
        top = -1;
    }

    void push(Node* node) {
        nodes[++top] = node;
    }

    Node* pop() {
        return nodes[top--];
    }

    Node* constructExpressionTree(const char postfix[]) {
        int length = strlen(postfix);
        for (int i = 0; i < length; i++) {
            char ch = postfix[i];

            Node* newNode = new Node(ch);

            if (ch >= '0' && ch <= '9') { 
                push(newNode); // Operand: push to stack
            } else { 
                // Operator: Pop two nodes and make them children
                newNode->right = pop();
                newNode->left = pop();
                push(newNode);
            }
        }
        return pop(); // Root node of the tree
    }

    void preorder(Node* root) {
        if (root) {
            std::printf("%c ", root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            std::printf("%c ", root->data);
            inorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            std::printf("%c ", root->data);
        }
    }
};

int main() {
    ExpressionTree tree;
    Node* root = NULL;
    char postfix[100];
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter Postfix Expression\n";
        std::cout << "2. Construct Expression Tree\n";
        std::cout << "3. Preorder Traversal\n";
        std::cout << "4. Inorder Traversal\n";
        std::cout << "5. Postorder Traversal\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter postfix expression: ";
                std::cin >> postfix;
                break;
            case 2:
                root = tree.constructExpressionTree(postfix);
                std::cout << "Expression tree constructed successfully.\n";
                break;
            case 3:
                if (root) {
                    std::cout << "Preorder Traversal: ";
                    tree.preorder(root);
                    std::cout << "\n";
                } else {
                    std::cout << "Tree not constructed yet!\n";
                }
                break;
            case 4:
                if (root) {
                    std::cout << "Inorder Traversal: ";
                    tree.inorder(root);
                    std::cout << "\n";
                } else {
                    std::cout << "Tree not constructed yet!\n";
                }
                break;
            case 5:
                if (root) {
                    std::cout << "Postorder Traversal: ";
                    tree.postorder(root);
                    std::cout << "\n";
                } else {
                    std::cout << "Tree not constructed yet!\n";
                }
                break;
            case 6:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
