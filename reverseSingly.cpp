#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int x): data(x), next(nullptr) {} };
Node* reverseList(Node* head) {
    Node *prev = nullptr, *cur = head;
    while (cur) { Node* nextNode = cur->next; cur->next = prev; prev = cur; cur = nextNode; }
    return prev;
}
int main() {
    int n, x; cin >> n;
    Node *head = nullptr, *tail = nullptr;
    for (int i=0; i<n; i++) { cin >> x; Node* t=new Node(x); if(!head) head=tail=t; else {tail->next=t; tail=t;} }
    head = reverseList(head);
    for (Node* p=head; p; p=p->next) cout << p->data << " ";
    cout << "\n";
    while(head){Node*t=head;head=head->next;delete t;}
}
