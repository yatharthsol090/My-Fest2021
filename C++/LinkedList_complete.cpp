#include <iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
//Constructor 
    node(int d){
        this-> data = d ;
        this-> next = NULL;
    }
};

// To determine the length of linked list
int length(node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

// -------------------- INSERTION -----------------

//Insert At Head
void insertAtHead(node* &head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
}

//Insert At Tail
void insertAtTail(node* &head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}

//Insert in between the linked list
void insertInMiddle(node* &head,int d, int pos){
    //Corner Cases
    if(head == NULL || pos == 0){
        head = new node(d);
        return;
    }
    else if(pos>= length(head))
    {
        insertAtTail(head,d);
    }
    else{
        int jump = pos-1;
        node* temp = head;
        while(jump--){
            temp=temp->next;
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}


// -------------------- DELETION -----------------

// Delete head of linked list
void deleteHead(node* &head){
    if(head==NULL){
        return;
    }
    else{
        node* temp = head->next;
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Delete Tail of Linked List
void deleteTail(node* &head){
    if(head==NULL){
        return;
    }
    else{
        node*temp = head;
        while((temp->next)->next!=NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

    }
}

// Delete In Middle of linked list 
// using node's position
void deleteInMiddle_pos(node* &head,int pos){
    // Corner Cases
    if(head== NULL || pos <= 1){
        deleteHead(head);
        return;
    }
    else if(pos>=length(head)){
        deleteTail(head);
        return;
    }
    else{
        int jumps = pos-2;
        node* temp = head;
        while(jumps--){
            temp = temp -> next;
        }
        node* temp1 = temp ->next;
        temp->next = temp1->next;
        delete temp1;
        
    }
}

// Delete in Middle of Linked List 
// using node's value
void deleteInMiddle_value(node* &head,int value){

}

// -------------------- INPUT/OUTPUT -----------------

// Take input from user
node* take_input(){
    int d;
    node* head = NULL;

    while(cin >> d){
        insertAtHead(head,d);
    }
    return head;
}



//Print linked list
void print(node* head){
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// -------------------- OPERATOR OVERLOADING -----------------


ostream& operator<<(ostream &os,node* head){
    print(head);
    return os; // cout << head will represent linked list
} 

istream& operator>>(istream& is,node* &head){
    head = take_input();
    return is;
}

int main() {
    node* head;
    cin >> head ;
    // insertAtHead(head,30);
    // insertAtHead(head,12);
    // insertAtHead(head,123);
    // insertAtHead(head,235);
    // print(head);

    // insertAtTail(head,1654);
    // insertAtTail(head,1324);
    // print(head);
    // insertInMiddle(head,6435,4);
    // insertInMiddle(head,6477,7);
    // print(head);
    deleteHead(head);
    cout << head ;
    deleteTail(head);
    // cout << head;
    cout << head ;
    deleteInMiddle_pos(head,1);
    cout << head;
    //print(head);


    return 0;
}
