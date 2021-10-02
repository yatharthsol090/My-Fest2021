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


void reverseLinkedList(node* &head){
    node* P = NULL;
    node* C = head;
    node* N ;
    while(C != NULL){
        N = C-> next;
        C->next = P;
        P = C;
        C = N;
    }
    head = P;
}

node* reverseRecursive(node * head){
    if(head->next == NULL or head == NULL){
        return head;
    }

    node* smallHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

// Runner Technique to find mid point of linkedlist
// 2 horses race
// 1st horse -> 2x speed
// 2nd horse -> x speed
node* mid(node* head){
    if(head==NULL or head->next == NULL){
        return head;
    }
    node* fast = head->next;
    node* slow = head;
    while(fast != NULL and fast->next != NULL ){
        fast = fast->next->next;
        slow = slow ->next;
    }
    return slow;
}

node* kthNode_end(node* head,int k){

    node* fast = head;
    node* slow = head;
    while(k--){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


int main() {
    node* head ;
    cin >> head ;
    cout << head;
    // reverseLinkedList(head);
    // cout << head;
    // head = reverseRecursive(head);
    // cout << head;

    node* midpt = mid(head);

    cout << midpt->data << endl;

    node* kth = kthNode_end(head,3);
    cout << kth -> data;
}
