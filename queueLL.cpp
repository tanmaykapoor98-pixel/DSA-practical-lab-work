#include <iostream>
using namespace std;
struct Node{int data;Node*next;Node(int x):data(x),next(nullptr){}};
Node *frontNode=nullptr,*rearNode=nullptr;
void enqueue(int x){Node*t=new Node(x);if(!rearNode)frontNode=rearNode=t;else{rearNode->next=t;rearNode=t;}}
void dequeue(){if(!frontNode){cout<<"Queue empty\n";return;}Node*t=frontNode;cout<<"Removed: "<<t->data<<"\n";frontNode=frontNode->next;if(!frontNode)rearNode=nullptr;delete t;}
void display(){for(Node*p=frontNode;p;p=p->next)cout<<p->data<<" ";cout<<"\n";}
int main(){int ch,x;do{cout<<"\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nChoice: ";cin>>ch;if(ch==1){cin>>x;enqueue(x);}else if(ch==2)dequeue();else if(ch==3)display();}while(ch!=0);while(frontNode){Node*t=frontNode;frontNode=frontNode->next;delete t;}}
