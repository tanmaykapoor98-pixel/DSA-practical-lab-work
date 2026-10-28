#include <iostream>
using namespace std;
struct Node { int data; Node* next; Node(int x):data(x),next(nullptr){} };
void insertAtPosition(Node*& head,int x,int pos) {
    if(pos<=1){Node*t=new Node(x);t->next=head;head=t;return;}
    Node*cur=head;
    for(int i=1;cur && i<pos-1;i++)cur=cur->next;
    if(!cur){cout<<"Invalid position\n";return;}
    Node*t=new Node(x);t->next=cur->next;cur->next=t;
}
void deleteAtPosition(Node*&head,int pos){
    if(!head||pos<1){cout<<"Invalid position\n";return;}
    if(pos==1){Node*t=head;head=head->next;delete t;return;}
    Node*cur=head;
    for(int i=1;cur->next&&i<pos-1;i++)cur=cur->next;
    if(!cur->next){cout<<"Invalid position\n";return;}
    Node*t=cur->next;cur->next=t->next;delete t;
}
int search(Node*head,int x){int pos=1;for(;head;head=head->next,pos++)if(head->data==x)return pos;return -1;}
void display(Node*head){for(;head;head=head->next)cout<<head->data<<" -> ";cout<<"NULL\n";}
int main(){
    Node*head=nullptr;int ch,x,p;
    do{cout<<"\n1.Insert at position 2.Delete at position 3.Search 4.Display 0.Exit\nChoice: ";cin>>ch;
        if(ch==1){cout<<"Value and position: ";cin>>x>>p;insertAtPosition(head,x,p);}
        else if(ch==2){cout<<"Position: ";cin>>p;deleteAtPosition(head,p);}
        else if(ch==3){cout<<"Value: ";cin>>x;p=search(head,x);if(p==-1)cout<<"Not found\n";else cout<<"Found at position "<<p<<"\n";}
        else if(ch==4)display(head);
    }while(ch!=0);
    while(head){Node*t=head;head=head->next;delete t;}
}
