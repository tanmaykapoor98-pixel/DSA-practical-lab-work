#include <iostream>
using namespace std;
const int MAX=100;
int q[MAX],frontIndex=0,rearIndex=-1;
void enqueue(int x){if(rearIndex==MAX-1)cout<<"Queue full (linear queue cannot reuse freed space)\n";else q[++rearIndex]=x;}
void dequeue(){if(frontIndex>rearIndex)cout<<"Queue empty\n";else cout<<"Removed: "<<q[frontIndex++]<<"\n";}
void display(){if(frontIndex>rearIndex){cout<<"Queue empty\n";return;}for(int i=frontIndex;i<=rearIndex;i++)cout<<q[i]<<" ";cout<<"\n";}
int main(){int ch,x;do{cout<<"\n1.Enqueue 2.Dequeue 3.Display 0.Exit\nChoice: ";cin>>ch;if(ch==1){cin>>x;enqueue(x);}else if(ch==2)dequeue();else if(ch==3)display();}while(ch!=0);}
