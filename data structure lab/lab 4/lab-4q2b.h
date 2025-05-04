class List {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    List(); // Constructor
    void insert(int num); 
    void merge(List& other); 
    void display() const; 
};

// Constructor initializes the head of the list
List::List() {
    head = nullptr;
}

// Insert a new node in ascending order
void List::insert(int num) {
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = nullptr;

    // Insert as the first element or keep it in ascending order
    if (head == nullptr || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Merge another list into this list
void List::merge(List& other) {
    Node* currentOther = other.head; 
    while (currentOther != nullptr) {
        insert(currentOther->data); 
        currentOther = currentOther->next;
    }
}

// Display the list
void List::display() const {
    Node* current = head;
    if (current == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}