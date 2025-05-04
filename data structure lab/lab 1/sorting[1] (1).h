#include<stdio.h>
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
