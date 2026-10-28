#include <iostream>
using namespace std;
struct Node{int data;Node*left,*right;Node(int x):data(x),left(nullptr),right(nullptr){}};
Node* insert(Node*r,int x){if(!r)return new Node(x);if(x<r->data)r->left=insert(r->left,x);else if(x>r->data)r->right=insert(r->right,x);return r;}
bool search(Node*r,int x){if(!r)return false;if(r->data==x)return true;return x<r->data?search(r->left,x):search(r->right,x);}
Node* minNode(Node*r){while(r&&r->left)r=r->left;return r;}
Node* eraseNode(Node*r,int x){if(!r)return r;if(x<r->data)r->left=eraseNode(r->left,x);else if(x>r->data)r->right=eraseNode(r->right,x);else{if(!r->left){Node*t=r->right;delete r;return t;}if(!r->right){Node*t=r->left;delete r;return t;}Node*t=minNode(r->right);r->data=t->data;r->right=eraseNode(r->right,t->data);}return r;}
void inorder(Node*r){if(r){inorder(r->left);cout<<r->data<<" ";inorder(r->right);}}
int main(){Node*root=nullptr;int n,x;cout<<"Number of values: ";cin>>n;cout<<"Enter values: ";for(int i=0;i<n;i++){cin>>x;root=insert(root,x);}cout<<"Inorder: ";inorder(root);cout<<"\nSearch value: ";cin>>x;cout<<(search(root,x)?"Found\n":"Not found\n");cout<<"Value to delete: ";cin>>x;root=eraseNode(root,x);cout<<"After deletion: ";inorder(root);cout<<"\n";}
