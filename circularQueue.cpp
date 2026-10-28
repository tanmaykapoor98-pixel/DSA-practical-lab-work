#include <iostream>
using namespace std;
const int MAX=5;
int q[MAX],frontIndex=-1,rearIndex=-1;
bool isFull(){return (rearIndex+1)%MAX==frontIndex;}
bool isEmpty(){return frontIndex==-1;}
void enqueue(int x){if(isFull()){cout<<"Queue full\n";return;}if(isEmpty())frontIndex=rearIndex=0;else rearIndex=(rearIndex+1)%MAX;q[rearIndex]=x;}
void dequeue(){if(isEmpty()){cout<<"Queue empty\n";return;}cout<<"Removed: "<<q[frontIndex]<<"\n";if(frontIndex==rearIndex)frontIndex=rearIndex=-1;else frontIndex=(frontIndex+1)%MAX;}
void display(){if(isEmpty()){cout<<"Queue empty\n";return;}int i=frontIndex;while(true){cout<<q[i]<<" ";if(i==rearIndex)break;i=(i+1)%MAX;}cout<<"\n";}
int main(){int ch,x;do{cout<<"\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nChoice: ";cin>>ch;if(ch==1){cin>>x;enqueue(x);}else if(ch==2)dequeue();else if(ch==3)display();}while(ch!=0);}
