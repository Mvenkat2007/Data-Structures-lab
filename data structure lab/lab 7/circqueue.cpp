#include <iostream>
using namespace std;

class CircularQueue {
private:
    static const int MAX_SIZE = 5; 
    int arr[5];                    
    int front;                     
    int rear;                      
    int count;                    

public:
    CircularQueue();
    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    int dequeue();
    int peek();
};


CircularQueue::CircularQueue() {
    front = 0;
    rear = -1;
    count = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = 0;
    }
}

bool CircularQueue::isEmpty() {
    return count == 0;
}


bool CircularQueue::isFull() {
    return count == MAX_SIZE;
}


void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue " << value << endl;
        return;
    }
    rear = (rear + 1) % MAX_SIZE; 
    arr[rear] = value;
    count++;
    cout << "Enqueued " << value << endl;
}


int CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue." << endl;
        return -1; 
    }
    int value = arr[front];
    arr[front] = 0; 
    front = (front + 1) % MAX_SIZE;
    count--;
    return value;
}

int CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot peek." << endl;
        return -1; 
    }
    return arr[front];
}

int main() {
    CircularQueue queue;
    int choice, value;

    do {
        cout << "\nCircular Queue Operations:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2: {
                int dequeuedValue = queue.dequeue();
                if (dequeuedValue != -1) {
                    cout << "Dequeued value: " << dequeuedValue << endl;
                }
                break;
            }

            case 3: {
                int peekedValue = queue.peek();
                if (peekedValue != -1) {
                    cout << "Front element: " << peekedValue << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}