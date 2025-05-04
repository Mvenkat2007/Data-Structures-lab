#include <cstdio>
#include"sorting.h"
int linear_search(int a[],int n,int key){

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {                 //LINEAR SEARCH
            return i;
        }
    }
    return -1;
}


int bineary_search(int a[],int n,int key){

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a [mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
int n;
printf("enter the size of array-");               //geeting the array from user
scanf("%d",&n);
int a[n];
printf("enter the  array-\n");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);}
printf("the  array is -");
for(int i=0;i<n;i++){
printf(" %d ",a[i]);                         //printing the intial array
}
printf("if u want to search for an element in the array you have these options\n");
int key;
printf("enter the element  in the array to search-");                // searching by linear or binary 
scanf("%d",&key);
printf("1-linear search\n2-binary search\n");
int u;
printf("enter the number-");
scanf("%d",&u);

switch(u){
case 1 :
 int l_result ;
 l_result = linear_search(a, n, key);

    if (l_result != -1) {                                           //finding element in linear search
        printf("Element %d found at index %d.\n", key, l_result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
break ;

case 2 :                                          //finding element in binary search 
 printf("if uwant to do binary search u have to sort the array first \n we can do  it by bubble sort-\n");
 
 
 bubble(a,n);
 printf("the sorted array is -");
 for(int i=0;i<n;i++){
 printf(" %d ",a[i]);
 }
 
 
 

 
 

 int b_result;
 b_result =bineary_search(a, n,key);

    if (b_result != -1) {
        printf("Element %d found at index %d.\n", key, b_result);
    } else {
        printf("Element %d not found in the array.\n",key);
    }
break ;

 default :
 printf("enter the number either 1 or 2 ") ;
 }

 }
