// Finding middle node of linked list.
// Approaches: 1. Traverse LL and count number of nodes and in second traversal we go till mid of node
//                 to get mid element.
//             2. 2 pointer approach(Only one traversal required.)
//                 One is fast ptr and another is slow ptr, while fast ptr reaches end the slow will
//                 reach to mid of LL. 

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

void middleNode(){
    if(start != NULL){
        struct node *slow, *fast;
        slow = start;
        fast = start;
        while(fast || fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<slow->data<<endl;
    }
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
    middleNode();
}
