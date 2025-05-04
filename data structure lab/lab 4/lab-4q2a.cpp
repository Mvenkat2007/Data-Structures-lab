#include <iostream>
using namespace std;
#include "lab-4q2b.h"



int main() {
    List list1, list2, list3; // Create three lists
    int choice, num;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert List1\n";
        cout << "2. Insert List2\n";
        cout << "3. Merge into List3\n";
        cout << "4. Display List3\n";
        cout << "5. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert into List1 (0 to stop): ";
                while (true) {
                    cin >> num;
                    if (num == 0) break; // Stop when 0 is entered
                    list1.insert(num);
                }
                break;
            case 2:
                cout << "Enter the value to insert into List2 (0 to stop): ";
                while (true) {
                    cin >> num;
                    if (num == 0) break; // Stop when 0 is entered
                    list2.insert(num);
                }
                break;
            case 3:
                list3.merge(list1); // Merge List1 into List3
                list3.merge(list2); // Merge List2 into List3
                cout << "Lists merged into List3." << endl;
                break;
            case 4:
                cout << "Displaying List3: ";
                list3.display();
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid Choice!!!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
