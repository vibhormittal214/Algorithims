#include<iostream>
using namespace std;
int main(){
   int dist;
   cin>>dist;
   int count1[dist+1];
   count1[0]=1;count1[1]=1;count1[2]=2;//initialize base value
   for(int i=3;i<=dist;i++)
    count1[i]=count1[i-1]+count1[i-2]+count1[i-3];
   cout<<count1[dist];
   return 0;
}
