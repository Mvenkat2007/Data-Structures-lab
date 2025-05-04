#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>  // Include for scanf and printf

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> s(n);
    
    int max1 = -1, max2 = -1;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        if (s[i] > max1) {
            max2 = max1;
            max1 = s[i];
        } else if (s[i] > max2) {
            max2 = s[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] == max1) {
            printf("%d ", s[i] - max2);
        } else {
            printf("%d ", s[i] - max1);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
