#include <iostream>
using namespace std;
struct Node { int data; Node *prev,*next; Node(int x):data(x),prev(nullptr),next(nullptr){} };
Node* reverseList(Node* head) {
    Node* cur = head;
    while (cur) {
        swap(cur->next, cur->prev);
        if (!cur->prev) { head = cur; break; }
        cur = cur->prev;
    }
    return head;
}
int main() {
    int n,x; cin>>n; Node *head=nullptr,*tail=nullptr;
    for(int i=0;i<n;i++){cin>>x;Node*t=new Node(x);if(!head)head=tail=t;else{tail->next=t;t->prev=tail;tail=t;}}
    head=reverseList(head);
    for(Node*p=head;p;p=p->next)cout<<p->data<<" ";
    cout<<"\n";
    while(head){Node*t=head;head=head->next;delete t;}
}
