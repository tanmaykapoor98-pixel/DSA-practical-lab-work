#include <iostream>
#include <vector>
using namespace std;
struct Node{int data;Node*left,*right;Node(int x):data(x),left(nullptr),right(nullptr){}};
Node* buildComplete(const vector<int>&a,int i){if(i>=(int)a.size())return nullptr;Node*r=new Node(a[i]);r->left=buildComplete(a,2*i+1);r->right=buildComplete(a,2*i+2);return r;}
bool isMaxHeap(Node*r){if(!r)return true;if(r->left&&r->left->data>r->data)return false;if(r->right&&r->right->data>r->data)return false;return isMaxHeap(r->left)&&isMaxHeap(r->right);}
void preorder(Node*r){if(r){cout<<r->data<<" ";preorder(r->left);preorder(r->right);}}
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;Node*root=buildComplete(a,0);cout<<"Tree preorder: ";preorder(root);cout<<"\n"<<(isMaxHeap(root)?"It satisfies max-heap order\n":"It does not satisfy max-heap order\n");}
