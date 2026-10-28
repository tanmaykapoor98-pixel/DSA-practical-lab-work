#include <iostream>
#include <algorithm>
using namespace std;
struct Node{int key,height;Node*left,*right;Node(int k):key(k),height(1),left(nullptr),right(nullptr){}};
int h(Node*n){return n?n->height:0;}
void update(Node*n){n->height=1+max(h(n->left),h(n->right));}
int balance(Node*n){return n?h(n->left)-h(n->right):0;}
Node* rightRotate(Node*y){Node*x=y->left;Node*T2=x->right;x->right=y;y->left=T2;update(y);update(x);return x;}
Node* leftRotate(Node*x){Node*y=x->right;Node*T2=y->left;y->left=x;x->right=T2;update(x);update(y);return y;}
Node* insert(Node*n,int key){if(!n)return new Node(key);if(key<n->key)n->left=insert(n->left,key);else if(key>n->key)n->right=insert(n->right,key);else return n;update(n);int b=balance(n);
if(b>1&&key<n->left->key)return rightRotate(n);
if(b<-1&&key>n->right->key)return leftRotate(n);
if(b>1&&key>n->left->key){n->left=leftRotate(n->left);return rightRotate(n);}
if(b<-1&&key<n->right->key){n->right=rightRotate(n->right);return leftRotate(n);}return n;}
void preorder(Node*r){if(r){cout<<r->key<<" ";preorder(r->left);preorder(r->right);}}
int main(){Node*root=nullptr;int n,x;cout<<"Number of keys: ";cin>>n;cout<<"Enter keys: ";for(int i=0;i<n;i++){cin>>x;root=insert(root,x);}cout<<"Preorder after AVL balancing: ";preorder(root);cout<<"\n";}
