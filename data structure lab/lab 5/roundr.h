#include <iostream>
using namespace std;

class list {
    struct Node {
        int time;
        Node* next;
    } *tail;
    int fixedTime;

public:
    list(int ft) : tail(nullptr), fixedTime(ft) {}

    void insertProcess(int t);

    void execute();
};

// To insert the task and the time required to do the task
void list::insertProcess(int t) {
    Node* newNode = new Node();
    newNode->time = t;

    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// To execute the task
void list::execute() {
    if (!tail) {
        cout << "No processes to execute." << endl;
        return;
    }

    Node* head = tail->next;
    cout << "Executing process with time: " << head->time << endl;
    head->time -= fixedTime;

    if (head->time <= 0) {
        cout << "Process completed." << endl;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    } else {
        cout << "Process reinserted with remaining time: " << head->time << endl;
        tail->next = head->next;
        head->next = tail->next;
        tail->next = head;
        tail = head;
    }
}
