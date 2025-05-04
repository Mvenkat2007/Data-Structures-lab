// Program to implement List ADT using a Singly Linked List


#include <iostream>
#include <cstdio>

using namespace std;

class List {
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* head;

public:
    List();
    void InsertBeginning(int num);
    void InsertEnd(int num);
    void InsertPos(int num, int pos);
    void DeleteBeginning();
    void DeleteEnd();
    void DeletePos(int pos);
    void Search(int num);
    void display();
    void displayReverse();
    void DisplayReverse(Node* node);
    void reverseLink();
};

// Constructor Definition
List::List() {
    head = NULL;
}

// Function to display the list elements
void List::display() {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL \n\n";
}

// Function to Insert at the beginning of the Singly Linked List
void List::InsertBeginning(int num) {
    struct Node* newnode = new Node;
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

// Function to Insert at the End of the Singly Linked List
void List::InsertEnd(int num) {
    struct Node* newnode = new Node;
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to Insert at a given position in the Singly Linked List
void List::InsertPos(int num, int pos) {
    if (pos < 1) {
        cout << "Invalid Position" << endl;
        return;
    }
    struct Node* newnode = new Node;
    newnode->data = num;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
    } else {
        cout << "Invalid Position" << endl;
        delete newnode; // Avoid memory leak
    }
}


// Function to Delete the first element of the Singly Linked List
void List::DeleteBeginning() {
    if (head == NULL) {
        cout << "List is empty. Cannot delete from the beginning." << endl;
        return;
    }

    struct Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to Delete the last element of the Singly Linked List
void List::DeleteEnd() {
    if (head == NULL) {
        cout << "List is empty. Cannot delete from the end." << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Function to Delete from a given position in the Singly Linked List
void List::DeletePos(int pos) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete from this position." << endl;
        return;
    }

    if (pos < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Function to Search for a number in the Singly Linked List
void List::Search(int num) {
    Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == num) {
            cout << num << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << num << " not found in the list." << endl;
}

// Function to display the list elements in reverse (recursive)
void List::displayReverse() {
    DisplayReverse(head);
    cout << "NULL" << endl;
}

void List::DisplayReverse(Node* head) {
    if (head == NULL)
        return;

    DisplayReverse(head->next);
    cout << head->data << "->";
}

// Function to reverse the linked list
void List::reverseLink() {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    head = prev;
}


int main() {
    List sl1;
    int choice, num, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Display Reverse\n";
        cout << "10. Reverse Link\n";
        cout << "11. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> num;
                sl1.InsertBeginning(num);
                sl1.display();
                break;
            case 2:
                cout << "Enter the value: ";
                cin >> num;
                sl1.InsertEnd(num);
                sl1.display();
                break;
            case 3:
                cout << "Enter the value: ";
                cin >> num;
                cout << "Enter the position: ";
                cin >> pos;
                sl1.InsertPos(num, pos);
                sl1.display();
                break;
            case 4:
                sl1.DeleteBeginning();
                sl1.display();
                break;
            case 5:
                sl1.DeleteEnd();
                sl1.display();
                break;
            case 6:
                cout << "Enter the position to delete: ";
                cin >> pos;
                sl1.DeletePos(pos);
                sl1.display();
                break;
            case 7:
                cout << "Enter the value to search: ";
                cin >> num;
                sl1.Search(num);
                break;
            case 8:
                sl1.display();
                break;
            case 9:
                cout << "Reversed Display: ";
                sl1.displayReverse();
                break;
            case 10:
                sl1.reverseLink();
                sl1.display();
                break;
            case 11:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid Choice!!!\n";
                break;
        }
    } while (choice != 11);

    return 0;
}
