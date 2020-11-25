// Reverse a linked list.
// Approaches: 1. 3 pointer approach --> O(n)
//             2. stack approach --> O(n) + O(n)

# include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node* createNode(int data){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

void addNode(int data){
    struct node *p = createNode(data);
    if(start == NULL){
        start = p;
        return;
    }
    struct node* temp = start;
    while(temp->next)
        temp = temp->next;
    temp->next = p;
}

void display(){
    struct node *temp = start;
    if(start == NULL){
        cout<<"LL is empty.\n";
        return;
    }
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverseLL(){
    if(start == NULL || start->next == NULL)
        return;
    struct node *ptr, *p1, *p2;
    ptr = start;
    p1 = NULL;
    p2 = NULL;
    while(ptr){
        p2 = ptr->next;
        ptr->next = p1;
        p1 = ptr;
        ptr = p2;
    }
    start = p1;
}

int main(){
    addNode(10);
    addNode(20);
    addNode(30);
    addNode(40);
    addNode(50);
    addNode(60);
    addNode(70);
    display();
    reverseLL();
    display();
}