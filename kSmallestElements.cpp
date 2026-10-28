#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){int n,k;cout<<"Enter n: ";cin>>n;vector<int>a(n);cout<<"Enter elements: ";for(int&i:a)cin>>i;cout<<"Enter k: ";cin>>k;if(k<0||k>n){cout<<"Invalid k\n";return 0;}sort(a.begin(),a.end());cout<<k<<" smallest elements: ";for(int i=0;i<k;i++)cout<<a[i]<<" ";cout<<"\n";}
