



#include<cstdio>
#include<cstdlib>
#include<cmath>
int palindrome (int* num){
  int* original=(int*)malloc(sizeof(int));
  int* reverse=(int*)malloc(sizeof(int));
  *original=*num ;
  *reverse= 0 ;
   
   while(*num != 0 )
   {
      *reverse = *reverse * 10 + ( *num % 10) ;
      *num = *num/10 ;
   }


    free(num);
   if(*original==*reverse)
   {
   return 1 ;
   }
   else
   {
    return 0 ;
   }
}



int armstrong(int*num) {
     int*original=(int*)malloc(sizeof(int));
      num=(int*)malloc(sizeof(int));
     int*result =(int*)malloc(sizeof(int));
     int*digits=(int*)malloc(sizeof(int)); 
     int*remainder=(int*)malloc(sizeof(int));
     *result=0;
     digits = 0;
      *original=*num;

    // Count the number of digits
    while (*original != 0) {
    *original /= 10;
        *digits++;
    }

     *original = *num;

    // Compute Armstrong sum
    while (*original != 0) {
        *remainder = *original % 10;
        *result += pow(*remainder,*digits);
        *original /= 10;
    }

    return (*result == *num);
}



int perfect(int* num){
 int* original = (int*)malloc(sizeof(int));
 int* sum = (int*)malloc(sizeof(int));
 int* i =(int*)malloc(sizeof(int));
 *original = *num ;
 *sum  = 0 ;
 for(*i=1; *i <= *original / 2 ;(*i)++)
 {
 if(*original % *i == 0 )
 {
  *sum = *sum + *i ;  
 }
 }

 free(i);

 if(*original==*sum)
 {
    return 1 ;
 }
 else
 {
    return 0 ;
 }
}

int main(){
int*num=(int*)malloc(sizeof(int));
int *choice=(int*)malloc(sizeof(int)); //intializing the variables
do{
printf("\nThe menu\n");
printf("1-palindrome\n");
printf("2-armstrong number\n");
printf("3-perfect number\n");
printf("4-exit\n");
printf("enter your choice-");
scanf("%d",&*choice);


 //creating the menu
if(*choice==1||*choice==2||*choice==3){
printf("enter the number-");
scanf("%d",&*num);
switch(*choice){
case 1:
if(palindrome(num)){
printf("the %d is a palindrome",*num);
} 
else{
printf("it is not a palindrome");
}
break ;

case 2:
if(armstrong(num)){
printf("the %d is a armstrong",*num);
}
else{
printf("it is not a armstrong");
}
break ;


case 3:
if(perfect(num)){
printf("the %d is a perfect number",*num);
}
else{
printf("it is not a perfect number");
}
break ;
}
}
if(*choice>4){
printf(" invalid choice , enter the correct number"); 
}

}while(*choice!=4);
printf("exiting");
free(num);
free(choice);
return 0; //

}


