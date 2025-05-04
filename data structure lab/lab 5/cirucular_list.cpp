//TO do the list ADT with circular linked list
#include<iostream>
#include<cstdlib>
class list{
    private:
    struct node{
        int data;
        struct node* link;
    };
    struct node* head;
    int cur;

    public:
    list() {
        head=NULL;
        cur=0;
    }
    int inbeg(int num);
    int inend(int num);
    int inmid(int num,int index);
    int delbeg();
    int delend();
    int delmid(int index);
    int search(int num);
    void  dis();

};
int main(){
    list linked;
    int num,index,ans,choice;
    while(true){
        printf("\nMENU:\n 1) Insert in the beginning\n 2) Insert in the end\n 3) Insert at index\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                ans = linked.inbeg(num);
                if (ans == 1) {
                    printf("Inserted\n");
                } else {
                    printf("Failed\n");
                }
                break;

            case 2:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                ans = linked.inend(num);
                if (ans == 1) {
                    printf("Inserted\n");
                } else {
                    printf("Failed\n");
                }
                break;

            case 3:
                printf("Enter the index to be inserted: ");
                scanf("%d", &index);
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                ans = linked.inmid(num,index);
                if (ans == 1) {
                    printf("Inserted\n");
                } else {
                    printf("Failed\n");
                }
                break;

            case 4:        
                ans = linked.delbeg();
                if (ans == -1) {
                    printf("Faied\n");
                } else {
                    printf("%d deleated!!\n",ans);
                }
                break;

            case 5:        
                ans = linked.delend();
                if (ans == -1) {
                    printf("Faied\n");
                } else {
                    printf("%d deleated!!\n",ans);
                }
                break;

            case 6:        
                printf("Enter the index to be deleated: ");
                scanf("%d", &index);
                ans = linked.delmid(index);
                if (ans == 0) {
                    printf("Faied\n");
                } else {
                    printf("%d deleated!!\n",ans);
                }
                break;

            case 7:
                printf("Enter the number to be searched: ");
                scanf("%d", &num);
                ans = linked.search(num);
                if (ans == -1) {
                    printf("Failed\n");
                } else {
                    printf("%d is the index of the number %d\n",ans,num);
                }
                break;

            case 8:
                linked.dis();
                break;
                
            case 9:
                printf("Exiting the loop!!!\n");
                break;

            default:
                printf("You have entered the wrong value!\n");
                break;
        }
        if (choice == 9) {
            break;
        } else {
            continue;
        }
    }
    return 0;
}

//To insert the number in the bergining
int list::inbeg(int num){
    struct node* newnode=(struct node* )malloc(sizeof(struct node));
    if(newnode==NULL){
        return 0;
    }
    newnode->data=num;
    newnode->link=NULL;
    if(head==NULL){
        newnode->link=newnode;
        head=newnode;
    }
    else{
        struct node*temp=head;
        while(temp->link !=head){
            temp=temp->link;
        }
        newnode->link=head;
        temp->link=newnode;
        head=newnode;
    }
    cur++;
    return 1;
}

//To insert the number in the end
int list::inend(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        return 0;
    }
    newnode->data=num;
    newnode->link=NULL;
    struct node* temp=head;
    while(temp->link!= head){
        temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;
    cur ++;
    return 1;

}

//To insert the number in the position
int list::inmid(int num,int index){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        return 0;
    }
    if(index>cur){
        return 0;
    }
    newnode->data=num;
    newnode->link=NULL;
    if(index==0){
        if(head==NULL){
            newnode->link=newnode;
            head=newnode;
        }
        else{
            struct node*temp=head;
            while(temp->link !=head){
                temp=temp->link;
            }
            newnode->link=head;
            temp->link=newnode;
            head=newnode;
        } 
    }
    else{
        struct node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->link;
        }
        newnode->link=temp->link;
        temp->link=newnode;
    }
    cur ++;
    return 1;
}

//To delete the number in the begning
int list:: delbeg(){
    int value;
    if(head==NULL){
        return -1;
    }
    value=head->data;
    if (head->link == head) {
        free(head);
        head = NULL;
    }
    else{
    struct node* temp1=head;
    struct node* temp=head;
    while(temp->link!=head){
        temp=temp->link;
    }
    temp->link=head->link;
    head=temp1->link;
    free(temp1);
    }
    cur--;
    return value;
}

//To delete the element in the end of the list
int list::delend(){
    int value;
    if (head==NULL){
        return -1;
    }
    if (head->link == head) {
        value=head->data;
        free(head);
        head = NULL;
    }
    else{
        struct node* temp=head;
        while(temp->link->link!=head){
            temp=temp->link;
        }
        struct node* temp1=temp->link;
        value=temp1->data;
        temp->link=head;
        free(temp1);
    }
    cur--;
    return value;
}

//To delete the elment in the given position
int list::delmid(int index){
    int value;
    if(head==NULL){
        return -1;
    }
    if(index==0){
        value=head->data;
        if (head->link == head) {
            free(head);
            head = NULL;
        }
        else{
        struct node* temp1=head;
        struct node* temp=head;
        while(temp->link!=head){
            temp=temp->link;
        }
        temp->link=head->link;
        head=temp1->link;
        free(temp1);
        }
    }
    else if(index==cur-1){
        struct node* temp=head;
        while(temp->link->link!=head){
            temp=temp->link;
        }
        struct node* temp1=temp->link;
        value=temp1->data;
        temp->link=head;
        free(temp1);
    }
    else{
        struct node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->link;
        }
        struct node* temp1=temp->link;
        value=temp1->data;
        temp->link=temp1->link;
        free(temp1);
    }
    cur--;
    return value;
}

//To search the number in the lilnked list
int list::search(int num){
    int i;
    i=0;
    struct node* temp=head;
    do{
        if(temp->data==num){
            return i; 
        }
        temp=temp->link;
        i++;
    }while(temp !=head);
    return -1;
}

//To display the linked list
void list::dis(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp=head;
    do{
        printf("%d  ",temp->data);
        temp=temp->link;
    }while(temp !=head);
    printf("\n");
}