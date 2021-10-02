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
    cin >> d;
    node* head = NULL;

    while(d!= -1){
        insertAtHead(head,d);
        cin >> d;
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

// -------------------- Merge -----------------

//This function merges 2 sorted linked list
node* merge(node* a , node* b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}

int main(){
    
    node *head, *head1;
    cin >> head >>  head1;
    cout << head << head1;
    node* m = merge(head,head1);
    cout << m << endl;
}
