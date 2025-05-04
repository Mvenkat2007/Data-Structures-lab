#include<cstdio>
void bubble(int a[],int n){

for (int i=0;i<n;i++){
for(int j=1;j<n-i-1;j++){
if(a[j]>a[j+1]){
int temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
for(int i=0;i<n;i++){
printf(" %d ",a[i]);
}
printf("\n");
}

}

void insertion(int a[],int n){
for(int i=1;i<n;i++){
int var=a[i];
int j=i-1;
while(j>=0&&a[j]>var){
a[j+1]=a[j];
a[j]=var;
j=j-1;
}
a[j+1]=var;
for(int i=0;i<n;i++){
printf(" %d ",a[i]);
}

printf("\n");}
}
void seletion(int a[],int n){
for(int i=0;i<n-1;i++){
int min_index=i;
for(int j=i+1;j<n;j++){
if(a[j]<a[min_index]){
min_index=j;
}
}
int temp=a[i];
a[i]=a[min_index];
a[min_index]=temp;
for(int i=0;i<n;i++){
printf(" %d ",a[i]);
}
printf("\n");
}
}
int main(){
int n;
printf("enter the size of array-");
scanf("%d",&n);
int a[n];
printf("enter the unsorted array-\n");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);}
printf("the unsorted array is -");
for(int i=0;i<n;i++){
printf(" %d ",a[i]);
}
printf("\nif u want to sort the arrary here are the types of sorts\n\n");
printf("1-bubble sosrt\n2-insertion sort\n3-seletion sort\n\n");
int u;
printf("enter the number-");
scanf("%d",&u);
switch(u){
case 1 :
bubble(a,n);
break ;
case 2 :
insertion(a,n);
break ;

case 3 :
seletion(a,n);
break ;

default :
printf("enter the number between 1 and 3-");

}

printf("the sorted array is -");
for(int i=0;i<n;i++){
printf(" %d ",a[i]);
}

}



