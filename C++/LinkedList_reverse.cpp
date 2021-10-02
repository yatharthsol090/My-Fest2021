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


void insertAtHead(node* &head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node* n = new node(d);
    n->next = head;
    head = n;
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


// Reverse Linked List "ITERATEVILY"
void reverseLinkedList(node* &head){
    node *curr = head , *prev = NULL;
    node* n;
    while(curr!=NULL){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
}

// Reverse Linked List "RECURSIVELY"

node* reverseRecursive(node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }

    node* smallHead  = reverseRecursive(head->next);

    node* temp = head->next;
    temp->next = head;
    head ->next = NULL;

    return smallHead;
}



int main() {
    node* head ;
    cin >> head ;
    cout << head;
    // reverseLinkedList(head);
    // cout << head;
    head = reverseRecursive(head);
    cout << head;
}
