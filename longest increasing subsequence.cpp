#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
if(a>b)
    return a;
else
    return b;
}
int main(){
  int n;
  cin>>n;
  int *arr,*temp_msis;
  arr=new int[n];
  temp_msis=new int[n];
  int i,j;
  for(i=0;i<n;i++){
  cin>>arr[i];
  temp_msis[i]=arr[i];
  }
  if(i==1)
  cout<<"Longest Increasing subsequence is 1";
  else
  {
      for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if((arr[j]<arr[i]) && (temp_msis[i]<arr[i]+temp_msis[j])){
                temp_msis[i]=temp_msis[j]+arr[i];
            }
        }
      }
  }
  sort(temp_msis,temp_msis+n);
  cout<<"\nLENGTH OF LONGEST INCREASING SUBSEQUENCE IS "<<temp_msis[n-1];
  return 0;
}
