#include<iostream>

    class game {
    public:
        int fun(int arr[], int num);
    };
    
    int main() {
        game g;
        int test, num;
        printf("Enter the number of test cases: ");
        scanf("%d", &test);                                             
        int ans[test];
        for (int i = 0; i < test; i++) {
            printf("Enter the number of elements in the list: ");
            scanf("%d", &num);
            int arr[num];
            for (int j = 0; j < num; j++) {
                scanf("%d", &arr[j]);
            }
            ans[i] = g.fun(arr, num);
        }
        printf("\n-------OUTPUT-------\n");
        for (int i = 0; i < test; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n\n");
    }







            
    int game::fun(int arr[], int num) {
        bool seen[1001] = {false};
        int count = 0;
        for (int i = num - 1; i >= 0; i--) {
            if (seen[arr[i]]) {
                break;
            }
            seen[arr[i]] = true;
            count++;
        }
        return (num - count);
    }
    