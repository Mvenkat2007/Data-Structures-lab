#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) 
    {
        int k, q;
        scanf("%d %d", &k, &q);
        int a1;
        scanf("%d", &a1);
        for (int i = 1; i < k; i++) 
        {
            int dummy;
            scanf("%d", &dummy);
        }
        for (int i = 0; i < q; i++) 
        {
            int n;
            scanf("%d", &n);
            printf("%d ", (n < a1 ? n : a1 - 1));
        }
        printf("\n");
    }
    return 0;
}
