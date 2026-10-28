#include <iostream>
using namespace std;
void towerOfHanoi(int n,char from,char to,char aux){if(n==0)return;towerOfHanoi(n-1,from,aux,to);cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<"\n";towerOfHanoi(n-1,aux,to,from);}
int main(){int n;cout<<"Enter number of disks: ";cin>>n;if(n<0){cout<<"Number of disks cannot be negative\n";return 0;}towerOfHanoi(n,'A','C','B');}
