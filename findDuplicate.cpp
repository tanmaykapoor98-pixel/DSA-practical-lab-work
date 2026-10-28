#include <iostream>
#include <unordered_set>
using namespace std;
int main(){int n,x;cout<<"Number of elements: ";cin>>n;unordered_set<int>seen;bool found=false;cout<<"Duplicate values: ";for(int i=0;i<n;i++){cin>>x;if(seen.count(x)){cout<<x<<" ";found=true;}else seen.insert(x);}if(!found)cout<<"None";cout<<"\n";}
