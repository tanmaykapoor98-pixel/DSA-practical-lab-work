#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* arrayToList(int arr[], int n) {
    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* node = new Node(arr[i]);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void display(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n < 0) return 0;
    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* head = arrayToList(arr, n);
    cout << "Linked list: ";
    display(head);
    delete[] arr;
    while (head) { Node* temp = head; head = head->next; delete temp; }
    return 0;
}
