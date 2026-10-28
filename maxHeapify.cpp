#include <iostream>
#include <vector>
using namespace std;
void maxHeapify(vector<int>&a,int n,int i){int largest=i,left=2*i+1,right=2*i+2;if(left<n&&a[left]>a[largest])largest=left;if(right<n&&a[right]>a[largest])largest=right;if(largest!=i){swap(a[i],a[largest]);maxHeapify(a,n,largest);}}
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;int i=n/2-1;for(;i>=0;i--)maxHeapify(a,n,i);cout<<"Max heap: ";for(int x:a)cout<<x<<" ";cout<<"\n";}
