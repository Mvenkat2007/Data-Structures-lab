#include <iostream>
class ListAdt {
private:
    int current = 0;
    int max = 5;
    int arr[5];

public:
    int insertbeggining(int num);
    int insertend(int num);
    int insertpos(int position, int num);
    int deletebeggining();
    int deleteend();
    int deletepos(int pos);
    int rotate(int r);
    void display();
    int search(int num);
};

int main() {
    ListAdt list;
    int choice, result, num, pos, r;
    do {
        printf("\nMenu\n");
        printf("1.Insert Beginning\n");
        printf("2.Insert End\n");
        printf("3.Insert Position\n");
        printf("4.Delete Beginning\n");
        printf("5.Delete End\n");
        printf("6.Delete Position\n");
        printf("7.Search\n");
        printf("8.Display\n");
        printf("9.Rotate\n");
        printf("10.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            result = list.insertbeggining(num);
            if (result == 0) {
                printf("List is full\n");
            }
            break;

        case 2:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            result = list.insertend(num);
            if (result == 0) {
                printf("List is full\n");
            }
            break;

        case 3:
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position: ");
            scanf("%d", &pos);
            result = list.insertpos(pos, num);
            if (result == 0) {

                printf("List is full, cannot insert\n");
            } else if (result == -1) {

                printf("Invalid position\n");
            }
            break;

        case 4:
            result = list.deletebeggining();
            if (result == 0) {
                printf("List is empty\n");

            }
            break;

        case 5:
            result = list.deleteend();
            if (result == 0) {
                printf("List is empty\n");

            }
            break;

        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            result = list.deletepos(pos);
            if (result == 0) {
                
                printf("List is empty\n");
            } else if (result == -1) {
                printf("Invalid position\n");

            }
            break;

        case 7:
            printf("Enter the number to search: ");
            scanf("%d", &num);
            result = list.search(num);
            if (result == -1) {
                printf("Number not found\n");
            } else {
                printf("Number's position is %d\n", result);
            }
            break;

        case 8:
            list.display();
            break;

        case 9:
            printf("Enter the number of times to rotate: ");
            scanf("%d", &r);
            result = list.rotate(r);
            if (result == 1) {
                
                printf("Rotated %d times\n", r);
            }

            break;

        case 10:
            printf("Exiting\n");

            break;

        default:
            printf("You have entered the wrong value\n");
        }
    } while (choice != 10);

    return 0;
}

// Insert at beginning
int ListAdt::insertbeggining(int num) {
    if (current >= max) {
        return 0;

    }

    for (int i = current; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = num;
    current++;
    return 1;
}

// Insert at end
int ListAdt::insertend(int num) {
    if (current >= max) {
        return 0;
    }

    arr[current] = num;
    current++;
    return 1;
}

// Insert at position
int ListAdt::insertpos(int pos, int num) {
    if (current >= max) {
        return 0;
    }

    if (pos < 0 || pos > current) {
        return -1;
    }

    for (int i = current; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    current++;
    return 1;
}

// Delete from beginning
int ListAdt::deletebeggining() {
    if (current <= 0) {
        return 0;
    }
    for (int i = 0; i < current - 1; i++) {
        arr[i] = arr[i + 1];

    }
    current--;
    return 1;
}

// Delete from end
int ListAdt::deleteend() {
    if (current <= 0) {
        return 0;
    }
    current--;
    return 1;

}

// Delete at position
int ListAdt::deletepos(int pos) {
    if (current <= 0) {
        return 0;
    }
    if (pos < 0 || pos >= current) {
        return -1;
    }
    for (int i = pos; i < current - 1; i++) {
        arr[i] = arr[i + 1];
    }
    current--;

    return 1;
}

// Search for an element
int ListAdt::search(int num) {
    for (int i = 0; i < current; i++) {
        if (arr[i] == num) {
            return i;

        }
    }

    return -1;
}

// Rotate the list
int ListAdt::rotate(int r) {
    for (int i = 0; i < r; i++) {
        int temp = arr[0];
        for (int j = 0; j < current - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[current - 1] = temp;
    }

    return 1;
}

// Display the list
void ListAdt::display() {
    for (int i = 0; i < current; i++) {
        printf("%d\n", arr[i]);

    }
}
