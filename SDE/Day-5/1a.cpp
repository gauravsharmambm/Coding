// Stack approach to reverse a linked list.
// O(n) + O(n)stack required.

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
    stack<struct node*> S;
    struct node *temp = start;
    while(temp){
        S.push(temp);
        temp = temp->next;
    }
    start = S.top();
    S.pop();
    temp = start;
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    // Important point because in last node we need to add null in last index.
    temp->next = NULL;
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
