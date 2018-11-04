#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int max(int n1,int n2){
   if(n1>n2)
    return n1;
   else
    return n2;
}
int main(){
   char *s1,*s2;
   int n1,n2,i,j;
   cin>>n1;
   cin>>n2;
   s1=new char[n1];
   s2=new char[n2];
   cin>>s1;
   cin>>s2;
   //cout<<s1<<" "<<s2;
   int arr[n1+1][n2+1];
   for(i=0;i<n1+1;i++)
   arr[i][0]=0;
   for(i=0;i<n2+1;i++)
    arr[0][i]=0;
   for(i=1;i<n1+1;i++){
      for(j=1;j<n2+1;j++){
        if(s1[i-1]==s2[j-1])
            arr[i][j]=arr[i-1][j-1]+1;
        else
            arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
      }

   }
   cout<<"\n";
   for(i=0;i<n1+1;i++){
    for(j=0;j<n2+1;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }
   cout<<"The length of LCS is "<<arr[n1][n2];
   //Trace back starts
   i=n1;j=n2;
   cout<<"\nThe LCS IN REVRESE ORDER IS ";
   cout<<"\n";
   int ans=arr[i][j];
   while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            cout<<s1[i-1]<<" ";
            i--;
            j--;
        }
        else{
            ans=max(arr[i][j-1],arr[i-1][j]);
            if(ans==arr[i-1][j])
                i--;
            else
                j--;}
   }
   return 0;
}
