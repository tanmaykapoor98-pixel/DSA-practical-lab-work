#include <iostream>
#include <queue>
using namespace std;
struct Node{int data;Node*left,*right;Node(int x):data(x),left(nullptr),right(nullptr){}};
Node* buildTree(){
    int x;cout<<"Enter root value (-1 for no node): ";cin>>x;if(x==-1)return nullptr;
    Node*root=new Node(x);queue<Node*>q;q.push(root);
    while(!q.empty()){
        Node*cur=q.front();q.pop();
        cout<<"Left child of "<<cur->data<<" (-1 for none): ";cin>>x;
        if(x!=-1){cur->left=new Node(x);q.push(cur->left);}
        cout<<"Right child of "<<cur->data<<" (-1 for none): ";cin>>x;
        if(x!=-1){cur->right=new Node(x);q.push(cur->right);}
    }return root;
}
void preorder(Node*r){if(!r)return;cout<<r->data<<" ";preorder(r->left);preorder(r->right);}
void inorder(Node*r){if(!r)return;inorder(r->left);cout<<r->data<<" ";inorder(r->right);}
void postorder(Node*r){if(!r)return;postorder(r->left);postorder(r->right);cout<<r->data<<" ";}
int main(){Node*root=buildTree();cout<<"Preorder: ";preorder(root);cout<<"\nInorder: ";inorder(root);cout<<"\nPostorder: ";postorder(root);cout<<"\n";}
