#include <iostream>
using namespace std;

class list {
private:
    struct node {
        node* pre;
        int data;
        node* link;
    };
    node* head;
    node* tail;
    int cur;

public:
    list() : head(nullptr), tail(nullptr), cur(0) {}

    int inbeg(int num);
    int inend(int num);
    int inmid(int num, int index);
    int delbeg();
    int delend();
    int delmid(int index);
    int search(int num);
    void dis();
};

int main() {
    list linked;
    int num, index, ans, choice;
    while (true) {
        cout << "\nMENU:\n 1) Insert in the beginning\n 2) Insert in the end\n 3) Insert at index\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the number to be inserted: ";
            cin >> num;
            ans = linked.inbeg(num);
            if (ans == 1) {
                cout << "Inserted\n";
            } else {
                cout << "Failed\n";
            }
            break;

        case 2:
            cout << "Enter the number to be inserted: ";
            cin >> num;
            ans = linked.inend(num);
            if (ans == 1) {
                cout << "Inserted\n";
            } else {
                cout << "Failed\n";
            }
            break;

        case 3:
            cout << "Enter the index to be inserted: ";
            cin >> index;
            cout << "Enter the number to be inserted: ";
            cin >> num;
            ans = linked.inmid(num, index);
            if (ans == 1) {
                cout << "Inserted\n";
            } else {
                cout << "Failed\n";
            }
            break;

        case 4:
            ans = linked.delbeg();
            if (ans == 0) {
                cout << "Failed\n";
            } else {
                cout << ans << " deleted!!\n";
            }
            break;

        case 5:
            ans = linked.delend();
            if (ans == 0) {
                cout << "Failed\n";
            } else {
                cout << ans << " deleted!!\n";
            }
            break;

        case 6:
            cout << "Enter the index to be deleted: ";
            cin >> index;
            ans = linked.delmid(index);
            if (ans == 0) {
                cout << "Failed\n";
            } else {
                cout << ans << " deleted!!\n";
            }
            break;

        case 7:
            cout << "Enter the number to be searched: ";
            cin >> num;
            ans = linked.search(num);
            if (ans == -1) {
                cout << "Failed\n";
            } else {
                cout << num << " is at index " << ans << "\n";
            }
            break;

        case 8:
            linked.dis();
            break;

        case 9:
            cout << "Exiting the loop!!!\n";
            break;

        default:
            cout << "You have entered the wrong value!\n";
            break;
        }
        if (choice == 9) {
            break;
        } else {
            continue;
        }
    }

    return 0;
}

// To insert the element at the beginning
int list::inbeg(int num) {
    node* newnode = new node();
    if (!newnode) {
        return 0;
    }
    newnode->data = num;
    newnode->pre = nullptr;
    newnode->link = head;
    if (head != nullptr) {
        head->pre = newnode;
    }
    head = newnode;
    if (tail == nullptr) {
        tail = newnode;
    }
    cur++;
    return 1;
}

// To insert the element at the end
int list::inend(int num) {
    node* newnode = new node();
    if (!newnode) {
        return 0;
    }
    newnode->data = num;
    newnode->pre = tail;
    newnode->link = nullptr;
    if (tail != nullptr) {
        tail->link = newnode;
    }
    tail = newnode;
    if (head == nullptr) {
        head = newnode;
    }
    cur++;
    return 1;
}

// To insert the element at the position
int list::inmid(int num, int index) {
    node* newnode = new node();
    if (!newnode) {
        return 0;
    }
    if (index > cur) {
        return 0;
    }
    newnode->data = num;
    newnode->link = nullptr;
    newnode->pre = nullptr;

    if (index == 0) {
        newnode->link = head;
        if (head != nullptr) {
            head->pre = newnode;
        }
        head = newnode;
    }
    else if (index == (cur + 1)) {
        newnode->pre = tail;
        if (tail != nullptr) {
            tail->link = newnode;
        }
        tail = newnode;
    }
    else {
        node* temp = head;
        for (int i = 0; i < index - 1 && temp->link != nullptr; i++) {
            temp = temp->link;
        }
        if (temp == nullptr) {
            delete newnode;
            return 0;
        }
        newnode->link = temp->link;
        newnode->pre = temp;
        if (temp->link != nullptr) {
            temp->link->pre = newnode;
        }
        temp->link = newnode;
    }
    cur++;
    return 1;
}

// To delete the number at the beginning
int list::delbeg() {
    int a;
    if (head == nullptr) {
        return 0;
    }
    node* temp = head;
    a = head->data;
    if (head->link != nullptr) {
        head->link->pre = nullptr;
    }
    head = head->link;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    cur--;
    return a;
}

// To delete the number at the end
int list::delend() {
    int a;
    if (tail == nullptr) {
        return 0;
    }
    node* temp = tail;
    a = tail->data;
    if (tail->pre != nullptr) {
        tail->pre->link = nullptr;
    }
    tail = tail->pre;
    if (tail == nullptr) {
        head = nullptr;
    }
    delete temp;
    cur--;
    return a;
}

// To delete the number at the index
int list::delmid(int index) {
    node* temp = head;
    int a;
    if (index > cur) {
        return 0;
    }
    if (index == 0) {
        a = head->data;
        if (head->link != nullptr) {
            head->link->pre = nullptr;
        }
        head = head->link;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }
    else {
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->link;
        }
        a = temp->data;
        temp->pre->link = temp->link;
        if (temp->link != nullptr) {
            temp->link->pre = temp->pre;
        }
        else {
            tail = temp->pre;
        }
        delete temp;
        cur--;
        return a;
    }
}

// To search the number in the linked list
int list::search(int num) {
    int i = 0;
    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == num) {
            return i;
        }
        temp = temp->link;
        i++;
    }
    return -1;
}

// To display the list
void list::dis() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << "\n";

    temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->pre;
    }
    cout << "\n";
}
