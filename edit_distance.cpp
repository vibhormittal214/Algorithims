#include<iostream>
#include<string.h>
using namespace std;
int min(int a1,int a2,int a3){
   if(a1<=a2 && a1<=a3)
    return a1;
   else if(a2<=a1 && a2<=a3)
    return a2;
   else
    return a3;
}
int main(){
   int n1,n2,i,j;
   cin>>n1;
   cin>>n2;
   char *s1,*s2;
   s1=new char[n1];
   s2=new char[n2];
   cin>>s1;
   cin>>s2;
   int arr[n1+1][n2+1];
   for(i=0;i<n1+1;i++)
    arr[i][0]=i;
   for(i=0;i<n2+1;i++)
    arr[0][i]=i;
   for(i=1;i<n1+1;i++){
    for(j=1;j<n2+1;j++){
        if(s1[i-1]==s2[j-1])
            arr[i][j]=arr[i-1][j-1];
        else
            arr[i][j]=min(arr[i-1][j-1],arr[i][j-1],arr[i-1][j])+1;
    }
   }
   cout<<"\n";
   for(i=0;i<n1+1;i++){
    for(j=0;j<n2+1;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }
   cout<<"\n";
   cout<<"The edit distance is "<<arr[n1][n2];
   return 0;
}
