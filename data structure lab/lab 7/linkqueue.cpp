#include <iostream>
using namespace std;


class DoublyLinkedList {
    private:
       struct node{
            struct node *prev;
            int data;
            struct node *next;
       };

       struct node *head;
       struct node *tail;
       int current;
    
    public:
        DoublyLinkedList(){
            head=NULL;
            tail=NULL;
            current =0;
        }

        
        int enqueue(int num);
       
        int dequeue();

        int peek();
        
        void display();
        

};



void menu(){
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.Peek"<<endl;
    cout<<"4.Exit"<<endl;
   
    cout<<"Enter Your Choice :";
   

}


int main(){
    int choice;
    int result;
    int num;
    int index;
    DoublyLinkedList list;
    

    do{
        menu();
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter the Number to be Enqueued :";
                cin>>num;
                result=list.enqueue(num);
            
                if(result==-2){
                    cout<<"Memory Allocation Failed"<<endl;
                    
                }
                list.display();
                
                break;
            case 2:
                result=list.dequeue();
                if(result==-2){
                    cout<<"Memory Allocation Failed"<<endl;
                    
                }
                cout<<result<<endl;
                
                break;
            case 3:
                
                result=list.peek();
                if(result==-2){
                    cout<<"Memory Allocation Failed"<<endl;
                    
                }
                if(result==-1){
                    cout<<"List Is Empty";
                }
                cout<<result<<endl;
                break;
            case 4:
            cout<<"Program Exits..."<<endl;

                break;
            
        } 
    }
    while(choice!=4);
       
    return 0;
}
int DoublyLinkedList::enqueue(int num){
    struct node *newnode=(struct node* )malloc(sizeof(struct node));
     if(newnode==NULL){
        return -2;
     }
     if (current==5){
        cout<<"List is Full"<<endl;
        return -1;
     }
     newnode->data=num;
     newnode->next=NULL;
     if(head==NULL){
        head=newnode;
        tail=newnode;
        newnode->prev=NULL;
        current++;
        return 1;
     }    
     struct node *temp=tail;
     temp->next=newnode;
     newnode->prev=temp;
     tail=newnode;
     current++;

     return 1;

}

int DoublyLinkedList::dequeue(){
    int a;
    if(head==NULL){
        cout<<"List Is Empty"<<endl;
        return -2;
    }
    struct node *temp=head;
    a=temp->data;
    if(temp->next!=NULL){
        temp->next->prev=NULL;
        
    }
    head=temp->next;

    if(head==NULL){
        tail=NULL;
    }
    
    
    free(temp);
    
    return a;

}
int DoublyLinkedList::peek(){
    if(head==NULL){
        cout<<"List Is Empty"<<endl;
        return -1;
    }

    struct node * temp=head;
    return head->data;
}

void DoublyLinkedList::display(){
    if(head==NULL){
        cout<<"List Is Empty"<<endl;
        return;
    }
    struct node *temp=head;
    cout<<"Forward :";
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<" <-> ";

        }
        temp=temp->next;

    }
    cout<<endl;
    
    return;
}

