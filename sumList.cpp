#include <iostream>
using namespace std;
struct Node{int data;Node*next;Node(int x):data(x),next(nullptr){}};
int main(){int n,x;cout<<"Number of nodes: ";cin>>n;Node*head=nullptr,*tail=nullptr;long long sum=0;for(int i=0;i<n;i++){cin>>x;Node*t=new Node(x);if(!head)head=tail=t;else{tail->next=t;tail=t;}sum+=x;}cout<<"Sum = "<<sum<<"\n";while(head){Node*t=head;head=head->next;delete t;}}
