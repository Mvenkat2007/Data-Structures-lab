//code for stack using linked list
#include <string>
#include <iostream>
using namespace std;

struct sll{
    char letter;
    struct sll* next;
};

class stack{
    
        

    public:

        struct sll* head;
        
        stack(){
            head=nullptr;
        }

        void push(char c);
        void pop();
        void display(sll* hed);
        
};  


void stack::push(char c) {
    sll *newptr= new sll{c,nullptr};
    if(head==nullptr){
        head=newptr;
        return;
    }
    newptr->next=head;
    head=newptr;
}
void stack::pop(){
    if(head==nullptr){
        
        return;
    }
    
    head=head->next;
}
void stack::display(sll* hed){
    
    if(hed==nullptr){
       
        return;
    }
    display(hed->next);
    cout<<hed->letter;
   
    
}