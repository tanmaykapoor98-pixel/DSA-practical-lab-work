#include <iostream>
using namespace std;
struct Node{int data;Node*next;Node(int x):data(x),next(nullptr){}};
Node*topNode=nullptr;
void push(int x){Node*t=new Node(x);t->next=topNode;topNode=t;}
void pop(){if(!topNode){cout<<"Stack underflow\n";return;}Node*t=topNode;cout<<"Popped: "<<t->data<<"\n";topNode=t->next;delete t;}
void peek(){if(!topNode)cout<<"Stack is empty\n";else cout<<"Top: "<<topNode->data<<"\n";}
void display(){for(Node*p=topNode;p;p=p->next)cout<<p->data<<" ";cout<<"\n";}
int main(){int ch,x;do{cout<<"\n1.Push 2.Pop 3.Peek 4.Display 0.Exit\nChoice: ";cin>>ch;if(ch==1){cin>>x;push(x);}else if(ch==2)pop();else if(ch==3)peek();else if(ch==4)display();}while(ch!=0);while(topNode){Node*t=topNode;topNode=topNode->next;delete t;}}
