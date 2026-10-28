#include <iostream>
#include <vector>
using namespace std;
int main(){int n;cin>>n;vector<int>a(n);for(int&i:a)cin>>i;int pos=0;for(int i=0;i<n;i++)if(a[i]!=0)a[pos++]=a[i];while(pos<n)a[pos++]=0;for(int x:a)cout<<x<<" ";cout<<"\n";}
