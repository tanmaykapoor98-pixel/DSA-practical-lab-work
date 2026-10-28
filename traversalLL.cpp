#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    cout << "Forward traversal: ";
    for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " ";
    cout << "\n";
    while (head) { Node* temp = head; head = head->next; delete temp; }
    return 0;
}
