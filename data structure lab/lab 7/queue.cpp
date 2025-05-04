#include <iostream>
using namespace std;

class queue {
    private:
        int front;
        int rear;
        int capacity;
        int arr[5];
        
    public:
        queue() {
            front = -1;
            rear = -1;
            capacity = 5;
            for (int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }
        
        int enqueue(int num);
        int dequeue();
        int peek();
        void display();
};

void menu() {
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    int choice;
    int num;
    queue list;
    
    do {
        menu();
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the element to Enqueue: ";
                cin >> num;
                if(list.enqueue(num) == -1) {
                    cout << "Queue Is Full" << endl;
                } else {
                    list.display();
                }
                break;
                
            case 2:
                num = list.dequeue();
                if(num == -1) {
                    cout << "Queue Empty" << endl;
                } else {
                    cout << "Dequeued: " << num << endl;
                    list.display();
                }
                break;
                
            case 3:
                num = list.peek();
                if(num == -1) {
                    cout << "Queue Empty" << endl;
                } else {
                    cout << "Front element: " << num << endl;
                }
                break;
                
            case 4:
                cout << "Program Exits..." << endl;
                break;
                
            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 4);
    
    return 0;
}

int queue::enqueue(int num) {
    if (rear >= capacity - 1) {
        return -1;
    }
    if (front == -1) {
        front = 0;
    }
    
    rear++;
    arr[rear] = num;
    return 1;
}

int queue::dequeue() {
    if (front == -1) {
        return -1;
    }
    
    int del = arr[front];
    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    
    return del;
}

int queue::peek() {
    if (front == -1) {
        return -1;
    }
    return arr[front];
}

void queue::display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}