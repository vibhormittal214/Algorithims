#include<iostream>
using namespace std;
int main(){
   int n;
   cin>>n;
   if(n==2 || n==3)
    cout<<n-1;
   else{
        int res=1;
    while(n>4){
        n -=3;
   res *=3;
    }
    cout<<n*res;
    }
    return 0;
}

