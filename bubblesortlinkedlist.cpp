#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void bubbleSort(Node* head) {
    if (head == NULL) {
        return;
    }

    bool swapped;

    do {
        swapped = false;
        Node* temp = head;

        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }

            temp = temp->next;
        }
    } while (swapped);
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 5);
    insertAtEnd(head, 3);
    insertAtEnd(head, 8);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);

    bubbleSort(head);

    cout << "Sorted linked list: ";
    display(head);

    return 0;
}