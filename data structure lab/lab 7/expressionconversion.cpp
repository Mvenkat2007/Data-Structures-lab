#include "Stack.h"
#include <iostream>
#include <string>


int main(void){
    stack arr;
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    
    int len;
    len=str.length();

    for(int i=0;i<len;i++){

        if (str[i]!='+' && str[i] != ' ' ){
            
            arr.push(str[i]);
        }
        if(str[i]=='+'){
            arr.pop();
        }

    }

    arr.display(arr.head);
}