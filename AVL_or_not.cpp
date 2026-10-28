#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <cstdlib>
using namespace std;
struct Node{int data;Node*left,*right;Node(int x):data(x),left(nullptr),right(nullptr){}};
int checkHeight(Node*r){if(!r)return 0;int lh=checkHeight(r->left);if(lh==-1)return -1;int rh=checkHeight(r->right);if(rh==-1)return -1;if(abs(lh-rh)>1)return -1;return 1+max(lh,rh);}
int main(){int n,x;cout<<"Number of nodes: ";cin>>n;if(n<=0){cout<<"Empty tree is AVL\n";return 0;}cout<<"Enter values level-wise (-1 means missing child).\n";cout<<"Root: ";cin>>x;if(x==-1){cout<<"Empty tree is AVL\n";return 0;}Node*root=new Node(x); // Build a level-order tree
queue<Node*>q;q.push(root);
while(!q.empty()){Node*cur=q.front();q.pop();cout<<"Left child of "<<cur->data<<": ";cin>>x;if(x!=-1){cur->left=new Node(x);q.push(cur->left);}cout<<"Right child of "<<cur->data<<": ";cin>>x;if(x!=-1){cur->right=new Node(x);q.push(cur->right);}}
cout<<(checkHeight(root)==-1?"Not an AVL tree\n":"AVL tree\n");}
