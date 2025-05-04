/*program to implement Hash ADT with Separate Chaining. The Hash ADT has the following operations
1.Insert
2.Delete
3.Search
4.Exit*/

#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    list<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    
   //Function to insert an element
    void insert(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) {
                cout << "Key " << key << " already exists.\n";
                return;
            }
        }
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    //Function to delete an element
    void remove(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                cout << "Deleted " << key << " from index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found.\n";
    }

    //Function to insert an element
    void search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found.\n";
    }

    //Function to display an element
    void display() {
        cout << "Hash Table (Separate Chaining):\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " => ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

        ht.display();

    } while (choice != 4);

    return 0;
}
