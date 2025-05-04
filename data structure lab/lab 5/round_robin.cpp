#include <iostream>
#include <cstdlib>
#include "roundr.h"  

using namespace std;

int main() {
    int fixedTime;
    cout << "Enter the fixed time for process execution: ";
    cin >> fixedTime;

    list queue(fixedTime);

    int choice, time;
    do {
        cout << "\n1. Insert Process\n2. Execute\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> time;
                queue.insertProcess(time);
                break;
            case 2:
                queue.execute();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
