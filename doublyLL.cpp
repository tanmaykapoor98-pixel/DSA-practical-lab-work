#include <iostream>
using namespace std;

struct Node {
    int data; Node *prev, *next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};
void insertEnd(Node*& head, int x) {
    Node* node = new Node(x);
    if (!head) { head = node; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node; node->prev = cur;
}
void deleteValue(Node*& head, int x) {
    Node* cur = head;
    while (cur && cur->data != x) cur = cur->next;
    if (!cur) { cout << "Value not found\n"; return; }
    if (cur->prev) cur->prev->next = cur->next; else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    delete cur; cout << "Deleted\n";
}
void display(Node* head) {
    cout << "Forward: ";
    Node* tail = nullptr;
    for (Node* cur = head; cur; cur = cur->next) { cout << cur->data << " "; tail = cur; }
    cout << "\nBackward: ";
    for (Node* cur = tail; cur; cur = cur->prev) cout << cur->data << " ";
    cout << "\n";
}
int main() {
    Node* head = nullptr; int ch, x;
    do {
        cout << "\n1.Insert end 2.Delete value 3.Display 0.Exit\nChoice: "; cin >> ch;
        if (ch == 1) { cout << "Value: "; cin >> x; insertEnd(head, x); }
        else if (ch == 2) { cout << "Value: "; cin >> x; deleteValue(head, x); }
        else if (ch == 3) display(head);
    } while (ch != 0);
    while (head) { Node* t = head; head = head->next; delete t; }
    return 0;
}
