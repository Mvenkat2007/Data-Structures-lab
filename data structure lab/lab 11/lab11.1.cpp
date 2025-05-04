/*program to implement Hash ADT with Linear Probing. The Hash ADT has the following operations
1.Insert
2.Delete
3.Search
4.Display
5.Exit*/

#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];
    bool deleted[TABLE_SIZE]; 

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1; 
            deleted[i] = false;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    //Function to insert an element
    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != -1 && !deleted[index] && table[index] != key) {
            index = (originalIndex + ++i) % TABLE_SIZE;
            if (i == TABLE_SIZE) {
                cout << "Hash table is full. Cannot insert.\n";
                return;
            }
        }

        table[index] = key;
        deleted[index] = false;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    //Function to delete an element
    void remove(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != -1 && i < TABLE_SIZE) {
            if (table[index] == key && !deleted[index]) {
                deleted[index] = true;
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
            index = (originalIndex + ++i) % TABLE_SIZE;
        }

        cout << "Key " << key << " not found.\n";
    }

    //Function to search an element
    void search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 0;

        while (table[index] != -1 && i < TABLE_SIZE) {
            if (table[index] == key && !deleted[index]) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            index = (originalIndex + ++i) % TABLE_SIZE;
        }

        cout << "Key " << key << " not found.\n";
    }

    //Function to display an element
    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1 && !deleted[i])
                cout << i << " => " << table[i] << endl;
            else
                cout << i << " => " << "EMPTY" << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
