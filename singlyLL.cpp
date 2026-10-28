#include <iostream>
using namespace std;

struct Node {
    int data; Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void insertEnd(Node*& head, int x) {
    Node* node = new Node(x);
    if (!head) { head = node; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}
void insertBeginning(Node*& head, int x) {
    Node* node = new Node(x); node->next = head; head = node;
}
bool deleteValue(Node*& head, int x) {
    if (!head) return false;
    if (head->data == x) { Node* t = head; head = head->next; delete t; return true; }
    Node* cur = head;
    while (cur->next && cur->next->data != x) cur = cur->next;
    if (!cur->next) return false;
    Node* t = cur->next; cur->next = t->next; delete t; return true;
}
void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}
int main() {
    Node* head = nullptr;
    int choice, x;
    do {
        cout << "\n1.Insert beginning 2.Insert end 3.Delete value 4.Display 0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> x; insertBeginning(head, x); break;
            case 2: cout << "Value: "; cin >> x; insertEnd(head, x); break;
            case 3: cout << "Value to delete: "; cin >> x;
                    cout << (deleteValue(head, x) ? "Deleted\n" : "Value not found\n"); break;
            case 4: display(head); break;
        }
    } while (choice != 0);
    while (head) { Node* t = head; head = head->next; delete t; }
    return 0;
}
