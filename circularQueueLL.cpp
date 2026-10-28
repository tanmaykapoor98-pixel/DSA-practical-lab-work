#include <iostream>
using namespace std;
struct Node{int data;Node*next;Node(int x):data(x),next(nullptr){}};
Node*rearNode=nullptr;
void enqueue(int x){Node*t=new Node(x);if(!rearNode){rearNode=t;t->next=t;}else{t->next=rearNode->next;rearNode->next=t;rearNode=t;}}
void dequeue(){if(!rearNode){cout<<"Queue empty\n";return;}Node*frontNode=rearNode->next;cout<<"Removed: "<<frontNode->data<<"\n";if(frontNode==rearNode)rearNode=nullptr;else rearNode->next=frontNode->next;delete frontNode;}
void display(){if(!rearNode){cout<<"Queue empty\n";return;}Node*p=rearNode->next;do{cout<<p->data<<" ";p=p->next;}while(p!=rearNode->next);cout<<"\n";}
int main(){int ch,x;do{cout<<"\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nChoice: ";cin>>ch;if(ch==1){cin>>x;enqueue(x);}else if(ch==2)dequeue();else if(ch==3)display();}while(ch!=0);while(rearNode)dequeue();}
