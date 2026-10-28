#include <iostream>
using namespace std;
const int MAX = 100;
int st[MAX], topIndex = -1;
void push(int x){if(topIndex==MAX-1)cout<<"Stack overflow\n";else st[++topIndex]=x;}
void pop(){if(topIndex==-1)cout<<"Stack underflow\n";else cout<<"Popped: "<<st[topIndex--]<<"\n";}
void peek(){if(topIndex==-1)cout<<"Stack is empty\n";else cout<<"Top: "<<st[topIndex]<<"\n";}
void display(){if(topIndex==-1){cout<<"Stack is empty\n";return;}for(int i=topIndex;i>=0;i--)cout<<st[i]<<" ";cout<<"\n";}
int main(){int ch,x;do{cout<<"\n1.Push 2.Pop 3.Peek 4.Display 0.Exit\nChoice: ";cin>>ch;
if(ch==1){cin>>x;push(x);}else if(ch==2)pop();else if(ch==3)peek();else if(ch==4)display();}while(ch!=0);}
