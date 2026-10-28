#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node { int data; Node* next; Node(int x):data(x),next(nullptr){} };
int main(){
    int n,x,k;cin>>n;Node*head=nullptr,*tail=nullptr;vector<int>a;
    for(int i=0;i<n;i++){cin>>x; a.push_back(x);Node*t=new Node(x);if(!head)head=tail=t;else{tail->next=t;tail=t;}}
    cout<<"Enter k: ";cin>>k;
    if(k<1||k>n)cout<<"Invalid k\n";
    else{sort(a.begin(),a.end());cout<<k<<"th smallest element = "<<a[k-1]<<"\n";}
    while(head){Node*t=head;head=head->next;delete t;}
}
